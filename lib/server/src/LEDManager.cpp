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
    LEDManager::LEDManager(int brightness)
        : matrix_(nullptr)
        , off_canvas_(nullptr)
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
        int16_t red   = socket_->ReadShort();
        int16_t green = socket_->ReadShort();
        int16_t blue  = socket_->ReadShort();

        std::cout << "Fill() -> red:" << red << ", green:" << green << ", blue:" << blue << std::endl;

        off_canvas_->Fill(red, green, blue);
    }

    void LEDManager::SetPixel()
    {
        int16_t x = socket_->ReadShort();
        int16_t y = socket_->ReadShort();
        int16_t red   = socket_->ReadShort();
        int16_t green = socket_->ReadShort();
        int16_t blue  = socket_->ReadShort();

        std::cout << "SetPixel() -> x:" << x << ", y:" << y << ", red:" << red
                  << ", green:" << green << ", blue:" << blue << std::endl;

        off_canvas_->SetPixel(x, y, red, green, blue);
    }

    void LEDManager::Update()
    {
        matrix_->SwapOnVSync(off_canvas_);
    }
}
