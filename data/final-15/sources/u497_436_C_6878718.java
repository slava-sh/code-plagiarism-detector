import java.io.BufferedReader;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Collection;
import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
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
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int k = in.nextInt();
        int W = in.nextInt();
        g = new int[k + 1][k + 1];
        ArrayUtils.fill(g, -1);

        char[][][] levels = new char[k][n][m];
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < n; ++j) {
                String s = in.nextString();
                for (int l = 0; l < m; ++l) {
                    levels[i][j][l] = s.charAt(l);
                }
            }
            for (int past = i - 1; past >= 0; --past) {
                int notCommon = 0;
                for (int j = 0; j < n; ++j) {
                    for (int l = 0; l < m; ++l) {
                        if (levels[i][j][l] != levels[past][j][l]) {
                            ++notCommon;
                        }
                    }
                }
                g[past+1][i+1] = g[i+1][past+1] = notCommon * W;
            }
            g[0][i+1] = g[i+1][0] = n * m;
        }

        for (int i = 0; i <= k; ++i) g[i][i] = 0;
        ++k;
        boolean[] used = new boolean[k];
        int[] minE = new int[k];
        Arrays.fill(minE, Integer.MAX_VALUE / 2);
        int[] selE = new int[k];
        Arrays.fill(selE, -1);

        List<Integer> res = new ArrayList<Integer>();
        int result = 0;
        for (int i = 0; i < k; ++i) {
            int v = -1;
            for (int j = 0; j < k; ++j) {
                if (!used[j] && (v == -1 || minE[j] < minE[v])) {
                    v = j;
                }
            }
            assert (minE[v] < Integer.MAX_VALUE / 2);
            used[v] = true;
            if (selE[v] != -1) {
                res.add(v);
                res.add(selE[v]);
                result += g[v][selE[v]];
            }

            for (int to = 0; to < k; ++to) {
                if (g[v][to] != -1 && g[v][to] < minE[to]) {
                    minE[to] = g[v][to];
                    selE[to] = v;
                }
            }
        }
        out.println(result);
        for (int i = 0; i < res.size(); i += 2) {
            out.println(res.get(i) + " " + res.get(i + 1));
        }
    }

    int[][] g;
}

class InputReader {
    private BufferedReader reader;
    private StringTokenizer stt;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
    }

    public String nextLine() {
        try {
            return reader.readLine().trim();
        } catch (IOException e) {
            return null;
        }
    }

    public String nextString() {
        while (stt == null || !stt.hasMoreTokens()) {
            stt = new StringTokenizer(nextLine());
        }
        return stt.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(nextString());
    }

}

class ArrayUtils {

    public static void fill(int[][] f, int value) {
        for (int i = 0; i < f.length; ++i) {
            Arrays.fill(f[i], value);
        }
    }

}

