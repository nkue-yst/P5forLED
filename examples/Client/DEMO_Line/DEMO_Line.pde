import p5led.client.*;

Client led;

float a;

void setup() {
  frameRate(30);
  size(32, 32);
  a = height / 2;
  colorMode(RGB, 256);
  strokeWeight(3);
  
  led = new Client("127.0.0.1", 13579, this);
}

void draw() {
  background(0);
  stroke(255, 0, 0);
  line(0, a, width, a);
  stroke(0, 255, 0);
  line(width - a, 0, width - a, height);
  stroke(0, 0, 255);
  line(a, 0, a, height);
  a -= 0.5;
  if (a < 0) {
    a = height;
  }

  led.DrawFromP5(30, 0.4);
  
  if (key == ENTER) {
    led.closeSocket();
    exit();
  }
}
