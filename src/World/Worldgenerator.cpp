

#include "Worldgenerator.h"

int Worldgenerator::getHeight(sf::Vector2i pos)
{
    if(pos.y==0||pos.y==m_Worldsize||pos.x==0||pos.x==m_Worldsize)
        return 1000;//return 1000 if its a border

    auto heightRaw = m_Noise.GetNoise(pos.x,pos.y);
    auto heightCorrected = (int)(heightRaw*100.0);
    float correction=1.0;
    if(heightCorrected>=0) //if the land is above sea level we have to check if the borders need to be flattened.
    {
        auto positive_limit = (m_savetyZone/100.0)*m_Worldsize;
        auto negative_limit = ((100-m_savetyZone)/100.0)*m_Worldsize;
        //check if its in the safety zone
        if(pos.x < positive_limit ||pos.x > negative_limit ||pos.y < positive_limit||pos.y > negative_limit)
        {
            //when it is in the safety zone it needs to be flattened out
            int border_x = positive_limit ,border_y = positive_limit;
            if(pos.x < positive_limit)
                border_x=pos.x;
            if(pos.x > negative_limit)
                border_x=m_Worldsize-pos.x;
            if(pos.y < positive_limit)
                border_y=pos.y;
            if(pos.y > negative_limit)
                border_y=m_Worldsize-pos.y;

            auto smallest_distance_to_border = 0;
            if(border_x>border_y)
                smallest_distance_to_border=border_y;
            else
                smallest_distance_to_border=border_x;
            int safetyzone_size = (m_savetyZone/100.0)*m_Worldsize;
            auto how_many_percent_of_safety_zone = (100.0/safetyzone_size)*smallest_distance_to_border;
            correction = how_many_percent_of_safety_zone/100.0;
        }
    }
    return heightCorrected*correction;
}

void Worldgenerator::writeValues() {
    //world noise
    m_Noise.SetNoiseType(FastNoise::CubicFractal);
    m_Noise.SetFrequency(m_Noise_Frequency);
    m_Noise.SetSeed(m_Seed);
    m_Noise.SetFractalOctaves(m_Noise_Octave);
    m_Noise.SetFractalGain(m_Noise_Gain);
    m_Noise.SetFractalLacunarity(m_Noise_Lacuna);

    //tree noise
    m_TreeNoise.SetNoiseType(FastNoise::Cellular);
    m_TreeNoise.SetSeed(m_Seed);
}

TILE_TYPE Worldgenerator::getBlockID(sf::Vector2i pos) {

}
