import java.util.*;
import java.io.*;

public class merlin {

    public static void main
            (String [] args) throws IOException {
        Scanner in = new Scanner(new File("merlin.in"));
        int n = in.nextInt();
        long[] mainar = new long[n];
        for (int i = 0; i < n; i++) {
            mainar[i] = in.nextInt();
        }
        Arrays.sort(mainar);
        PrintWriter out = new PrintWriter ("merlin.out");
        if (mainar[0] == mainar[n - 1]) {
            out.print(0);
        } else {
            long a = 0;
            long b = mainar[n-1];
            for (int i =0; i<n-2; i++) {
                a = a + mainar[n-2]-mainar[i];
            }
            int i = n - 2;
            while (a > b) {
                b = b + mainar[i];
                a = a - (i-1)*(mainar[i] - mainar[i-1]);
                i--;
            }
            out.print(n - i - 1);
        }
        out.close();
    }
}