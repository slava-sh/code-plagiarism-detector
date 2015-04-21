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

        long n = in.nextLong();
        int k = in.nextInt();
        if (k == 3) out.println(2);
        else if (k == 2) {
            long minAns = Long.MAX_VALUE;
            for (long i = 1; i * i <= n; i++) {
                if (n % i == 0) {
                    long trialAns = E(n / i) * E(i);
                    if (trialAns < minAns) {
                        minAns = trialAns;
                    }
                }
            }
            out.println(minAns);
        }
        else if (k == 1) {
            out.println(E(n));
        }

        out.flush();
    }

    private static long E(long n) {
        return (n >> 1) + (n & 1);
    }
}
