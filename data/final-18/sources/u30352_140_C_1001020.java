import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.Arrays;

public class CR100A {

    // static Scanner in;
    static StreamTokenizer st;
    static int n;
    static int[] c;
    static PrintWriter out;
    public static void main(String[] args) throws IOException {
        // in = new Scanner(System.in);
        st = new StreamTokenizer(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        n = nextInt();
        c = new int[n];
        tmp = new int[n];
        for (int i = 0; i < n; ++i)
            c[i] = nextInt();
        Arrays.sort(c);
        int l = 0, r = n;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            if (may(m))
                l = m;
            else
                r = m;
        }
        out.println(l);
        if (l == 0) {
            out.close();
            return;
        }
        int[] x, y, z;
        x = new int[l];
        y = new int[l];
        z = new int[l];
        for (int i = 0; i < l; ++i)
            x[i] = c[i];
        int cc = 0;
        int i = 0;
        for (i = l; i < n; ++i) {
            if (c[i] > x[cc]) {
                y[cc++] = c[i];
            }
            if (cc == l) {
                ++i;
                break;
            }
        }
        cc = 0;
        for (; i < n; ++i) {
            if (c[i] > y[cc]) {
                z[cc++] = c[i];
            }
            if (cc == l)
                break;
        }
        for (i = 0; i < l; ++i) {
            out.println(z[i] + " " + y[i] + " " + x[i]);
        }
        out.close();
    }

    static int[] tmp;

    private static boolean may(int m) {
        int i = 0;
        for (i = 0; i < m; ++i)
            tmp[i] = c[i];
        int j, l = 0;
        for (j = i; j < n; ++j) {
            if (c[j] > tmp[l]) {
                tmp[l++] = c[j];
            }
            if (l == m)
                break;
        }
        ++j;
        if (l != m)
            return false;
        l = 0;
        for (i = j; i < n; ++i) {
            if (c[i] > tmp[l]) {
                ++l;
            }
            if (l == m)
                break;
        }
        if (l != m)
            return false;
        return true;
    }

    private static int nextInt() throws IOException {
        st.nextToken();
        return (int) st.nval;
    }
}
