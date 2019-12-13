

#pragma once

#include "WidgetBase.h"
#include "gui_Enums.h"
#include <vector>
#include "TextureHandler.h"
namespace gui
{
    class ExtensiveMenu : Widget{
    public:
        ExtensiveMenu(std::string texurepath,sf::Vector2u texture_structure, sf::Vector2u textureSize);
        void draw() override;
        void update() override;
        ~ExtensiveMenu() = default;
    private:
        EssentialWindow* m_Essential;
        Style m_Style;
        DIRECTIONS m_snapTo;
        TextureHandler m_TextureHandler;
        sf::Clock m_Timer;
        int m_AnimationSpeed;
        bool m_multiplePagesPresent;
        bool m_isTextured;
        bool m_hasAnimation;
        int m_SizeSidebarWhenClosed;
        int m_UnfoldedSize;
        int m_AmountMembersPerPage;
        int m_CurrentPage;
        int m_SizePerItem;
    protected:
    };
}




