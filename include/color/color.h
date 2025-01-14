#ifndef COLOR_H
#define COLOR_H

#include <array>
#include <memory>
class Color {
public:
    virtual ~Color() = default; // Виртуальный деструктор с реализацией по умолчанию

    virtual std::unique_ptr<Color> clone() const = 0; 
    // виртуальный метод для получения цвета RGB
    virtual std::array<unsigned char, 3> getRGBColor() const = 0;

    // виртуальный метод для получения черно-белого цвета
    virtual unsigned char getBWColor() const = 0;
};

#endif // COLOR_H