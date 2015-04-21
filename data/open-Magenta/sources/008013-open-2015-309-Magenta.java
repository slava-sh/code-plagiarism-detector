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

        //int count = 1;
        outer:
        while (true) {
            int rnd = (new Random()).nextInt(4);
            switch (rnd) {
                case 0:
                    out.println("U");
                    break;

                case 1:
                    out.println("D");
                    break;

                case 2:
                    out.println("L");
                    break;

                case 3:
                    out.println("R");
                    break;
            }
            out.flush();
            char answer = in.next().charAt(0);
            if (answer == 'Y' || answer == 'E') {
                break outer;
            }
            /*char symbol = (count & 1) == 1 ? 'D' : 'U';
            for (int i = 0; i < count; i++) {
                out.println(symbol);
                out.flush();
                char answer = in.next().charAt(0);
                if (answer == 'Y' || answer == 'E') {
                    break outer;
                }
            }
            symbol = (count & 1) == 1 ? 'R' : 'L';
            for (int i = 0; i < count; i++) {
                out.println(symbol);
                out.flush();
                char answer = in.next().charAt(0);
                if (answer == 'Y' || answer == 'E') {
                    break outer;
                }
            }
            ++count;*/
        }
    }
}