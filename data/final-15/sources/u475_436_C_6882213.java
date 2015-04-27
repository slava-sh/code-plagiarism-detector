import java.io.*;
import java.util.*;

public class Main implements Runnable {
    BufferedReader in;
    PrintWriter out;
    StringTokenizer st;

    String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(in.readLine());
        }
        return st.nextToken();
    }
    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }
    long nextLong() throws IOException{
        return Long.parseLong(nextToken());
    }

    class Edge {
        int b, e, w;
        boolean isTree = false;
        Edge(int q, int qq, int qqq) {
            b = q; e = qq; w = qqq;
        }
    }

    class Dsu {
        int n;
        int[] dsu;
        int[] rnk;
        Dsu(int q) {
            n = q;
            dsu = new int[n];
            rnk = new int[n];
            for (int i = 0; i < n; i++) dsu[i] = i;
        }
        int get(int q) {
            if (q == dsu[q]) return q;
            return dsu[q] = get(dsu[q]);
        }
        boolean uni(int q, int w) {
            q = get(q); w = get(w);
            if (q == w) return false;
            if (rnk[q] == rnk[w]) rnk[q]++;
            if (rnk[q] > rnk[w]) {
                dsu[w] = q;
            } else {
                dsu[q] = w;
            }
            return true;
        }
    }

    int diff(String a, String b) {
        int res = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) != b.charAt(i)) res++;
        }
        return res;
    }

    ArrayList<Edge>[] v;

    void dfs(int q, int w) {
        if (w != -1) out.println(q + " " + w);
        for (Edge r : v[q]) {
            if (r.e != w) dfs(r.e, q);
        }
    }

    void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int k = nextInt();
        int w = nextInt();
        String[] s = new String[k + 1];
        for (int q = 1; q <= k; q++) {
            StringBuilder sb = new StringBuilder("");
            for (int i = 0; i < n; i++) {
                sb.append(nextToken());
            }
            s[q] = sb.toString();
        }
        Edge[] r = new Edge[k + k * k];
        int rl = 0;
        for (int i = 1; i <= k; i++) {
            r[rl++] = new Edge(0, i, n * m);
            for (int j = i + 1; j <= k; j++) {
                r[rl++] = new Edge(i, j, diff(s[i], s[j]) * w);
            }
        }
        Arrays.sort(r, 0, rl, (a, b) -> a.w - b.w);
        Dsu dsu = new Dsu(k + 1);
        int ans = 0;
        v = new ArrayList[k + 1];
        for (int i = 0; i <= k; i++) v[i] = new ArrayList<>();
        for (int i = 0; i < rl; i++) {
            if (dsu.uni(r[i].b, r[i].e)) {
                r[i].isTree = true;
                ans += r[i].w;
                v[r[i].b].add(r[i]);
                v[r[i].e].add(new Edge(r[i].e, r[i].b, r[i].w));
            }
        }
        out.println(ans);
        dfs(0, -1);
    }

    public void run() {
        try {
//            in = new BufferedReader(new FileReader("input.txt"));
//            out = new PrintWriter("output.txt");
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
            Locale.setDefault(Locale.UK);
            solve();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        } finally {
            out.close();
        }
    }

    public static void main(String Args[]) {
        new Thread(null, new Main(), "1", 1 << 28).start();
    }
}