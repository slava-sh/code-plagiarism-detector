import java.io.*;
import java.util.*;
import java.lang.*;

public class J {
    BufferedReader br;
    StringTokenizer in;
    PrintWriter out;

    String nextToken() throws IOException {
        while (in == null || !in.hasMoreTokens()) {
            in = new StringTokenizer(br.readLine());
        }
        return in.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    class El implements Comparable<El> {
        int val;
        int cnt;

        El(int val, int cnt) {
            this.val = val;
            this.cnt = cnt;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            El el = (El) o;

            if (cnt != el.cnt) return false;
            if (val != el.val) return false;

            return true;
        }

        @Override
        public int hashCode() {
            int result = val;
            result = 31 * result + cnt;
            return result;
        }


        @Override
        public int compareTo(El o) {
            return this.val - o.val;
        }
    }

    void solve() throws IOException {
        int n = nextInt();
        int h = nextInt();
        int[] a = new int[n];
        long sum = 0;
        for (int i = 0; i < n; i++) {
            a[i] = nextInt() - i;
        }
        long res = Long.MAX_VALUE;
        TreeSet<Integer> cur = new TreeSet<Integer>();
        HashMap<Integer, Integer> cnt = new HashMap<Integer, Integer>();
        for (int i = 0; i < h; i++) {
            cur.add(a[i]);
            if (cnt.containsKey(a[i])) {
                cnt.put(a[i], cnt.get(a[i]) + 1);
            } else {
                cnt.put(a[i], 1);
            }
            sum += a[i] + i;
        }
        for (int i = 0; i <= n - h; i++) {
            if (cur.last() <= 1 - i) {
                res = Math.min(res, (long) h * (long) (h + 1) / 2 - sum);
            }
            sum -= a[i] + i;
            if (i + h < n) {
                sum += a[i + h] + i + h;
                if (cnt.containsKey(a[i + h])) {
                    cnt.put(a[i + h], cnt.get(a[i + h]) + 1);
                } else {
                    cnt.put(a[i + h], 1);
                }
                cur.add(a[i + h]);
            }
            cnt.put(a[i], cnt.get(a[i]) - 1);
            if (cnt.get(a[i]) == 0) {
                cur.remove(a[i]);
            }
        }
        if (res == Long.MAX_VALUE) {
            res = -1;
        }
        out.println(res);
    }

    void run() {
        try {
            br = new BufferedReader(new FileReader("seq.in"));
            out = new PrintWriter("seq.out");
            solve();
        } catch (Exception e) {
            e.printStackTrace();
        }
        out.close();
    }



    public static void main(String[] args) {
        new J().run();
    }
}
