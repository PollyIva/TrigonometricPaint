#ifndef BWCOLOR_H
#define BWCOLOR_H

#include <array>
#include "color.h"

class BWColor : public Color {
public:
    explicit BWColor(unsigned char color) : m_color(color) {}

    void changeColor(unsigned char color) { 
        m_color = color; 
    }
    std::unique_ptr<Color> clone() const override{
        return std::make_unique<BWColor>(*this);
    }

    std::array<unsigned char, 3> getRGBColor() const override { 
        return {m_color, m_color, m_color}; 
    }

    unsigned char getBWColor() const override { 
        return m_color; 
    }

private:
    unsigned char m_color;
};


#endif // BWCOLOR_H