#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"
#include "color.h"
#include "bw_color.h"
#include "rgb_color.h"
#include "point.h"
#include <iostream>


class Triangle : public Shape
{
public:
    Triangle(Point A, Point B, Point C, std::unique_ptr<Color> color);
    Triangle(Point A, Point B, Point C, const BWColor& color);
    Triangle(Point A, Point B, Point C, const RGBColor& color);


    using Shape::getColor; 
    std::vector<Point> getArea() const override;

private:
    Point A;
    Point B;
    Point C;
};

#endif // TRIANGLE_H