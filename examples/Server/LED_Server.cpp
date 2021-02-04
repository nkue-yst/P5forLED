/*****
 * LED_Server.cpp
 * 2021/02/04
 * 
 * Copyright (C) 2020 Yoshito Nakaue.
 *****/

#include "LEDManager.hpp"

/** fill led with single color **/
int main()
{
    p5led::LEDManager *led = new p5led::LEDManager(50, true);

    led->run();

    delete led;
    return 0;
}
