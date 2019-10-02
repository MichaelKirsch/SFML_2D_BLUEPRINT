

#include "Game.h"

Game::Game() : window(sf::VideoMode(WIDTH, HEIGHT), TITLE) {

}

Game::~Game() {

}

void Game::run() {
    while (window.isOpen())
    {
        float elapsedTime = clock.restart().asSeconds();
        callEvents(elapsedTime);
        update(elapsedTime);
        render(elapsedTime);
    }

}

void Game::callEvents(float elapsedTime) {
    eventTimer+=elapsedTime;
    if(eventTimer>1.0f/TICKRATE) //calculate time of tickevent
    {
        eventTimer=0; //reset timer
        //do stuff with events
    }
}

void Game::update(float elapsedTime) {
    updateTimer+=elapsedTime;
    if(updateTimer>1.0f/TICKRATE) //calculate time of tickevent
    {
        updateTimer=0; //reset timer
        //update stuff
    }
}

void Game::render(float elapsedTime) {
    renderTimer+=elapsedTime;
    if(renderTimer>1.0f/FRAMERATE) //this one is different as it represents the rendering
    {
        renderTimer=0; //reset timer
        //update the screen
    }
}
