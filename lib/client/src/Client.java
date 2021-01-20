/*****
 * Client.java
 * 2021/01/20
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

    public void Fill(int red, int green, int blue) {
        try {
            DataOutputStream dos = new DataOutputStream(socket.getOutputStream());
            dos.writeChar('F');
            dos.writeShort((short)red);
            dos.writeShort((short)green);
            dos.writeShort((short)blue);
        } catch (Exception e) {

        }
    }

    public void SetPixel(int x, int y, int red, int green, int blue) {
        try {
            DataOutputStream out = new DataOutputStream(socket.getOutputStream());
            out.writeChar('S');
            out.writeShort((short)x);
            out.writeShort((short)y);
            out.writeShort((short)red);
            out.writeShort((short)green);
            out.writeShort((short)blue);
        } catch (Exception e) {

        }
    }

    public void Shobon() {
        SetPixel(2, 3, 0, 255, 0);  SetPixel(2, 4, 0, 255, 0);  SetPixel(2, 5, 0, 255, 0);
        SetPixel(2, 6, 0, 255, 0);  SetPixel(3, 2, 0, 255, 0);  SetPixel(3, 7, 0, 255, 0);
        SetPixel(5, 3, 0, 255, 0);  SetPixel(8, 4, 0, 255, 0);  SetPixel(8, 5, 0, 255, 0);
        SetPixel(9, 4, 0, 255, 0);  SetPixel(9, 5, 0, 255, 0);  SetPixel(12, 5, 0, 255, 0);
        SetPixel(12, 6, 0, 255, 0);  SetPixel(13, 4, 0, 255, 0);  SetPixel(13, 7, 0, 255, 0);
        SetPixel(14, 7, 0, 255, 0);  SetPixel(15, 5, 0, 255, 0);  SetPixel(15, 6, 0, 255, 0);
        SetPixel(16, 7, 0, 255, 0);  SetPixel(17, 4, 0, 255, 0);  SetPixel(17, 7, 0, 255, 0);
        SetPixel(18, 5, 0, 255, 0);  SetPixel(18, 6, 0, 255, 0);  SetPixel(21, 4, 0, 255, 0);
        SetPixel(21, 5, 0, 255, 0);  SetPixel(22, 4, 0, 255, 0);  SetPixel(22, 5, 0, 255, 0);
        SetPixel(24, 2, 0, 255, 0);  SetPixel(25, 3, 0, 255, 0);  SetPixel(27, 2, 0, 255, 0);
        SetPixel(27, 7, 0, 255, 0);  SetPixel(28, 3, 0, 255, 0);  SetPixel(28, 4, 0, 255, 0);
        SetPixel(28, 5, 0, 255, 0);  SetPixel(28, 6, 0, 255, 0);  SetPixel(6, 2, 0, 255, 0);
    }
    
    private String  addr;
    private Integer port;
    private Socket  socket;

    private String  send_buf;
}
