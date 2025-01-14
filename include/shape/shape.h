#ifndef SHAPE_H
#define SHAPE_H
#include <vector>
#include <iostream>

// #include "bw_matrix.h"
// #include "rgb_matrix.h"
#include "point.h"
#include "color.h"
#include "bw_color.h"
#include "rgb_color.h"
#include <memory>

// Объявление класса Shape
class Shape {
public:
    virtual std::vector<Point> getArea() const = 0;
    const Color* getColor() const {
        return color.get();
    }
protected:
    std::unique_ptr<Color> color;
};

#endif // SHAPE_H
