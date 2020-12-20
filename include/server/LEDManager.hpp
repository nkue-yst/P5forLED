/*****
 * LEDManager.hpp
 * 2020/12/20
 * 
 * Copyright (C) 2020 Yoshito Nakaue.
 *****/

#include "led-matrix.h"

namespace p5led
{
    class LEDManager
    {
    public:
        LEDManager(int brightness = 50);
        ~LEDManager();

        /**
         * Fill LED with single color
         **/
        void Fill(const uint8_t red, const uint8_t green, const uint8_t blue);

        /**
         * Set pixel color
         **/
        void SetPixel(const int x, const int y,
                        const uint8_t red, const uint8_t green, const uint8_t blue);

        /**
         * Update matrix
         **/
        void Update();

    private:
        rgb_matrix::RGBMatrix *matrix_;
        rgb_matrix::FrameCanvas *off_canvas_;
    };
}
