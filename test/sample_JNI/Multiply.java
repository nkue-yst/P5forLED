public class Multiply {
    public static void main(String[] args) {
        System.loadLibrary("Multiply");
        System.out.println(multiply(5, 2));
    }

    public static native int multiply(int base, int rate);
}
