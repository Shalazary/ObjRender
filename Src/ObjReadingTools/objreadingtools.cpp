#include "objreadingtools.h"

#include <QFile>
#include <QTextStream>

// TODO Try to reduce repeating

bool ObjReadingTools::Utils::parseVertex(const QString &body, QVector3D &vertex, QString &errMsg)
{
    const QStringList blocks = body.split(" ", QString::SkipEmptyParts);

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
    const QStringList blocks = body.split(" ", QString::SkipEmptyParts);

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
    const QStringList blocks = body.split(" ", QString::SkipEmptyParts);

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

    const QStringList blocks = body.split(" ", QString::SkipEmptyParts);
    const int nBlocks = blocks.length();

    if (nBlocks < 3) {
        errMsg = QString("Face should contains 3 or more vertices. Actual received %1").arg(nBlocks);
        return false;
    }

    for(int i = 0; i < nBlocks; ++i){
        QString currentBlock = blocks[i];
        const int nSlash = currentBlock.count("/");

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
            const int firstSlashInd = currentBlock.indexOf("/");
            const int secondSlashInd = currentBlock.lastIndexOf("/");
            if(secondSlashInd - firstSlashInd == 1)
                currentBlock.insert(firstSlashInd + 1, "0");
        }

        const QStringList inds = currentBlock.split("/", QString::SkipEmptyParts);

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

    int nVertices = 0;
    int nTexCoords = 0;
    int nNormals = 0;
    int nPolygons = 0;
    int nVerticesInPolygons = 0;

    model.vertices.clear();
    model.texCoords.clear();
    model.normals.clear();
    model.polygonsVerticesIndices.clear();
    model.polygonsTexCoordsIndices.clear();
    model.polygonsNormalsIndices.clear();
    model.polygonsStarts.clear();

    Utils::getObjInfo(stream, nVertices, nTexCoords, nNormals, nPolygons, nVerticesInPolygons);

    model.vertices.reserve(nVertices);
    model.texCoords.reserve(nTexCoords);
    model.normals.reserve(nNormals);
    model.polygonsVerticesIndices.reserve(nVerticesInPolygons);
    model.polygonsTexCoordsIndices.reserve(nVerticesInPolygons);
    model.polygonsNormalsIndices.reserve(nVerticesInPolygons);
    model.polygonsStarts.reserve(nPolygons);

    stream.seek(0);

    while(!stream.atEnd()){
        ++lineInd;
        const QString line = stream.readLine().simplified();

        if(line.isEmpty() || line.startsWith('#'))
            continue;

        QString token;
        QString body;

        if(!Utils::parseTokenAndBody(line, token, body, errMsg)) {
            errMsg = QString("Line %1. ").arg(lineInd) + errMsg;
            return false;
        }

        if(token == "v") {
            QVector3D vertex;
            if(!ObjReadingTools::Utils::parseVertex(body, vertex, errMsg)){
                errMsg = QString("Line %1. ").arg(lineInd) + errMsg;
                return false;
            }
            model.vertices.append(vertex);
        } else if (token == "vt") {
            QVector2D texCoord;
            if(!ObjReadingTools::Utils::parseTexCoord(body, texCoord, errMsg)) {
                errMsg = QString("Line %1. ").arg(lineInd) + errMsg;
                return false;
            }
            model.texCoords.append(texCoord);
        } else if (token == "vn") {
            QVector3D normal;
            if(!ObjReadingTools::Utils::parseNormal(body, normal, errMsg)){
                errMsg = QString("Line %1. ").arg(lineInd) + errMsg;
                return false;
            }
            model.normals.append(normal);
        } else if (token == "f") {
            QVector<int> vericesInd;
            QVector<int> texCoordsInd;
            QVector<int> normalsInd;
            if(!ObjReadingTools::Utils::parseFace(body, vericesInd, texCoordsInd, normalsInd, errMsg)) {
                errMsg = QString("Line %1. ").arg(lineInd) + errMsg;
                return false;
            }
            model.polygonsStarts.append(model.polygonsVerticesIndices.size());
            model.polygonsVerticesIndices.append(vericesInd);
            model.polygonsTexCoordsIndices.append(texCoordsInd);
            model.polygonsNormalsIndices.append(normalsInd);
        } else if (token == "l") {
            // Line specification
        } else if (token == "g") {
            // Group specification
        } else {
            errMsg = QString("Line %1. Invalid token %2").arg(lineInd).arg(token);
            return false;
        }
    }

    model.polygonsStarts.append(model.polygonsVerticesIndices.size());

    return true;
}



bool ObjReadingTools::Utils::parseTokenAndBody(const QString &line, QString &token, QString &body, QString &errMsg)
{
    const int firstSpaceInd = line.indexOf(" ");

    if(firstSpaceInd == 0 || firstSpaceInd == -1) {
        errMsg = QString("Invalid line format");
        return false;
    }

    token = line.left(firstSpaceInd);
    body = line.mid(firstSpaceInd + 1);

    return true;
}

void ObjReadingTools::Utils::getObjInfo(
    QTextStream &stream,
    int &nVertices,
    int &nTexCoords,
    int &nNormals,
    int &nPolygons,
    int &nVerticesInPolygons)
{
    nVertices = 0;
    nTexCoords = 0;
    nNormals = 0;
    nPolygons = 0;
    nVerticesInPolygons = 0;

    while (!stream.atEnd()) {
        const QString line = stream.readLine().simplified();

        QString token;
        QString body;

        QString errMsg;

        Utils::parseTokenAndBody(line, token, body, errMsg);
        if(token == "v")
            ++nVertices;
        else if(token == "vt")
            ++nTexCoords;
        else if(token == "vn")
            ++nNormals;
        else if(token == "f") {
            ++nPolygons;
            //! REVIEW: split -> count
            nVerticesInPolygons += body.split(" ", QString::SkipEmptyParts).size();
        }
    }
}
