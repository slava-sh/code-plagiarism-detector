import java.io.*;
import java.util.*;

public class Sol {
    static FastScanner scanner;
    static PrintWriter writer;

    public int mod = (int) 1e9 + 7;
    private int MUL = 239;
    private static int[] hh;
    int[] pows;

    boolean lessThan(int from1, int from2, int n) {
        int left = 0, right = n + 1;
        while (right - left > 1) {
            int m = (left + right) >> 1;
            if (getHash(from1, from1 + m - 1) == getHash(from2, from2 + m - 1)) {
                left = m;
            } else {
                right = m;
            }
        }
        return left != n && string.charAt(from1 + left) < string.charAt(from2 + left);
    }

    int getHash(int from, int to) {
        long result = hh[to + 1] - hh[from] * 1L * pows[to - from + 1];
        result %= mod;
        if (result < 0)
            result += mod;
        return (int) result;
    }

    static String string;

    void solve() {
        string = scanner.next();
        int n = string.length();
        string = string + string;
        hh = new int[string.length() + 1];
        for (int i = 0; i < string.length(); i++) {
            hh[i + 1] = (int) ((hh[i] * 1L * MUL + string.charAt(i)) % mod);
        }
        precalc(n);
        int[] bal = new int[n + n - 1];
        for (int i = 0; i < n + n - 1; i++) {
            if (string.charAt(i) == '(') {
                bal[i]++;
            } else {
                bal[i]--;
            }
            if (i > 0) {
                bal[i] += bal[i - 1];
            }
        }
        int cur = string.length() - 1;
        int[] balanceChange = new int[n];
        int[] qPos = new int[n + n];
        int[] qValue = new int[n + n];
        int qSz = 0, qFrom = 0;
        for (int pos = n - 1; pos >= 0; pos--) {
            while (cur != pos) {
                cur--;
                int value = bal[cur];
                while (qSz > qFrom && qValue[qSz - 1] >= value) {
                    qSz--;
                }
                qValue[qSz] = value;
                qPos[qSz] = cur;
                qSz++;
            }
            while (qPos[qFrom] >= pos + n) {
                qFrom++;
            }
            int prevBalance = pos > 0 ? bal[pos - 1] : 0;
            balanceChange[pos] = qValue[qFrom] - prevBalance;
        }
        int cntOpen = 0;
        cntOpen = doit(n, cntOpen);
        int maxBalanceChange = 0;
        if (cntOpen < 0) {
            maxBalanceChange = cntOpen;
        }
        int bestCandidate = -1;
        for (int i = 0; i < n; i++) {
            if (balanceChange[i] >= maxBalanceChange) {
                if (bestCandidate != -1) {
                    if (!lessThan(i, bestCandidate, n)) {
                        continue;
                    }
                }
                bestCandidate = i;
            }
        }
        if (bestCandidate < 0) {
            throw new AssertionError();
        }
        for (int i = 0; i < -cntOpen; i++) {
            writer.print("(");
        }
        for (int i = 0; i < n; i++) {
            writer.print(string.charAt(i + bestCandidate));
        }
        for (int i = 0; i < cntOpen; i++) {
            writer.print(")");
        }
    }

    private int doit(int n, int cntOpen) {
        for (int i = 0; i < n; i++) {
            if (string.charAt(i) == '(') {
                cntOpen++;
            } else {
                cntOpen--;
            }
        }
        return cntOpen;
    }

    private void precalc(int n) {
        pows = new int[n + n + 2];
        pows[0] = 1;
        for (int i = 1; i < pows.length; i++) {
            pows[i] = (int) ((pows[i - 1] * 1L * MUL) % mod);
        }
    }

    void runIO() {

        scanner = new FastScanner(System.in);
        writer = new PrintWriter(System.out);

        solve();

        writer.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }
   }

    public static void main(String[] args) {
        new Sol().runIO();
    }
}
