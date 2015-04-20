import java.io.*;
import java.util.*;

/**
 * Created by spb on 09.11.2014.
 */
public class gcm {
    public static long greatest (long a, long b) {
        if (a == 0) { return b; }
        else { return greatest(b % a, a); }
    }
    public static void main (String[] args) throws IOException {
        Scanner in = new Scanner (new File("gcm.in"));
        long a = in.nextLong();
        long b = in.nextLong();

        long pr = (long) Math.sqrt((double)a*b);
        long g = greatest(a, b);
        while (pr % g != 0) {
            pr = pr - 1;
        }
        PrintWriter out = new PrintWriter("gcm.out");
        out.printf("%d %d", pr, a*b/pr);
        out.close();
    }
}
