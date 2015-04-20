import java.util.*;
import java.io.*;

class virus_as {
    FastScanner in;
    PrintWriter out;

    boolean[][] a;
    boolean[][] u;

    int[] x;
    int[] y;

    int h;
    int w;
    int m;
    int n;

    int ans;
    int[] dx = {-1, 0, 1, 0};
    int[] dy = { 0, 1, 0, -1};

    void print(boolean[][] a) {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                out.print(a[i][j] ? "*" : ".");
            }
            out.println();
        }
        out.println();
    }

    int cnt;

    class F implements Comparable<F> {
        boolean[][] a;

        F(boolean[][] a) {
            this.a = new boolean[h][];
            for (int i = 0; i < h; i++) {
                this.a[i] = a[i].clone();
            }
        }

        public int compareTo(F o) {
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (a[i][j] && !o.a[i][j]) {
                        return 1;
                    }
                    if (!a[i][j] && o.a[i][j]) {
                        return -1;
                    }
                }
            }
            return 0;
        }
    }

    TreeSet<F> all = new TreeSet<F>();

    int[] xstack;
    int[] ystack;

    void bt(int p, int from) {
        if (p == m) {
            ans++;
//            all.add(new F(a));
            return;
        }

        int sp = from;

        for (int i = 0; i < n + p; i++) {
            for (int k = 0; k < 4; k++) {
                int nx = x[i] + dx[k];
                int ny = y[i] + dy[k];
                if (0 <= nx && nx < h && 0 <= ny && ny < w && !a[nx][ny] && !u[nx][ny]) {
                    u[nx][ny] = true;
                    a[nx][ny] = true;
                    x[n + p] = nx;
                    y[n + p] = ny;
                    xstack[sp] = nx;
                    ystack[sp] = ny;
                    sp++;
                    bt(p + 1, sp);
                    a[nx][ny] = false;
                }
            }
        }

        while (sp > from) {
            sp--;
            int nx = xstack[sp];
            int ny = ystack[sp];
            u[nx][ny] = false;
        }
    }

    public void solve() throws IOException {
        h = in.nextInt();
        w = in.nextInt();
        m = in.nextInt();

        a = new boolean[h][w];
        n = 0;
        for (int i = 0; i < h; i++) {
            String s = in.next();
            for (int j = 0; j < w; j++) {
                a[i][j] = s.charAt(j) == '*';
                if (a[i][j]) {
                    n++;
                }
            }
        }
        x = new int[n + m];
        y = new int[n + m];
        n = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (a[i][j]) {
                    x[n] = i;
                    y[n] = j;
                    n++;
                }
            }
        }

        u = new boolean[h][w];
        xstack = new int[h * w * m];
        ystack = new int[h * w * m];
        ans = 0;
        bt(0, 0);

        out.println(ans);

        for (F x : all) {
            print(x.a);
        }
    }

    public void run() {
        try {
            in = new FastScanner(new File("virus.in"));
            out = new PrintWriter(new File("virus.out"));

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }

    public static void main(String[] arg) {
        new virus_as().run();
    }
}