import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class TaskD {
    private FastScanner in;
    private PrintWriter out;

    public void solve() throws IOException {
        int n = in.nextInt(), k = in.nextInt();
        String s = in.next();
        if (k == 1) {
            for (int i = 0; i < n; i++) {
                out.print(1);
            }
            return;
        }
        int[] z = buildZ(s.toCharArray());

        int[] startEvent = new int[n];
        int[] endEvent = new int[n];

        for (int l = 1; l <= n; l++) {
            if (l * k > n) {
                break;
            }
            if (l + z[l] >= k * l) {
                startEvent[k * l - 1]++;
                int end = Math.min((k + 1) * l - 1, l + z[l] - 1);
                endEvent[end]++;
            }
        }
        int bal = 0;
        for (int i = 0; i < n; i++) {
            bal += startEvent[i];
            out.print(bal > 0 ? 1 : 0);
            bal -= endEvent[i];
        }
    }

    public int[] buildZ(char[] s) {
        int n = s.length;
        int[] z = new int[n];

        for (int i = 1, l = 0, r = 0; i < n; ++i) {
            if (i <= r)
                z[i] = Math.min(r - i + 1, z[i - l]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                ++z[i];
            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }
        return z;
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
        new TaskD().run();
    }
}