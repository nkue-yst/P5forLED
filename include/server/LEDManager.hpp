/*****
 * LEDManager.hpp
 * 2021/02/04
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
        LEDManager(int brightness = 50, bool debug = false);
        ~LEDManager();

        void run()
        {
            bool isRunning = true;
            socket_->Listen();
            
            while (isRunning)
            {
                switch (socket_->ReadChar())
                {
                case 'F':
                    Fill();
                    break;
                case 'S':
                    SetPixel();
                    break;
                case 'D':
                    DrawFromP5();
                    break;
                case 'Q':
                    isRunning = false;
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

        void DrawFromP5();

        /**
         * Update matrix
         **/
        void Update();

    private:
        rgb_matrix::RGBMatrix *matrix_;
        rgb_matrix::FrameCanvas *off_canvas_;

        bool debug_;

        Socket *socket_;
    };
}
