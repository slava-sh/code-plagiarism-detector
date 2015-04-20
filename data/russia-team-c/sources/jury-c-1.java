import java.io.*;
import java.util.*;

public class dwarfs_bm {
    FastScanner in;
    PrintWriter out;

    ArrayList<Integer>[] g;
    int[] parent;
    
    void go(int v, int p) {
        parent[v] = p;
        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v].get(i);
            if (to == parent[v])
                continue;
            go(to, v);
        }
    }
    int[] ans1;
    int[] ans2;
    boolean[] onWay;
    int v2;
    
    int goAns(int v) {
        int res = 0;
        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v].get(i);
            if (to == parent[v])
                continue;
            int r2 = goAns(to);
            if (!onWay[to])
                res = Math.max(1 + r2, res);
        }
        ans2[v] = res;
        return res;
    }
    
    void goAns2(int v, int h) {
        if (v == v2)
            return;
        ans1[v] = Math.max(ans2[v] + h, ans1[parent[v]]);
        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v].get(i);
            if (to == parent[v])
                continue;
            goAns2(to, h + 1);
        }
    }
    
    void solve() {
        int n = in.nextInt();
        g = new ArrayList[n];
        for (int i = 0; i < n; i++)
            g[i] = new ArrayList<>();
        for (int i = 0; i < n - 1; i ++) {
            int fr = in.nextInt() - 1;
            int to = in.nextInt() - 1;
            g[fr].add(to);
            g[to].add(fr);
        }
        int v1 = in.nextInt() - 1;
        v2 = in.nextInt() - 1;
        parent = new int[n];
        go(v1, v1);
        int ans = 0;
        ans1 = new int[n];
        ans2 = new int[n];
        onWay = new boolean[n];
        int tmp = v2;
        while (v2 != v1) {
            onWay[v2] = true;
            v2 = parent[v2];
        }
        v2 = tmp;
        goAns(v1);
        goAns2(v1, 0);
        int h = 0;
        while (v2 != v1) {
            ans = Math.max(ans, Math.min(ans1[parent[v2]], ans2[v2] + h));
            h++;
            v2 = parent[v2];
        }
        out.println(1 + ans);
    }

    void run() {
        try {
            in = new FastScanner(new File("dwarfs.in"));
            out = new PrintWriter(new File("dwarfs.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() {

        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

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

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) {
        new dwarfs_bm().run();
    }
}