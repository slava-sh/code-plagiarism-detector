import java.util.*;
import java.io.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;

public class Solution implements Runnable {

    public void solve() throws Exception {
        int n = sc.nextInt(), m = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = i;
        }
        Treap t = Treap.build(arr, 0, n - 1);
        int[] val = new int[n];
        boolean[] used = new boolean[n + 2];
        Arrays.fill(val, -1);
        for (int i = 0; i < m; i++) {
            int x = sc.nextInt(), y = sc.nextInt() - 1;
            //int x = n - i;
            //int y = n - 1;
            Treap[] lc_r = Treap.split(t, y + 1, 0);
            Treap[] l_c = Treap.split(lc_r[0], y, 0);
            if (Treap.getSize(l_c[1]) != 1) {
                throw new Exception();
            }
            int pos = l_c[1].val;
            if (val[pos] == -1) {
                if (used[x]) {
                    out.println(-1);
                    return;
                }
                val[pos] = x;
                used[x] = true;
            } else if (val[pos] != x) {
                out.println(-1);
                return;
            }
            t = Treap.merge(Treap.merge(l_c[1], l_c[0]), lc_r[1]);
        }
        int curval = 1;
        for (int i = 0; i < n; i++) {
            if (val[i] == -1) {
                while (used[curval]) {
                    curval++;
                }
                val[i] = curval;
                used[curval] = true;
            }
            out.print(val[i] + " ");
        }
        out.println();
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

class Treap {
    
    static Random rnd = new Random();
    
    int val;
    Treap l, r;
    int sz;
    int prior = rnd.nextInt();
    
    public Treap(int val) {
        this.val = val;
        sz = 1;
    }
    
    public Treap(Treap t) {
        this.val = t.val;
        this.l = t.l;
        this.r = t.r;
        this.sz = t.sz;
    }
    
    static int getSize(Treap t) {
        if (t == null) {
            return 0;
        } else {
            return t.sz;
        }
    }
    
    static void updateSize(Treap t) {
        if (t != null) {
            t.sz = getSize(t.l) + getSize(t.r) + 1; 
        }
    }
    
    static Treap[] split(Treap t, int key, int add) {
        if (t == null) {
            return new Treap[] { null, null };
        } else {
            int curkey = add + getSize(t.l);
            if (key <= curkey) {
                Treap[] lresult = split(t.l, key, add);
                //Treap newt = new Treap(t);
                Treap newt = t;
                newt.l = lresult[1];
                updateSize(newt);
                lresult[1] = newt;
                return lresult;
            } else {
                Treap[] rresult = split(t.r, key, add + getSize(t.l) + 1);
                //Treap newt = new Treap(t);
                Treap newt = t;
                newt.r = rresult[0];
                updateSize(newt);
                rresult[0] = newt;
                return rresult;
            }
        }
    }
    
    static Treap merge(Treap t1, Treap t2) {
        if (t1 == null) {
            return t2;
        } else if (t2 == null) {
            return t1;
        } else {
            if (t1.prior < t2.prior) {
                //Treap result = new Treap(t1);
                Treap result = t1;
                result.r = merge(result.r, t2);
                updateSize(result);
                return result;
            } else {
                //Treap result = new Treap(t2);
                Treap result = t2;
                result.l = merge(t1, result.l);
                updateSize(result);
                return result;
            }
        }
    }
    
    static Treap multiply(Treap t, int n) {
        Treap result = null;
        while (n > 0) {
            if (n % 2 == 1) {
                result = merge(result, t);
            }
            t = merge(t, t);
            n /= 2;
        }
        return result;
    }
    
    static Treap build(int[] arr, int l, int r) {
        if (r == l) {
            return new Treap(arr[l]);
        } else {
            int m = (l + r) / 2;
            return merge(build(arr, l, m), build(arr, m + 1, r));
        }
    }
        
    static void myToString(Treap t, StringBuilder sb) {
        if (t != null) {
            if (t.l != null) {
                myToString(t.l, sb);
                sb.append(' ');
            }
            sb.append(t.val);
            if (t.r != null) {
                sb.append(' ');
                myToString(t.r, sb);
            }
        }
    }
    
}