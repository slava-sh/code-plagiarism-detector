import java.util.*;
import java.io.*;

public class TaskC {
    private FastScanner in;
    private PrintWriter out;

    public void solve() throws IOException {
        int tests = in.nextInt();
        for (int t = 0; t < tests; t++) {
            int m = in.nextInt() - 1, k = in.nextInt();
            int[] data = new int[k];
            for (int i = 0; i < k; i++) {
                data[i] = in.nextInt();
            }
            int firstFail = m;
            int[] a = new int[m];
            int[] b = new int[m];
            for (int i = 0; i < m; i++) {
                a[i] = in.nextInt() - 1;
                b[i] = in.nextInt();
                if (firstFail == m && b[i] == 1) {
                    firstFail = i;
                }
            }
            int numZeroBefore = 0;
            int numZeroAfter = 0;
            boolean[] canEmptyAtFirstReject = new boolean[k];
            boolean[] result = new boolean[k];

            Arrays.fill(canEmptyAtFirstReject, true);

            for (int i = 0; i < firstFail; i++) {
                if (a[i] != -1) {
                    data[a[i]]--;
                } else {
                    numZeroBefore++;
                }
            }
            for (int i = firstFail; i < m; i++) {
                if (a[i] != -1) {
                    data[a[i]]--;
                    canEmptyAtFirstReject[a[i]] = false;
                } else {
                    numZeroAfter++;
                }
            }
            for (int i = 0; i < k; i++) {
                if (data[i] == 0) {
                    result[i] = true;
                }
            }

            if (firstFail != m) {
                int minRemToEmpty = Integer.MAX_VALUE;
                for (int i = 0; i < k; i++) {
                    if (canEmptyAtFirstReject[i]) {
                        minRemToEmpty = Math.min(minRemToEmpty, data[i]);
                    }
                }
                for (int i = 0; i < k; i++) {
                    if ((numZeroBefore >= data[i] && canEmptyAtFirstReject[i]) || (numZeroBefore + numZeroAfter - minRemToEmpty >= data[i])) {
                        result[i] = true;
                    }
                }
            } else {
                for (int i = 0; i < k; i++) {
                    if (numZeroBefore >= data[i]) {
                        result[i] = true;
                    }
                }
            }


            for (int i = 0; i < k; i++) {
                out.print(result[i] ? "Y" : "N");
            }
            out.println();
        }
    }

    public void run() {
        try {
            in = new FastScanner();
            out = new PrintWriter(System.out);
            solve();
            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private class FastScanner {
        private BufferedReader br;
        private StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

    }

    public static void main(String[] arg) {
        new TaskC().run();
    }
}