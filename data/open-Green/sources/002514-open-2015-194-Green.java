import java.util.*;
import java.lang.*;
import java.io.*;

public class Green1 {

    StringTokenizer in;
    BufferedReader br;
    PrintWriter out;
    int n, k;
    int[][] dp;

    public void solve() throws IOException {
        n = nextInt();
        k = nextInt();
        dp = new int[k + 1][n + 1];
        for (int i = 0; i < k + 1; i++) {
            Arrays.fill(dp[i], Integer.MAX_VALUE);
        }
        for (int k1 = 1; k1 <= k; k1++) {
            for (int n1 = 0; n1 <= n; n1++) {
                if (k1 == 1) {
                    dp[k1][n1] = (n1 + 1) / 2;
                } else {
                    for (int i = 1; i * i <= n1; i++) {
                        int i1 = i;
                        if (n1 % i1 == 0) {
                            dp[k1][n1] = Math.min(dp[k1][n1], dp[k1 - 1][n1 / i1] * (i1 + 1) / 2);
                        }
                        i1 = n / i;
                        if (n1 % i1 == 0) {
                            dp[k1][n1] = Math.min(dp[k1][n1], dp[k1 - 1][n1 / i1] * (i1 + 1) / 2);
                        }
                    }
                }
            }
        }
        out.println(dp[k][n]);
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
        new Green1().run();
    }

}
