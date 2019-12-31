

#include "ToggleButton.h"

gui::ToggleButton::ToggleButton(EssentialWindow &es) : Widget(es) {
    m_body.setFillColor(m_Essential.m_GuiStyle.defaultBackground);
    m_buttonText.setFillColor(m_Essential.m_GuiStyle.textColor);
    button_active = m_Essential.m_GuiStyle.actuatedWidget;
    button_inactive = m_Essential.m_GuiStyle.inactiveColor;
    m_size = m_Essential.m_GuiStyle.buttonHeight*((m_Essential.m_Window.getSize().y)/100.f);
    refactor();
}

void gui::ToggleButton::refactor() {
    m_buttonText.setFont(m_Essential.m_GlobFont);
    m_buttonText.setCharacterSize(m_size);
    m_buttonText.setString(m_name);
    auto width_of_text = m_buttonText.getGlobalBounds().width;
    auto space_between_text_and_button = width_of_text*0.1;//10% space
    auto width_of_knob = m_buttonText.getCharacterSize();
    auto height_of_base = width_of_knob*0.6;
    auto width_of_base = 2*width_of_knob;
    auto pos = m_Essential.fromPercentageToScreenFloat({(int)m_position.x,(int)m_position.y});
    m_buttonText.setPosition(pos);
    m_body.setSize({static_cast<float>(width_of_base*0.7),static_cast<float>(height_of_base)});
    m_knob.setRadius(width_of_knob/2.f);
    m_body.setPosition(pos.x+width_of_text+space_between_text_and_button+0.15*width_of_base,pos.y+(0.3*height_of_base));
    buffer.setSize({static_cast<float>(2*m_buttonText.getCharacterSize()),static_cast<float>(m_buttonText.getCharacterSize())});
    buffer.setPosition(pos.x+width_of_text+space_between_text_and_button,pos.y);
    if(m_status)
    {
        m_knob.setFillColor(button_active);
        m_knob.setPosition(pos.x+width_of_text+space_between_text_and_button+width_of_knob,pos.y);
    }
    else
    {
        m_knob.setFillColor(button_inactive);
        m_knob.setPosition(pos.x+width_of_text+space_between_text_and_button,pos.y);
    }
}

void gui::ToggleButton::draw() {
    m_Essential.m_Window.draw(m_buttonText);
    m_Essential.m_Window.draw(m_body);
    m_Essential.m_Window.draw(m_knob);
}

void gui::ToggleButton::update() {
    time_since_last_toggle+=m_Essential.m_Clock.getElapsedTime().asSeconds();
    auto mouse = m_Essential.getMouseRelPos();
    auto bounds = buffer.getGlobalBounds();
    if(m_Essential.m_Mouse.isButtonPressed(sf::Mouse::Left))
    {
        if (mouse.x > bounds.left && mouse.x< bounds.left+bounds.width && mouse.y > bounds.top && mouse.y < bounds.top+bounds.height && time_since_last_toggle>0.0005) {
            time_since_last_toggle = 0.f;
            toggle();
        }
    }
}

void gui::ToggleButton::toggle() {
    m_status=!m_status;
    refactor();
}
