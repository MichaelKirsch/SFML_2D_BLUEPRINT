

#pragma once
#include "Widgets/WidgetBase.h"
#include "Widgets/Button.h"
#include "Widgets/Menu.h"
#include "Widgets/SimpleText.h"
#include "Widgets/progressBar.h"
#include <experimental/filesystem>
#include <string>
#include <vector>
namespace gui
{
    class Manager
    {
    public:
        Manager(EssentialWindow& es):m_Essential(es) {};
        void draw();
        void update();
        ~Manager()=default;
        gui::Button* addButton();
        gui::Button* addButton(std::string);
        gui::Button* addButtonCentered(std::string,sf::Vector2u);
        gui::Menu* addMenu();
        gui::SimpleText* addSimpleText();
        gui::SimpleText* addSimpleText(std::string);
        gui::SimpleText* addSimpleTextCentered(std::string,sf::Vector2u);
        gui::progressBar* addProgressBar(int value = 50,int max_value = 100);
    private:
        EssentialWindow& m_Essential;
        std::vector<std::unique_ptr<Widget>> m_Elements;
    };
}



