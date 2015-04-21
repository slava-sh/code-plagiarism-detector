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
            return Integer.parseInt(next());
        }
    }

    public static void main(String[] args) {
	    FastReader in = new FastReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        long n = in.nextLong();
        int k = in.nextInt();
        if (k == 2) out.println(4);
        else if (k == 3) out.println(2);
        else out.println((n >> 1) + (n & 1));

        out.flush();
    }
}
