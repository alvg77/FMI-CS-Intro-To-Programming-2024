#include <iostream>
#include <cmath>
#include "./draw/sdlwrapper.h"

void drawArc(int x, int y, int radius, float startAngle, float endAngle, int segments) {
    float angleStep = (endAngle - startAngle) / segments;
    float theta = startAngle;

    for (int i = 0; i < segments; ++i) {
        float x1 = x + radius * cos(theta);
        float y1 = y + radius * sin(theta);
        theta += angleStep;
        float x2 = x + radius * cos(theta);
        float y2 = y + radius * sin(theta);

        sdlw::drawLine(x1, y1, x2, y2);
    }
}

void drawCircleOutline(int x, int y, int radius, int offset, uint8_t r, uint8_t g, uint8_t b) {
    sdlw::drawFillCircle(x, y, radius);
    sdlw::setColor(r, g, b);
    sdlw::drawFillCircle(x, y, radius - offset);
    sdlw::setColor(255, 255, 255);
}

void drawNoseAndMouth(int x, int y) {
    sdlw::drawLine(x, y, x, y + 20);
    sdlw::drawLine(x, y + 20, x - 5, y + 25);
    sdlw::drawLine(x, y + 20, x + 5, y + 25);
    sdlw::drawLine(x - 5, y + 25, x - 15, y + 20);
    sdlw::drawLine(x + 5, y + 25, x + 15, y + 20);
}

void drawWhiskers(int x, int y) {
    sdlw::drawLine(x - 10, y + 5, x - 130, y - 15);
    sdlw::drawLine(x + 10, y + 5, x + 130, y - 15);

    sdlw::drawLine(x - 10, y + 10, x - 130, y + 5);
    sdlw::drawLine(x + 10, y + 10, x + 130, y + 5);

    sdlw::drawLine(x - 10, y + 15, x - 130, y + 20);
    sdlw::drawLine(x + 10, y + 15, x + 130, y + 20);
}

void drawPaw(int x, int y, int len, uint8_t r, uint8_t g, uint8_t b) {
    sdlw::drawLine(x - 20, y, x - 20, y + len);
    sdlw::drawLine(x + 20, y, x + 20, y + len);
    int tSize = 7;
    for (int i = x - 20; i < x + 20; i += 2 * tSize) {
        drawCircleOutline(i + tSize, y + len, tSize, 2, r, g, b);
    }
}

void drawEars(int x, int y, int headRadius, int offset) {
    sdlw::drawLine(x - headRadius, y, x - headRadius - offset, y - headRadius - offset);
    sdlw::drawLine(x - headRadius - offset, y - headRadius - offset, x, y - headRadius);
    sdlw::drawLine(x + headRadius, y, x + headRadius + offset, y - headRadius - offset);
    sdlw::drawLine(x + headRadius + offset, y - headRadius - offset, x, y - headRadius);
}

void drawBody(int headCenterX, int headCenterY, int bodyLength, int bodyWidth) {
    sdlw::drawLine(headCenterX + bodyWidth, headCenterY + bodyLength, headCenterX, headCenterY);
    sdlw::drawLine(headCenterX - bodyWidth, headCenterY + bodyLength, headCenterX, headCenterY);
    drawArc(headCenterX + bodyWidth / 2, headCenterY + bodyLength, bodyWidth / 2, M_PI / 2, 0, 50);
    drawArc(headCenterX - bodyWidth / 2, headCenterY + bodyLength, bodyWidth / 2, -M_PI, -3 * M_PI / 2, 50);
    sdlw::drawLine(headCenterX - bodyWidth / 2, headCenterY + bodyLength + bodyWidth / 2,
                   headCenterX + bodyWidth / 2, headCenterY + bodyLength + bodyWidth / 2);
}

int main() {
    sdlw::setColor(255, 255, 255);
    uint8_t r = 0, g = 0, b = 0;  // Black color

    int headCenterX = 250;
    int headCenterY = 150;
    int bodyLength = 200;
    int bodyWidth = 100;
    int headRadius = 90;
    int eyeRadius = 20;
    int pawLength = 50;

    // Body
    drawBody(headCenterX, headCenterY, bodyLength, bodyWidth);

    // Head
    drawCircleOutline(headCenterX, headCenterY, headRadius, 2, r, g, b);
    drawEars(headCenterX, headCenterY, headRadius, 20);

    // Left eye
    sdlw::setColor(0, 255, 0);  // Green color
    drawCircleOutline(headCenterX - 50, headCenterY, eyeRadius, 10, r, g, b);

    // Right eye
    sdlw::setColor(0, 255, 0);  // Green color
    drawCircleOutline(headCenterX + 50, headCenterY, eyeRadius, 10, r, g, b);

    // Nose and mouth
    drawNoseAndMouth(headCenterX, headCenterY + 30);

    // Whiskers
    drawWhiskers(headCenterX, headCenterY + 30);

    // Paws
    drawPaw(headCenterX - bodyWidth / 2, headCenterY + bodyLength, pawLength, r, g, b);
    drawPaw(headCenterX + bodyWidth / 2, headCenterY + bodyLength, pawLength, r, g, b);

    sdlw::updateGraphics();
    std::cin.get();
}
