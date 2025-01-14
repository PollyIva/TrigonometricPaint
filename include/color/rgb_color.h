#ifndef RGBCOLOR_H
#define RGBCOLOR_H

#include <array>
#include "color.h"

class RGBColor : public Color {
public:
    explicit RGBColor(unsigned char r, unsigned char g, unsigned char b) : m_r(r), m_g(g), m_b(b) {}

    void changeColor(unsigned char r, unsigned char g, unsigned char b) {
        m_r = r;
        m_g = g;
        m_b = b;
    }
    std::unique_ptr<Color> clone() const override{
        return std::make_unique<RGBColor>(*this);
    }

    std::array<unsigned char, 3> getRGBColor() const override { 
        return {m_r, m_g, m_b}; 
    }

    unsigned char getBWColor() const override { 
        return static_cast<unsigned char>((m_r + m_g + m_b) / 3); 
    }

private:
    unsigned char m_r;
    unsigned char m_g;
    unsigned char m_b;
};

#endif // RGBCOLOR_H
