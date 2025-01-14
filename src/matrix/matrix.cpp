#include "matrix.h"
#include "bw_color.h"
#include "rgb_color.h"
#include <iostream> 
#include <iomanip>
#include <algorithm>


Matrix::Matrix() : m_rows(0), m_cols(0), m_channels(1){}

Matrix::Matrix(const Matrix& mat) 
    : m_rows(mat.m_rows) 
    , m_cols(mat.m_cols)
    , m_channels(mat.m_channels)
    , m_data(mat.m_data)
{}

Matrix::Matrix (size_t rows, size_t cols, size_t channels)
    : m_rows(rows)
    , m_cols(cols)
    , m_channels(std::max(channels, (size_t)1))
    , m_data(rows * cols * channels)
{}

Matrix::Matrix(size_t rows, size_t cols,size_t channels, int initValue)
    : m_rows(rows)
    , m_cols(cols)
    , m_channels(std::max(channels, (size_t)1))
    , m_data(rows * cols * channels, initValue)
{}


void Matrix::display() const
{
    cv::imshow("Display image", toOpenCV());
    cv::waitKey(0);
}


Matrix& Matrix::operator=(const Matrix& mat){
    if (this != &mat){
        m_rows = mat.m_rows;
        m_cols = mat.m_cols;
        m_channels = mat.m_channels;
        m_data.assign(mat.m_data.begin(), mat.m_data.end());
    }
    return *this;
}


void Matrix::add(Matrix& res, int val) const{
    for (size_t i = 0; i < m_data.size(); ++i){
        res.m_data[i] = m_data[i] + val;
    }
}

void Matrix::multiply(Matrix& res, int val) const{
    for (size_t i = 0; i < m_data.size(); ++i){
        res.m_data[i] = m_data[i] * val;
    }
}

void Matrix::subtract(Matrix& res, int val) const{
    for (size_t i = 0; i < m_data.size(); ++i){
        res.m_data[i] = m_data[i] - val;
    }
}
