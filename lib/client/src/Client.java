package p5led.client;

import java.net.Socket;

public class Client {
    public Client(String ip_address, Integer port_number) throws Exception {
        addr = ip_address;
        port = port_number;
        socket = new Socket(addr, port);
    }

    public void closeSocket() throws Exception {
        socket.close();
    }
    
    public String  addr;
    public Integer port;
    public Socket  socket;

    public String  send_buf;
}
