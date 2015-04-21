import java.util.*;
import java.lang.*;
import java.io.*;

public class Blue1 {

    StringTokenizer in;
    BufferedReader br;
    PrintWriter out;
    String s;
    long[] hash;
    long[] pp;
    int n;
    final int p = 239;
    final int MOD = 1000000007;

    long h(int L, int R) {
        return ((hash[R] - hash[L] * pp[R - L]) % MOD + MOD) % MOD;
    }

    public void solve() throws IOException {
        int L = nextInt();
        s = nextToken();
        n = s.length();
        pp = new long[n + 1];
        pp[0] = 1;
        hash = new long[n + 1];
        hash[0] = 0;
        for (int i = 0; i < n; i++) {
            pp[i + 1] = (pp[i] * p) % MOD;
            hash[i + 1] = (hash[i] * p + ((int) s.charAt(i))) % MOD;
        }
        for (int i = 1; i <= L; i++) {
            if (n % i == 0) {
                long h1 = h(0, i);
                boolean flag = true;
                for (int j = 0; j < n; j += i) {
                    if (h(j, j + i) != h1) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    out.println(1);
                    out.println(s.substring(0, i));
                    return;
                }
            }
        }
        out.println(2);
        out.println("a");
        out.println("b");
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
        new Blue1().run();
    }

}
