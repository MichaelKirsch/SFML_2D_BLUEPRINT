

#include "ChooseMap.h"

ChooseMap::ChooseMap(EssentialWindow &es) : m_Essential(es), GameState(es) {

}

void ChooseMap::init() {
    srand(time(0));
    seed = rand();
    seedText = m_Gui.addSimpleTextCentered("Seed:" + std::to_string(seed), {80, 50 + 5 * m_Essential.m_GuiStyle.buttonHeight});
    ChosenRegion = m_Gui.addSimpleTextCentered("You Chose:" + std::to_string(position_in_map.x) + "|" + std::to_string(position_in_map.y), {80, 20});
    nextMap = m_Gui.addButtonCentered("Generate new Map", {80, 50 - 2 * m_Essential.m_GuiStyle.buttonHeight});
    useThisMap = m_Gui.addButtonCentered("Start the game on Ship", {80, 50});
    spawnOnLand = m_Gui.addButtonCentered("Start the game on Land", {80, 50 + 2 * m_Essential.m_GuiStyle.buttonHeight});
    backButton = m_Gui.addButtonCentered("Back", {80, 50 + 4 * m_Essential.m_GuiStyle.buttonHeight});
    mapLining.setPosition(m_Essential.getPixelValues({10,10}));
    auto size_box = m_Essential.getPixelValues({80,80});
    mapLining.setSize({size_box.y,size_box.y}); //this is right as it is. we need the y-value both times to get it square and to be sure that it will fit with the buttons
    mapLining.setFillColor(m_Essential.m_GuiStyle.inactiveColor);
    mouse_circle.setSize({m_Essential.getPixelValues({0.5,0.5}).y,m_Essential.getPixelValues({0.5,0.5}).y});
    mouse_circle.setFillColor(sf::Color(255, 0, 0, 100));
    auto circle_size = mouse_circle.getSize();
    mouse_circle.setOrigin(circle_size.x/2,circle_size.y/2);
    if(DEBUG)
    {
        seedText->setActive(0);
    }
    generateMap();
    m_WorldGen.setSafetyZone(14);
}

void ChooseMap::handle_events() {
    if(initialiced)
    {
        if(position_in_map==sf::Vector2i(0,0))
        {
            useThisMap->isActive = false;
        }
        else
        {
            useThisMap->setActive(true);
        }

        m_Gui.update();
        if(backButton->isClicked())
        {
            m_Essential.nextState = STATES :: MENU;
        }
        if(nextMap->isClicked())
        {
            seed = rand();
            seedText->setText("Seed:"+std::to_string(seed));
            generateMap();
        }
        auto mousepos = m_Essential.m_Mouse.getPosition(m_Essential.m_Window);
        auto bounds = mapLining.getGlobalBounds();
        if(mousepos.x>bounds.left&&mousepos.x<bounds.left+bounds.width)
        {
            if(mousepos.y>bounds.top&&mousepos.y<bounds.top+bounds.height)
            {
                if(m_Essential.m_Mouse.isButtonPressed(sf::Mouse::Left))
                {
                    mouse_circle.setPosition(mousepos.x,mousepos.y);
                    sf::Vector2i vituralPos = {static_cast<int>(mousepos.x-bounds.left),static_cast<int>(mousepos.y-bounds.top)};
                    sf::Vector2f virtualPosPercentage = {(vituralPos.x/bounds.width),(vituralPos.y/bounds.width)};
                    ChosenRegion->setText("You Chose:"+std::to_string(position_in_map.x)+"|"+std::to_string(position_in_map.y));
                }
            }
        }

        sf::Event m_Event;
        while (getGamestateEssential()->m_Window.pollEvent(m_Event))
        {
            if (m_Event.type == sf::Event::Closed )
            {
                GameState::getGamestateEssential()->nextState = STATES::EXITING;
            }
        }
    }
}

void ChooseMap::render() {
    if(initialiced)
    {
        m_Essential.m_Window.clear();
        m_Gui.draw();
        m_Essential.m_Window.draw(mapLining);
        m_Essential.m_Window.draw(m_VertexMap);
        m_Essential.m_Window.draw(mouse_circle);
        m_Essential.m_Window.display();
    }
}

void ChooseMap::logic() {
    if (!initialiced)
    {
        init();
        initialiced = true;
    }
}

void ChooseMap::generateMap() {
    //lets restrict the vertex-array to the size of the box *4 as we will need 4 vertices for every quad shape
    //the minimal size is one pixel
    float max,min;
    m_WorldGen.setSeed(seed);
    auto size_box = mapLining.getSize();
    auto virtual_zero_pos = mapLining.getPosition();
    auto bounds = mapLining.getGlobalBounds();
    m_VertexMap.clear();
    m_VertexMap.resize(((size_box.x*size_box.y)*4));
    m_VertexMap.setPrimitiveType(sf::Quads);

    for(int x =0;x<bounds.width/2;x++)
    {
        for (int i = 0; i < bounds.height/2; i++) {
            int index = ((x*bounds.height)+i)*4;
            m_VertexMap[index].position = sf::Vector2f(virtual_zero_pos.x+x*2,virtual_zero_pos.y+i*2);
            m_VertexMap[index+1].position = sf::Vector2f(virtual_zero_pos.x+(x+1)*2, virtual_zero_pos.y+i*2);
            m_VertexMap[index+2].position = sf::Vector2f(virtual_zero_pos.x+(x+1)*2, virtual_zero_pos.y+(i+1)*2);
            m_VertexMap[index+3].position = sf::Vector2f(virtual_zero_pos.x+x*2, virtual_zero_pos.y+(i+1)*2);

            auto noise1 = m_WorldGen.getHeight({static_cast<int>((worldSizeInBlocks/bounds.width)*x*2),static_cast<int>(((worldSizeInBlocks)/bounds.height)*i*2)});
            float val = (noise1);
            sf::Color col;
            int  coloring_val = val/10;
            auto val2 = val/10.0;
            switch (coloring_val)
            {
                default:
                    col = {0, 175, 245};
                    break;

                case 1:
                    if(val2<1.05)
                        col = {5, 79, 158};
                    if(val2>=1.05&&val2<=1.1)
                        col = {43, 220, 255};
                    if(val2>1.1&&val2<=1.2)
                        col = {176, 160, 90};
                    if(val2>1.2)
                        col = {81, 184, 62};
                    break;
                case 2:
                    col = {17, 140, 38};
                    break;
                case 3:
                    col = {23, 135, 3};
                    break;
                case 4:
                    col = {0, 77, 1};
                    break;
                case 5:
                    col = {62, 77, 0};
                    break;
                case 6:
                    col = {32, 54, 1};
                    break;
                case 7:
                    col = {48, 42, 21};
                    break;
                case 100:
                    //Bordercase
                    col = { 0,0,0};
                    break;
            }

            m_VertexMap[index].color = col;
            m_VertexMap[index+1].color = col;
            m_VertexMap[index+2].color = col;
            m_VertexMap[index+3].color = col;

        }
    }

}


