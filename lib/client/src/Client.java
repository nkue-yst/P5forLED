/*****
 * Client.java
 * 2020/12/23
 * 
 * Copyright (C) 2020 Yoshito Nakaue.
 *****/

package p5led.client;

import java.io.DataOutputStream;
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

    public void Fill(Integer red, Integer green, Integer blue) throws Exception {
        DataOutputStream dos = new DataOutputStream(socket.getOutputStream());
        dos.write('F');
        dos.write(red);
        dos.write(green);
        dos.write(blue);
    }
    
    public String  addr;
    public Integer port;
    public Socket  socket;

    public String  send_buf;
}
