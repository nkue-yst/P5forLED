import java.lang.System;

public class Test {
    public static native int run();

    public static void main(String[] args) {
        System.loadLibrary("Test");
        run();
    }
}