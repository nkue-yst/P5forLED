#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    struct sockaddr_in server;
    int sock;
    char buf[10];

    sock = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port   = htons(1234);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sock, (struct sockaddr*)&server, sizeof(server));

    memset(buf, 0, sizeof(buf));
    read(sock, buf, sizeof(buf));

    std::cout << buf << std::endl;

    close(sock);

    return 0;
}
