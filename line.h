#ifndef LINE_H
#define LINE_H

#include <SFML/Graphics.hpp>

#pragma once

class line
{
public:
    line(float x1, float y1, float x2, float y2, sf::Color color);
    void draw_line(sf::RenderWindow& window);

private:
    sf::Vertex vertex_line[2];
};

#endif