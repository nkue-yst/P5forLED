import java.lang.System;
import com.sun.jna.Library;
import com.sun.jna.Native;

interface Lib02 extends Library {
    Lib02 INSTANCE = (Lib02) Native.loadLibrary("02_lib", Lib02.class);

    int run(int argc, String[] argv);
}

public class Sample03 {
    public static void main(String[] args) {
        Lib02 lib02 = Lib02.INSTANCE;
        String[] temp = {""};
        String[] argv = new String[args.length+1];
        System.arraycopy(temp, 0, argv, 0, temp.length);
        System.arraycopy(args, 0, argv, 1, args.length);
        
        lib02.run(argv.length, argv);
    }
}
