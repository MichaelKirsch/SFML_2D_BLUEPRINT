#pragma once

#include "SFML/Graphics.hpp"
#include "Worldgenerator.h"
#include "EssentialWindow.h"

class tilemaploader
{
public:
    tilemaploader(std::string path, int sizex, int sizey);
    ~tilemaploader()= default;

private:
    sf::Texture m_text;
};

class simple {
public:
    simple();
    void setPointer(EssentialWindow* es);
    ~simple()= default;
    sf::Texture m_text;
    sf::VertexArray map;
    void drawTile(float x, float y, int pos, float tilesize,sf::Color col);
    void tile(int nbr,int x,int y);
    Worldgenerator wgen;
    EssentialWindow* es;
protected:
};



