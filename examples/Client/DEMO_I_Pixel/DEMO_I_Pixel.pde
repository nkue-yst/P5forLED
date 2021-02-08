/*****
 * DEMO_I_Pixel.pde
 * 2021/02/08
 *
 * Copyright (C) 2021 Yoshito Nakaue
 *****/

import p5led.client.*;

Client led;

void setup() {
  size(32, 32);
  
  led = new Client(this, "localhost", 13579, false);
  led.SetPixel(10, 10, 255,   0,   0);
  led.SetPixel(15, 15,   0, 255,   0);
  led.SetPixel(20, 20,   0,   0, 255);
}

void draw() {
  if (key == 'q') {
    led.closeSocket();
    exit();
  }
}
