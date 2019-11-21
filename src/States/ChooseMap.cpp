

#include "ChooseMap.h"

ChooseMap::ChooseMap(EssentialWindow &es) : GameState(es),m_Essential(es),m_GuiManager(es) {
    m_Essential.m_Music.stop();
    zoomIn = m_GuiManager.addButtonCentered("Zoom +",{40,95});
    zoomOut = m_GuiManager.addButtonCentered("Zoom -",{30,95});
    introduction = m_GuiManager.addSimpleTextCentered("Choose your starting region",{50,4});
    nextMap = m_GuiManager.addButtonCentered("Next Map",{80,50-2*m_Essential.m_GuiStyle.buttonHeight});
    useThisMap = m_GuiManager.addButtonCentered("Use this Map",{80,50});
    backButton = m_GuiManager.addButtonCentered("Back",{80,50+2*m_Essential.m_GuiStyle.buttonHeight});
    srand(time(0));
    seed = rand();
    m_Noise.SetNoiseType(FastNoise::SimplexFractal);
    m_Noise.SetFrequency(0.008);
    m_Noise.SetFractalLacunarity(2.0);
    m_Noise.SetFractalGain(3);
    seedText = m_GuiManager.addSimpleTextCentered("Seed:"+std::to_string(seed),{80,50+4*m_Essential.m_GuiStyle.buttonHeight});
    mapLining.setPosition(m_Essential.getPixelValues({10,10}));
    auto size_box = m_Essential.getPixelValues({80,80});
    mapLining.setSize({size_box.y,size_box.y}); //this is right as it is. we need the y-value both times to get it square and to be sure that it will fit with the buttons
    mapLining.setFillColor(m_Essential.m_GuiStyle.inactiveColor);
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
    m_Essential.m_Window.display();
}

void ChooseMap::logic() {

}

void ChooseMap::generateMap() {
    //lets restrict the vertex-array to the size of the box *4 as we will need 4 vertices for every quad shape
    //the minimal size is one pixel
    auto size_box = mapLining.getSize();
    auto virtual_zero_pos = mapLining.getPosition();
    auto bounds = mapLining.getGlobalBounds();
    m_VertexMap.clear();
    m_VertexMap.resize(((size_box.x*size_box.y)*4)/zoom);
    m_VertexMap.setPrimitiveType(sf::Quads);
    m_Noise.SetSeed(seed);
    for(int x =0;x<bounds.width/zoom;x++)
    {
        for (int i = 0; i < bounds.height/zoom; i++) {
            int index = ((x*bounds.height/zoom)+i)*4;
            m_VertexMap[index].position = sf::Vector2f(virtual_zero_pos.x+x*zoom,virtual_zero_pos.y+i*zoom);
            m_VertexMap[index+1].position = sf::Vector2f(virtual_zero_pos.x+(x+1)*zoom, virtual_zero_pos.y+i*zoom);
            m_VertexMap[index+2].position = sf::Vector2f(virtual_zero_pos.x+(x+1)*zoom, virtual_zero_pos.y+(i+1)*zoom);
            m_VertexMap[index+3].position = sf::Vector2f(virtual_zero_pos.x+x*zoom, virtual_zero_pos.y+(i+1)*zoom);
            int val = m_Noise.GetNoise(x,i)*10;
            if(val<0)
                val =0;
            sf::Color col;
            switch(val)
            {
                case 0:
                    col = sf::Color::Blue;
                    break;
                case 1:
                    col = sf::Color::Yellow;
                    break;
                case 2:
                case 3:
                case 4:
                    col = sf::Color::Green;
                    break;
                default:
                    col = {80,80,80};
                    break;


            }
            m_VertexMap[index].color = col;
            m_VertexMap[index+1].color = col;
            m_VertexMap[index+2].color = col;
            m_VertexMap[index+3].color = col;

        }
    }
}
