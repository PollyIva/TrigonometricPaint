#include "circle.h"
#include <iostream> 
#include <vector>
#include <algorithm>

Circle::Circle(Point center, int radius, std::unique_ptr<Color> color)
    : center(center), radius(radius) 
    {
        this->color = std::move(color);
    }

Circle::Circle(Point center, int radius, const BWColor& color)
    : center(center), radius(radius)
    {
        this->color = std::make_unique<BWColor>(color);
    } 
Circle::Circle(Point center, int radius, const RGBColor& color)
    : center(center), radius(radius)
    {
        this->color = std::make_unique<RGBColor>(color);
    } 

std::vector<Point> Circle::getArea() const {
    std::vector<Point> figure;
    int x_max = center.x + radius;
    int x_min = center.x - radius;
    int y_max = center.y + radius;
    int y_min = center.y - radius;

    for (int x_tmp = x_min; x_tmp < x_max; ++x_tmp) {
        for (int y_tmp = y_min; y_tmp < y_max; ++y_tmp) {
            if ((x_tmp - center.x) * (x_tmp - center.x) + (y_tmp - center.y) * (y_tmp - center.y) <= radius * radius)
            {
                figure.push_back(Point{x_tmp, y_tmp});
            }
        }
    }
    return figure;
}
