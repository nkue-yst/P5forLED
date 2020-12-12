import SamplePackage.Sample04;

Sample04 s = new Sample04(250, 250, 400, 400);

void setup() {
  size(500, 500);
}

void draw() {
  colorMode(RGB, 256);
  noStroke();
  fill(255, 0, 0);
  ellipse(s.x, s.y, s.w, s.h);
}
