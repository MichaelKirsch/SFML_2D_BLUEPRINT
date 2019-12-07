

#include "simple.h"

simple::simple() {
    pointerset = false;
    building_timer =0.0;
}

void simple:: drawTile(float x, float y, int pos, float tilesize,sf::Color col) {
    auto tilewidth = tilesize;
    auto tileheight = tilesize/2.f;
    sf::Vector2f center  = {x,y};
    //map[pos].color = col;
    //map[pos+1].color = col;
    //map[pos+2].color = col;
    //map[pos+3].color = col;


    map[pos].position = sf::Vector2f{center.x-tilewidth/2,center.y-(tileheight/2.f)};
    map[pos+1].position = sf::Vector2f{center.x+(tilewidth/2.f),center.y-(tileheight/2)};
    map[pos+2].position = sf::Vector2f{center.x+(tilewidth/2),center.y+(tileheight/2.f)};
    map[pos+3].position = sf::Vector2f{center.x-(tilewidth/2.f),center.y+(tileheight/2)};

    int height = rand()%16;
    if(height>=6)
        height=0;
    map[pos].texCoords = sf::Vector2f(64*height, 16.f);
    map[pos+1].texCoords = sf::Vector2f(64.f*(height+1), 16.f);
    map[pos+2].texCoords = sf::Vector2f(64.f*(height+1), 64.f-16);
    map[pos+3].texCoords = sf::Vector2f(64*height, 64.f-16);

    tile_overlay[pos].position = sf::Vector2f{center.x-tilewidth/2,center.y-(tileheight/2.f)};
    tile_overlay[pos+1].position = sf::Vector2f{center.x+(tilewidth/2.f),center.y-(tileheight/2)};
    tile_overlay[pos+2].position = sf::Vector2f{center.x+(tilewidth/2),center.y+(tileheight/2.f)};
    tile_overlay[pos+3].position = sf::Vector2f{center.x-(tilewidth/2.f),center.y+(tileheight/2)};
    tile_overlay[pos].color = sf::Color::Red;
    tile_overlay[pos+1].color = sf::Color::Green;
    tile_overlay[pos+2].color = sf::Color::Blue;
    tile_overlay[pos+3].color = sf::Color::White;
    center = {32,16};


}

void simple::setPointer(EssentialWindow *es) {
    pointerset = true;
    this->es =es;
    map.setPrimitiveType(sf::Quads);
    map.resize(100*100*4);
    tile_overlay.resize(100*100*4);
    tile_overlay.setPrimitiveType(sf::Points);
    wgen.setWorldSize(100);
    wgen.setFrequency(100.f);
    wgen.setOctaves(13);
    m_text.loadFromFile(es->m_PathToParent+"/data/Pics/isometric2.png");
    tree.loadFromFile(es->m_PathToParent+"/data/Pics/build.png");
    float tilesize = 32.0f;
    for(int x =0;x<100;x++)
    {
        for(int y =0;y<100;y++)
        {
            sf::Color col;
            if(rand()%2==0)
                col={0,255,0,19};
            else
                col={0,0,255,19};
            auto pos = ((x*100)+y)*4;
            if((y%2)==0)
            {
                drawTile(x*tilesize,y*(tilesize/4),pos,tilesize,col);
            } else
            {
                drawTile((x+0.5f)*tilesize,y*(tilesize/4),pos,tilesize,col);
            }
        }
    }
}

void simple::update() {
    if(pointerset) {
        auto elapsed = b_cl.restart().asSeconds();
        building_timer += elapsed;
        if(1)
        {
            if(dir)
                occ+=8;
            else
                occ-=8;

            if(occ>252)
            {
               dir = false;
            }
            if(occ<100)
                dir=true;
        }

        mouse_rect.setFillColor({150, 255, 150, (uint8_t)occ});
        mouse_rect.setTexture(&tree);
        mouse_rect.setSize({64, 64});
        mouse_rect.setOutlineColor(sf::Color::Yellow);
        mouse_rect.setOutlineThickness(0);
        mouse_rect.setOrigin(mouse_rect.getSize().x/2,mouse_rect.getSize().y/2);
        EssentialWindow &buf = *es;

        auto m_pos = buf.m_Mouse.getPosition(buf.m_Window);


        mouse_rect.setPosition(buf.m_Mouse.getPosition(buf.m_Window).x, buf.m_Mouse.getPosition(buf.m_Window).y);
    }
}
