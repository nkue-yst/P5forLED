/*****
 * LEDManager.hpp
 * 2020/12/25
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
                    break;
                case 'S':
                    SetPixel();
                    break;
                default:
                    break;
                }
                Update();
            }
        }

        /**
         * Fill LED with single color
         **/
        void Fill();

        /**
         * Set pixel color
         **/
        void SetPixel();

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
