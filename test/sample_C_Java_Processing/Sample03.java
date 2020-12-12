import com.sun.jna.Library;
import com.sun.jna.Native;

public class Sample03 {
    public interface Lib01 extends Library {
        Lib01 INSTANCE = (Lib01) Native.loadLibrary("01_lib", Lib01.class);

        void simpleIO();
    }

    public static void main(String[] args) {
        Lib01.INSTANCE.simpleIO();
    }
}
