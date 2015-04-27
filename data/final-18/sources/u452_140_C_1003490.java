import java.io.*;
import java.util.*;

public class C {

    BufferedReader in;
    StringTokenizer st;
    PrintWriter out;

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(in.readLine());
        return st.nextToken();
    }

    int nextInt() throws Exception {
        return Integer.parseInt(next());
    }

    long nextLong() throws Exception {
        return Long.parseLong(next());
    }

    double nextDouble() throws Exception {
        return Double.parseDouble(next());
    }

    class Ball implements Comparable<Ball> {
        int sz, cnt;

        public Ball(int x, int y) {
            //System.err.println(x + " " + y);
            this.sz = x;
            this.cnt = y;
        }

        public int compareTo(Ball other) {
            if (cnt != other.cnt)
                return cnt > other.cnt ? -1 : 1;

            return sz > other.sz ? -1 : sz < other.sz ? 1 : 0;
            
        }

    }

    int ans = 0;
    String aw[];

    void store(String s) {
        aw[ans] = s;
        ans++;
    }

    void outp(Ball q, Ball w, Ball e) {
        store(Math.max(Math.max(q.sz, e.sz), w.sz)
                + " "
                + (q.sz + w.sz + e.sz - Math.min(Math.min(q.sz, e.sz), w.sz) - Math
                        .max(Math.max(q.sz, e.sz), w.sz)) + " "
                + Math.min(Math.min(q.sz, e.sz), w.sz));
    }

    void solve() throws Exception {
        int n = nextInt();
        int a[] = new int[n];
        aw = new String[n];
        for (int i = 0; i < n; i++)
            a[i] = nextInt();

        Arrays.sort(a);

        PriorityQueue<Ball> h = new PriorityQueue<Ball>();

        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] != a[i - 1]) {
                h.add(new Ball(a[i - 1], cnt));
                cnt = 0;
            }
            cnt++;
        }
        // out.println(Arrays.toString(a));
        // out.println(cnt);
        h.add(new Ball(a[n - 1], cnt));
        while (h.size() >= 3) {
            Ball t1 = h.remove(), t2 = h.remove(), t3 = h.remove();
            outp(t1, t2, t3);
            t1.cnt--;
            t2.cnt--;
            t3.cnt--;
            if (t1.cnt > 0)
                h.add(t1);
            if (t2.cnt > 0)
                h.add(t2);
            if (t3.cnt > 0)
                h.add(t3);
        }
        out.println(ans);
        for (int i = 0; i < ans; i++)
            out.println(aw[i]);
    }

    void run() {
        try {
            Locale.setDefault(Locale.US);
            in = new BufferedReader(new InputStreamReader((System.in)));
            out = new PrintWriter(System.out);

            solve();
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    public static void main(String[] args) {
        new C().run();

    }

}
