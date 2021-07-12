#ifndef OBJDATA_H
#define OBJDATA_H

#include <QVector>
#include <QVector2D>
#include <QVector3D>
#include <QString>
#include <QTextStream>

#include "DrawableModel/drawablemodel.h"

namespace ObjReadingTools {
bool readModel(QTextStream &stream, DrawableModel &model, QString &errMsg);
namespace Utils {
bool parseVertex(const QString &body, QVector3D &vertex, QString &errMsg);
bool parseTexCoord(const QString &body, QVector2D &texCoord, QString &errMsg);
bool parseNormal(const QString &body, QVector3D &normal, QString &errMsg);
bool parseFace(const QString &body, QVector<int> &verticesInd, QVector<int> &texCodsInd, QVector<int> &normalsInd, QString &errMsg);
}
}

#endif // OBJDATA_H
