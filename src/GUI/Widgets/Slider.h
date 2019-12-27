

#pragma once

#include "WidgetBase.h"
#include "SFML/Graphics.hpp"

namespace gui
{
    class SimpleIntSlider :public Widget
    {
    public:
        SimpleIntSlider(EssentialWindow& es, int starting_value,int upper_limit,int lower_limit);
        
    private:
        int value = 0;
    };

    class Slider : public Widget {
    public:
        Slider();

    private:
    protected:
    };
}





