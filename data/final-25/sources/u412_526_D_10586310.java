//package codeforces;

import java.io.BufferedReader;
import java.io.Closeable;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class D implements Closeable {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter writer = new PrintWriter(System.out);
    StringTokenizer stringTokenizer;

    String next() throws IOException {
        while (stringTokenizer == null || !stringTokenizer.hasMoreTokens()) {
            stringTokenizer = new StringTokenizer(reader.readLine());
        }
        return stringTokenizer.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    private double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    int MOD = 1000 * 1000 * 1000 + 7;

    int sum(int a, int b) {
        a += b;
        return a >= MOD ? a - MOD : a;
    }

    int product(int a, int b) {
        return (int) (1l * a * b % MOD);
    }

    @SuppressWarnings("unchecked")
    void solve() throws IOException {
        int n = nextInt(), f = nextInt();
        char[] s = next().toCharArray();
//        brute(s, f);
        int[] p = new int[n + 1];
        int k = 0;
        for (int i = 2; i <= n; i++) {
            while (k > 0 && s[k] != s[i - 1]) {
                k = p[k];
            }
            if (s[k] == s[i - 1]) k++;
            p[i] = k;
        }
        k = f;
        boolean[] good = new boolean[n + 1];
        for (int i = 0; i < k && i * (k + 1) <= n; i++) {
            for (int j = i * (k + 1); j < good.length; j += k) {
                good[j] = true;
            }
        }
        boolean[] good2 = new boolean[n + 1];
        for (int i = 1; i <= n; i++) {
            int period = i / k;
            if (i - period * k < period) {
                good2[i] = true;
            }
        }
        for (int i = 1; i <= n; i++) {
            int l = i - p[i];
            int full = i / l;
            boolean tail = i % l != 0;
            boolean ok = false;
            if (tail) {
                ok = good2[full];
            } else {
                ok = good[full];
            }
            writer.print((ok ? 1 : 0));
        }
    }

    void brute(char[] s, int k) {
        int[] answer = new int[s.length + 1];
        for (int i = 1; i <= s.length; i++) {
            for (int a = 0; a <= i; a++) {
                for (int b = 0; b <= i; b++) {
                    if (a * (k + 1) + b * k != i) {
                        continue;
                    }
                    int p = a + b;
                    boolean ok = true;
                    for (int j = 0; j + p < i; j++) {
                        if (s[j] != s[j + p]) {
                            ok = false;
                        }
                    }
                    if (ok) {
                        answer[i] = 1;
                    }
                }
            }
        }
        for (int i = 1; i < answer.length; i++) {
            writer.print(answer[i]);
        }
        writer.println();
    }

    public static void main(String[] args) throws IOException, InterruptedException {
        try (D d = new D()) {
            d.solve();
        }
    }

    @Override
    public void close() throws IOException {
        reader.close();
        writer.close();
    }
}