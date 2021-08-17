#ifndef ARRAY2D_H
#define ARRAY2D_H

#include <utility>

namespace Array2D {

template<typename T>
class Array2D
{
public:
    Array2D(int nRows, int nColumns)
        : m_nRows(nRows),
          m_nColumns(nColumns)
    {
        m_array2d = new T *[nRows];
        m_array2d[0] = new T [nRows * nColumns];
        for(int i = 1; i < nRows; ++i)
            m_array2d[i] = m_array2d[i - 1] + nColumns;
    }

    Array2D(int nRows, int nColumns, const T &value)
        : m_nRows(nRows),
          m_nColumns(nColumns)
    {
        m_array2d = new T *[nRows];
        m_array2d[0] = new T [nRows * nColumns];
        for(int i = 1; i < nRows; ++i)
            m_array2d[i] = m_array2d[i - 1] + nColumns;

        fill(value);
    }

    Array2D(const Array2D &other)
    {
        *this = Array2D(other.nRows(), other.nColumns());

        for(int i = 0; i < m_nRows; ++i)
            for(int j = 0; j < m_nColumns; ++j)
                m_array2d[i][j] = other.m_array2d[i][j];
    }

    Array2D(Array2D &&other)
    {
        m_array2d = other.m_array2d;
        other.m_array2d = nullptr;
    }

    Array2D &operator=(const Array2D &other)
    {
        Array2D tmp(other);
        swap (*this, tmp);
        return *this;
    }

    Array2D &operator=(Array2D &&other)
    {
        swap (*this, other);
        return *this;
    }

    ~Array2D()
    {
        delete[] m_array2d[0];
        delete[] m_array2d;
    }

    void fill(const T &value)
    {
        for(int i = 0; i < m_nRows; ++i)
            for(int j = 0; j < m_nColumns; ++j)
                m_array2d[i][j] = value;
    }

    int nRows() const
    {
        return m_nRows;
    }

    int nColumns() const
    {
        return m_nColumns;
    }

    T& operator()(int row, int column) const
    {
        return m_array2d[row][column];
    }

    void swap(Array2D &l, Array2D &r)
    {
        std::swap(l.m_array2d, r.m_array2d);
        std::swap(l.m_nRows, r.m_nRows);
        std::swap(l.m_nColumns, r.m_nColumns);
    }
private:
    int m_nRows = 0;
    int m_nColumns = 0;
    T **m_array2d = nullptr;
};

}

#endif
