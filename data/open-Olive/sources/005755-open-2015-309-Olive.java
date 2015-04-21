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

        int n = in.nextInt();
        int[] A = new int[n];
        for (int i = 0; i < n; i++) {
            A[i] = in.nextInt() - 1;
        }
        int max = 0, left = -2, right = -2;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; ++j) {
                if (A[j] > A[i]) continue;
                int count = 1;
                for (int k = i + 1; k < j; ++k) {
                    if (A[k] > A[j] && A[k] < A[i]) {
                        ++count;
                    }
                }
                if (count > max) {
                    max = count;
                    left = i;
                    right = j;
                }
            }
        }
        ++left; ++right;
        out.println(left + " " + right);

        out.flush();
    }
}
