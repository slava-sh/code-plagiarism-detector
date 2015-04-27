import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.StringTokenizer;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		Reader in = new Reader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, Reader in, PrintWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        char[] s = in.next().toCharArray();
        int[] pr = new int[n];
        pr[0] = -1;
        for (int i = 1; i < n; i++) {
            int j = pr[i - 1];
            while (j > -1 && s[j + 1] != s[i]) j = pr[j];
            if (s[j + 1] == s[i]) j++;
            pr[i] = j;
        }
        StringBuffer ans = new StringBuffer();
        if (k == 1) {
            for (int i = 0; i < n; i++) ans.append("1");
        } else {
            ans.append("0");
            for (int i = 1; i < n; i++) {
                if (pr[i] == -1) ans.append("0");
                else {
                    int cl = i - pr[i];
                    int x = (i + 1) / cl;
                    int r = (i + 1) % cl;
                    if (r == 0) {
                        if (x / k >= x % k) ans.append("1"); else ans.append("0");
                    } else {
                        if (x / k >= x % k + 1) ans.append("1"); else ans.append("0");
                    }
                }
            }
        }
        out.println(ans);
    }
}

class Reader {
    private BufferedReader in;
    private StringTokenizer st;
    public Reader(InputStream is) {
        in = new BufferedReader(new InputStreamReader(is));
    }
    public String next() {
        try {
            while (st == null || !st.hasMoreTokens()) {
                st = new StringTokenizer(in.readLine());
            }
            return st.nextToken();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
    public int nextInt() {
        return Integer.parseInt(next());
    }

}

