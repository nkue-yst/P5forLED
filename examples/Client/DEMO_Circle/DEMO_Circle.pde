import p5led.client.*;

Client led;

void setup() {
  frameRate(30);
  size(32, 32);
  background(0, 0, 0);
  
  colorMode(RGB, 256);
  fill(0, 255, 0);

  led = new Client("127.0.0.1", 13579, this);
}

void draw() {
  circle(16, 16, 20);

  led.DrawFromP5();
  
  if (key == ENTER) {
    led.closeSocket();
    exit();
  }
  else {
  }
}
