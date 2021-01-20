/*****
 * LEDManager.hpp
 * 2021/01/02
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
            socket_->Listen();
            
            while (1)
            {
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
