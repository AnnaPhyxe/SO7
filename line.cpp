#include "line.h"

line::line(float x1, float y1, float x2, float y2, sf::Color color){
    vertex_line[0] = sf::Vertex(sf::Vector2f(x1, y1), color);
    vertex_line[1] = sf::Vertex(sf::Vector2f(x2, y2), color);
}

void line::draw_line(sf::RenderWindow &window){
    window.draw(vertex_line, 2, sf::Lines);
}