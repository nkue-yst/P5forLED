/*****
 * LED_Client.java
 * 2021/01/20
 * 
 * Copyright (C) 2020 Yoshito Nakaue.
 *****/

import p5led.client.Client;

public class LED_Client {
    public static void main(String[] args) {
        Client led = new Client("127.0.0.1", 13579);

        led.Shobon();

        led.closeSocket();
    }
}
