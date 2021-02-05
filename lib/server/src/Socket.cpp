/*****
 * Socket.cpp
 * 2021/01/20
 * 
 * Copyright (C) 2020 Yoshito Nakaue.
 *****/

#include "Socket.hpp"
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

namespace p5led
{
    Socket::Socket(const int port)
        : sock_(0)
        , sock_rcv_(0)
        , port_(port)
        , length_(0)
    {
        memset(&addr_, 0, sizeof(addr_));
        memset(&client_, 0, sizeof(client_));
        sock_ = socket(AF_INET, SOCK_STREAM, 0);
    }

    Socket::~Socket()
    {
        close(sock_);
        close(sock_rcv_);
    }

    void Socket::Listen()
    {
        addr_.sin_family = AF_INET;
        addr_.sin_port   = htons(port_);
        addr_.sin_addr.s_addr = INADDR_ANY;
        
        bind(sock_, (struct sockaddr*)&addr_, sizeof(addr_));

        std::cout << "Accept waiting..." << std::endl;

        listen(sock_, 5);
        length_ = sizeof(client_);
        sock_rcv_ = accept(sock_, (struct sockaddr*)&client_, &length_);

        std::cout << "Connected to " << inet_ntoa(client_.sin_addr)
                    << "(" << ntohs(client_.sin_port) << ")" << std::endl;
    }

    char Socket::ReadChar()
    {
        read(sock_rcv_, rcv_buf_, sizeof(char16_t));

        return rcv_buf_[0];
    }

    int16_t Socket::ReadShort()
    {
        read(sock_rcv_, rcv_buf_, sizeof(int16_t));

        return rcv_buf_[0];
    }

    int16_t Socket::ReadByte()
    {
        read(sock_rcv_, rcv_buf_, sizeof(int8_t));
        return (rcv_buf_[0] & 0xFF);
    }
}
