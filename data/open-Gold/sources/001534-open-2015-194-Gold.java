import java.util.*;
import java.lang.*;
import java.io.*;

public class Gold {

    StringTokenizer in;
    BufferedReader br;
    PrintWriter out;

    class Pair implements Comparable<Pair> {
        int first, second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public int compareTo(Pair o) {
            return (this.second - this.first) - (o.second - o.first);
        }
    }

//    int myMod(int n, int k) {
//        if (n % k != 0) return n % k;
//        return k;
//    }

    public void solve() throws IOException {
        int n = nextInt();
        int k = nextInt();
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
//        int curN = n;
//        while (true) {
//            int x = myMod(curN, k);
//            if (ts.size() >= x) {
//                long over = 0;
//                for (int i = 0; i < x; i++) {
//                    Pair p = ts.pollFirst();
//                    curN--;
//                    over += d * (p.second - p.first);
//                }
//                if (over <= c) {
//                    res += over;
//                    res -= c;
//                }
//            } else {
//                break;
//            }
//        }
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
