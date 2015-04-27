import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Artyom Korzun
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int[] a = new int[100000];
        boolean[] b = new boolean[100000];
        for (int i = 0; i < n; i++) {
            int m = in.nextInt();
            int k = in.nextInt();

            for (int j = 0; j < k; j++)
                a[j] = in.nextInt();

            boolean firstR = true;
            int dishCredit = 0;
            for (int j = 0; j < m - 1; j++) {
                int t = in.nextInt();
                int r = in.nextInt();

                if (r == 1) {
                    if (firstR) {
                        for (int p = 0; p < k; p++)
                            b[p] = a[p] <= dishCredit;

                        firstR = false;
                    }
                }

                if (t == 0) {
                    dishCredit++;
                } else {
                    int dishIndex = t - 1;
                    a[dishIndex]--;
                    b[dishIndex] = false;
                }
            }

            if (!firstR) {
                int min = Integer.MAX_VALUE;
                for (int j = 0; j < k; j++) {
                    if (b[j]) {
                        if(min > a[j])
                            min = a[j];
                    }
                }

                for (int j = 0; j < k; j++) {
                    if(b[j])
                         a[j]-=min;
                }

                dishCredit-= min;
            }

            for (int j = 0; j < k; j++)
                out.print((a[j] - dishCredit) > 0 ? 'N' : 'Y');

            out.println();
        }

    }

}

class FastScanner {

    private final BufferedReader reader;

    private StringTokenizer tokenizer;

    public FastScanner(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
    }

   public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens())
            tokenizer = new StringTokenizer(nextLine());

        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    private String nextLine() {
        try {
            return reader.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

}

