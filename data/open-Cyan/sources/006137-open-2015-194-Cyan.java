import java.util.*;
import java.lang.*;
import java.io.*;

public class Cyan {

    StringTokenizer in;
    BufferedReader br;
    PrintWriter out;
    int A, B, n;
    int[][] x, y;
    final int MAXL = 400;
    int[] L;

    double h(int x1, int y1, int x2, int y2, int x, int y) {
        double a = y2 - y1;
        double b = x1 - x2;
        double c = -(a * x1 + b * y1);

        double resY = (-c - a * x) / b;
        return y - resY;
    }

    int sign(double x) {
        if (x < 0) return -1;
        if (x > 0) return 1;
        return 0;
    }

    boolean intersects(int a, int b) {
        int sgn = sign(y[a][0] - y[b][0]);
        int i2 = 0;
        for (int i1 = 0; i1 < L[a]; i1++) {
            while (x[b][i2 + 1] < x[a][i1]) {
                i2++;
            }
            double dist = h(x[b][i2], y[b][i2], x[b][i2 + 1], y[b][i2 + 1], x[a][i1], y[a][i1]);
            if (sign(dist) == -sgn && sgn != 0 && sign(dist) != 0) {
                return true;
            } else if (sgn == 0) {
                sgn = sign(dist);
            }
        }

        int t = a; a = b; b = t;
        sgn = sign(y[a][0] - y[b][0]);
        i2 = 0;
        for (int i1 = 0; i1 < L[a]; i1++) {
            while (x[b][i2 + 1] < x[a][i1]) {
                i2++;
            }
            double dist = h(x[b][i2], y[b][i2], x[b][i2 + 1], y[b][i2 + 1], x[a][i1], y[a][i1]);
            if (sign(dist) == -sgn && sgn != 0 && sign(dist) != 0) {
                return true;
            } else if (sgn == 0) {
                sgn = sign(dist);
            }
        }

        return false;
    }

    public void solve() throws IOException {
        A = nextInt();
        B = nextInt();
        n = nextInt();
        x = new int[n][MAXL];
        y = new int[n][MAXL];
        L = new int[n];
        for (int i = 0; i < n; i++) {
            L[i] = nextInt() + 1;
            for (int j = 0; j < L[i]; j++) {
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
