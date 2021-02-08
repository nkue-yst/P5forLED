/*****
 * DEMO_V_Line.pde
 * 2021/02/08
 *
 * Copyright (C) 2021 Yoshito Nakaue
 *****/

import p5led.client.*;

Client led;

float a;

void setup() {
  size(32, 32);
  a = height / 2;
  colorMode(RGB, 256);
  strokeWeight(3);
  
  led = new Client(this, "127.0.0.1", 13579, true);
}

void draw() {
  background(0);
  stroke(255, 0, 0);
  line(0, a, width, a);
  stroke(200, 200, 0);
  line(0, height - a, width, height - a);
  stroke(0, 255, 0);
  line(width - a, 0, width - a, height);
  stroke(0, 0, 255);
  line(a, 0, a, height);
  a -= 0.2;
  if (a < 0) {
    a = height;
  }

  led.DrawFromP5(0.3);
  
  if (key == 'q') {
    led.closeSocket();
    exit();
  }
}
