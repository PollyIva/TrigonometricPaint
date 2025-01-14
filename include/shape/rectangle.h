#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
#include "color.h"
#include "bw_color.h"
#include "rgb_color.h"
#include "point.h"

#include <iostream>


class Rectangle : public Shape
{
public:

    Rectangle(Point lt, int w, int h, std::unique_ptr<Color> color);
    Rectangle(Point lt, int w, int h, const BWColor& color);
    Rectangle(Point lt, int w, int h, const RGBColor& color);

    using Shape::getColor; 
    std::vector<Point> getArea() const override;

private:
    Point lt; // Верхний левый угол
    int w, h; // Ширина и высота
};

#endif // RECTANGLE_H