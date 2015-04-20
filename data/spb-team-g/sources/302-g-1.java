import java.io.*;
import java.util.*;
import java.lang.*;

public class G {
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

    void solve() throws IOException {
        int n = nextInt();
        Long[] a = new Long[n];
        long sum = 0;
        for (int i = 0; i < n; ++i) {
            a[i] = nextLong();
            sum += a[i];
        }
        Arrays.sort(a, new Comparator<Long>() {
            @Override
            public int compare(Long o1, Long o2) {
                return o2.compareTo(o1);
            }
        });
        for (int i = 0; i < n; ++i) {
            if (a[i] * (n - i) <= sum) {
                out.print(i);
                return;
            }
        }
    }

    void run() {
        try {
            br = new BufferedReader(new FileReader("merlin.in"));
            out = new PrintWriter("merlin.out");
            solve();
        } catch (Exception e) {
            e.printStackTrace();
        }
        out.close();
    }



    public static void main(String[] args) {
        new G().run();
    }
}
