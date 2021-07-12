#ifndef DRAWABLE_MODEL_H
#define DRAWABLE_MODEL_H

#include <QString>
#include <QTextStream>
#include <QVector>
#include <QVector2D>
#include <QVector3D>

#include "DrawableObject/drawableobject.h"

class DrawableModel : public DrawableObject
{
public:
    DrawableModel() = default;

    int nPoligons() const;

    bool save(const QString &filename, QString &errMsg) const;
    bool save(QTextStream &stream, QString &errMsg) const;

    bool read(const QString &filename, QString &errMsg);
    bool read(QTextStream &stream, QString &errMsg);

    QVector<QVector3D> vertices;
    QVector<QVector2D> texCoords;
    QVector<QVector3D> normals;

    QVector<QVector<int>> polygonsVerticesIndices;
    QVector<QVector<int>> polygonsTexCoordsIndices;
    QVector<QVector<int>> polygonsNormalsIndices;

    void draw(const QMatrix4x4 &modelViewMatrix, const QMatrix4x4 &projectionMatrix, QImage &image, int **zbuffer) override;
};

#endif
