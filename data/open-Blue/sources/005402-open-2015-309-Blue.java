import java.io.*;
import java.util.*;

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

        int L = in.nextInt();
        String message = in.next();
        int minSize = 3;
        String[] minAnswer = new String[]{"a", "b",  "c"};
        for (int i = 0; i <= L && i <= message.length(); ++i) {
            String x = message.substring(0, i);
            for (int j = i; j <= i + L && j <= message.length(); ++j) {
                String y = message.substring(i, j);
                String trialMessage = message.substring(j);
                boolean isOK = isConcatenable(trialMessage, x, y);
                if (isOK) {
                    int size = 2;
                    if (x.isEmpty()) --size;
                    if (y.isEmpty()) --size;
                    if (minSize > size) {
                        minSize = size;
                        minAnswer = new String[]{x, y};
                    }
                }
            }
        }

        out.println(minSize);
        for (String S : minAnswer) {
            if (!S.isEmpty()) {
                out.println(S);
            }
        }
        out.flush();
    }

    private static boolean isConcatenable(String trialMessage, String x, String y) {
        int len = trialMessage.length();
        boolean[] dp = new boolean[len + 1];
        dp[len] = true;
        for (int i = len - 1; i >= 0; --i) {
            dp[i] = false;
            if (i + x.length() <= len && trialMessage.substring(i).startsWith(x)) {
                if (dp[i + x.length()]) {
                    dp[i] = true;
                }
            }
            if (i + y.length() <= len && trialMessage.substring(i).startsWith(y)) {
                if (dp[i + y.length()]) {
                    dp[i] = true;
                }
            }
        }
        return dp[0];
    }
}
