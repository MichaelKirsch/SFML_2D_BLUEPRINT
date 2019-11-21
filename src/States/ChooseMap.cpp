

#include "ChooseMap.h"

ChooseMap::ChooseMap(EssentialWindow &es) : GameState(es),m_Essential(es),m_GuiManager(es) {
    m_Essential.m_Music.stop();
    map_playaround = m_GuiManager.addMenu();
    map_playaround->createMenu("msun",{"Freq+","Freq-","Oct+","Oct-","Lacu+","Lacu-","Gain+","Gain-"},5);
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
    map_playaround->isVisible= false;
    map_playaround->isActive = false;
    generateMap();
}

void ChooseMap::handle_events() {
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
                mouse_circle.setPosition(mousepos.x,mousepos.y);
        }
    }

    if(map_playaround->getButtonState("Freq+"))
    {
       frequency+= 0.000001;
       generateMap();
    }
    if(map_playaround->getButtonState("Freq-"))
    {
        frequency-= 0.000001;
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
    m_VertexMap.resize(((size_box.x*size_box.y)*4)/zoom);
    m_VertexMap.setPrimitiveType(sf::Quads);
    m_Noise.SetSeed(seed);
    m_Noise.SetFrequency(frequency);
    m_Noise.SetFractalLacunarity(lacuna);
    m_Noise.SetFractalOctaves(octave);
    m_Noise.SetFractalGain(gain);

    for(int x =0;x<bounds.width/zoom;x++) {
        for (int i = 0; i < bounds.height / zoom; i++) {
            float val = m_Noise.GetNoise((100000 / bounds.height) * x, (100000 / bounds.height) * i);
            if (val > max)
                max = val;
            if (val < min)
                min = val;
        }
    }
    for(int x =0;x<bounds.width/zoom;x++)
    {
        for (int i = 0; i < bounds.height/zoom; i++) {
            int index = ((x*bounds.height/zoom)+i)*4;
            m_VertexMap[index].position = sf::Vector2f(virtual_zero_pos.x+x*zoom,virtual_zero_pos.y+i*zoom);
            m_VertexMap[index+1].position = sf::Vector2f(virtual_zero_pos.x+(x+1)*zoom, virtual_zero_pos.y+i*zoom);
            m_VertexMap[index+2].position = sf::Vector2f(virtual_zero_pos.x+(x+1)*zoom, virtual_zero_pos.y+(i+1)*zoom);
            m_VertexMap[index+3].position = sf::Vector2f(virtual_zero_pos.x+x*zoom, virtual_zero_pos.y+(i+1)*zoom);

            float val = m_Noise.GetNoise((100000/bounds.height)*x,(100000/bounds.height)*i);
            if(val<0.0)
                val=0.0;
            sf::Color col;
            int color = val*10;
            switch (color)
            {
                case 0:
                    col = {0, 136, 255};
                    break;

                case 1:
                    col = {118, 185, 245};
                    break;

                case 2:
                    col = {245, 205, 118};
                    break;

                case 3:
                case 4:
                    col = {0, 133, 24};
                    break;
                case 5:
                    col = {94, 94, 94};
                    break;
                default:
                    col = {207, 207, 207};
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
