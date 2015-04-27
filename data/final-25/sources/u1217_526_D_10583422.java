import java.util.*;
import java.io.*;

import static java.lang.Math.*;

public class D {
    int[] z;
    int[] d;
    int n, k;

    int rmqSlow(int from, int to) {
        int max = -1;
        for (int x = from; x <= to; x++) {
            if (z[x] + x > max) {
                max = z[x] + x;
            }
        }
        return max;
    }

    void init(int p, int L, int R) {
        if (L == R - 1) {
            d[p] = z[L] + L;
            return;
        }
        int M = (L + R) / 2;
        init(2 * p + 1, L, M);
        init(2 * p + 2, M, R);
        d[p] = max(d[2 * p + 1], d[2 * p + 2]);
    }

    int rmq(int p, int L, int R, int a, int b) {
        if (b <= L || R <= a) {
            return Integer.MIN_VALUE;
        }
        if (a <= L && R <= b) {
            return d[p];
        }
        int M = (L + R) / 2;
        return max(rmq(2 * p + 1, L, M, a, b), rmq(2 * p + 2, M, R, a, b));
    }

    String solve(char[] s) {
        z = new int[n + 1];

        for (int i = 1, l = 0, r = 1; i < n; i++, r = i < r ? r : i) {
            for (z[i] = r - i < z[i - l] ? r - i : z[i - l]; s[i + z[i]] == s[z[i]]; z[i]++, r = i + z[i], l = i) ;
        }

        d = new int[4 * n];
        init(0, 0, n + 1);

        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < n; i++) {
            int len = i + 1;
            int minLen = (len + k) / (k + 1);
            int maxLen = len / k;
//            System.out.println(minLen + " " + maxLen);
            int maxVal = rmq(0, 0, n + 1, minLen, maxLen + 1);
//            System.out.println(maxVal);
            if (maxVal >= len) {
                ans.append('1');
            } else {
                ans.append('0');
            }
        }

        return ans.toString();
    }

    String solveSlow(char[] c) {
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < n; i++) {
            String need = new String(Arrays.copyOfRange(c, 0, i + 1));
            boolean good = false;
            search:
            for (int alen = 0; alen <= i + 1; alen++) {
                for (int blen = 0; blen <= i + 1; blen++) {
                    if (alen * (k + 1) + blen * k > i + 1) {
                        continue;
                    }
                    String a = new String(Arrays.copyOfRange(c, 0, alen));
                    String b = new String(Arrays.copyOfRange(c, alen, alen + blen));
                    StringBuilder res = new StringBuilder();
                    for (int j = 0; j < 2 * k + 1; j++) {
                        if (j % 2 == 0) {
                            res.append(a);
                        } else {
                            res.append(b);
                        }
                    }
                    if (res.toString().equals(need)) {
                        good = true;
                        break search;
                    }
                }
            }
            if (good) {
                ans.append('1');
            } else {
                ans.append('0');
            }
        }
        return ans.toString();
    }

    public void run() throws IOException {
        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        n = in.nextInt();
        k = in.nextInt();
        char[] s = (in.next() + "$").toCharArray();

        out.println(solve(s));
//        out.println(solveSlow(s));

        out.close();
    }

    void stress() {
        Random rnd = new Random(2348972497L);
        int cnt = 0;
        while (true) {
            n = rnd.nextInt(100) + 1;
            k = rnd.nextInt(5) + 1;
            char[] c = new char[n + 1];
            c[n] = '$';
            for (int i = 0; i < n; i++) {
                c[i] = (char) ('a' + rnd.nextInt(2));
            }
            String slow = solveSlow(c);
            String smart = solve(c);
            if (!slow.equals(smart)) {
                System.out.println(n + " " + k + " " + new String(c) + " " + slow + " " + smart);
                break;
            }
            System.out.println(cnt++);
        }
    }

    FastScanner in;
    PrintWriter out;

    public static void main(String[] args) throws IOException {
        new D().run();
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(InputStream in) throws IOException {
            br = new BufferedReader(new InputStreamReader(in));
        }

        String next() {
            try {
                while (st == null || !st.hasMoreTokens()) {
                    st = new StringTokenizer(br.readLine());
                }
            } catch (IOException e) {
                System.err.println(e);
                System.exit(1);
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }
}