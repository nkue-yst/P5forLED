package RandomerPackage;

import java.util.Random;

public class Randomer {
    public static int rand(int min, int range) {
        Random r = new Random();
        return (r.nextInt(range) + min);
    }
}
