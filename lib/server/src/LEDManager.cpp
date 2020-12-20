/*****
 * LEDManager.cpp
 * 2020/12/20
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
    {
        rgb_matrix::RGBMatrix::Options options;
        rgb_matrix::RuntimeOptions runtime_options;
        options.rows = 32;
        options.rows = 32;
        options.brightness = brightness;

        matrix_ = CreateMatrixFromOptions(options, runtime_options);
        off_canvas_ = matrix_->CreateFrameCanvas();
    }

    LEDManager::~LEDManager()
    {
        delete matrix_;
    }

    void LEDManager::Fill(const uint8_t red, const uint8_t green, const uint8_t blue)
    {
        off_canvas_->Fill(red, green, blue);
    }

    void LEDManager::SetPixel(const int x, const int y,
                                const uint8_t red, const uint8_t green, const uint8_t blue)
    {
        off_canvas_->SetPixel(x, y, red, green, blue);
    }

    void LEDManager::Update()
    {
        matrix_->SwapOnVSync(off_canvas_);
    }
}