#include "modelgeometry.h"

bool operator ==(const ModelGeometry &m1, const ModelGeometry &m2)
{
    return m1.m_vertices == m2.m_vertices &&
           m1.m_texCoords == m2.m_texCoords &&
           m1.m_normals == m2.m_normals &&
           m1.m_polygonsVerticesIndices == m2.m_polygonsVerticesIndices &&
           m1.m_polygonsTexCoordsIndices == m2.m_polygonsTexCoordsIndices &&
           m1.m_polygonsNormalsIndices == m2.m_polygonsNormalsIndices;
}
