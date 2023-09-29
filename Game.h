#ifndef GAME_H
#define GAME_H

#include "line.h"
#include <string>
#include <SFML/Graphics.hpp>
#include <functional>
#include <vector>

#pragma once

struct IterationData {
    double x; //x-koordinatet der bruges som udgangspunkt for iterationen
    double y; //y-koordinatet der bruges som udgangspunkt for iterationen
    double tangentX1; //det første punkts x-værdi
    double tangentY1; //det første punkts y-værdi
    double tangentX2; //det andet punkts x-værdi
    double tangentY2; //det andet punkts y-værdi
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
    sf::VertexArray graph; //det er funktionen, man finder nulpunktet på 
    sf::Font font;

    std::unordered_map<double, double> memo; //hashmap til memoization
    std::vector<IterationData> iterations; //alle iterationernes xn
    std::vector<line> tangents; //alle tangenterne til xn
    std::vector<sf::CircleShape> points; //alle tangenternes midtpunkt
    std::function<double(double)> func;
    std::function<double(double)> func_derivative;

    double x0;
    double precision;
    int coordinateSystemMin; //bruges til at skalere koordinatsystemet
    int coordinateSystemMax; //bruges til at skalere koordinatsystemet
    int dist_lines_axis; //afstanden mellem linjerne på x-aksen og y-aksen
    int iterationCount; //antallet af iterationer (bruges til at holde styr på antallet af iterationer)

    IterationData data; //objekt der repræsenterer iterationerne

    void setup();

    void initGraph();
    void initText(const std::string& text, double pos_x, double pos_y, int fontSize, const sf::Color& color);

    double root(double x0, double precision, std::function<double(double)> func, std::function<double(double)> func_derivative); //newtons metode

    void drawText();
    void drawAxis();    
    void drawTangents(const std::vector<IterationData>& iterations);

    void update();
    void render();
};
#endif