import java.util.*;
import java.lang.*;
import java.io.*;

public class Blue1 {

    StringTokenizer in;
    BufferedReader br;
    PrintWriter out;
    String s;
    long[] hash1;
    long[] pp1;
    long[] hash2;
    long[] pp2;
    int n;
    final int p1 = 239;
    final int MOD1 = 1000000007;
    final int p2 = 101;
    final int MOD2 = 1000000009;

    long h1(int L, int R) {
        return ((hash1[R] - hash1[L] * pp1[R - L]) % MOD1 + MOD1) % MOD1;
    }

    long h2(int L, int R) {
        return ((hash2[R] - hash2[L] * pp2[R - L]) % MOD2 + MOD2) % MOD2;
    }

    public void solve() throws IOException {
        int L = nextInt();
        boolean containsC = false;
        s = nextToken();
        n = s.length();
        pp1 = new long[n + 1];
        pp1[0] = 1;
        pp2 = new long[n + 1];
        pp2[0] = 1;
        hash1 = new long[n + 1];
        hash1[0] = 0;
        hash2 = new long[n + 1];
        hash2[0] = 0;
        for (int i = 0; i < n; i++) {
            pp1[i + 1] = (pp1[i] * p1) % MOD1;
            pp2[i + 1] = (pp2[i] * p2) % MOD2;
            hash1[i + 1] = (hash1[i] * p1 + ((int) s.charAt(i))) % MOD1;
            hash2[i + 1] = (hash2[i] * p2 + ((int) s.charAt(i))) % MOD2;
            if (s.charAt(i) == 'c') {
                containsC = true;
            }
        }

        for (int i = 1; i <= L; i++) {
            if (n % i == 0) {
                long hf1 = h1(0, i);
                long hf2 = h2(0, i);
                boolean flag = true;
                for (int j = 0; j < n; j += i) {
                    if (h1(j, j + i) != hf1 || h1(j, j + i) != hf2) {
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
            for (int i = 1; i <= L; i++) {
                long hf1 = h1(0, i);
                long hf2 = h2(0, i);
                for (int j = 1; j <= L; j++) {
                    if (i + j <= n) {
                        long hs1 = h1(i, i + j);
                        long hs2 = h2(i, i + j);
                        Arrays.fill(dp, false);
                        dp[0] = true;
                        for (int k = 0; k < n; k++) {
                            if (dp[k]) {
                                if (k + i <= n && h1(k, k + i) == hf1 && h2(k, k + i) == hf2) {
                                    dp[k + i] = true;
                                }
                                if (k + j <= n && h1(k, k + j) == hs1 && h2(k, k + j) == hs2) {
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
