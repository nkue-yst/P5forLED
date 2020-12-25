/*****
 * Socket.hpp
 * 2020/12/25
 * 
 * Copyright (C) 2020 Yoshito Nakaue.
 *****/

#include <netinet/in.h>

namespace p5led
{
    class Socket
    {
    public:
        Socket(const int port = 12345);
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
        int ReadInteger();

    private:
        struct sockaddr_in addr_;
        struct sockaddr_in client_;

        int sock_;
        int sock_rcv_;
        int port_;
        socklen_t length_;

        char rcv_buf_[2048];
    };
}
