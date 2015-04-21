import java.util.*;
import java.lang.*;
import java.io.*;

public class Blue1 {

    StringTokenizer in;
    BufferedReader br;
    PrintWriter out;
    String s;
    long[] hash;
    long[] pp;
    int n;
    final int p = 239;
    final int MOD = 1000000007;

    long h(int L, int R) {
        return ((hash[R] - hash[L] * pp[R - L]) % MOD + MOD) % MOD;
    }

    public void solve() throws IOException {
        int L = nextInt();
        boolean containsC = false;
        s = nextToken();
        n = s.length();
        pp = new long[n + 1];
        pp[0] = 1;
        hash = new long[n + 1];
        hash[0] = 0;
        for (int i = 0; i < n; i++) {
            pp[i + 1] = (pp[i] * p) % MOD;
            hash[i + 1] = (hash[i] * p + ((int) s.charAt(i))) % MOD;
            if (s.charAt(i) == 'c') {
                containsC = true;
            }
        }

        for (int i = 1; i <= L; i++) {
            if (n % i == 0) {
                long h1 = h(0, i);
                boolean flag = true;
                for (int j = 0; j < n; j += i) {
                    if (h(j, j + i) != h1) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    out.println(1);
                    out.println(s.substring(0, i));
                    return;
                }
            }
        }

        if (!containsC) {
            out.println(2);
            out.println("a");
            out.println("b");
        } else {
            boolean[] dp = new boolean[n + 1];
            for (int i = 1; i <= L; i++) { // -2 - Can't, -1 - Can with only one, other - can with start and this hash
                long h1 = h(0, i);
                for (int j = 1; j <= L; j++) {
                    if (i + j <= n) {
                        long h2 = h(i, i + j);
                        Arrays.fill(dp, false);
                        dp[0] = true;
                        for (int k = 0; k < n; k++) {
                            if (dp[k]) {
                                if (k + i <= n && h(k, k + i) == h1) {
                                    dp[k + i] = true;
                                }
                                if (k + j <= n && h(k, k + j) == h2) {
                                    dp[k + j] = true;
                                }
                            }
                        }
                        if (dp[n]) {
                            out.println(2);
                            out.println(s.substring(0, i));
                            out.println(s.substring(i, i + j));
                            return;
                        }
                    }
                }
            }
            out.println(3);
            out.println("a");
            out.println("b");
            out.println("c");
        }
    }

    public String nextToken() throws IOException {
        while (in == null || !in.hasMoreTokens()) {
            in = new StringTokenizer(br.readLine());
        }
        return in.nextToken();
    }

    public double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    public long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    public void run() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    public static void main(String[] args) throws IOException {
        new Blue1().run();
    }

}
