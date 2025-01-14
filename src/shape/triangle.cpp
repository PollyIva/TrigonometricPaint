#include "triangle.h"
#include <iostream> 
#include <vector>
#include <algorithm>
#include <cmath>


// Основной конструктор, принимающий unique_ptr<Color>
Triangle::Triangle(Point A, Point B, Point C, std::unique_ptr<Color> color)
    : A(A), B(B), C(C)
    {
        this->color = std::move(color);
    }


// Конструктор для инициализации BWColor
Triangle::Triangle(Point A, Point B, Point C, const BWColor& color)
    : A(A), B(B), C(C)
    {
        this->color = std::make_unique<BWColor>(color);
    }

// Конструктор для инициализации RGBColor
Triangle::Triangle(Point A, Point B, Point C, const RGBColor& color)
    : A(A), B(B), C(C)
    {
        this->color = std::make_unique<RGBColor>(color);
    }

template <typename T>
T max_of_three(const T& a, const T& b, const T& c) {
    return (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
}

template <typename T>
T min_of_three(const T& a, const T& b, const T& c) {
    return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}


bool isPointInTriangle(int x_tmp, int y_tmp,
                       Point A, Point B, Point C) {
    // Площадь треугольника ABC
    double areaABC = 0.5 * std::abs(A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y));

    // Площади треугольников с точкой внутри
    double areaPAB = 0.5 * std::abs(x_tmp * (A.y - B.y) + A.x * (B.y - y_tmp) + B.x * (y_tmp - A.y));
    double areaPBC = 0.5 * std::abs(x_tmp * (B.y - C.y) + B.x * (C.y - y_tmp) + C.x * (y_tmp - B.y));
    double areaPCA = 0.5 * std::abs(x_tmp * (C.y - A.y) + C.x * (A.y - y_tmp) + A.x * (y_tmp - C.y));

    // Проверка
    return (areaABC == areaPAB + areaPBC + areaPCA);
}


std::vector<Point> Triangle::getArea() const{
    std::vector<Point> figure;
    int x_max = max_of_three(A.x, B.x, C.x);
    int x_min = min_of_three(A.x, B.x, C.x);
    int y_max = max_of_three(A.y, B.y, C.y);
    int y_min = min_of_three(A.y, B.y, C.y);

    for (int x_tmp = x_min; x_tmp < x_max; ++x_tmp) {
        for (int y_tmp = y_min; y_tmp < y_max; ++y_tmp) {
            if (isPointInTriangle(x_tmp, y_tmp, A, B, C)){
                figure.push_back(Point{x_tmp, y_tmp});
            }
        }
    }
    return figure;   
}