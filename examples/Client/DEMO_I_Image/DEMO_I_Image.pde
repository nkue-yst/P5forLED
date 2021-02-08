/*****
 * DEMO_I_Image.pde
 * 2021/02/08
 *
 * Copyright (C) 2021 Yoshito Nakaue
 *****/

import p5led.client.*;

Client led;

void setup() {
  size(32, 32);
  PImage img = loadImage("../SampleImage.png");
  
  img.resize(32, 32);
  image(img, 0, 0);
  
  led = new Client(this, "localhost", 13579, false);
  led.DrawFromP5();
}

void draw() {
  if (key == 'q') {
    led.closeSocket();
    exit();
  }
}
