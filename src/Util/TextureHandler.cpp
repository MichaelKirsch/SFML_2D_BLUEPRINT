

#include "TextureHandler.h"

void TextureHandler::loadTexture(std::string path, sf::Vector2u structure, sf::Vector2u individualSize) {
    m_Texture.loadFromFile(path);
    this->m_Structure = structure;
    this->m_IndivSize = individualSize;
}

sf::Texture *TextureHandler::getTexturePtr() {
    return &m_Texture;
}

Texture_Coordinates TextureHandler::getCoordinatesForElement(sf::Vector2u positionElement) {
    Texture_Coordinates buf;
    buf.p1 = {static_cast<float>(m_IndivSize.x*positionElement.x),static_cast<float>(m_IndivSize.y*positionElement.y)};
    buf.p2 = {static_cast<float>((m_IndivSize.x+1)*positionElement.x),static_cast<float>(m_IndivSize.y*positionElement.y)};
    buf.p3 = {static_cast<float>((m_IndivSize.x+1)*positionElement.x),static_cast<float>((m_IndivSize.y+1)*positionElement.y)};
    buf.p4 = {static_cast<float>((m_IndivSize.x)*positionElement.x),static_cast<float>((m_IndivSize.y+1)*positionElement.y)};
    return buf;
}

Texture_Coordinates TextureHandler::getCoordinatesForElement(int indexElement) {
    sf::Vector2u positionElement = {indexElement/m_Structure.x,indexElement%m_Structure.x};
    Texture_Coordinates buf;
    buf.p1 = {static_cast<float>(m_IndivSize.x*positionElement.x),static_cast<float>(m_IndivSize.y*positionElement.y)};
    buf.p2 = {static_cast<float>((m_IndivSize.x+1)*positionElement.x),static_cast<float>(m_IndivSize.y*positionElement.y)};
    buf.p3 = {static_cast<float>((m_IndivSize.x+1)*positionElement.x),static_cast<float>((m_IndivSize.y+1)*positionElement.y)};
    buf.p4 = {static_cast<float>((m_IndivSize.x)*positionElement.x),static_cast<float>((m_IndivSize.y+1)*positionElement.y)};
    return buf;
}
