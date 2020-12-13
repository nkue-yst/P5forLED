import RandomerPackage.Randomer;

void setup() {
  size(500, 500);
}

void draw() {
  circle(Randomer.rand(0, 500), Randomer.rand(0, 500), Randomer.rand(0, 500));
}
