import java.util.*;
import java.io.*;

public class merlin {

    public static long topsum
            (long[] ag, int pos) {
        long res = 0;
        int lnt = ag.length;
        for (int i=pos+1; i<lnt; i++) {
            res = res + ag[i];
        }
        return res;
    }

    public static long  lowsum
            (long[] ag, int pos) {
        long res = 0;
        for (int i=0; i<pos+1; i++) {
            res = res + (ag[pos] - ag[i]);
        }
        return res;
    }

    public static void main
            (String [] args) throws IOException {
        Scanner in = new Scanner(new File("merlin.in"));
        int n = in.nextInt();
        long[] mainar = new long[n];
        for (int i = 0; i < n; i++) {
            mainar[i] = in.nextLong();
        }
        Arrays.sort(mainar);
        PrintWriter out = new PrintWriter ("merlin.out");
        if (mainar[0] == mainar[n - 1]) {
            out.print(0);
        } else {
            int k = n - 2;
            while (topsum(mainar, k) <= lowsum(mainar, k)) {
                k = k - 1;
            }

            out.print(n - 1 - k);
        }
        out.close();
    }
}