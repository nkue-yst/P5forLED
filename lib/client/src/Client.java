/*****
 * Client.java
 * 2020/12/25
 * 
 * Copyright (C) 2020 Yoshito Nakaue.
 *****/

package p5led.client;

import java.io.DataOutputStream;
import java.net.Socket;

public class Client {
    public Client(String ip_address, Integer port_number) {
        addr = ip_address;
        port = port_number;
        
        try {
            socket = new Socket(addr, port);
        } catch (Exception e) {

        }
    }

    public void closeSocket() {
        try {
            socket.close();
        } catch (Exception e) {

        }
    }

    public void Fill(Integer red, Integer green, Integer blue) {
        try {
            DataOutputStream dos = new DataOutputStream(socket.getOutputStream());
            dos.write('F');
            dos.write(red);
            dos.write(green);
            dos.write(blue);
        } catch (Exception e) {

        }
    }

    public void SetPixel(Integer x, Integer y, Integer red, Integer green, Integer blue) {
        try {
            DataOutputStream out = new DataOutputStream(socket.getOutputStream());
            out.write('S');
            out.write(x);
            out.write(y);
            out.write(red);
            out.write(green);
            out.write(blue);
        } catch (Exception e) {

        }
    }
    
    private String  addr;
    private Integer port;
    private Socket  socket;

    private String  send_buf;
}
