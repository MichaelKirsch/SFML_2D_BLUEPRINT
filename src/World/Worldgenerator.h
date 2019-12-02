

#pragma once

#include <SFML/Graphics.hpp>
#include "FastNoise.h"
#include "iostream"
#include <math.h>
#include "Tile-Enum.h"

class Worldgenerator {
public:
    Worldgenerator(){
        writeValues();
    }
    Worldgenerator(int worldSize, int seed): m_Seed(seed),m_Worldsize(worldSize){
        writeValues();
    };

    Worldgenerator(int worldSize): m_Worldsize(worldSize){
        writeValues();
    };
    void writeValues();
    void setWorldSize(int size){m_Worldsize=size;writeValues();};
    void setSafetyZone(int saf){m_savetyZone = saf;writeValues();};
    void setSeed(int seed){m_Seed=seed;writeValues();};
    void setLacuna(float lac){m_Noise_Lacuna = lac;writeValues();};
    void setOctaves(int octave){m_Noise_Octave=octave;writeValues();};
    void setFrequency(float freq){m_Noise_Frequency = freq;writeValues();};
    int getHeight(sf::Vector2i pos);
    TILE_TYPE getBlockID(sf::Vector2i pos);
    ~Worldgenerator() = default;

private:
    int m_Noise_Octave = 9;//standard value
    float m_Noise_Frequency = 17.0;//standard value
    float m_Noise_Lacuna = 0.26;//standard value
    float m_Noise_Gain = 5.0;//standard value
    int m_savetyZone =5;
    FastNoise m_Noise;
    FastNoise m_TreeNoise;
    int m_Worldsize = 100000;
    int m_Seed = 199;
};



