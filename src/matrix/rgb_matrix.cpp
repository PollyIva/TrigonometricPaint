#include "rgb_matrix.h"
#include "shape.h"
#include "color.h"
#include <iostream> 
#include <iomanip>
#include <algorithm>


RGBMatrix::RGBMatrix()
    : Matrix(0, 0, 3)
{}

RGBMatrix::RGBMatrix(const RGBMatrix& mat)
    :Matrix(mat)
{}

RGBMatrix::RGBMatrix(size_t rows, size_t cols)
    :Matrix(rows, cols, 3)
{}

RGBMatrix::RGBMatrix(size_t rows, size_t cols, int initVal)
    :Matrix(rows, cols, 3, initVal)
{}

void RGBMatrix::print() const
{
    std::cout << *this << std::endl;
}

void RGBMatrix::fromOpenCV(const cv::Mat& mat)
{
    if (mat.channels() != 3 || mat.depth() != CV_8U)
        return;
    
    m_rows = mat.rows;
    m_cols = mat.cols;
    m_data.resize(mat.total() * 3);

    for (size_t r = 0; r < m_rows; ++r) {
        for (size_t c = 0; c < m_cols; ++c) {
            auto val = mat.at<cv::Vec3b>(static_cast<int>(r), static_cast<int>(c));
            at(r, c, 0) = val[2];
            at(r, c, 1) = val[1];
            at(r, c, 2) = val[0];
        }
    }
}

cv::Mat RGBMatrix::toOpenCV() const
{
    cv::Mat mat(static_cast<int>(m_rows), static_cast<int>(m_cols), CV_8UC3);

    for (size_t r = 0; r < m_rows; ++r) {
        for (size_t c = 0; c < m_cols; ++c) {
                        
            cv::Vec3b val;
            val[0] = at(r, c, 2);
            val[1] = at(r, c, 1);
            val[2] = at(r, c, 0);
            mat.at<cv::Vec3b>(static_cast<int>(r), static_cast<int>(c)) = val;
        }
    }
    return mat;
}

bool RGBMatrix::readImage(const std::string& path)
{
    cv::Mat rgbImage = cv::imread(path, cv::IMREAD_COLOR);
    if (rgbImage.empty())
        return false;
    fromOpenCV(rgbImage);
    return true;
}

BWMatrix RGBMatrix::toBW() const{
    BWMatrix res(m_rows, m_cols);
    // Проходим по каждому пикселю
    for (size_t r = 0; r < m_rows; ++r) {
        for (size_t c = 0; c < m_cols; ++c) {
            int gray = 0;
            // Для каждого канала (RGB)
            for (size_t ch = 0; ch < m_channels; ++ch) {
                gray += at(r, c, ch);  // Суммируем все каналы
            }
            // Усредняем значения по всем каналам
            res.at(r, c) = gray / int(m_channels);
        }
    }
    return res;
}


RGBMatrix RGBMatrix::add(int val) const 
{
    RGBMatrix res(m_rows, m_cols); 
    Matrix::add(res, val);
    return res;
}

RGBMatrix RGBMatrix::multiply(int val) const
{
    RGBMatrix res(m_rows, m_cols); 
    Matrix::multiply(res, val);
    return res;
}

RGBMatrix RGBMatrix::subtract (int val) const
{
    RGBMatrix res(m_rows, m_cols); 
    Matrix::subtract(res, val);
    return res;
}

RGBMatrix RGBMatrix::operator+(int val) const
{
    return add(val);
}

RGBMatrix RGBMatrix::operator-(int val) const
{
    return subtract(val);
}

RGBMatrix RGBMatrix::operator*(int val) const
{
    return multiply(val);
}


RGBMatrix& RGBMatrix::operator=(const RGBMatrix& mat)
{
    Matrix::operator=(mat);
    return *this;
}

std::ostream& operator<<(std::ostream& out, const RGBMatrix& mat)
{
    static const std::vector<std::string> names = {"r", "g", "b"};
    for (size_t r = 0; r < mat.m_rows; ++r){
        for (size_t c = 0; c < mat.m_cols; ++c) {
            out << (c > 0 ? " " : "" ) << std::setw(2);
            out << '[';
            for (size_t ch = 0; ch < mat.m_channels; ++ch){
                out << (ch > 0 ? " " : "" ) << std::setw(3);
                out << names[ch] << ": " << mat.at(r, c, ch);
            }
            out << ']';
        }
        out << std::endl;  
    }
    return out;
}

