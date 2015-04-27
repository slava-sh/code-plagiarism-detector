import java.io.*;
import java.util.*;

public class sd3D {

    FastScanner ssdd;
    PrintWriter slsa;

    List<sls_33>[] ak__$4s;

    class sls_33 {
        int dd_s3__, xlss, ss_;

        public sls_33(int dd_s3__, int xlss, int ss_) {
            super();
            this.dd_s3__ = dd_s3__;
            this.xlss = xlss;
            this.ss_ = ss_;
        }
    }

    int[] ssda______;
    void glub(int vert, int otec) {
        __[vert] = _[vert] = ________++;
        ___[vert] = 1;

        for (sls_33 e : ak__$4s[vert]) {
            if (e.ss_ == otec) {
                continue;
            }
            if (___[e.xlss] == 0) {
                glub(e.xlss, e.ss_);
                _[vert] = Math.min(_[vert], _[e.xlss]);
            }
            if (___[e.xlss] == 1) {
                _[vert] = Math.min(_[vert], __[e.xlss]);
            }
            if (_[e.xlss] > __[vert]) {
                most[e.ss_] = true;
            }
        }

        ___[vert] = 2;
    }

    int[] __, _;

    int ________ = 0;

    int[] ___;

    boolean[] most;

    void solve() {
        int n = ssdd.nextInt(), m = ssdd.nextInt();
        ak__$4s = new List[n];
        for (int i = 0; i < n; i++) {
            ak__$4s[i] = new ArrayList<>();
        }
        int[] dg = new int[m], to = new int[m];

        for (int _ = 0; _ < m; _++) {
            dg[_] = ssdd.nextInt() - 1;
            to[_] = ssdd.nextInt() - 1;
            ak__$4s[dg[_]].add(new sls_33(dg[_], to[_], _));
            ak__$4s[to[_]].add(new sls_33(to[_], dg[_], _));
        }

        ssda______ = new int[n];
        __ = new int[n];
        _ = new int[n];
        most = new boolean[m];
        ___ = new int[n];
        glub(0, -1);

        ___ = new int[n];
        int dclaa = 0;
        Arrays.fill(___, -1);
        for (int i = 0; i < n; i++) {
            if (___[i] == -1) {
                sse2(i, dclaa++);
            }
        }

        int s = dclaa;
        nggg = new List[s];
        for (int i = 0; i < s; i++) {
            nggg[i] = new ArrayList<>();
        }

        raz = new int[s];
        for (int _ = 0; _ < n; _++) {
            raz[___[_]]++;
        }

        podd = new int[s];
        long otv = 0;

        for (int j = 0; j < s; j++) {
            otv += 1L * raz[j] * raz[j];
        }

        for (int i = 0; i < m; i++) {
            if (most[i]) {
                int c1 = ___[dg[i]], c2 = ___[to[i]];
                nggg[c1].add(c2);
                nggg[c2].add(c1);
            }
        }

        sraza(0, -1);

        int ctr = 0;
        int pp = -1;

        while (true) {
            int maximum = -1, vert = -1;
            for (int i : nggg[ctr]) {
                if (i == pp) {
                    continue;
                }

                if (podd[i] > maximum) {
                    maximum = podd[i];
                    vert = i;
                }
            }

            if (maximum > n / 2) {
                pp = ctr;
                ctr = vert;
            } else {
                break;
            }
        }

        podd = new int[s];
        sraza(ctr, -1);

        for (int v : nggg[ctr]) {
            koka(v, ctr, 0);
        }
        otv += sameSubTree;


        otv += 1L * raz[ctr] * (n - raz[ctr]);
        int summa = n - raz[ctr];
        boolean[] moget = new boolean[summa + 1];

        moget[0] = true;
        for (int i : nggg[ctr]) {
            int w = podd[i];
            for (int t = summa; t >= w; t--) {
                moget[t] |= moget[t - w];
            }
        }

        long maximum = 0;
        for (int i = 0; i <= summa; i++) {
            if (moget[i]) {
                maximum = Math.max(maximum, 1L * i * (summa - i));
            }
        }
        otv += maximum;
        slsa.println(otv);
    }

    void sse2(int u, int col) {
        ___[u] = col;
        for (sls_33 e : ak__$4s[u]) {
            if (most[e.ss_]) {
                continue;
            }
            if (___[e.xlss] == -1) {
                sse2(e.xlss, col);
            }
        }
    }

    private void koka(int u, int par, int sum) {
        sameSubTree += 1L * sum * raz[u];
        for (int v : nggg[u]) {
            if (v != par) {
                koka(v, u, sum + raz[u]);
            }
        }
    }

    long sameSubTree = 0;

    private void sraza(int u, int p) {
        podd[u] = raz[u];
        for (int v : nggg[u]) {
            if (v != p) {
                sraza(v, u);
                podd[u] += podd[v];
            }
        }
    }

    List<Integer>[] nggg;
    int[] raz;
    int[] podd;

    void run() {
        ssdd = new FastScanner();
        slsa = new PrintWriter(System.out);
        solve();
        slsa.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public FastScanner(String s) {
            try {
                br = new BufferedReader(new FileReader(s));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(nextToken());
        }

        long nextLong() {
            return Long.parseLong(nextToken());
        }

        double nextDouble() {
            return Double.parseDouble(nextToken());
        }
    }

    public static void main(String[] args) {
        new sd3D().run();
    }
}
