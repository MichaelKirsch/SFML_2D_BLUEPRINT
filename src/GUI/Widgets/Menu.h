

#pragma once

#include "WidgetBase.h"
#include "Button.h"

namespace gui
{
    class Menu : public Widget {
    public:
        Menu(EssentialWindow* es);
        ~Menu()=default;
        void draw();
        void update();
        void createMenu(std::string name, std::vector<std::string> buttons);
        bool getButtonState(std::string buttonName);
    private:
        EssentialWindow* m_Essential;
        std::map<std::string,std::unique_ptr<gui::Button>> m_Elements;
    };
}





