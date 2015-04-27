import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Vadim Semenov
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(final int testNumber, final InputReader in, final PrintWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        String string = in.next() + "#";
        int[] z = StringUtils.buildZFunction(string.toCharArray());
        int[] last = new int[n];
        for (int len = 1; len * k <= n; ++len) {
            boolean good = true;
            for (int cur = len; cur < k * len; cur += len) {
                if (z[cur] < len) {
                    good = false;
                    break;
                }
            }
            if (good) {
                last[k * len - 1] = Math.min(z[k * len], len) + k * len;
            }
        }
//        System.err.println(Arrays.toString(z) + " " + Arrays.toString(last));
        if (k == 1) {
            out.print(1);
        } else {
            out.print(0);
        }
        int cur = 0;
        for (int i = 1; i < n; ++i) {
            cur = Math.max(cur, last[i]);
            if (i < cur) {
                out.print(1);
            } else {
                out.print(0);
            }
        }
        out.println();
    }
}

class InputReader {
    private final BufferedReader reader;
    private StringTokenizer tokenizer;

    public InputReader(InputStream in) {
        reader = new BufferedReader(new InputStreamReader(in));
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(readLine());
        }
        return tokenizer.nextToken();
    }

    public String readLine() {
        String line;
        try {
            line = reader.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        return line;
    }
}

class StringUtils {

    public static int[] buildZFunction(final char[] string) {
        final int length = string.length;
        final int[] zFunction = new int[length];
        for (int i = 1, l = 0, r = 0; i < length; ++i) {
            if (i < r) {
                zFunction[i] = Math.min(zFunction[i - l], r - i);
            }
            while (i + zFunction[i] < length && string[zFunction[i]] == string[i + zFunction[i]]) {
                zFunction[i]++;
            }
            if (i + zFunction[i] > r) {
                l = i;
                r = i + zFunction[i];
            }
        }
        return zFunction;
    }

}

