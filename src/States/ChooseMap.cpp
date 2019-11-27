

#include "ChooseMap.h"

ChooseMap::ChooseMap(EssentialWindow &es) : GameState(es),m_Essential(es),m_GuiManager(es) {
    m_Essential.m_Music.stop();
    ChosenRegion = m_GuiManager.addSimpleTextCentered("You Chose:"+std::to_string(position_in_map.x)+"|"+std::to_string(position_in_map.y),{80,20});
    map_playaround = m_GuiManager.addMenu();
    map_playaround->createMenu("msun",{"Freq+","Freq-","Oct+","Oct-","Lacu+","Lacu-","Gain+","Gain-","Factor+","Factor-"},5);
    zoomIn = m_GuiManager.addButtonCentered("Zoom +",{40,95});
    zoomOut = m_GuiManager.addButtonCentered("Zoom -",{30,95});
    introduction = m_GuiManager.addSimpleTextCentered("Choose your starting region",{50,4});
    nextMap = m_GuiManager.addButtonCentered("Next Map",{80,50-2*m_Essential.m_GuiStyle.buttonHeight});
    useThisMap = m_GuiManager.addButtonCentered("Use this Map",{80,50});
    backButton = m_GuiManager.addButtonCentered("Back",{80,50+2*m_Essential.m_GuiStyle.buttonHeight});
    srand(time(0));
    seed = rand();
    m_Noise.SetNoiseType(FastNoise::SimplexFractal);
    seedText = m_GuiManager.addSimpleTextCentered("Seed:"+std::to_string(seed),{80,50+5*m_Essential.m_GuiStyle.buttonHeight});
    mapLining.setPosition(m_Essential.getPixelValues({10,10}));
    auto size_box = m_Essential.getPixelValues({80,80});
    mapLining.setSize({size_box.y,size_box.y}); //this is right as it is. we need the y-value both times to get it square and to be sure that it will fit with the buttons
    mapLining.setFillColor(m_Essential.m_GuiStyle.inactiveColor);
    mouse_circle.setRadius(m_Essential.getPixelValues({1,1}).y);
    mouse_circle.setFillColor(sf::Color(255,0,0,100));
    auto circle_size = mouse_circle.getRadius();
    mouse_circle.setOrigin(circle_size/2,circle_size/2);
    map_playaround->isVisible= true;
    map_playaround->isActive = true;

}

void ChooseMap::handle_events() {
    if(position_in_map==sf::Vector2i(0,0))
    {
        useThisMap->setActive(false);
    }
    else
    {
        useThisMap->setActive(true);
    }

    m_GuiManager.update();
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
    if(zoomIn->isClicked())
    {
        zoom++;
        generateMap();
    }
    if(zoomOut->isClicked())
    {
        zoom--;
        if(zoom<1)
            zoom =1;
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
                position_in_map = mousepos;
                ChosenRegion->setText("You Chose:"+std::to_string(position_in_map.x)+"|"+std::to_string(position_in_map.y));
            }
        }
    }

    if(map_playaround->getButtonState("Freq+"))
    {
       frequency+= 0.001;
       generateMap();
    }
    if(map_playaround->getButtonState("Freq-"))
    {
        frequency-= 0.001;
        generateMap();
    }

    if(map_playaround->getButtonState("Lacu-"))
    {
        lacuna-=0.1;
        generateMap();
    }
    if(map_playaround->getButtonState("Lacu+"))
    {
        lacuna+=0.1;
        generateMap();
    }

    if(map_playaround->getButtonState("Oct+"))
    {
        octave++;
        generateMap();
    }

    if(map_playaround->getButtonState("Oct-"))
    {
        octave--;
        generateMap();
    }

    if(map_playaround->getButtonState("Gain-"))
    {
        gain-=0.1;
        generateMap();
    }
    if(map_playaround->getButtonState("Gain+"))
    {
        gain+=0.1;
        generateMap();
    }

    if(map_playaround->getButtonState("Factor+"))
    {
        factor+=0.5;
        generateMap();
    }

    if(map_playaround->getButtonState("Factor-"))
    {
        factor-=0.5;
        generateMap();
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

void ChooseMap::render() {
    m_Essential.m_Window.clear();
    m_GuiManager.draw();
    m_Essential.m_Window.draw(mapLining);
    m_Essential.m_Window.draw(m_VertexMap);
    m_Essential.m_Window.draw(mouse_circle);
    m_Essential.m_Window.display();
}

void ChooseMap::logic() {

}

void ChooseMap::generateMap() {
    //lets restrict the vertex-array to the size of the box *4 as we will need 4 vertices for every quad shape
    //the minimal size is one pixel
    float max,min;
    auto size_box = mapLining.getSize();
    auto virtual_zero_pos = mapLining.getPosition();
    auto bounds = mapLining.getGlobalBounds();
    m_VertexMap.clear();
    m_VertexMap.resize(((size_box.x*size_box.y)*4));
    m_VertexMap.setPrimitiveType(sf::Quads);
    m_Noise.SetSeed(seed);
    m_Noise.SetFrequency(frequency);
    m_Noise.SetFractalLacunarity(lacuna);
    m_Noise.SetFractalOctaves(octave);
    m_Noise.SetFractalGain(gain);

    for(int x =0;x<bounds.width/2;x++)
    {
        for (int i = 0; i < bounds.height/2; i++) {
            int index = ((x*bounds.height)+i)*4;
            m_VertexMap[index].position = sf::Vector2f(virtual_zero_pos.x+x*2,virtual_zero_pos.y+i*2);
            m_VertexMap[index+1].position = sf::Vector2f(virtual_zero_pos.x+(x+1)*2, virtual_zero_pos.y+i*2);
            m_VertexMap[index+2].position = sf::Vector2f(virtual_zero_pos.x+(x+1)*2, virtual_zero_pos.y+(i+1)*2);
            m_VertexMap[index+3].position = sf::Vector2f(virtual_zero_pos.x+x*2, virtual_zero_pos.y+(i+1)*2);

            auto noise1 = m_Noise.GetNoise(((worldSizeInBlocks/zoom)/bounds.width)*x,((worldSizeInBlocks/zoom)/bounds.height)*i);
            float val = noise1;
            sf::Color col;
            int  coloring_val = val*10;
            switch (coloring_val)
            {
                default:
                    col = {5, 79, 158};
                    break;
                case 1:
                    col = {135, 173, 68};
                    break;
                case 2:
                    col = {69, 135, 3};
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
            }

            m_VertexMap[index].color = col;
            m_VertexMap[index+1].color = col;
            m_VertexMap[index+2].color = col;
            m_VertexMap[index+3].color = col;

        }
    }
    seedText->setText("Seed:"+std::to_string(seed)+" Gain:"+std::to_string(gain)+"\nFreq:"+std::to_string(frequency)+
    " Lacu:"+std::to_string(lacuna)+"\nOct:"+std::to_string(octave)+"\nMax:"+std::to_string(max)+" Min:"+std::to_string(min));

}
