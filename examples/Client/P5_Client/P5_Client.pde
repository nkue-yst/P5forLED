import p5led.client.Client;

Client led;

void setup() {
  try {
    led = new Client("127.0.0.1", 12345);
  } catch (Exception e) {

  }
}

void draw() {
  try {
    led.Fill(255, 255, 255);
  } catch (Exception e) {
  
  }
}
