import java.io.*;
import java.util.*;

public class Main {
    private static final int PREV = 0, NEXT = 1;
    private static final long INF = Long.MAX_VALUE;

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
        long C = in.nextInt(), D = in.nextInt();
        long[][] dp = new long[2][k];
        int a = in.nextInt(), b = in.nextInt();
        for (int i = 0; i < k - 1; i++) {
            dp[NEXT][i] = INF;
        }
        dp[NEXT][k - 1] = D * (b - a);
        int prevB;
        for (int i = 1; i < n; ++i) {
            System.arraycopy(dp[NEXT], 0, dp[PREV], 0, k);
            prevB = b;
            a = in.nextInt(); b = in.nextInt();
            for (int j = 0; j < k - 1; ++j) {
                dp[NEXT][j] = dp[PREV][j + 1];
                if (dp[PREV][j] < INF) {
                    long trial = dp[PREV][j] + D * (a - prevB);
                    if (trial < dp[NEXT][j]) {
                        dp[NEXT][j] = trial;
                    }
                }
                if (dp[NEXT][j] < INF) {
                    dp[NEXT][j] += D * (b - a);
                }
            }
            dp[NEXT][k - 1] = (dp[PREV][0] < INF) ? dp[PREV][0] + C : INF;
            if (dp[PREV][k - 1] < INF) {
                long trial = dp[PREV][k - 1] + D * (a - prevB);
                if (trial < dp[NEXT][k - 1]) {
                    dp[NEXT][k - 1] = trial;
                }
            }
            if (dp[NEXT][k - 1] < INF) {
                dp[NEXT][k - 1] += D * (b - a);
            }
        }

       long min = INF;
        for (long val : dp[NEXT]) {
            if (val < min) {
                min = val;
            }
        }
        out.println(min);

        out.flush();
    }
}
