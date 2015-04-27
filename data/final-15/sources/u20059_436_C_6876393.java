import java.util.*;
import java.io.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;

public class Solution implements Runnable {

    final int INF = Integer.MAX_VALUE / 3;

    public void solve() throws Exception {
        int n = sc.nextInt(), m = sc.nextInt(), k = sc.nextInt(), w = sc.nextInt();
        char[][][] levels = new char[k][n][];
        for (int i = 0; i < k; i++) {
            for (int ii = 0; ii < n; ii++) {
                levels[i][ii] = in.readLine().toCharArray();
            }
        }
        int[][] graph = new int[k + 1][k + 1];
        for (int i = 0; i < k; i++) {
            Arrays.fill(graph[i], INF);
        }
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                graph[i][j] = 0;
                for (int ii = 0; ii < n; ii++) {
                    for (int jj = 0; jj < m; jj++) {
                        if (levels[i][ii][jj] != levels[j][ii][jj]) {
                            graph[i][j] += w;
                        }
                    }
                }
            }
            graph[i][k] = graph[k][i] = n * m;
        }
        int[] d = new int[k + 1];
        boolean[] used = new boolean[k + 1];
        int[] from = new int[k + 1];
        Arrays.fill(d, INF);
        d[k] = 0;
        Arrays.fill(from, -1);
        long ans = 0;
        ArrayList<String> lines = new ArrayList<>();
        for (int it = 0; it <= k; it++) {
            int mind = -1;
            for (int i = 0; i <= k; i++) {
                if (!used[i] && (mind == -1 || d[i] < d[mind])) {
                    mind = i;
                }
            }
            used[mind] = true;
            ans += d[mind];
            if (mind != k) {
                lines.add((mind + 1) + " " + (from[mind] == k ? 0 : from[mind] + 1));
            }
            for (int i = 0; i <= k; i++) {
                if (!used[i]) {
                    if (graph[mind][i] < d[i]) {
                        d[i] = min(d[i], graph[mind][i]);
                        from[i] = mind;
                    }
                }
            }
        }
        out.println(ans);
        for (String str : lines) {
            out.println(str);
        }
    }

    static Throwable uncaught;

    BufferedReader in;
    FastScanner sc;
    PrintWriter out;

    @Override
    public void run() {
        try {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
            sc = new FastScanner(in);
            solve();
        } catch (Throwable uncaught) {
            Solution.uncaught = uncaught;
        } finally {
            out.close();
        }
    }

    public static void main(String[] args) throws Throwable {
        Thread thread = new Thread(null, new Solution(), "", (1 << 26));
        thread.start();
        thread.join();
        if (Solution.uncaught != null) {
            throw Solution.uncaught;
        }
    }

}

class FastScanner {

    BufferedReader in;
    StringTokenizer st;

    public FastScanner(BufferedReader in) {
        this.in = in;
    }

    public String nextToken() throws Exception {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(in.readLine());
        }
        return st.nextToken();
    }

    public int nextInt() throws Exception {
        return Integer.parseInt(nextToken());
    }

    public long nextLong() throws Exception {
        return Long.parseLong(nextToken());
    }

    public double nextDouble() throws Exception {
        return Double.parseDouble(nextToken());
    }

}