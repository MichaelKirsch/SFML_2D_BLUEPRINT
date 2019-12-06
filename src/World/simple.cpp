

#include "simple.h"

simple::simple() {

}

void simple:: drawTile(float x, float y, int pos, float tilesize,sf::Color col) {
    auto tilewidth = tilesize;
    auto tileheight = tilesize/2.f;
    sf::Vector2f center  = {x,y};
    //map[pos].color = col;
    //map[pos+1].color = col;
    //map[pos+2].color = col;
    //map[pos+3].color = col;
    map[pos].position = sf::Vector2f{center.x,center.y-(tileheight/2.f)};
    map[pos+1].position = sf::Vector2f{center.x+(tilewidth/2.f),center.y};
    map[pos+2].position = sf::Vector2f{center.x,center.y+(tileheight/2.f)};
    map[pos+3].position = sf::Vector2f{center.x-(tilewidth/2.f),center.y};
    center = {32,16};
    map[pos].texCoords = sf::Vector2f(150.f, 0.f);
    map[pos+1].texCoords = sf::Vector2f(300.f, 75.f);
    map[pos+2].texCoords = sf::Vector2f(150.f, 150.f);
    map[pos+3].texCoords = sf::Vector2f(0.f, 75.f);

}

void simple::setPointer(EssentialWindow *es) {
    map.setPrimitiveType(sf::Quads);
    map.resize(100*100*4);
    wgen.setWorldSize(100);
    wgen.setFrequency(100.f);
    wgen.setOctaves(13);
    m_text.loadFromFile(es->m_PathToParent+"/data/Pics/iso-test.png");
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
