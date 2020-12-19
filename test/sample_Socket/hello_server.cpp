#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

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
    listen(sock,5);

    len = sizeof(client);
    sock_rcv = accept(sock, (struct sockaddr*)&client, &len);

    write(sock_rcv, "Hello", 5);

    close(sock_rcv);
    close(sock);

    return 0;
}
