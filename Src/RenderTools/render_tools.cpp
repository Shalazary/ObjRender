#include "render_tools.h"

#include "ModelGeometry/Utils/utils.h"
#include "ShapeDrawingTools/shapedrawingtools.h"
#include "TexturePixelColorGetter/texture_pixel_color_getter.h"
#include "PlainPixelColorGetter/plain_pixel_color_getter.h"
#include "ShadePixelColorGetter/shade_pixel_color_getter.h"
#include "LightPixelColorTransformer/light_pixel_color_transformer.h"

void RenderTools::render(
    QImage *image,
    Array2D::Array2D<float> &zbuffer,
    const QVector<QVector3D> &vertices,
    const QVector<int> &polygonsVerticesIndices,
    const QVector<QVector2D> &texCoords,
    const QVector<int> &polygonsTexCoordsIndices,
    const QVector<int> &polygonsStart,
    const QImage &texture,
    const QVector3D &lightDirection,
    const QMatrix4x4 &MVP,
    const QColor &modelColor)
{
    bool useTexture = true;
    bool useLight = true;

    if(texture.isNull())
        useTexture = false;

    if(lightDirection.isNull())
        useLight = false;

    for(int polygonInd = 0; polygonInd < polygonsStart.size() - 1; ++polygonInd) {

        const QVector<int> polygonVertices = polygonsVerticesIndices.mid(polygonsStart[polygonInd], polygonsStart[polygonInd + 1] - polygonsStart[polygonInd]);
        const QVector<int> polygonTex = polygonsTexCoordsIndices.mid(polygonsStart[polygonInd], polygonsStart[polygonInd + 1] - polygonsStart[polygonInd]);

        const QVector<QVector<int>> triangles = ModelGeometryUtils::triangulate(polygonVertices);

        for(const QVector<int> &triangle : triangles){
            const QVector4D p1 = MVP * QVector4D(vertices[polygonVertices[triangle[0]] - 1], 1);
            const QVector4D p2 = MVP * QVector4D(vertices[polygonVertices[triangle[1]] - 1], 1);
            const QVector4D p3 = MVP * QVector4D(vertices[polygonVertices[triangle[2]] - 1], 1);

            QVector2D vt1;
            QVector2D vt2;
            QVector2D vt3;

            if(useTexture) {
                vt1 = texCoords[polygonTex[triangle[0]] - 1];
                vt2 = texCoords[polygonTex[triangle[1]] - 1];
                vt3 = texCoords[polygonTex[triangle[2]] - 1];
            }

            QVector3D vn1;
            QVector3D vn2;
            QVector3D vn3;

            if(useLight) {
                vn1 = ModelGeometryUtils::calculateNormal(polygonVertices[triangle[0]], vertices, polygonsVerticesIndices, polygonsStart);
                vn2 = ModelGeometryUtils::calculateNormal(polygonVertices[triangle[1]], vertices, polygonsVerticesIndices, polygonsStart);
                vn3 = ModelGeometryUtils::calculateNormal(polygonVertices[triangle[2]], vertices, polygonsVerticesIndices, polygonsStart);
            }

            if(!useTexture && !useLight) {
                DrawingTools::PlainPixelColorGetter plainColorGetter(modelColor);
                ShapeDrawingTools::drawTriangle(*image, zbuffer, p1, p2, p3, &plainColorGetter);
            }
            else if(!useTexture && useLight) {
                DrawingTools::PlainPixelColorGetter plainColorGetter(modelColor);
                DrawingTools::LightPixelColorTransformer lightColorTransformer(lightDirection, vn1, vn2, vn3);
                DrawingTools::ShadePixelColorGetter colorGetter(&plainColorGetter, &lightColorTransformer);
                ShapeDrawingTools::drawTriangle(*image, zbuffer, p1, p2, p3, &colorGetter);
            }
            else if(useTexture && !useLight){
                DrawingTools::TexturePixelColorGetter textureColorGetter(texture, vt1, vt2, vt3);
                ShapeDrawingTools::drawTriangle(*image, zbuffer, p1, p2, p3, &textureColorGetter);
            }
            else if(useTexture && useLight) {
                DrawingTools::TexturePixelColorGetter textureColorGetter(texture, vt1, vt2, vt3);
                DrawingTools::LightPixelColorTransformer lightColorTransformer(lightDirection, vn1, vn2, vn3);
                DrawingTools::ShadePixelColorGetter colorGetter(&textureColorGetter, &lightColorTransformer);
                ShapeDrawingTools::drawTriangle(*image, zbuffer, p1, p2, p3, &colorGetter);
            }
        }
    }
}

QImage RenderTools::render(
    const QVector<QVector3D> &vertices,
    const QVector<int> &polygonsVerticesIndices,
    const QVector<QVector2D> &texCoords,
    const QVector<int> &polygonsTexCoordsIndices,
    const QVector<int> &polygonsStart,
    const QImage &texture,
    const QVector3D &lightDirection,
    const QMatrix4x4 &MVP,
    const int renderWidth,
    const int renderHeight,
    const QColor &modelColor,
    const QColor &backgroundColor)
{
    QImage image = QImage(renderWidth, renderHeight, QImage::Format_ARGB32);
    image.fill(backgroundColor);

    Array2D::Array2D<float> zbuffer(renderHeight, renderWidth, 2.0f);

    render(
        &image,
        zbuffer,
        vertices,
        polygonsVerticesIndices,
        texCoords,
        polygonsTexCoordsIndices,
        polygonsStart,
        texture,
        lightDirection,
        MVP,
        modelColor);

    return image;
}

QImage RenderTools::render(
    const ModelGeometry::ModelGeometry &model,
    const Camera::Camera &camera,
    const int renderWidth,
    const int renderHeight,
    const QColor &modelColor,
    const QColor &backgroundColor)
{
    return render(
        model.vertices,
        model.polygonsVerticesIndices,
        model.texCoords,
        model.polygonsTexCoordsIndices,
        model.polygonsStarts,
        QImage(),
        QVector3D(),
        camera.projection() * camera.view(),
        renderWidth,
        renderHeight,
        modelColor,
        backgroundColor);
}

QImage RenderTools::render(
    const ModelGeometry::ModelGeometry &model,
    const Camera::Camera &camera,
    const QVector3D &lightDirection,
    const int renderWidth,
    const int renderHeight,
    const QColor &modelColor,
    const QColor &backgroundColor)
{
    return render(
        model.vertices,
        model.polygonsVerticesIndices,
        model.texCoords,
        model.polygonsTexCoordsIndices,
        model.polygonsStarts,
        QImage(),
        lightDirection,
        camera.projection() * camera.view(),
        renderWidth,
        renderHeight,
        modelColor,
        backgroundColor);
}

QImage RenderTools::render(
    const ModelGeometry::ModelGeometry &model,
    const Camera::Camera &camera,
    const QImage &texture,
    const int renderWidth,
    const int renderHeight,
    const QColor &modelColor,
    const QColor &backgroundColor)
{
    return render(
        model.vertices,
        model.polygonsVerticesIndices,
        model.texCoords,
        model.polygonsTexCoordsIndices,
        model.polygonsStarts,
        texture,
        QVector3D(),
        camera.projection() * camera.view(),
        renderWidth,
        renderHeight,
        modelColor,
        backgroundColor);
}

QImage RenderTools::render(
    const ModelGeometry::ModelGeometry &model,
    const Camera::Camera &camera,
    const QImage &texture,
    const QVector3D lightDirection,
    const int renderWidth,
    const int renderHeight,
    const QColor &modelColor,
    const QColor &backgroundColor)
{
    return render(
        model.vertices,
        model.polygonsVerticesIndices,
        model.texCoords,
        model.polygonsTexCoordsIndices,
        model.polygonsStarts,
        texture,
        lightDirection,
        camera.projection() * camera.view(),
        renderWidth,
        renderHeight,
        modelColor,
        backgroundColor);
}


