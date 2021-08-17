#include "modelgeometry.h"

#include "Utils/utils.h"

bool operator ==(const ModelGeometry::ModelGeometry &m1, const ModelGeometry::ModelGeometry &m2)
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

int ModelGeometry::ModelGeometry::nPolygons() const
{
    return polygonsStarts.size() - 1;
}

int ModelGeometry::ModelGeometry::nTriangles() const
{
    return m_nTrianles;
}

bool ModelGeometry::ModelGeometry::isTriangulated() const
{
    return m_nTrianles > 0;
}

bool ModelGeometry::ModelGeometry::isNormalsRecomputed() const
{
    return recomputedNormals.size() > 0;
}

void ModelGeometry::ModelGeometry::clear()
{
    vertices.clear();
    texCoords.clear();
    normals.clear();
    recomputedNormals.clear();

    polygonsVerticesIndices.clear();
    polygonsTexCoordsIndices.clear();
    polygonsNormalsIndices.clear();

    polygonsStarts.clear();

    triangulatedPolygonsVerticesIndices.clear();
    triangulatedPolygonsTexCoordsIndices.clear();
    triangulatedPolygonsNormalsIndices.clear();
}

void ModelGeometry::ModelGeometry::triangulate()
{
    for(int polygonNumber = 0; polygonNumber < polygonsStarts.size() - 1; ++polygonNumber) {
        int polygonSize = polygonsStarts[polygonNumber + 1] - polygonsStarts[polygonNumber];
        int polygonStartInd = polygonsStarts[polygonNumber];
        for(int triangleNumber = 0; triangleNumber < polygonSize - 2; ++triangleNumber) {
            m_nTrianles++;

            triangulatedPolygonsVerticesIndices.append({
                polygonsVerticesIndices[polygonStartInd],
                polygonsVerticesIndices[polygonStartInd + triangleNumber + 1],
                polygonsVerticesIndices[polygonStartInd + triangleNumber + 2]
            });

            triangulatedPolygonsTexCoordsIndices.append({
                polygonsTexCoordsIndices[polygonStartInd],
                polygonsTexCoordsIndices[polygonStartInd + triangleNumber + 1],
                polygonsTexCoordsIndices[polygonStartInd + triangleNumber + 2]
            });

            triangulatedPolygonsNormalsIndices.append({
                polygonsNormalsIndices[polygonStartInd],
                polygonsNormalsIndices[polygonStartInd + triangleNumber + 1],
                polygonsNormalsIndices[polygonStartInd + triangleNumber + 2]
            });
        }
    }
}

void ModelGeometry::ModelGeometry::recomputeNormals()
{
    recomputedNormals.clear();
    for(int vertexInd = 1; vertexInd <= vertices.size(); ++vertexInd)
        recomputedNormals.append(ModelGeometryUtils::calculateNormal(vertexInd, vertices, polygonsVerticesIndices, polygonsStarts));
}




