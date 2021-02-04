import p5led.client.*;

void setup() {
  size(32, 32);
  background(0, 0, 0);
  
  colorMode(RGB, 256);
  fill(0, 255, 0);
  //circle(16, 16, 20);
  triangle(16, 2, 2, 30, 30, 30);
  
  Client led = new Client("127.0.0.1", 13579);
  updatePixels();
  loadPixels();
  color c;
  for (int y = 0; y < 32; y++) {
    for (int x = 0; x < 32; x++) {
      c = pixels[y * 32 + x];
      led.SetPixel(x, y, (int)red(c), (int)green(c), (int)blue(c));
    }
  }
    
  led.closeSocket();
}

void draw() {
  
}
