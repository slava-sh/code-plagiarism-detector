import java.util.*;
import java.lang.*;
import java.io.*;

public class Gold {

    StringTokenizer in;
    BufferedReader br;
    PrintWriter out;

    class Pair implements Comparable<Pair> {
        long first, second;

        public Pair(long first, long second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public int compareTo(Pair o) {
            int x = Long.compare(this.second - this.first, o.second - o.first);
            if (x != 0) return x;
            return Long.compare(this.first, o.first);
        }
    }

    public void solve() throws IOException {
        int n = nextInt();
        long k = nextLong();
        long c = nextLong();
        long d = nextLong();
        long res = 0;
        Pair[] a = new Pair[n];
        for (int i = 0; i < n; i++) {
            a[i] = new Pair(nextInt(), nextInt());
            res += d * (a[i].second - a[i].first);
        }
        TreeSet<Pair> ts = new TreeSet<Pair>();
        for (int i = 0; i < n - 1; i++) {
            ts.add(new Pair(a[i].second, a[i + 1].first));
        }
        long cur = res;
        res = cur + ((n - 1) / k) * c;
        while (!ts.isEmpty()) {
            Pair p = ts.pollFirst();
            n--;
            cur += d * (p.second - p.first);
            res = Math.min(res, cur + ((n - 1) / k) * c);
        }
        out.println(res);
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
        new Gold().run();
    }

}
