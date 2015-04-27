import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author AlexFetisov
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

    private int[] pref;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        String s = in.nextString();
        if (k == 1) {
            for (int i = 0; i < s.length(); ++i) {
                out.print("1");
            }
            return;
        }

        out.print("0");
        pref = PrefixFunction.run(s);

        int last = -1;
        int lastPer = -1;
        boolean going = false;
        for (int i = 1; i < n; ++i) {
            int len = i + 1;
            if (len % k == 0 && rrr(len / k, len-1)) {
                last = i;
                lastPer = len / k;
                going = true;
                out.print("1");
                continue;
            }
            if (going) {
                int cur = i - last - 1;
                if (cur + 1 > lastPer) {
                    going = false;
                } else {
                    if (s.charAt(cur) == s.charAt(i)) {
                        out.print("1");
                        continue;
                    } else {
                        going = false;
                    }
                }
            }
            out.print("0");
        }
    }

    boolean rrr(int len, int upTo) {
        int p = pref[upTo];
        int k = upTo + 1 - p;
        return (upTo + 1) % k == 0 && (len % k == 0);
    }
}

class InputReader {
    private BufferedReader reader;
    private StringTokenizer stt;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
    }

    public String nextLine() {
        try {
            return reader.readLine();
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

class PrefixFunction {
    public static int[] run(String s) {
        int n = s.length();
        int[] res = new int[n];
        for (int i = 1; i < n; ++i) {
            int j = res[i-1];
            while (j > 0 && s.charAt(i) != s.charAt(j)) {
                j = res[j - 1];
            }
            if (s.charAt(i) == s.charAt(j)) {
                ++j;
            }
            res[i] = j;
        }
        return res;
    }

}

