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

struct tile_tex_coords
{
    sf::Vector2f co1,co2,co3,co4;
};

class tilemap_loader
{
public:
    tilemap_loader()= default;
    void load_map(std::string path,sf::Vector2u amount_tiles, sf::Vector2u tilesize ,sf::Vector2f offset_tileset,bool isometric_tile= true);
    tile_tex_coords getTile(sf::Vector2u posInTilemap);
    ~tilemap_loader()=default;
};

class simple {
public:
    simple();
    void update();
    void setPointer(EssentialWindow* es);
    const int worldsize=4;
    int world_space = 0;
    ~simple()= default;
    sf::Texture m_text;
    sf::Texture tree;
    sf::View view1;
    sf::Text coordinatestext;
    sf::Texture m_ground;
    sf::VertexArray map;
    sf::VertexArray tile_overlay;
    sf::RectangleShape mouse_rect;
    sf::RectangleShape ground_test;
    void drawTile(float x, float y, int pos, float tilesize,sf::Color col);
    void tile(int nbr,int x,int y);
    Worldgenerator wgen;
    EssentialWindow* es;
    int occ = 150;
    int danwjhk = 0;
    sf::Clock b_cl;
    float building_timer;
    bool pointerset = false;
    bool dir;
protected:
};



