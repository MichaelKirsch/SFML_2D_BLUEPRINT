#pragma once

#include "../Statemachine/Gamestate.h"
#include "../GUI/GuiManager.h"
#include "FastNoise.h"
#include "../World/Worldgenerator.h"

#define DEBUG 1

class ChooseMap : public GameState {
public:
    ChooseMap(EssentialWindow& es);
    void handle_events() override;
    void logic() override;
    void render() override;
    ~ChooseMap()= default;

private:
    bool initialiced = false;
    void init();
    Worldgenerator m_WorldGen;
    int seed;
    sf::Vector2i position_in_map = {0,0};
    int zoom = 1;
    void generateMap();
    int worldSizeInBlocks = 100000;
    sf::RectangleShape mouse_circle;
    EssentialWindow& m_Essential;
    gui::SimpleText* seedText= nullptr;
    gui::SimpleText* ChosenRegion= nullptr;
    gui::Button* nextMap= nullptr;
    gui::Button* spawnOnLand = nullptr;
    gui::Button* useThisMap= nullptr;
    gui::Button* backButton= nullptr;
    sf::RectangleShape mapLining;
    sf::VertexArray m_VertexMap;
};



