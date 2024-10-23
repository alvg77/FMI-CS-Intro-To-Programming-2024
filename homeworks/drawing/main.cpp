#include <iostream>
#include <cmath>
#include "./draw/sdlwrapper.h"

struct Color
{
    uint8_t r;
    uint8_t g;
    uint8_t b;

    Color(int r, int g, int b)
    {
        this->r = r;
        this->g = g;
        this->b = b;
    }
};

void drawArc(int x, int y, int radius, float startAngle, float endAngle, int segments)
{
    float angleStep = (endAngle - startAngle) / segments;
    float theta = startAngle;

    for (int i = 0; i < segments; ++i)
    {
        float x1 = x + radius * cos(theta);
        float y1 = y + radius * sin(theta);
        theta += angleStep;
        float x2 = x + radius * cos(theta);
        float y2 = y + radius * sin(theta);

        sdlw::drawLine(x1, y1, x2, y2);
    }
}

void drawCircleOutline(int x, int y, int radius, int offset, Color innerColor)
{
    sdlw::drawFillCircle(x, y, radius);
    sdlw::setColor(innerColor.r, innerColor.g, innerColor.b);
    sdlw::drawFillCircle(x, y, radius - offset);
    sdlw::setColor(255, 255, 255);
}

void drawNoseAndMouth(int x, int y)
{
    sdlw::drawLine(x, y, x, y + 20);
    sdlw::drawLine(x, y + 20, x - 5, y + 25);
    sdlw::drawLine(x, y + 20, x + 5, y + 25);
    sdlw::drawLine(x - 5, y + 25, x - 15, y + 20);
    sdlw::drawLine(x + 5, y + 25, x + 15, y + 20);
}

void drawWhiskers(int x, int y)
{
    sdlw::drawLine(x - 10, y + 5, x - 130, y - 15);
    sdlw::drawLine(x + 10, y + 5, x + 130, y - 15);

    sdlw::drawLine(x - 10, y + 10, x - 130, y + 5);
    sdlw::drawLine(x + 10, y + 10, x + 130, y + 5);

    sdlw::drawLine(x - 10, y + 15, x - 130, y + 20);
    sdlw::drawLine(x + 10, y + 15, x + 130, y + 20);
}

void drawPaw(int x, int y, int len)
{
    sdlw::drawLine(x - 20, y, x - 20, y + len);
    sdlw::drawLine(x + 20, y, x + 20, y + len);
    Color black = Color(0, 0, 0);
    int tSize = 7;
    for (int i = x - 20; i < x + 20; i += 2 * tSize)
    {
        std::cout << i << " " << tSize << " " << x << std::endl;
        drawCircleOutline(i + tSize, y + len, tSize, 2, black);
    }
}

void drawEars(int x, int y, int headRadius, int offset)
{
    sdlw::drawLine(x - headRadius, y, x - headRadius - offset, y - headRadius - offset);
    sdlw::drawLine(x - headRadius - offset, y - headRadius - offset, x, y - headRadius);
    sdlw::drawLine(x + headRadius, y, x + headRadius + offset, y - headRadius - offset);
    sdlw::drawLine(x + headRadius + offset, y - headRadius - offset, x, y - headRadius);
}

void drawBody(int headCenterX, int headCenterY, int bodyLength, int bodyWidth)
{
    sdlw::drawLine(headCenterX + bodyWidth, headCenterY + bodyLength, headCenterX, headCenterY);
    sdlw::drawLine(headCenterX - bodyWidth, headCenterY + bodyLength, headCenterX, headCenterY);
    drawArc(headCenterX + bodyWidth / 2, headCenterY + bodyLength, bodyWidth / 2, M_PI / 2, 0, 50);
    drawArc(headCenterX - bodyWidth / 2, headCenterY + bodyLength, bodyWidth / 2, -M_PI, -3 * M_PI / 2, 50);
    sdlw::drawLine(headCenterX - bodyWidth / 2, headCenterY + bodyLength + bodyWidth / 2, headCenterX + bodyWidth / 2, headCenterY + bodyLength + bodyWidth / 2);
}

int main()
{
    sdlw::setColor(255, 255, 255);
    Color black = Color(0, 0, 0);

    int headCenterX = 250;
    int headCenterY = 150;
    int bodyLength = 200;
    int bodyWidth = 100;
    int headRadius = 90;
    int eyeRadius = 20;
    int pawLength = 70;

    // body
    drawBody(headCenterX, headCenterY, bodyLength, bodyWidth);

    // head
    drawCircleOutline(headCenterX, headCenterY, headRadius, 2, black);
    drawEars(headCenterX, headCenterY, headRadius, 20);

    // left eye
    sdlw::setColor(0, 255, 0);
    drawCircleOutline(headCenterX - 50, headCenterY, eyeRadius, 10, black);

    // right eye
    sdlw::setColor(0, 255, 0);
    drawCircleOutline(headCenterX + 50, headCenterY, eyeRadius, 10, black);

    // nose and mouth
    drawNoseAndMouth(headCenterX, headCenterY + 30);

    // whiskers
    drawWhiskers(headCenterX, headCenterY + 30);

    // paws
    drawPaw(headCenterX - bodyWidth / 2, headCenterY + 220, 70);
    drawPaw(headCenterX + bodyWidth / 2, headCenterY + 220, 70);

    sdlw::updateGraphics();
    std::cin.get();
}