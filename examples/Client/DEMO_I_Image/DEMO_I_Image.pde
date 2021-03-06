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

  led = new Client(this, "localhost", 13579, false);
  led.DrawImage(loadImage("../SampleImage.png"), 0, 0);
}

void draw() {
  if (key == 'q') {
    led.closeSocket();
    exit();
  }
}
