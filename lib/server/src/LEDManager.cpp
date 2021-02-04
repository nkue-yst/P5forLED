/*****
 * LEDManager.cpp
 * 2021/01/20
 * 
 * Copyright (C) 2020 Yoshito Nakaue.
 *****/

#include "LEDManager.hpp"
#include <iostream>

namespace p5led
{
    LEDManager::LEDManager(int brightness, bool debug)
        : matrix_(nullptr)
        , off_canvas_(nullptr)
        , debug_(debug)
        , socket_(nullptr)
    {
        rgb_matrix::RGBMatrix::Options options;
        rgb_matrix::RuntimeOptions runtime_options;
        options.rows = 32;
        options.rows = 32;
        options.brightness = brightness;

        matrix_ = CreateMatrixFromOptions(options, runtime_options);
        off_canvas_ = matrix_->CreateFrameCanvas();

        socket_ = new Socket();
    }

    LEDManager::~LEDManager()
    {
        delete matrix_;
    }

    void LEDManager::Fill()
    {
        int16_t R   = socket_->ReadShort();
        int16_t G = socket_->ReadShort();
        int16_t B  = socket_->ReadShort();

        if (debug_)
        {
            std::cout << "Fill() -> R:" << R << ", G:" << G << ", B:" << B << std::endl;
        }

        off_canvas_->Fill(R, G, B);
    }

    void LEDManager::SetPixel()
    {
        int16_t x = socket_->ReadShort();
        int16_t y = socket_->ReadShort();
        int16_t R   = socket_->ReadShort();
        int16_t G = socket_->ReadShort();
        int16_t B  = socket_->ReadShort();

        if (debug_)
        {
            std::cout << "SetPixel() -> x:" << x << ", y:" << y << ", R:" << R
                  << ", G:" << G << ", B:" << B << std::endl;
        }

        off_canvas_->SetPixel(x, y, R, G, B);
    }

    void LEDManager::DrawFromP5()
    {
        int16_t R = 0;
        int16_t G = 0;
        int16_t B = 0;

        for (int y = 0; y < 32; y++)
        {
            for (int x = 0; x < 32; x++)
            {
                R = socket_->ReadShort();
                G = socket_->ReadShort();
                B = socket_->ReadShort();
                off_canvas_->SetPixel(x, y, R, G, B);
            }
        }
    }

    void LEDManager::Update()
    {
        matrix_->SwapOnVSync(off_canvas_);
    }
}
