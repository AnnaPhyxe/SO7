#include "Game.h"
#include <iostream>
#include <cmath>
#include <unordered_map>

using namespace std;

Game::Game() {
    this->window = nullptr;
}

Game::~Game() {
    if (this->window != nullptr) {
        delete this->window;
    }
}

void Game::run() {
    setup();

    while (this->window->isOpen()) {
        while (this->window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                this->window->close();
        }

        update();
        render();
    }
}

void Game::setup() {
    this->videomode.height = 1080;
    this->videomode.width = 1080;
    this->window = new sf::RenderWindow(this->videomode, "SO7");
    this->window->setFramerateLimit(60);

    this->x0 = 1.5;

    precision = 1e-6;
    func = [](double x) -> double { return log(x + 1);};
    func_derivative = [](double x) -> double { return 1/(x + 1);};

    this->coordinateSystemMin = -10.0;
    this->coordinateSystemMax = 10.0;
    this->dist_lines_axis = 1.0;
    this->iterationCount = 0;

    initGraph();
}

void Game::initGraph(){
    /*
        Tegner grafen der findes et nulpunkt på 
    */
    graph.setPrimitiveType(sf::LineStrip);
    for (double x = coordinateSystemMin; x <= coordinateSystemMax; x += 0.01) {
        double y = func(x);

        float graphX = (x - coordinateSystemMin) / (coordinateSystemMax - coordinateSystemMin) * videomode.width;
        float graphY = videomode.height - (y - coordinateSystemMin) / (coordinateSystemMax - coordinateSystemMin) * videomode.height;

        graph.append(sf::Vertex(sf::Vector2f(graphX, graphY), sf::Color::Red));
    }
}

void Game::initText(const std::string& text, double pos_x, double pos_y, int fontSize, const sf::Color& color){
    if(!font.loadFromFile("Content/Content/font/font.ttf")){
        std::cerr << "Could not load font" << std::endl; 
    }

    sf::Text sfText;
    sfText.setFont(font);
    sfText.setString(text);
    sfText.setCharacterSize(fontSize);
    sfText.setFillColor(color);
    sfText.setPosition(pos_x, pos_y);

    window->draw(sfText);
}


double Game::root(double x0, double precision, std::function<double(double)> func, std::function<double(double)> func_derivative) {
    if (abs(func(x0)) < precision) { return x0; }
    if (memo.find(x0) != memo.end()) { return memo[x0]; }

    data.x = x0;
    data.y = func(x0);

    double tangentSlope = func_derivative(x0);
    double tangentLength = abs(data.y / tangentSlope);
    data.tangentX1 = x0 - tangentLength;
    data.tangentY1 = data.y - tangentSlope * tangentLength;
    data.tangentX2 = x0 + tangentLength;
    data.tangentY2 = data.y + tangentSlope * tangentLength;
    iterations.push_back(data); // Opret en iteration for hver tangent
    iterationCount++; 

    memo[x0] = root(x0 - (func(x0) / func_derivative(x0)), precision, func, func_derivative);
    return memo[x0];
}

void Game::drawText(){
    initText("f(x) = log(x + 1)", 10.f, 10.f, 35.f, sf::Color::Red);
    initText("Antal iterationer: " + std::to_string(iterationCount), 10.f, 70.f, 35.f, sf::Color::White);
    initText("Nulpunkt: " + std::to_string(root(x0, precision, func, func_derivative)), 10.f, 120.0f, 35.f, sf::Color::White);
    initText("x0: " + std::to_string(x0), 10.f, 170.f, 35.f, sf::Color::White);
    initText("y", (videomode.width/2.0f) - 30.f, 5.f, 35.f, sf::Color::White);
    initText("x", videomode.width - 35.f, (videomode.height/2.f) + 20.f, 35.f, sf::Color::White);
}

void Game::drawAxis(){
    line xAxis(0, videomode.height/2.0f, videomode.width, videomode.height/2.0f, sf::Color::White);
    line yAxis(videomode.width/2.0f, 0, videomode.width/2.0f, videomode.height, sf::Color::White);
    xAxis.draw_line(*window);
    yAxis.draw_line(*window);

    for(float x = coordinateSystemMin; x <= coordinateSystemMax; x += dist_lines_axis){
        float xPos = (x - coordinateSystemMin) / (coordinateSystemMax - coordinateSystemMin) * videomode.width;
        line line(xPos, videomode.height / 2.0f - 5.0f, xPos, videomode.height / 2.0f + 5.0f, sf::Color::White);
        line.draw_line(*window);
    }

    for(float y = coordinateSystemMin; y <= coordinateSystemMax; y += dist_lines_axis){
        float yPos = videomode.height - (y - coordinateSystemMin) / (coordinateSystemMax - coordinateSystemMin) * videomode.height;
        line line(videomode.width / 2.0f - 5.0f, yPos, videomode.width / 2.0f + 5.0f, yPos, sf::Color::White);
        line.draw_line(*window);
    }
}

void Game::drawTangents(const std::vector<IterationData>& iterations) {
    tangents.clear();
    points.clear();

    for (const IterationData& data : iterations) {
        float tangentX1 = (data.tangentX1 - coordinateSystemMin) / (coordinateSystemMax - coordinateSystemMin) * videomode.width;
        float tangentY1 = videomode.height - (data.tangentY1 - coordinateSystemMin) / (coordinateSystemMax - coordinateSystemMin) * videomode.height;
        float tangentX2 = (data.tangentX2 - coordinateSystemMin) / (coordinateSystemMax - coordinateSystemMin) * videomode.width;
        float tangentY2 = videomode.height - (data.tangentY2 - coordinateSystemMin) / (coordinateSystemMax - coordinateSystemMin) * videomode.height;

        line tangent_line(tangentX1, tangentY1, tangentX2, tangentY2, sf::Color(0, 150, 255, 255));
        tangents.push_back(tangent_line);

        sf::CircleShape point(5);
        point.setFillColor(sf::Color(0, 150, 255, 255));
        point.setPosition(((tangentX1 + tangentX2) / 2.0f) - (point.getGlobalBounds().width/2.0f), ((tangentY1 + tangentY2) / 2.0f) - (point.getGlobalBounds().height/2.0f));
        points.push_back(point);
    }

    for(line& tangent : tangents){
        tangent.draw_line(*window);
    }

    for(const sf::CircleShape& circle : points){
        window->draw(circle);
    }
}

void Game::update() {
    root(x0, precision, func, func_derivative);
}

void Game::render() {
    window->clear();

    window->draw(graph);
    drawAxis();
    drawTangents(iterations);
    drawText();

    window->display();
}