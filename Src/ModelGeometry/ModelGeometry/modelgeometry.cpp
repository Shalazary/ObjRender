#include "modelgeometry.h"

bool operator ==(const ModelGeometry &m1, const ModelGeometry &m2)
{
    return
        m1.vertices == m2.vertices &&
        m1.texCoords == m2.texCoords &&
        m1.normals == m2.normals &&
        m1.polygonsVerticesIndices == m2.polygonsVerticesIndices &&
        m1.polygonsTexCoordsIndices == m2.polygonsTexCoordsIndices &&
        m1.polygonsNormalsIndices == m2.polygonsNormalsIndices &&
        m1.polygonsStarts == m2.polygonsStarts;
}

QVector<QVector3D> ModelGeometry::polygonVertices(int polygonIndex) const
{
    const int polygonSize = polygonsStarts[polygonIndex + 1] - polygonsStarts[polygonIndex];
    const int startIndex = polygonsStarts[polygonIndex];

    QVector<QVector3D> polygonVertices(polygonSize);

    for(int vertexNumber = 0; vertexNumber < polygonSize; ++vertexNumber)
        polygonVertices[vertexNumber] = vertices[polygonsVerticesIndices[startIndex + vertexNumber]];

    return polygonVertices;
}

QVector<QVector2D> ModelGeometry::polygonTexCoords(int polygonIndex) const
{
    const int polygonSize = polygonsStarts[polygonIndex + 1] - polygonsStarts[polygonIndex];
    const int startIndex = polygonsStarts[polygonIndex];

    QVector<QVector2D> polygonTexCoords(polygonSize);

    for(int texCoordNumber = 0; texCoordNumber < polygonSize; ++texCoordNumber)
        polygonTexCoords[texCoordNumber] = texCoords[polygonsTexCoordsIndices[startIndex + texCoordNumber]];

    return polygonTexCoords;
}

QVector<QVector3D> ModelGeometry::polygonNormals(int polygonIndex) const
{
    const int polygonSize = polygonsStarts[polygonIndex + 1] - polygonsStarts[polygonIndex];
    const int startIndex = polygonsStarts[polygonIndex];

    QVector<QVector3D> polygonNormals(polygonSize);

    for(int normalNumber = 0; normalNumber < polygonSize; ++normalNumber)
        polygonNormals[normalNumber] = normals[polygonsNormalsIndices[startIndex + normalNumber]];

    return polygonNormals;
}
