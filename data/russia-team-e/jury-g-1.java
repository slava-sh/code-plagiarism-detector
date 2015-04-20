import java.io.*;
import java.util.*;

public class prizes_bm {
    FastScanner in;
    PrintWriter out;

    int typeRight(int type) {
        switch (type) {
        case 0:
            return 1;
        case 1:
            return 5;
        case 2:
            return 2;
        case 3:
            return 0;
        case 4:
            return 4;
        case 5:
            return 3;
        default:
            return -1;
        }
    }

    int typeUp(int type) {
        switch (type) {
        case 0:
            return 4;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 3;
        case 4:
            return 5;
        case 5:
            return 2;
        default:
            return -1;
        }
    }

    class State implements Comparable<State> {
        int x, y, type, d;

        State(int x, int y, int type, int d) {
            this.x = x;
            this.y = y;
            this.d = d;
            this.type = type;
        }

        @Override
        public int compareTo(State arg0) {
            return Integer.compare(d, arg0.d);
        }

    }

    void stupid() {
        int n = 20, m = 20;
        int[][][] ans = new int[6][n][m];
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < n; j++)
                Arrays.fill(ans[i][j], Integer.MAX_VALUE / 3);
        ans[0][0][0] = 0;
        PriorityQueue<State> q = new PriorityQueue<prizes_bm.State>();
        q.add(new State(0, 0, 0, 0));
        while (q.size() > 0) {
            State s = q.remove();
            int x = s.x;
            int y = s.y;
            int type = s.type;
            int d = ans[type][x][y];
            {
                // right
                int nx = x + 1;
                int ny = y;
                int ntype = typeRight(type);
                int nd = d + (ntype == 5 ? 1 : 0);
                if (nx < n)
                    if (ans[ntype][nx][ny] > nd) {
                        ans[ntype][nx][ny] = nd;
                        q.add(new State(nx, ny, ntype, nd));
                    }
            }
            {
                // up
                int nx = x;
                int ny = y + 1;
                int ntype = typeUp(type);
                int nd = d + (ntype == 5 ? 1 : 0);
                if (ny < m)
                    if (ans[ntype][nx][ny] > nd) {
                        ans[ntype][nx][ny] = nd;
                        q.add(new State(nx, ny, ntype, nd));
                    }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int min = Integer.MAX_VALUE;
                for (int k = 0; k < 6; k++)
                    min = Math.min(min, ans[k][i][j]);
                System.err.print(min + " ");
            }
            System.err.println();
        }
    }

    void solve() {
//        stupid();
        int n = in.nextInt();
        int m = in.nextInt();
        if (n > m) {
            int tmp = n;
            n = m;
            m = tmp;
        }
        if (n == 1) {
            out.println((m + 1) / 4);
        } else {
            if (n == 2) {
                out.println(0);
            } else {
                out.println(1);
            }
        }
    }

    void run() {
        try {
            in = new FastScanner(new File("prizes.in"));
            out = new PrintWriter(new File("prizes.out"));

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
        new prizes_bm().run();
    }
}