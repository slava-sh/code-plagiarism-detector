import java.util.*;
import java.lang.*;
import java.io.*;

public class Gold {

    StringTokenizer in;
    BufferedReader br;
    PrintWriter out;

    class Pair {
        long first, second;

        public Pair(long first, long second) {
            this.first = first;
            this.second = second;
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
        Pair[] ts = new Pair[n - 1];
        for (int i = 0; i < n - 1; i++) {
            ts[i] = new Pair(a[i].second, a[i + 1].first);
        }
        Arrays.sort(ts, new Comparator<Pair>() {
            @Override
            public int compare(Pair o1, Pair o2) {
                return Long.compare(o1.second - o1.first, o2.second - o2.first);
            }
        });
        long cur = res;
        res = cur + ((n - 1) / k) * c;
        for (int i = 0; i < n - 1; i++) {
            Pair p = ts[i];
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
