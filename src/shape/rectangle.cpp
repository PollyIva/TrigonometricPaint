#include "rectangle.h"
#include <iostream> 
// #include <iomanip>
#include <vector>
#include <algorithm>

Rectangle::Rectangle(Point lt, int w, int h, std::unique_ptr<Color> color)
    : lt(lt), w(w), h(h)
    {
        this->color = std::move(color);
    }


// Конструктор для инициализации BWColor
Rectangle::Rectangle(Point lt, int w, int h, const BWColor& color)
    : lt(lt), w(w), h(h)
    {
        this->color = std::make_unique<BWColor>(color);
    }

// Конструктор для инициализации RGBColor
Rectangle::Rectangle(Point lt, int w, int h, const RGBColor& color)
    : lt(lt), w(w), h(h)
    {
        this->color = std::make_unique<RGBColor>(color);
    }

std::vector<Point> Rectangle::getArea() const{
    std::vector<Point> figure;
    int x_max = lt.x + w;
    int x_min = lt.x;
    // int y_max = lt.y;
    // int y_min = lt.y - h;
    int y_max = lt.y + h;
    int y_min = lt.y;

    for (int x_tmp = x_min; x_tmp < x_max; ++x_tmp) {
        for (int y_tmp = y_min; y_tmp < y_max; ++y_tmp) {
            figure.push_back(Point{x_tmp, y_tmp});
        }
    }
    return figure;
}
