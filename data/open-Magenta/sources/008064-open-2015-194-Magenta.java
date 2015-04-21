import java.util.*;
import java.lang.*;
import java.io.*;

public class Magenta {

    StringTokenizer in;
    BufferedReader br;
    PrintWriter out;
    char cur;

    void doit(char c) throws IOException {
        out.println(c);
        out.flush();
        cur = nextToken().charAt(0);
        if (cur != 'N') {
            System.exit(0);
        }
    }

    public void solve() throws IOException {
        int cnt = 1;
        int iterations = 3;
        while (true) {
            int cnt1 = cnt;
            for (int i = 0; i < iterations; i++) {
                doit('R');
                for (int j = 0; j < cnt; j++) {
                    doit('U');
                }
                cnt++;
                doit('R');
                for (int j = 0; j < cnt; j++) {
                    doit('D');
                }
                cnt++;
            }

            cnt = cnt1;
            doit('D');

            for (int i = 0; i < iterations; i++) {
                doit('L');
                for (int j = 0; j < cnt; j++) {
                    doit('U');
                }
                cnt++;
                doit('L');
                for (int j = 0; j < cnt; j++) {
                    doit('D');
                }
                cnt++;
            }

            doit('D');
            iterations += 10;
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
