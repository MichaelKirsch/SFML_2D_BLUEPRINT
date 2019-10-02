#pragma once

#include "SFML/Graphics.hpp"
#include "iostream"

#define TITLE "INSERT TITLE"
#define WIDTH 1000
#define HEIGHT 1000

#define TICKRATE 30 //Tickrate of the whole system in Hz
#define FRAMERATE 60 //Framerate of the Rendering in Hz

class Game  {
public:
    Game();
    void run();
    ~Game();
//VARS
private:
    sf::RenderWindow window;
    sf::Clock clock;
    float eventTimer;
    float updateTimer;
    float renderTimer;
//FUNCTIONS
private:
    void callEvents(float elapsedTime);
    void update(float elapsedTime);
    void render(float elapsedTime);
};



