#ifndef GAME_H
#define GAME_H

#include <string>
#include <SFML/Graphics.hpp>
#include <functional>
#include <vector>

#pragma once

struct IterationData {
    double x;
    double y;
    double tangentX1;
    double tangentY1;
    double tangentX2;
    double tangentY2;
};

class Game
{
public:
    Game();
    ~Game();

    void run();
private:
    sf::RenderWindow* window;
    sf::VideoMode videomode;
    sf::Event event;
    sf::VertexArray graph;
    sf::Font font;

    std::unordered_map<double, double> memo; //hashmap til memoization
    std::vector<IterationData> iterations; //alle iterationernes xn
    std::vector<sf::VertexArray> tangents; //alle tangenterne til xn
    std::vector<sf::CircleShape> points; //alle iterationernes punkt
    std::function<double(double)> func;
    std::function<double(double)> func_derivative;

    double x0;
    double precision;
    double coordinateSystemMin;
    double coordinateSystemMax;
    double dist_lines_axis;
    int iterationCount;

    IterationData data;

    void setup();

    void initGraph();
    void initText(const std::string& text, double pos_x, double pos_y, int fontSize, const sf::Color& color);

    double root(double x0, double precision, std::function<double(double)> func, std::function<double(double)> func_derivative);

    void drawText();
    void drawAxis();    
    void drawTangents(const std::vector<IterationData>& iterations);

    void update();
    void render();
};
#endif