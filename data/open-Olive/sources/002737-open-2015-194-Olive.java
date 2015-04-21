import java.util.*;
import java.lang.*;
import java.io.*;

public class Olive {

    StringTokenizer in;
    BufferedReader br;
    PrintWriter out;

    public void solve() throws IOException {
        int n = nextInt();
        int[] h = new int[n];
        for (int i = 0; i < n; i++) {
            h[i] = nextInt();
        }

        int[][] moreNext = new int[n][n];
        for (int j = 0; j < n - 1; j++) {
            for (int i = j; i >= 0; i--) {
                moreNext[i][j] = moreNext[i + 1][j];
                if (h[i] > h[j + 1]) {
                    moreNext[i][j]++;
                }
            }
        }

        int[][] lessNext = new int[n][n];
        for (int j = 0; j < n - 1; j++) {
            for (int i = j; i >= 0; i--) {
                lessNext[i][j] = lessNext[i + 1][j];
                if (h[i] < h[j + 1]) {
                    lessNext[i][j]++;
                }
            }
        }

        int[][] lessPrev = new int[n][n];
        for (int i = 1; i < n; i++) {
            for (int j = i; j < n; j++) {
                lessPrev[i][j] = lessPrev[i][j - 1];
                if (h[j] < h[i - 1]) {
                    lessPrev[i][j]++;
                }
            }
        }

        int[][] morePrev = new int[n][n];
        for (int i = 1; i < n; i++) {
            for (int j = i; j < n; j++) {
                morePrev[i][j] = morePrev[i][j - 1];
                if (h[j] > h[i - 1]) {
                    morePrev[i][j]++;
                }
            }
        }

        int[] ans = {-1, -1};
        long val = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long invs = moreNext[i + 1][j - 1] + lessPrev[i + 1][j - 1] - morePrev[i + 1][j - 1] - lessNext[i + 1][j - 1];
                if (invs > val) {
                    val = invs;
                    ans[0] = i + 1;
                    ans[1] = j + 1;
                }
            }
        }
        out.println(ans[0] + " " + ans[1]);
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
        new Olive().run();
    }

}
