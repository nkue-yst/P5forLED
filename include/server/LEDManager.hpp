/*****
 * LEDManager.hpp
 * 2020/12/23
 * 
 * Copyright (C) 2020 Yoshito Nakaue.
 *****/

#include "led-matrix.h"
#include "Socket.hpp"
#include <iostream>

namespace p5led
{
    class LEDManager
    {
    public:
        LEDManager(int brightness = 50);
        ~LEDManager();

        void run()
        {
            while (1)
            {
                socket_->Listen();
                switch (socket_->ReadChar())
                {
                case 'F':
                    Fill();
                    Update();
                    break;
                default:
                    break;
                }
            }
        }

        /**
         * Fill LED with single color
         **/
        void Fill();

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

        Socket *socket_;
    };
}
