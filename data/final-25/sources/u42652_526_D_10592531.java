import java.util.*;
import java.io.*;

public class D {
    FastScanner in;
    PrintWriter out;

    int[] zFunction(String s) {
        int[] zFunction = new int[s.length()];
        int l = 0;
        int r = 0;
        for (int i = 1; i < s.length(); i++) {
            if (i <= r) {
                zFunction[i] = Math.min(r - i + 1, zFunction[i - l]);
            }
            while (i + zFunction[i] < s.length() && s.charAt(zFunction[i]) == s.charAt(zFunction[i] + i)) {
                zFunction[i]++;
            }
            if (i + zFunction[i] - 1 > r) {
                l = i;
                r = i + zFunction[i] - 1;
            }
        }
        return zFunction;
    }

    int[] prefixFunction(String s) {
        int[] prefix = new int[s.length()];
        for (int i = 1; i < s.length(); i++) {
            int j = prefix[i - 1];
            while (j > 0 && s.charAt(i) != s.charAt(j)) {
                j = prefix[j - 1];
            }
            if (s.charAt(i) == s.charAt(j)) {
                j++;
            }
            prefix[i] = j;
        }
        return prefix;
    }

    public void solve() throws IOException {
        int n = in.nextInt(), k = in.nextInt();
        String str = in.next();
        if (k == 1) {
            for (int i = 0; i < n; i++) {
                out.print(1);
            }
            out.println();
            return;
        }
        int[] z = zFunction(str);
        int[] ans = new int[n + 1];
        int min = 0;
        for (int i = 1; i < n;) {
            int good = z[i] + i;
            for (min = Math.max(min, i * k); min <= Math.min(i * k + i, good); min++) {
                ans[min] = 1;
            }
            i++;
        }
        for (int i = 1; i < ans.length; i++) {
            out.print(ans[i]);
        }
        out.println();
    }

    public void run() {
        try {
            in = new FastScanner(System.in);
            out = new PrintWriter(System.out);
            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(InputStream is) {
            br = new BufferedReader(new InputStreamReader(is));
        }

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }

    public static void main(String[] arg) throws FileNotFoundException {
        new D().run();
    }
}