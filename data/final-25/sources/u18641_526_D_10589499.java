import java.io.*;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 * Author: Sergey Paramonov
 * Date: 04.04.15
 * Time: 20:06
 */
public class Zepto_20150404_D {

    Scanner scanner = new Scanner(System.in);
    BufferedReader buffered = new BufferedReader(new InputStreamReader(System.in));
    StreamTokenizer input = new StreamTokenizer(buffered);

    PrintWriter output = new PrintWriter(new BufferedOutputStream(System.out));

    int nextInt() throws Exception {
        input.nextToken();
        return (int) input.nval;
    }

    void flushAndClose() {
        output.flush();
        System.out.flush();
        output.close();
    }

    final long MOD1 = 1000000021;
    final long MOD2 = 1000000007;
    final long F1 = 97;
    final long F2 = 89;

    void main() throws Exception {
//        int n = 1000000;
//        int k = 300;
//        StringBuilder str = new StringBuilder();
//        for (int i = 0; i < n; i++) {
//            str.append('a');
//        }
//        String s = str.toString();
//        long start = System.currentTimeMillis();

        String[] nk = buffered.readLine().trim().split(" ");
        int n = Integer.valueOf(nk[0]);
        int k = Integer.valueOf(nk[1]);
        String s = buffered.readLine();
        long[] P1 = new long[n];
        long[] H1 = new long[n];
        long[] P2 = new long[n];
        long[] H2 = new long[n];
        P1[0] = 1;
        H1[0] = s.charAt(0) - 'a';
        P2[0] = 1;
        H2[0] = s.charAt(0) - 'a';
        for (int i = 1; i < n; i++) {
            P1[i] = (P1[i-1] * F1) % MOD1;
            H1[i] = (H1[i-1] + (s.charAt(i)-'a')*P1[i]) % MOD1;
            P2[i] = (P2[i-1] * F2) % MOD2;
            H2[i] = (H2[i-1] + (s.charAt(i)-'a')*P2[i]) % MOD2;
        }

        int[] ans = new int[n+1];
        for (int t = 1; t*k <= n; t++) {
            boolean bingo = true;

            for (int i=1; i<k; i++) {
                long h1 = H1[(i+1)*t-1] - H1[i*t-1];
                if (h1 < 0) {
                    h1 += MOD1;
                }
                long h2 = H2[(i+1)*t-1] - H2[i*t-1];
                if (h2 < 0) {
                    h2 += MOD2;
                }
                if (((H1[t-1] * P1[i * t]) % MOD1 != h1) || (H2[t-1] * P2[i*t])%MOD2 != h2)
                {
                    bingo = false;
                    break;
                }
            }

            if (bingo) {
                int l = 0;
                int r = Math.min(t + 1, n - t * k + 1);
                while (r-l > 1) {
                    int m = (r+l) / 2;
                    long h1 = H1[(t*k)-1+m] - H1[(t*k)-1];
                    if (h1 < 0) {
                        h1 += MOD1;
                    }
                    long h2 = H2[(t*k)-1+m] - H2[(t*k)-1];
                    if (h2 < 0) {
                        h2 += MOD2;
                    }
                    if (((H1[m-1] * P1[t*k]) % MOD1 != h1) || ((H2[m-1] * P2[t*k]) % MOD2 != h2)) {
                        r = m;
                    } else {
                        l = m;
                    }
                }
                ans[t*k-1]++;
                ans[t*k+l]--;
            }
        }
        StringBuilder buf = new StringBuilder();
        int bal = 0;
        for (int i = 0; i < n; i++) {
            bal += ans[i];
            buf.append((bal > 0) ? '1' : '0');
        }
        output.println(buf.toString());

//        output.println(System.currentTimeMillis() - start);

        flushAndClose();
    }

    public static void main(String[] args) throws Exception {
        new Zepto_20150404_D().main();
    }

}
