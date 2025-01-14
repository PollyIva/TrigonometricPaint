#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include "color.h"
#include "bw_color.h"
#include "rgb_color.h"
#include "point.h"
#include <iostream>


class Circle : public Shape
{
public:
    Circle(Point center, int radius, const BWColor& color);
    Circle(Point center, int radius, const RGBColor& color);
    Circle(Point center, int radius, std::unique_ptr<Color> color);

    using Shape::getColor; 
    std::vector<Point> getArea() const override;

private:
    Point center;
    int radius;
};

#endif // CIRCLE_H