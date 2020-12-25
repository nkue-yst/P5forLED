import p5led.client.Client;

Client led;

void setup() {
  led = new Client("127.0.0.1", 12345);
}

void draw() {
  led.Fill(255, 255, 255);
}
