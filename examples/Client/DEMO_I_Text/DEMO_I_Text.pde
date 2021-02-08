/*****
 * DEMO_I_Text.pde
 * 2021/02/08
 *
 * Copyright (C) 2021 Yoshito Nakaue
 *****/

import p5led.client.*;

Client led;

void setup() {
  size(32, 32);
  led = new Client(this, "localhost", 13579, false);
  
  fill(0, 255, 0);
  textSize(12);
  text("Hello", 0, 13);
  text("World", 0, 25);
  
  led.DrawFromP5();
}

void draw() {
  if (key == 'q') {
    led.closeSocket();
    exit();
  }
}
  
