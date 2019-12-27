

#pragma once

#include "WidgetBase.h"
#include "Button.h"

namespace gui
{
    class Menu : public Widget {
    public:
        Menu(EssentialWindow& es);
        ~Menu()=default;
        void draw();
        void update();
        void createMenu(std::string name, std::vector<std::string> buttons, unsigned int x_center_line_pos=50);
        bool getButtonState(std::string buttonName);
        std::string getPressedButton();
        gui::Button* getButtonPtr(std::string buttonName);
    private:
        std::map<std::string,std::unique_ptr<gui::Button>> m_Elements;
    };
}





