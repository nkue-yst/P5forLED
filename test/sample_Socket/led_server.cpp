#include "led-matrix.h"

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

using rgb_matrix::RGBMatrix;
using rgb_matrix::RuntimeOptions;
using rgb_matrix::FrameCanvas;

int run_led(char color)
{
    RGBMatrix::Options opt;
    RuntimeOptions runtime_opt;

    opt.rows = 32;
    opt.cols = 32;
    opt.chain_length = 1;
    opt.parallel = 1;
    opt.brightness = 50;

    RGBMatrix *matrix = CreateMatrixFromOptions(opt, runtime_opt);
    if (matrix == NULL)
        return 1;

    FrameCanvas *offscreen = matrix->CreateFrameCanvas();

    switch (color)
    {
    case 'r':
        offscreen->Fill(255, 0, 0);
        break;
    case 'g':
        offscreen->Fill(0, 255, 0);
        break;
    case 'b':
        offscreen->Fill(0, 0, 255);
        break;
    default:
        std::cout << "Incorrect character. \"'" << color << "'" << std::endl;
        return 1;
    }

    matrix->SwapOnVSync(offscreen);
    sleep(5);
    
    delete matrix;
    return 0;
}

int main()
{
    int sock;
    struct sockaddr_in addr;
    struct sockaddr_in client;
    socklen_t len;
    int sock_rcv;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_port   = htons(12345);
    addr.sin_addr.s_addr = INADDR_ANY;
    bind(sock, (struct sockaddr*)&addr, sizeof(addr));

    char color;

    listen(sock, sizeof(char));

    len = sizeof(client);
    sock_rcv = accept(sock, (struct sockaddr*)&client, &len);

    read(sock_rcv, &color, sizeof(char));

    std::cout << run_led(color) << std::endl;

    close(sock_rcv);
    close(sock);
    return 0;
}
