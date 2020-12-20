/*****
 * Server.cpp
 * 2020/12/20
 * 
 * Copyright (C) 2020 Yoshito Nakaue.
 *****/

#include "LEDManager.hpp"
#include "Socket.hpp"
#include <iostream>
#include <unistd.h>

using p5led::LEDManager;
using p5led::Socket;

/***** Simple LED test *****/
int main()
{
    LEDManager *led = new LEDManager();
    Socket *socket  = new Socket();

    char c = 'r';

    while (c != 'e')
    {
        socket->Listen();
        c = socket->ReadChar();

        switch (c)
        {
        case 'r':
            led->Fill(255, 0, 0);
            break;
        case 'g':
            led->Fill(0, 255, 0);
            break;
        case 'b':
            led->Fill(0, 0, 255);
            break;
        default:
            led->Fill(255, 255, 255);
        }
        led->Update();
    }

    delete led;
    return 0;
}
