/**
 * Created by root on 13.06.14.
 */
import java.util.*;
import java.io.*;

public class C {
    FastScanner in;
    PrintWriter out;

    int w;

    class Edge implements Comparable<Edge>{
        int from;
        int to;
        int weight;

        Edge(int from, int to, int weight) {
            this.from = from;
            this.to = to;
            this.weight = weight;
        }


        @Override
        public int compareTo(Edge o) {
            return Integer.compare(this.weight, o.weight);
        }
    }

    class Field {
        char[] field;

        Field(char[] field) {
            this.field = field;
        }

        int getDiff(Field o) {
            int different = 0;
            for (int i = 0; i < this.field.length; i++) {
                if (this.field[i] != o.field[i]) {
                    different++;
                }
            }
            return different * w;
        }
    }
    Random random = new Random(123L);

    class DSU {
        int[] a;

        DSU(int n) {
            a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = i;
            }
        }

        int get(int x) {
            if (a[x] != x) {
                a[x] = get(a[x]);
            }
            return a[x];
        }

        boolean same(int x, int y) {
            return get(x) == get(y);
        }

        void union(int x, int y) {
            x = get(x);
            y = get(y);
            if (same(x, y)) {
                return;
            }
            if (random.nextBoolean()) {
                a[x] = y;
            } else {
                a[y] = x;
            }
        }
    }
    boolean[] used;
    ArrayList<Edge>[] graph;
    int[][] diff;

    void DFS(int current) {
        for (Edge e : graph[current]) {
            if (!used[e.to]) {
                used[e.to] = true;
                out.println((e.to + 1) + " " + (e.from + 1));
                DFS(e.to);
            }
        }
    }

    public void solve() throws IOException {
        int n = in.nextInt();
        int m = in.nextInt();
        int k = in.nextInt();
        w = in.nextInt();
        Field[] fields = new Field[k];
        for (int i = 0; i < k; i++) {
            char[] field = new char[n * m];
            int idx = 0;
            String temp;
            for (int j = 0; j < n; j++) {
                temp = in.next();
                for (int q = 0; q < m; q++) {
                    field[idx++] = temp.charAt(q);
                }
            }
            fields[i] = new Field(field);
        }

        int maxSize = n * m;
        ArrayList<Edge> list = new ArrayList<Edge>();
        for (int i = 0; i < k; i++) {
            for (int j = i + 1; j < k; j++) {
                int temp = fields[i].getDiff(fields[j]);
                if (temp >= maxSize) {
                    continue;
                }
                list.add(new Edge(i, j, temp));
            }
        }

        Collections.sort(list);
        DSU dsu = new DSU(k);

        graph = new ArrayList[k];
        used = new boolean[k];
        for (int i = 0; i < k; i++) {
            graph[i] = new ArrayList<Edge>();
        }

        int ans = 0;
        int cnt = k;

        for (int i = 0; i < list.size(); i++) {
            Edge e = list.get(i);
            if (!dsu.same(e.from, e.to)) {
                ans += e.weight;
                dsu.union(e.from, e.to);
                graph[e.from].add(e);
                Edge e2 = new Edge(e.to, e.from, e.weight);
                graph[e.to].add(e2);
                cnt--;
            }
        }
        out.println(ans + cnt * maxSize);

        for (int i = 0; i < k; i++) {
            if (!used[i]) {
                out.println((i + 1) + " 0");
                used[i] = true;
                DFS(i);
            }
        }
    }

    public void run() {
        try {
            in = new FastScanner(System.in);
            out = new PrintWriter(System.out);

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
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
        new C().run();
    }
}