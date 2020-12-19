import java.io.*;
import java.net.*;

public class LED_Client {
    public static void main(String[] args) throws Exception {
        Socket socket = new Socket("127.0.0.1", 12345);

        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);

        System.out.print("Color('r' or 'g' or 'b') -> ");
        char[] str;
        str = br.readLine().toCharArray();
        char c = str[0];

        DataOutputStream dos = new DataOutputStream(socket.getOutputStream());
        dos.write(c);

        br.close();
        socket.close();
    }
}
