import java.util.*;
import java.lang.*;
import java.io.*;

public class Cyan {

    StringTokenizer in;
    BufferedReader br;
    PrintWriter out;
    int A, B, n;
    int[][] x, y;

    boolean intersectIntervals(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
        double a1 = y2 - y1;
        double b1 = x1 - x2;
        double c1 = -(a1 * x1 + b1 * y1);

        double a2 = y4 - y3;
        double b2 = x3 - x4;
        double c2 = -(a2 * x3 + b2 * y3);

        double d = a1 * b2 - b1 * a2;
        if (d == 0) return false;
        double d1 = c1 * b2 - b1 * c2;
        double d2 = a1 * c2 - c1 * a2;

        double x = -d1 / d;
        double y = -d2 / d;

        double v1x = x - x1;
        double v1y = y - y1;
        double v2x = x - x2;
        double v2y = y - y2;
        double sc1 = v1x * v2x + v1y * v2y;

        v1x = x - x3;
        v1y = y - y3;
        v2x = x - x4;
        v2y = y - y4;
        double sc2 = v1x * v2x + v1y * v2y;

        return sc1 < 0 && sc2 < 0;
    }

    boolean intersects(int a, int b) {
        int i2 = 1;
        for (int i1 = 0; i1 < x[a].length - 1; i1++) {
            while (x[b][i2] < x[a][i1 + 1]) {
                if (intersectIntervals(x[b][i2], y[b][i2], x[b][i2 - 1], y[b][i2 - 1], x[a][i1], y[a][i1], x[a][i1 + 1], y[a][i1 + 1])) {
                    return true;
                }
                i2++;
            }
            if (i2 < x[b].length && intersectIntervals(x[b][i2], y[b][i2], x[b][i2 - 1], y[b][i2 - 1], x[a][i1], y[a][i1], x[a][i1 + 1], y[a][i1 + 1])) {
                return true;
            }
        }
        return false;
    }

    public void solve() throws IOException {
        A = nextInt();
        B = nextInt();
        n = nextInt();
        x = new int[n][];
        y = new int[n][];
        for (int i = 0; i < n; i++) {
            int L = nextInt() + 1;
            x[i] = new int[L];
            y[i] = new int[L];
            for (int j = 0; j < L; j++) {
                x[i][j] = nextInt();
                y[i][j] = nextInt();
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (intersects(i, j)) {
                    out.println("No");
                    out.println((i + 1) + " " + (j + 1));
                    return;
                }
            }
        }
        out.println("Yes");

//        int x1 = nextInt();
//        int y1 = nextInt();
//        int x2 = nextInt();
//        int y2 = nextInt();
//        int x3 = nextInt();
//        int y3 = nextInt();
//        int x4 = nextInt();
//        int y4 = nextInt();
//        out.println(intersectIntervals(x1, y1, x2, y2, x3, y3, x4, y4));

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
        new Cyan().run();
    }

}
