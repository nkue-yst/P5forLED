/*****
 * LED_Client.java
 * 2020/12/25
 * 
 * Copyright (C) 2020 Yoshito Nakaue.
 *****/

import p5led.client.Client;

public class LED_Client {
    public static void main(String[] args) {
        Client led = new Client("127.0.0.1", 12345);

        //led.Fill(255, 255, 255);
        led.SetPixel(5, 5, 255, 0, 0);

        led.closeSocket();
    }
}
