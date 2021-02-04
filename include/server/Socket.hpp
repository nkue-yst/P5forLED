/*****
 * Socket.hpp
 * 2021/01/20
 * 
 * Copyright (C) 2020 Yoshito Nakaue.
 *****/

#include <netinet/in.h>

namespace p5led
{
    class Socket
    {
    public:
        Socket(const int port = 13579);
        ~Socket();

        /**
         * Listen packet from client
         **/ 
        void Listen();

        /**
         * Read characters from client
         **/
        char ReadChar();

        /**
         * Read integer from client
         **/
        int16_t ReadShort();

    private:
        struct sockaddr_in addr_;
        struct sockaddr_in client_;

        int sock_;
        int sock_rcv_;
        int port_;
        socklen_t length_;

    public:
        int16_t rcv_buf_[3*64*64];
    };
}
