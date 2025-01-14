#ifndef RGB_MATRIX_H
#define RGB_MATRIX_H

#include "matrix.h"
#include "bw_matrix.h"
#include "shape/shape.h"

#include <iostream>

class RGBMatrix : public Matrix {
public:
    RGBMatrix();
    RGBMatrix(const RGBMatrix& mat);
    RGBMatrix(size_t rows, size_t cols);
    RGBMatrix(size_t rows, size_t cols, int initVal);
    void print() const override;
    void fromOpenCV(const cv::Mat& mat) override;
    cv::Mat toOpenCV() const override;
    bool readImage(const std::string& path) override;
    template<typename T>
    void draw(T& shape){
        // Получаем указатель на объект типа Color
        const Color* colorPtr = shape.getColor();  

        // Используем метод getRGBColor() для получения цветов RGB
        std::array<unsigned char, 3> color_ = colorPtr->getRGBColor();  // Получаем массив RGB-цветов

        // Получаем область (точки фигуры)
        auto figure = shape.getArea();
        for(size_t point = 0; point < figure.size(); ++point){
            if ((figure[point].x < m_cols)&&(figure[point].y < m_rows)&&
                (figure[point].x >= 0)&&(figure[point].y >= 0)){
                at(figure[point].y, figure[point].x, 0) = color_[0];
                at(figure[point].y, figure[point].x, 1) = color_[1];
                at(figure[point].y, figure[point].x, 2) = color_[2];
            }
        }
    }

    BWMatrix toBW() const;
    RGBMatrix add(int val) const; 
    RGBMatrix multiply(int val) const; 
    RGBMatrix subtract(int val) const;
    RGBMatrix operator+(int val) const; 
    RGBMatrix operator-(int val) const; 
    RGBMatrix operator*(int val) const;
    RGBMatrix& operator=(const RGBMatrix& mat);
    friend std::ostream& operator<<(std::ostream& out, const RGBMatrix& mat);
};

#endif // RGB_MATRIX_H
