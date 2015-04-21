import java.util.*;
import java.lang.*;
import java.io.*;

public class Magenta1 {

    StringTokenizer in;
    BufferedReader br;
    PrintWriter out;
    char outcome;

    void doit(char c) throws IOException {
        out.println(c);
        out.flush();
        outcome = nextToken().charAt(0);
        if (outcome != 'N') {
            System.exit(0);
        }
    }

    public void solve() throws IOException {
        outcome = 'N';
        int cnt = 1;
        while (outcome == 'N') {
            doit('R');
            for (int i = 0; i < cnt; i++) {
                doit('U');
            }
            cnt += 2;
            doit('R');
            for (int i = 0; i < cnt; i++) {
                doit('D');
            }
            cnt += 2;
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
        new Magenta1().run();
    }

}
