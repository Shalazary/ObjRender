#ifndef OBJDATA_H
#define OBJDATA_H

#include <QVector>
#include <QVector2D>
#include <QVector3D>
#include <QString>
#include <QTextStream>

#include "ModelGeometry/ModelGeometry/modelgeometry.h"

namespace ObjReadingTools {

bool readModelGeometry(QTextStream &stream, ModelGeometry &model, QString &errMsg);

namespace Utils {

bool parseTokenAndBody(const QString &line, QString &token, QString &body, QString &errMsg);
bool parseVertex(const QString &body, QVector3D &vertex, QString &errMsg);
bool parseTexCoord(const QString &body, QVector2D &texCoord, QString &errMsg);
bool parseNormal(const QString &body, QVector3D &normal, QString &errMsg);

bool parseFace(
    const QString &body,
    QVector<int> &verticesInd,
    QVector<int> &texCodsInd,
    QVector<int> &normalsInd,
    QString &errMsg);

void getObjInfo(
    QTextStream &stream,
    int &nVertices,
    int &nTexCoords,
    int &nNormals,
    int &nPolygons,
    int &nVerticesInPolygons);
}

}

#endif // OBJDATA_H
