import p5led.client.Client;

public class LED_Client {
    public static void main(String[] args) throws Exception {
        Client led = new Client("127.0.0.1", 12345);
        led.closeSocket();
    }
}
