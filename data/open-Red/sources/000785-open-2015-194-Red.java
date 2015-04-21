import java.util.*;
import java.lang.*;
import java.io.*;

public class Red1 {

    StringTokenizer in;
    BufferedReader br;
    PrintWriter out;
    int n;
    int m;
    ArrayList<Long>[] al;
    int D;

    int bfs(int start, int finish) {
        ArrayDeque<Long> q = new ArrayDeque<Long>();
        HashMap<Long, Integer> d = new HashMap<Long, Integer>();
        d.put((-1L << 32) + start, 0);
        q.addLast((-1L << 32) + start);
        while (!q.isEmpty()) {
            Long cur = q.pollFirst();
            int t1 = (int) (cur >> 32);
            int u = (int) (cur << 32 >> 32);
            for (long edge : al[u]) {
                int t2 = (int) (edge >> 32);
                if (t1 == -1 || Math.abs(t2 - t1) <= D) {
                    if (!d.containsKey(edge)) {
                        d.put(edge, d.get(cur) + 1);
                        q.add(edge);
                    }
                }
            }
        }

        int res = Integer.MAX_VALUE;
        for (long edge : al[finish]) {
            int t = (int) (edge >> 32);
            long want = ((long) t << 32L) + finish;
            if (d.containsKey(want)) {
                res = Math.min(res, d.get(want));
            }
        }
        if (res == Integer.MAX_VALUE) {
            res = -1;
        }
        return res;
    }

    public void solve() throws IOException {
        n = nextInt();
        m = nextInt();
        D = nextInt();
        al = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            al[i] = new ArrayList<Long>();
        }
        for (int i = 0; i < m; i++) {
            int a = nextInt() - 1;
            int b = nextInt() - 1;
            int t = nextInt();
            al[a].add((((long) t) << 32L) + b);
            al[b].add((((long) t) << 32L) + a);
        }
        int q = nextInt();
        for (int i = 0; i < q; i++) {
            out.println(bfs(nextInt() - 1, nextInt() - 1));
        }
    }

    public String nextToken() throws IOException {
        while (in == null || !in.hasMoreTokens()) {
            in = new StringTokenizer(br.readLine());
        }
        return in.nextToken();
    }

    public double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    public long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    public void run() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    public static void main(String[] args) throws IOException {
        new Red1().run();
    }

}
