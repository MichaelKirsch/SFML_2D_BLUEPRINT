

#pragma once

#include "../Statemachine/Gamestate.h"
#include "../GUI/GuiManager.h"
#include "FastNoise.h"

class ChooseMap : public GameState {
public:
    ChooseMap(EssentialWindow& es);
    void handle_events() override;
    void logic() override;
    void render() override;
    ~ChooseMap()= default;

private:
    int seed;
    int zoom = 1;
    void generateMap();
    int octave = 9;
    float frequency = 0.000003;
    float lacuna = 1.6;
    float gain = 2.1;
    sf::CircleShape mouse_circle;
    EssentialWindow& m_Essential;
    gui::Manager m_GuiManager;
    gui::SimpleText* seedText;
    gui::SimpleText* introduction;
    gui::Button* nextMap;
    gui::Button* zoomIn;
    gui::Button* zoomOut;
    gui::Button* useThisMap;
    gui::Button* backButton;
    gui::Menu* map_playaround;
    sf::RectangleShape mapLining;
    sf::VertexArray m_VertexMap;
    FastNoise m_Noise;
};



