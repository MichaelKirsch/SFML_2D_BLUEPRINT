

#pragma once
#include "Widgets/WidgetBase.h"
#include "Widgets/Button.h"
#include "Widgets/Menu.h"
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
        gui::Menu* addMenu();
    private:
        EssentialWindow& m_Essential;
        std::vector<std::unique_ptr<Widget>> m_Elements;
    };
}



