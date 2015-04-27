import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Rubanenko
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {

    final int INF = 1000_000_000;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int k = in.nextInt();
        int w = in.nextInt();
        int[][] dif = new int[k + 1][k + 1];
        char[][][] ar = new char[k + 1][n][m];
        String s;
        for (int u = 1; u <= k; u++) {
            for (int i = 0; i < n; i++) {
                s = in.next();
                for (int j = 0; j < m; j++) {
                    ar[u][i][j] = s.charAt(j);
                }
            }
        }
        for (int i = 1; i <= k; i++) {
            for (int j = i + 1; j <= k; j++) {
                for (int x1 = 0; x1 < n; x1++) {
                    for (int y1 = 0; y1 < m; y1++) {
                        dif[i][j] += (ar[i][x1][y1] != ar[j][x1][y1]) ? 1 : 0;
                    }
                }
                dif[i][j] *= w;
                dif[j][i] = dif[i][j];
            }
        }
        int[] f = new int[k + 1], p = new int[k + 1], num = new int[k + 1], ww = new int[k + 1];
        Arrays.fill(f, INF);
        int square = n * m;
        f[1] = -1;
        num[1] = 1;
        p[1] = 0;
        for (int i = 2; i <= k; i++) {
            ww[i] = 1;
            f[i] = dif[1][i];
            if (square < f[i]) {
               f[i] = square;
               ww[i] = 0;
            }
        }
        int ans = square;
        for (int i = 1; i < k; i++) {
            int v = 1, mn = INF;
            for (int j = 1; j <= k; j++) {
                if (f[j] < mn && f[j] != -1) {
                    v = j;
                    mn = f[j];
                }
            }
         //   out.println(v);
            ans += mn;
            num[i + 1] = v;
            p[i + 1] = ww[v];
            f[v] = -1;
            for (int j = 1; j <= k; j++) {
                if (dif[v][j] < f[j]) {
                    f[j] = dif[v][j];
                    ww[j] = v;
                }
            }
        }
        out.println(ans);
        for (int i = 1; i <= k; i++) {
            out.println(num[i] + " " + p[i]);
        }
    }
}

class InputReader {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

    public InputReader(InputStream inputStream) {
        reader = new BufferedReader(new InputStreamReader(inputStream));
    }

    public String nextLine() {
        String line = null;
        try {
            line = reader.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        return line;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens())
            tokenizer = new StringTokenizer(nextLine());
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }
}

