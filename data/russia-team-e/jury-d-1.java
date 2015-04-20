import java.io.*;
import java.util.*;

public class fence_bm {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n= in.nextInt();
        int k = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = in.nextInt();
        Arrays.sort(a);
        int l = 0, r = a[0] + 1;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            long maxR = 0;
            for (int i = 0; i < n; i++) {
                maxR = Math.max(maxR + m, a[i]);
            }
            if (maxR <= k) {
                l = m;
            } else {
                r = m;
            }
        }
        out.println(l);
    }

    void run() {
        try {
            in = new FastScanner(new File("fence.in"));
            out = new PrintWriter(new File("fence.out"));

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
        new fence_bm().run();
    }
}