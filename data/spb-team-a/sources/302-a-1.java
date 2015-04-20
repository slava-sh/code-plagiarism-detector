import java.io.*;
import java.util.*;
import java.lang.*;

public class A {
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
        int t = nextInt();
        for(int i = 0; i < t; i++) {
            String s = nextToken();
            int ab = Integer.parseInt(s.substring(0, 2));
            int cd = Integer.parseInt(s.substring(2));
            ab = ab * ab;
            cd = cd * cd;
            if((ab + cd) % 7 == 1) {
                out.println("YES");
            }else {
                out.println("NO");
            }
        }
    }

    void run() {
        try {
            br = new BufferedReader(new FileReader("abcd.in"));
            out = new PrintWriter("abcd.out");
            solve();
        } catch (Exception e) {
            e.printStackTrace();
        }
        out.close();
    }



    public static void main(String[] args) {
        new A().run();
    }
}
