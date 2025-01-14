#ifndef BW_MATRIX_H
#define BW_MATRIX_H

#include "matrix.h"
#include "shape/shape.h"
#include <iostream>

class BWMatrix : public Matrix {
public:
    BWMatrix();
    BWMatrix(const BWMatrix& mat);
    BWMatrix(size_t rows, size_t cols);
    BWMatrix(size_t rows, size_t cols, int initVal);
    
    void print() const override;
    void fromOpenCV(const cv::Mat& mat) override;
    cv::Mat toOpenCV() const override;
    bool readImage(const std::string& path) override;
    template<typename T>
    void draw(T& shape){
        // Получаем указатель на объект типа Color
        const Color* colorPtr = shape.getColor();  

        // Вызываем метод getBWColor() у объекта, на который указывает colorPtr
        unsigned char color_ = colorPtr->getBWColor();  // Используем -> для вызова метода через указатель

        auto figure = shape.getArea();
        for(size_t point = 0; point < figure.size(); ++point){
            if ((figure[point].x < m_cols)&&(figure[point].y < m_rows)&&
                (figure[point].x >= 0)&&(figure[point].y >= 0)) //getRows()
                Matrix::at(figure[point].y, figure[point].x) = color_;
        }
    }

    
    BWMatrix invert() const;

    BWMatrix add(int val) const; 
    BWMatrix multiply(int val) const; 
    BWMatrix subtract(int val) const;
    BWMatrix operator+(int val) const; 
    BWMatrix operator-(int val) const; 
    BWMatrix operator*(int val) const;
    BWMatrix& operator=(const BWMatrix& mat);

    friend std::ostream& operator<<(std::ostream& out, const BWMatrix& mat);
};

#endif // BW_MATRIX_H
