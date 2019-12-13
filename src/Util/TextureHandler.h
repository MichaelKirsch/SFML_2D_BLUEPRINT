

#pragma once

#include <string>
#include "SFML/Graphics.hpp"

struct Texture_Coordinates
{
    sf::Vector2f p1 = {0.f,0.f};
    sf::Vector2f p2 = {128.0f,0.f};
    sf::Vector2f p3 = {128.0f,128.f};
    sf::Vector2f p4 = {0.0f,128.f};
};

class TextureHandler {
public:
    TextureHandler(){};
    void loadTexture(std::string path,sf::Vector2u structure, sf::Vector2u individualSize);
    sf::Texture* getTexturePtr();
    Texture_Coordinates getCoordinatesForElement(sf::Vector2u positionElement);
    Texture_Coordinates getCoordinatesForElement(int positionElement);
    ~TextureHandler()=default;
private:
    sf::Texture m_Texture;
    sf::Vector2u m_Structure;
    sf::Vector2u m_IndivSize;
};



