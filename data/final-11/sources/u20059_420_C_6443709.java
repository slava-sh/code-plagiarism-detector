import java.util.*;
import java.io.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;

public class Solution implements Runnable {
    
    class FenwickTree {
        
        int n;
        int[] t;
        
        public FenwickTree(int n) {
            this.n = n;
            t = new int[n];
        }
        
        int get(int r) {
            int ans = 0;
            while (r >= 0) {
                ans += t[r];
                r = (r & (r + 1)) - 1;
            }
            return ans;
        }
        
        int get(int l, int r) {
            return get(r) - get(l - 1);
        }
        
        void add(int pos, int val) {
            while (pos < n) {
                t[pos] += val;
                pos = pos | (pos + 1);
            }
        }
    }


    public void solve() throws Exception {
        int n = sc.nextInt(), p = sc.nextInt();
        ArrayList<Integer>[] g = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < n; i++) {
            int x = sc.nextInt() - 1, y = sc.nextInt() - 1;
            g[x].add(y);
            g[y].add(x);
        }
        
        int[] deg = new int[n];
        FenwickTree t = new FenwickTree(n + 1);
        for (int i = 0; i < n; i++) {
            deg[i] = g[i].size();
            t.add(deg[i], 1);
        }
        long ans = 0;
        for (int i = 0; i < n; i++) {
            int val = deg[i];
            for (int e : g[i]) {
                t.add(deg[i], -1);
                t.add(deg[e], -1);
                deg[i]--;
                deg[e]--;
                t.add(deg[i], 1);
                t.add(deg[e], 1);
            }
            t.add(deg[i], -1);
            ans += t.get(max(0, p - val), n);
            t.add(deg[i], 1);
            for (int e : g[i]) {
                t.add(deg[i], -1);
                t.add(deg[e], -1);
                deg[i]++;
                deg[e]++;
                t.add(deg[i], 1);
                t.add(deg[e], 1);
            }
        }
        out.println(ans / 2);
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