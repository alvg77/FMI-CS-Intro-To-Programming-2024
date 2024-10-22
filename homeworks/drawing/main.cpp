#include <iostream>
#include <cmath>
#include "./draw/sdlwrapper.h"

struct Color {
    uint8_t r;
    uint8_t g;
    uint8_t b;

    Color(int r, int g, int b) {
        this->r = r;
        this->g = g;
        this->b = b;
    }
};

void drawCircleOutline(int x, int y, int radius, int offset, Color innerColor) {
    sdlw::drawFillCircle(x, y, radius);
    sdlw::setColor(innerColor.r, innerColor.g, innerColor.b);
    sdlw::drawFillCircle(x, y, radius-offset);
    sdlw::setColor(255, 255, 255);
}

void drawNoseAndMouth(int x, int y) {
    sdlw::drawLine(x, y, x, y+20);
    sdlw::drawLine(x, y+20, x-5, y+25);
    sdlw::drawLine(x, y+20, x+5, y+25);
    sdlw::drawLine(x-5, y+25, x-15, y+20);
    sdlw::drawLine(x+5, y+25, x+15, y+20);
}

void drawWhiskers(int noseX, int noseY) {
    sdlw::drawLine(noseX-10, noseY+5, noseX-130, noseY-15);
    sdlw::drawLine(noseX+10, noseY+5, noseX+130, noseY-15);

    sdlw::drawLine(noseX-10, noseY+10, noseX-130, noseY+5);
    sdlw::drawLine(noseX+10, noseY+10, noseX+130, noseY+5);

    sdlw::drawLine(noseX-10, noseY+15, noseX-130, noseY+20);
    sdlw::drawLine(noseX+10, noseY+15, noseX+130, noseY+20);
}

// void drawPaw(int x, int y) {
//     sdlw::drawLine(x-20, y, x+20, y+50);
//     Color black = Color(0, 0, 0);
//     drawCircleOutline()
// }

int main()
{
    sdlw::setColor(255,255,255);
    Color black = Color(0, 0, 0);

    // head
    drawCircleOutline(250, 100, 90, 2, black);

    // left eye
    sdlw::setColor(0, 255, 0);
    drawCircleOutline(200, 90, 20, 10, black);
    
    // right eye
    sdlw::setColor(0, 255, 0);
    drawCircleOutline(300, 90, 20, 10, black);

    // nose and mouth
    drawNoseAndMouth(250, 120);

    // whiskers
    drawWhiskers(250, 120);

    sdlw::updateGraphics();
    std::cin.get();
}