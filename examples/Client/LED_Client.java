/*****
 * LED_Client.java
 * 2021/02/06
 * 
 * Copyright (C) 2020 Yoshito Nakaue.
 *****/

import p5led.client.Client;

public class LED_Client {
    public static void main(String[] args) {
        Client led = new Client("127.0.0.1", 13579, null);

        led.Shobon();

        try {
            Thread.sleep(10000);
        } catch (Exception e) {

        }

        led.closeSocket();
    }
}
