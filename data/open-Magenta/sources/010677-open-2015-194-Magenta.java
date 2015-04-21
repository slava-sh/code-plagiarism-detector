import java.util.*;
import java.lang.*;
import java.io.*;

public class Magenta {

    StringTokenizer in;
    BufferedReader br;
    PrintWriter out;
    char cur;
    final int N = 1;
    final int M = 13;

    void doit(char c) throws IOException {
        out.println(c);
        out.flush();
        cur = nextToken().charAt(0);
        if (cur != 'N') {
            System.exit(0);
        }
    }

    public void solve() throws IOException {
        int cnt1 = M;
        while (true) {
            for (int i = 0; i < cnt1 / M; i++) {
                doit('R');
            }
            doit('U');
            cnt1 += N;
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
        new Magenta().run();
    }

}
