#include "objreadingtools.h"

#include <QFile>
#include <QTextStream>

// TODO Try to reduce repeating

bool ObjReadingTools::Utils::parseVertex(const QString &body, QVector3D &vertex, QString &errMsg)
{
    QStringList blocks = body.split(" ", QString::SkipEmptyParts);

    if(blocks.length() != 3){
        errMsg = QString("Invalid number of vertex coordinates. Expected 3. Actual received %1").arg(blocks.length());
        return false;
    }

    bool ok = true;
    for(int i = 0; i < 3; ++i) {
        vertex[i] = blocks[i].toFloat(&ok);
        if(!ok) {
            errMsg = QString("To float conversion failed in string %1. Position %2").arg(blocks[i]).arg(i + 1);
            return false;
        }
    }

    return true;
}

bool ObjReadingTools::Utils::parseTexCoord(const QString &body, QVector2D &texCoord, QString &errMsg)
{
    QStringList blocks = body.split(" ", QString::SkipEmptyParts);

    if(!(blocks.length() == 2 || blocks.length() == 3)){
        errMsg = QString("Invalid number of texture coordinates. Expected 2 or 3. Actual received %1").arg(blocks.length());
        return false;
    }

    bool ok = true;
    for(int i = 0; i < 2; ++i) {
        texCoord[i] = blocks[i].toFloat(&ok);
        if(!ok) {
            errMsg = QString("To float conversion failed in string %1. Position %2").arg(blocks[i]).arg(i + 1);
            return false;
        }
    }

    return true;
}

bool ObjReadingTools::Utils::parseNormal(const QString &body, QVector3D &normal, QString &errMsg)
{
    QStringList blocks = body.split(" ", QString::SkipEmptyParts);

    if(blocks.length() != 3){
        errMsg = QString("Invalid number of normals coordinates. Expected 3. Actual received %1").arg(blocks.length());
        return false;
    }

    bool ok = true;
    for(int i = 0; i < 3; ++i) {
        normal[i] = blocks[i].toFloat(&ok);
        if(!ok) {
            errMsg = QString("To float conversion failed in string %1. Position %2").arg(blocks[i]).arg(i + 1);
            return false;
        }
    }

    return true;
}

bool ObjReadingTools::Utils::parseFace(const QString &body, QVector<int> &verticesInd, QVector<int> &texCodsInd, QVector<int> &normalsInd, QString &errMsg)
{
    verticesInd.clear();
    texCodsInd.clear();
    normalsInd.clear();

    QStringList blocks = body.split(" ", QString::SkipEmptyParts);
    int nBlocks = blocks.length();

    if (nBlocks < 3) {
        errMsg = QString("Face should contains 3 or more vertices. Actual received %1").arg(nBlocks);
        return false;
    }

    for(int i = 0; i < nBlocks; ++i){
        QString currentBlock = blocks[i];
        int nSlash = currentBlock.count("/");

        if(nSlash > 2 || currentBlock.startsWith('/') || currentBlock.endsWith('/')){
            errMsg = QString("Vertex format should be v, v/vt, v//vn or v/vt/vn. Now block contains %1. Block number %2").arg(currentBlock).arg(i + 1);
            return false;
        }

        // To format v/vt/vn. Missing replace with 0
        if(nSlash == 0) {
            currentBlock += "/0/0";
        } else if (nSlash == 1) {
            currentBlock += "/0";
        } else {
            int firstSlashInd = currentBlock.indexOf("/");
            int secondSlashInd = currentBlock.lastIndexOf("/");
            if(secondSlashInd - firstSlashInd == 1)
                currentBlock.insert(firstSlashInd + 1, "0");
        }

        QStringList inds = currentBlock.split("/", QString::SkipEmptyParts);

        bool ok = true;
        int vInd = 0;
        int vtInd = 0;
        int vnInd = 0;

        // It can be better
        vInd = inds[0].toInt(&ok);
        if(!ok) {
            errMsg = QString("To int conversion failed in string %1").arg(inds[0]);
            return false;
        }

        vtInd = inds[1].toInt(&ok);
        if(!ok) {
            errMsg = QString("To int conversion failed in string %1").arg(inds[1]);
            return false;
        }

        vnInd = inds[2].toInt(&ok);
        if(!ok) {
            errMsg = QString("To int conversion failed in string %1").arg(inds[2]);
            return false;
        }

        verticesInd.append(vInd);
        texCodsInd.append(vtInd);
        normalsInd.append(vnInd);
    }

    return true;
}

bool ObjReadingTools::readModelGeometry(QTextStream &stream, ModelGeometry &model, QString &errMsg)
{
    int lineInd = 0;
    while(!stream.atEnd()){
        ++lineInd;
        QString line = stream.readLine().simplified();

        if(line.isEmpty() || line.startsWith("#"))
            continue;

        int firstSpaceInd = line.indexOf(" ");

        if(firstSpaceInd == 0) {
            errMsg = QString("Invalid format in line %1").arg(lineInd);
            return false;
        }

        QString token = line.left(firstSpaceInd);
        QString body = line.mid(firstSpaceInd + 1);

        if(token == "v") {
            QVector3D vertex;
            if(!ObjReadingTools::Utils::parseVertex(body, vertex, errMsg)){
                errMsg = QString("Line %1. ").arg(lineInd) + errMsg;
                return false;
            }
            model.m_vertices.append(vertex);
        } else if (token == "vt") {
            QVector2D texCoord;
            if(!ObjReadingTools::Utils::parseTexCoord(body, texCoord, errMsg)) {
                errMsg = QString("Line %1. ").arg(lineInd) + errMsg;
                return false;
            }
            model.m_texCoords.append(texCoord);
        } else if (token == "vn") {
            QVector3D normal;
            if(!ObjReadingTools::Utils::parseNormal(body, normal, errMsg)){
                errMsg = QString("Line %1. ").arg(lineInd) + errMsg;
                return false;
            }
            model.m_normals.append(normal);
        } else if (token == "f") {
            QVector<int> vericesInd;
            QVector<int> texCoordsInd;
            QVector<int> normalsInd;
            if(!ObjReadingTools::Utils::parseFace(body, vericesInd, texCoordsInd, normalsInd, errMsg)) {
                errMsg = QString("Line %1. ").arg(lineInd) + errMsg;
                return false;
            }
            model.m_polygonsVerticesIndices.append(vericesInd);
            model.m_polygonsTexCoordsIndices.append(texCoordsInd);
            model.m_polygonsNormalsIndices.append(normalsInd);
        } else if (token == "l") {
            // line specification
        } else if (token == "g") {
            // Group specification
        } else {
            errMsg = QString("Line %1. Invalid token %2").arg(lineInd).arg(token);
            return false;
        }
    }

    return true;
}


