#include "matrix/matrix.h"
#include "matrix/rgb_matrix.h"
#include "matrix/bw_matrix.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "color/color.h"
#include "shape/triangle.h"
#include "shape/rectangle.h"
#include "shape/circle.h"
#include <chrono>

double measureExecutionTime(std::function<void()> lambda);

void mushroom_small();
void house_small();
void mushroom();
void house();
void fish();


int main()
{
    std::cout << "Mushroom small time: " << measureExecutionTime(mushroom_small) << "ms" << std::endl;
    std::cout << "House small time: " << measureExecutionTime(house_small) << "ms" << std::endl;
    std::cout << "Mushroom time: " << measureExecutionTime(mushroom) << "ms" << std::endl;
    std::cout << "House time: " << measureExecutionTime(house) << "ms" << std::endl;
    std::cout << "Fish time: " << measureExecutionTime(fish) << "ms" << std::endl;

    return 0;
}

void mushroom_small()
{
    int bgColor = 255;
    int capColor = 179;
    int stipeColor = 128;
    int bottomColor = 52;
    BWMatrix bw(1000, 1000, 255);
    BWColor bwColor(capColor);
    Circle cap({500, 500}, 350, bwColor);
    bwColor.changeColor(bgColor);
    Rectangle background({0, 350}, 1000, 500, bwColor);
    Rectangle background2({400, 650}, 200, 100, bwColor);

    bwColor.changeColor(stipeColor);
    Triangle stipe({500, 175}, {600, 750}, {400, 750}, bwColor);
    bwColor.changeColor(capColor);
    Rectangle background3({400, 175}, 200, 175, bwColor);
    bwColor.changeColor(bottomColor);
    Circle bottom({500, 750}, 100, bwColor);

    bw.draw(cap);
    bw.draw(background);
    bw.draw(bottom);
    bw.draw(background2);
    bw.draw(stipe);
    bw.draw(background3);
    bw.display();
}

void house_small()
{
    RGBMatrix rgb(1000, 1000, 0);
    RGBColor rgbColor(102, 205, 255);
    Rectangle sky({0, 0}, 1000, 750, rgbColor);
    rgbColor.changeColor(0, 153, 0);
    Rectangle grass({0, 750}, 1000, 1000, rgbColor);
    rgbColor.changeColor(255, 255, 0);
    Circle sun({25, 25}, 150, rgbColor);
    Triangle ray1({180, 25}, {275, 15}, {275, 35}, rgbColor);
    Triangle ray2({135, 135}, {210, 180}, {195, 200}, rgbColor);
    Triangle ray3({25, 180}, {15, 275}, {35, 275}, rgbColor);
    rgbColor.changeColor(102, 51, 0);
    Rectangle wall({300, 450}, 500, 400, rgbColor);
    rgbColor.changeColor(0, 0, 0);
    Rectangle flue({650, 275}, 50, 100, rgbColor);
    rgbColor.changeColor(51, 0, 0);
    Triangle roof({280, 450}, {550, 250}, {820, 450}, rgbColor);
    rgbColor.changeColor(204, 102, 0);
    Rectangle door({700, 675}, 75, 150, rgbColor);
    rgbColor.changeColor(0, 0, 0);
    Circle knob({767, 750}, 3, rgbColor);
    rgbColor.changeColor(102, 163, 255);
    Rectangle window1({350, 475}, 150, 175, rgbColor);
    Rectangle window2({600, 475}, 150, 175, rgbColor);

    rgb.draw(sky);
    rgb.draw(grass);
    rgb.draw(sun);
    rgb.draw(ray1);
    rgb.draw(ray2);
    rgb.draw(ray3);
    rgb.draw(wall);
    rgb.draw(flue);
    rgb.draw(roof);
    rgb.draw(door);
    rgb.draw(knob);
    rgb.draw(window1);
    rgb.draw(window2);
    rgb.display();
}

void fish(){
    RGBMatrix rgb(1000, 1000, 0);
    RGBColor rgbColor(85, 170, 255);
    Rectangle water({0, 0}, 1000, 1000, rgbColor);
    rgb.draw(water);

    rgbColor.changeColor(128, 0, 128);
    Triangle fish({400, 300}, {700, 500}, {350, 600}, rgbColor);
    
    rgbColor.changeColor(66, 49, 137);
    Circle tail({250, 450}, 150, rgbColor);
    rgb.draw(tail);
    rgb.draw(fish);

    rgbColor.changeColor(135, 77, 191);
    Circle fin({500, 575}, 50, rgbColor);
    rgb.draw(fin);

    rgbColor.changeColor(85, 170, 255);
    Circle tail_cutting({130, 450}, 120, rgbColor);
    rgb.draw(tail_cutting);

    Circle fin_cutting({530, 600}, 50, rgbColor);
    rgb.draw(fin_cutting);

    rgbColor.changeColor(255, 255, 255);
    Circle eye_w({590, 450}, 15, rgbColor);

    rgbColor.changeColor(0, 0, 0);
    Circle eye_b({590, 445}, 8, rgbColor);

    rgb.draw(eye_w);
    rgb.draw(eye_b);

    rgb.display();
}


void mushroom()
{
    int bgColor = 255;
    int capColor = 179;
    int stipeColor = 128;
    int bottomColor = 52;
    BWMatrix bw(2000, 2000, 255);
    BWColor bwColor(capColor);
    Circle cap({1000, 1000}, 700, bwColor);
    bwColor.changeColor(bgColor);
    Rectangle background({0, 700}, 2000, 1000, bwColor);
    Rectangle background2({800, 1300}, 400, 200, bwColor);
    bwColor.changeColor(stipeColor);
    Triangle stipe({1000, 350}, {1200, 1500}, {800, 1500}, bwColor);
    bwColor.changeColor(capColor);
    Rectangle background3({800, 350}, 400, 350, bwColor);
    bwColor.changeColor(bottomColor);
    Circle bottom({1000, 1500}, 200, bwColor);

    bw.draw(cap);
    bw.draw(background);
    bw.draw(bottom);
    bw.draw(background2);
    bw.draw(stipe);
    bw.draw(background3);
    bw.display();

}

void house()
{
    RGBMatrix rgb(2000, 2000, 0);
    RGBColor rgbColor(102, 205, 255);
    Rectangle sky({0, 0}, 2000, 1500, rgbColor);
    rgbColor.changeColor(0, 153, 0);
    Rectangle grass({0, 1500}, 2000, 2000, rgbColor);
    rgbColor.changeColor(255, 255, 0);
    Circle sun({50, 50}, 300, rgbColor);
    Triangle ray1({360, 50}, {550, 30}, {550, 70}, rgbColor);
    Triangle ray2({270, 270}, {420, 360}, {390, 400}, rgbColor);
    Triangle ray3({50, 360}, {30, 550}, {70, 550}, rgbColor);
    rgbColor.changeColor(102, 51, 0);
    Rectangle wall({600, 900}, 1000, 800, rgbColor);
    rgbColor.changeColor(0, 0, 0);
    Rectangle flue({1300, 550}, 100, 200, rgbColor);
    rgbColor.changeColor(51, 0, 0);
    Triangle roof({560, 900}, {1100, 500}, {1640, 900}, rgbColor);
    rgbColor.changeColor(204, 102, 0);
    Rectangle door({1400, 1350}, 150, 300, rgbColor);
    rgbColor.changeColor(0, 0, 0);
    Circle knob({1535, 1500}, 6, rgbColor);
    rgbColor.changeColor(102, 163, 255);
    Rectangle window1({700, 950}, 300, 350, rgbColor);
    Rectangle window2({1200, 950}, 300, 350, rgbColor);

    rgb.draw(sky);
    rgb.draw(grass);
    rgb.draw(sun);
    rgb.draw(ray1);
    rgb.draw(ray2);
    rgb.draw(ray3);
    rgb.draw(wall);
    rgb.draw(flue);
    rgb.draw(roof);
    rgb.draw(door);
    rgb.draw(knob);
    rgb.draw(window1);
    rgb.draw(window2);
    rgb.display();
}



double measureExecutionTime(std::function<void()> lambda)
{
    using Time = std::chrono::high_resolution_clock;
    using ns = std::chrono::nanoseconds;

    Time::time_point start = Time::now();
    lambda();
    Time::time_point end = Time::now();
    double duration = std::chrono::duration_cast<ns>(end - start).count() * 1e-6;
    return duration;
}