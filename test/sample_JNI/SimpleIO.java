public class SimpleIO {
    public static void main(String[] args) {
        System.loadLibrary("SimpleIO");
        run();
    }

    public static native void run();
}
