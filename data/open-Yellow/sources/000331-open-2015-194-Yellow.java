import java.util.*;
import java.lang.*;
import java.io.*;

public class Yellow1 {

    StringTokenizer in;
    BufferedReader br;
    PrintWriter out;

    public void solve() throws IOException {
        int n = nextInt();
        int[] t = new int[n];
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            t[i] = nextInt();
            if (i == 0 || t[i] != t[i - 1]) {
                cnt++;
            }
        }

        int q = nextInt();
        for (int i = 0; i < q; i++) {
            int p = nextInt() - 1;
            int c = nextInt();
            if (p != 0) {
                if (t[p - 1] == t[p] && t[p - 1] != c) {
                    cnt++;
                } else if (t[p - 1] != t[p] && t[p - 1] == c) {
                    cnt--;
                }
            }
            if (p != n - 1) {
                if (t[p + 1] == t[p] && t[p + 1] != c) {
                    cnt++;
                } else if (t[p + 1] != t[p] && t[p + 1] == c) {
                    cnt--;
                }
            }
            t[p] = c;
            out.println(cnt);
        }
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
        new Yellow1().run();
    }

}
