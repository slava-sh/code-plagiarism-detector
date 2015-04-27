import java.io.*;
import java.util.*;

public class D {

    int[] prefixFunction(char[] s, int n) {
        int[] p = new int[n];
        p[0] = 0;
        for (int i = 1; i < n; i++) {
            int j = p[i - 1];
            while (j > 0 && s[i] != s[j]) {
                j = p[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            p[i] = j;
        }
        return p;
    }

    int[] zFunction(char[] s, int n) {
        int[] z = new int[n];
        int l = 0;
        int r = 0;
        for (int i = 1; i < n; i++) {
            if (i <= r) {
                z[i] = Math.min(r - i + 1, z[i - l]);
            }
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }
        return z;
    }

    public void solve() throws IOException {
        int n = in.nextInt();
        int k = in.nextInt();
        char[] s = in.nextToken().toCharArray();
        int[] p = prefixFunction(s, n);
        boolean[] ans = new boolean[n];
        int last = -1;
        for (int i = 0; i < n; i++) {
            if ((i + 1) % k != 0) continue;
            int ab = (i + 1) / k;
            int per = i + 1 - p[i];
            if (ab % per != 0) continue;
            ans[i] = true;
            for (int j = Math.max(last + 1, i + 1); j < n && j - i <= ab && s[j] == s[j - i - 1]; j++) {
                ans[j] = true;
                last = j;
            }
        }
//        for (int l = k; l <= n; l++) {
//            if (l % (k + 1) == 0) {
//                int per = l - p[l - 1];
//                if ((l / (k + 1)) % per == 0) {
//                    ans[l] = true;
//                    continue;
//                }
//            }
//            if (l % k == 0) {
//                int per = l - p[l - 1];
//                if ((l / k) % per == 0) {
//                    ans[l] = true;
//                    continue;
//                }
//            }
//            for (int ab = l / (k + 1) + 1; ab <= l / k; ++ab) {
//                int a = l - ab * k;
//                if (p[l - 1] < a) continue;
//                int per = ab * k - p[ab * k - 1];
//                if (ab % per != 0) continue;
//                ans[l] = true;
//                break;
//            }
//        }
        for (int i = 0; i < n; i++) {
            out.print(ans[i] ? 1 : 0);
        }
        out.println();
    }

    static FastReader in;
    static PrintWriter out;
    static PrintStream err;

    public static void main(String[] args) throws IOException {
        try {
            in = new FastReader();
            out = new PrintWriter(System.out);
            err = System.err;
            new D().solve();
            out.close();
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
    }
}

class FastReader {
    BufferedReader br;
    StringTokenizer in;

    FastReader() {
        this.br = new BufferedReader(new InputStreamReader(System.in));
    }

    FastReader(String filename) {
        try {
            this.br = new BufferedReader(new FileReader(filename));
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    public String nextToken() throws IOException {
        while (in == null || !in.hasMoreTokens()) {
            in = new StringTokenizer(br.readLine());
        }
        return in.nextToken();
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    public double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    public long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }
}