#ifndef RENDER_TOOLS_H
#define RENDER_TOOLS_H

#include <QImage>
#include <QVector>
#include <QVector2D>
#include <QVector3D>
#include <QMatrix4x4>

#include "ModelGeometry/modelgeometry.h"
#include "Camera/camera.h"

namespace RenderTools {

void render(
    QImage *image,
    float **zbuffer,
    const QVector<QVector3D> &vertices,
    const QVector<int> &polygonsVerticesIndices,
    const QVector<QVector2D> &texCoords,
    const QVector<int> &polygonsTexCoordsIndices,
    const QVector<int> &polygonsStart,
    const QImage &texture,
    const QVector3D &lightDirection,
    const QMatrix4x4 &MVP,
    const QColor &modelColor = Qt::white);

QImage render(
    const QVector<QVector3D> &vertices,
    const QVector<int> &polygonsVerticesIndices,
    const QVector<QVector2D> &texCoords,
    const QVector<int> &polygonsTexCoordsIndices,
    const QVector<int> &polygonsStart,
    const QImage &texture,
    const QVector3D &lightDirection,
    const QMatrix4x4 &MVP,
    const int renderWidth = 1080,
    const int renderHeight = 1080,
    const QColor &modelColor = Qt::white,
    const QColor &backgroundColor = Qt::black
);

QImage render(
    const ModelGeometry &model,
    const Camera &camera,
    const int renderWidth = 1080,
    const int renderHeight = 1080,
    const QColor &modelColor = Qt::white,
    const QColor &backgroundColor = Qt::black);

QImage render(
    const ModelGeometry &model,
    const Camera &camera,
    const QVector3D &lightDirection,
    const int renderWidth = 1080,
    const int renderHeight = 1080,
    const QColor &modelColor = Qt::white,
    const QColor &backgroundColor = Qt::black);

QImage render(
    const ModelGeometry &model,
    const Camera &camera,
    const QImage &texture,
    const int renderWidth = 1080,
    const int renderHeight = 1080,
    const QColor &modelColor = Qt::white,
    const QColor &backgroundColor = Qt::black);

QImage render(
    const ModelGeometry &model,
    const Camera &camera,
    const QImage &texture,
    const QVector3D lightDirection,
    const int renderWidth = 1080,
    const int renderHeight = 1080,
    const QColor &modelColor = Qt::white,
    const QColor &backgroundColor = Qt::black);

}

#endif
