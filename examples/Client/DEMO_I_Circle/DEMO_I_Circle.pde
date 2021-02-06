/*****
 * DEMO_I_Circle.pde
 * 2021/02/06
 * 
 * Copyright (C) 2021 Yoshito Nakaue.
 *****/

import p5led.client.*;

Client led;

void setup() {
  size(32, 32);
  background(0, 0, 0);
  
  colorMode(RGB, 256);
  fill(0, 255, 0);
  circle(16, 16, 30);

  led = new Client(this, "127.0.0.1", 13579, false);
  led.DrawFromP5();
}

void draw() {
  if (key == 'q') {
    led.closeSocket();
    exit();
  }
}
