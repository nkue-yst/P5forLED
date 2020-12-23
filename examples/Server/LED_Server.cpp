/*****
 * LED_Server.cpp
 * 2020/12/23
 * 
 * Copyright (C) 2020 Yoshito Nakaue.
 *****/

#include "LEDManager.hpp"

/** fill led with single color **/
int main()
{
    p5led::LEDManager *led = new p5led::LEDManager();

    led->run();

    delete led;
    return 0;
}
