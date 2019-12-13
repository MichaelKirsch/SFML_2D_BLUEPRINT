

#include "simple.h"

simple::simple() {
    pointerset = false;
    building_timer =0.0;
    wgen.setFrequency(100);
    view1.setSize(16*20,9*20);
    view1.setCenter(100,100);
}

void simple:: drawTile(float x, float y, int pos, float tilesize,sf::Color col) {
    auto tilewidth = tilesize;
    auto tileheight = tilesize/2.f;
    sf::Vector2f center  = {x,y};
    //map[pos].color = col;
    //map[pos+1].color = col;
    //map[pos+2].color = col;
    //map[pos+3].color = col;


    map[pos].position = sf::Vector2f{center.x,center.y};
    map[pos+1].position = sf::Vector2f{center.x+tilewidth,center.y};
    map[pos+2].position = sf::Vector2f{center.x+tilewidth,center.y+tileheight};
    map[pos+3].position = sf::Vector2f{center.x,center.y+tileheight};

    int height = rand()%16;
    if(height>=6)
        height=0;
    map[pos].texCoords = sf::Vector2f(64*height, 16.f);
    map[pos+1].texCoords = sf::Vector2f(64.f*(height+1), 16.f);
    map[pos+2].texCoords = sf::Vector2f(64.f*(height+1), 64.f-16);
    map[pos+3].texCoords = sf::Vector2f(64*height, 64.f-16);

    tile_overlay[pos].position = sf::Vector2f{center.x,center.y};
    tile_overlay[pos+1].position = sf::Vector2f{center.x+tilewidth,center.y};
    tile_overlay[pos+2].position = sf::Vector2f{center.x+tilewidth,center.y+tileheight};
    tile_overlay[pos+3].position = sf::Vector2f{center.x,center.y+tileheight};
    tile_overlay[pos].color = sf::Color::Red;
    tile_overlay[pos+1].color = sf::Color::Transparent;
    tile_overlay[pos+2].color = sf::Color::Transparent;
    tile_overlay[pos+3].color = sf::Color::Transparent;
    center = {32,16};


}

void simple::setPointer(EssentialWindow *es) {
    pointerset = true;
    this->es =es;
    coordinatestext.setFont(es->m_GlobFont);
    const int size_chunk = 100;
    map.setPrimitiveType(sf::Quads);
    map.resize(size_chunk*size_chunk*4);
    tile_overlay.resize(size_chunk*size_chunk*4);
    tile_overlay.setPrimitiveType(sf::Points);
    wgen.setWorldSize(100);
    wgen.setFrequency(100.f);
    wgen.setOctaves(13);
    m_text.loadFromFile(es->m_PathToParent+"/data/Pics/isometric2.png");
    tree.loadFromFile(es->m_PathToParent+"/data/Pics/iso-test.png");
    m_ground.loadFromFile(es->m_PathToParent+"/data/Pics/brickpavers2.png");
    float tilesize = 32.0f;
    world_space = (size_chunk*worldsize)*tilesize;
    float tileheight = tilesize/2;
    const int offset = 20;
    for(int x =0;x<size_chunk;x++)
    {
        for(int y =size_chunk;y>0;y--)
        {
            sf::Color col;
            if(rand()%2==0)
                col={0,255,0,19};
            else
                col={0,0,255,19};
            auto pos = ((x*size_chunk)+(size_chunk-y))*4;
            auto screenX = (y * (tilesize  / 2)) + (x * (tilesize  / 2));
            auto screenY = (x* (tileheight / 2)) - (y* (tileheight / 2));
            drawTile(screenX,screenY,pos,tilesize,col);
        }
    }
}

void simple::update() {
    if(pointerset) {

        EssentialWindow &buf = *es;
        auto mou = buf.m_Mouse.getPosition(buf.m_Window);
        if(mou.x < buf.m_Window.getSize().x*0.1)
        {
            view1.move(-10.0,0);
        }
        if(mou.x > buf.m_Window.getSize().x*0.9)
        {
            view1.move(10.0,0);
        }
        if(mou.y > buf.m_Window.getSize().y*0.9)
        {
            view1.move(0,10.0);
        }
        if(mou.y < buf.m_Window.getSize().y*0.1)
        {
            view1.move(0,-10.0);
        }

        auto elapsed = b_cl.restart().asSeconds();
        building_timer += elapsed;
        if(1)
        {
            if(dir)
                occ+=5;
            else
                occ-=5;

            if(occ>250)
            {
               dir = false;
            }
            if(occ<5)
                dir=true;
        }

        mouse_rect.setTexture(&tree);
        ground_test.setTexture(&m_ground);
        sf::Vector2u houseSizeInTiles{1,1};
        const float tilewidth = 32.f;
        const float tileheight = tilewidth/2.f;
        mouse_rect.setFillColor(sf::Color{255,255,255,(uint8_t)occ});
        mouse_rect.setSize({houseSizeInTiles.x*tilewidth, houseSizeInTiles.y*tileheight});
        ground_test.setSize({houseSizeInTiles.x*tilewidth, houseSizeInTiles.x*tileheight});
        mouse_rect.setOutlineColor({
                                           252, 186, 3
                                   });
        mouse_rect.setOutlineThickness(1);
        auto mouspos_relaitve_toWindow = buf.m_Mouse.getPosition(buf.m_Window);
        auto center_of_view = view1.getCenter();
        auto size_of_view = view1.getSize();
        auto window_size = buf.m_Window.getSize();
        auto mouse_to_percent = sf::Vector2f{((1.f/window_size.x)*mouspos_relaitve_toWindow.x)-0.5f,((1.f/window_size.y)*mouspos_relaitve_toWindow.y)-0.5f};

        auto end_pos = sf::Vector2i{static_cast<int>(center_of_view.x+(size_of_view.x/1.f)*mouse_to_percent.x),static_cast<int>(center_of_view.y+(size_of_view.y/1.f)*mouse_to_percent.y)};
        std::string coord = "X:"+std::to_string(end_pos.x)+" Y:"+std::to_string(end_pos.y);
        coordinatestext.setString(coord);
        coordinatestext.setPosition(view1.getCenter().x-view1.getSize().x/2,view1.getCenter().y-view1.getSize().y/2);
        mouse_rect.setPosition(end_pos.x,end_pos.y);
    }
}
