#include "render_tools.h"

#include "ModelGeometry/Utils/utils.h"
#include "DrawingTools/drawingtools.h"

QImage RenderTools::render(
    const QVector<QVector3D> &vertices,
    const QVector<QVector<int>> &polygonsVerticesIndices,
    const QVector<QVector2D> &texCoords,
    const QVector<QVector<int>> &polygonsTexCoordsIndices,
    const QImage &texture,
    const QVector3D &lightDirection,
    const QMatrix4x4 &MVP,
    const int renderWidth,
    const int renderHeight,
    const QColor &modelColor,
    const QColor &backgroundColor)
{
    bool useTexture = true;
    bool useLight = true;

    if(texture.isNull())
        useTexture = false;

    if(lightDirection.isNull())
        useLight = false;

    QImage image = QImage(renderWidth, renderHeight, QImage::Format_ARGB32);
    image.fill(backgroundColor);

    float **zbuffer = new float * [renderHeight];
    zbuffer[0] = new float [renderHeight * renderWidth];
    for(int i = 1; i < renderHeight; ++i)
        zbuffer[i] = zbuffer[i - 1] + renderWidth;
    for(int i = 0; i < renderHeight; ++i)
        for(int j = 0; j < renderWidth; ++j)
            zbuffer[i][j] = 2.0f;

    for(int polygonInd = 0; polygonInd < polygonsVerticesIndices.size(); ++polygonInd) {
        QVector<QVector<int>> triangles = ModelGeometryUtils::triangulate(polygonsVerticesIndices[polygonInd]);
        for(const QVector<int> &triangel : triangles){
            QVector<int> polygonVertices = polygonsVerticesIndices[polygonInd];
            QVector<int> polygonTex = polygonsTexCoordsIndices[polygonInd];

            QVector4D p1 = QVector4D(MVP * QVector4D(vertices[polygonVertices[triangel[0]] - 1], 1));
            QVector4D p2 = QVector4D(MVP * QVector4D(vertices[polygonVertices[triangel[1]] - 1], 1));
            QVector4D p3 = QVector4D(MVP * QVector4D(vertices[polygonVertices[triangel[2]] - 1], 1));

            QVector2D vt1;
            QVector2D vt2;
            QVector2D vt3;

            if(useTexture) {
                vt1 = texCoords[polygonTex[triangel[0]] - 1];
                vt2 = texCoords[polygonTex[triangel[1]] - 1];
                vt3 = texCoords[polygonTex[triangel[2]] - 1];
            }

            QVector3D vn1;
            QVector3D vn2;
            QVector3D vn3;

            if(useLight) {
                vn1 = ModelGeometryUtils::calculateNormal(polygonVertices[triangel[0]], vertices, polygonsVerticesIndices);
                vn2 = ModelGeometryUtils::calculateNormal(polygonVertices[triangel[1]], vertices, polygonsVerticesIndices);
                vn3 = ModelGeometryUtils::calculateNormal(polygonVertices[triangel[2]], vertices, polygonsVerticesIndices);
            }

            if(!useTexture && !useLight)
                DrawingTools::drawTriangel(image, p1, p2, p3, modelColor, zbuffer);
            else if(!useTexture && useLight)
                DrawingTools::drawTriangel(image, p1, p2, p3, vn1, vn2, vn3, -lightDirection, modelColor, zbuffer);
            else if(useTexture && !useLight)
                DrawingTools::drawTriangel(image, p1, p2, p3, vt1, vt2, vt3, texture, zbuffer);
            else if(useTexture && useLight)
                DrawingTools::drawTriangel(image, p1, p2, p3, vt1, vt2, vt3, vn1, vn2, vn3, -lightDirection, texture, zbuffer);
        }
    }

    return image;
}

QImage RenderTools::render(const ModelGeometry &model,
    const Camera &camera,
    const int renderWidth,
    const int renderHeight,
    const QColor &modelColor,
    const QColor &backgroundColor)
{
    return render(
        model.m_vertices,
        model.m_polygonsVerticesIndices,
        model.m_texCoords,
        model.m_polygonsTexCoordsIndices,
        QImage(),
        QVector3D(),
        camera.projection() * camera.view(),
        renderWidth,
        renderHeight,
        modelColor,
        backgroundColor);
}

QImage RenderTools::render(const ModelGeometry &model,
    const Camera &camera,
    const QVector3D &lightDirection,
    const int renderWidth,
    const int renderHeight,
    const QColor &modelColor,
    const QColor &backgroundColor)
{
    return render(
        model.m_vertices,
        model.m_polygonsVerticesIndices,
        model.m_texCoords,
        model.m_polygonsTexCoordsIndices,
        QImage(),
        lightDirection,
        camera.projection() * camera.view(),
        renderWidth,
        renderHeight,
        modelColor,
        backgroundColor);
}

QImage RenderTools::render(
    const ModelGeometry &model,
    const Camera &camera,
    const QImage &texture,
    const int renderWidth,
    const int renderHeight,
    const QColor &modelColor,
    const QColor &backgroundColor)
{
    return render(
        model.m_vertices,
        model.m_polygonsVerticesIndices,
        model.m_texCoords,
        model.m_polygonsTexCoordsIndices,
        texture,
        QVector3D(),
        camera.projection() * camera.view(),
        renderWidth,
        renderHeight,
        modelColor,
        backgroundColor);
}

QImage RenderTools::render(
    const ModelGeometry &model,
    const Camera &camera,
    const QImage &texture,
    const QVector3D lightDirection,
    const int renderWidth,
    const int renderHeight,
    const QColor &modelColor,
    const QColor &backgroundColor)
{
    return render(
        model.m_vertices,
        model.m_polygonsVerticesIndices,
        model.m_texCoords,
        model.m_polygonsTexCoordsIndices,
        texture,
        lightDirection,
        camera.projection() * camera.view(),
        renderWidth,
        renderHeight,
        modelColor,
        backgroundColor);
}
