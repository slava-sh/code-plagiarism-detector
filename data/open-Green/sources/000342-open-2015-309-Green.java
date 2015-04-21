import java.io.*;
import java.util.StringTokenizer;

public class Main {
    private static class FastReader {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        public FastReader(InputStream inputStream) {
            reader = new BufferedReader(new InputStreamReader(inputStream), 1 << 16);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                }
                catch (IOException ex) {
                    throw new RuntimeException(ex);
                }
            }
            return tokenizer.nextToken();
        }

        public String nextLine() {
            try {
                return reader.readLine();
            }
            catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) {
	    FastReader in = new FastReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        int k = in.nextInt();
        int[][] dp = new int[k][n + 1];
        for (int i = 1; i <= n; ++i) {
            dp[0][i] = (int)E(i);
        }
        for (int i = 1; i < k; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = Integer.MAX_VALUE;
                for (int d = 1; d <= j; ++d) {
                    if (j % d == 0) {
                        int trial = dp[i - 1][j / d] * dp[0][d];
                        if (trial < dp[i][j]) {
                            dp[i][j] = trial;
                        }
                    }
                }
            }
        }
        out.println(dp[k - 1][n]);

        out.flush();
    }

    private static long E(long n) {
        return (n >> 1) + (n & 1);
    }
}
