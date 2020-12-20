#include "LEDManager.hpp"
#include <iostream>
#include <unistd.h>

using p5led::LEDManager;

/***** Simple LED test *****/
int main()
{
    LEDManager *led = new LEDManager();
    char c;
    int r = 0;
    int g = 0;
    int b = 0;

    while (1)
    {
        std::cin >> c;
        switch (c)
        {
        case 'r':
            r += 10;
            break;
        case 'g':
            g += 10;
            break;
        case 'b':
            b += 10;
            break;
        default:
            r = g = b = 0;
        }
        led->Fill(r, g, b);
        led->Update();
    }

    sleep(3);
    delete led;
    return 0;
}
