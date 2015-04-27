import java.io.BufferedReader;
import java.io.IOError;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {
    FastIO scan = new FastIO();
    PrintWriter cout = new PrintWriter(System.out);

    final static int $ = 1111;

    public void run() {
        int n = scan.nextInt();
        int m = scan.nextInt();
        int k = scan.nextInt();
        int w = scan.nextInt();
        int[][][] f = new int[$][13][13];
        int[][] g = new int[$][$];
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= n; j++) {
                String str = scan.next();
                for (int l = 0; l < m; l++) {
                    f[i][j][l+1] = str.charAt(l);
                }
            }
        }
        for (int i = 1; i < k; i++) {
            for (int j = i + 1; j <= k; j++) {
                int $$$ = 0;
                for (int l = 1; l <= n; l++) {
                    for (int r = 1; r <= m; r++) {
                        if (f[i][l][r] != f[j][l][r])
                            $$$++;
                    }
                }
                g[i][j] = g[j][i] = $$$ * w;
            }
        }
        for (int i = 1; i <= k; i++) {
            g[0][i] = g[i][0] = n * m;
        }
        int[] _ = new int[$];
        boolean[] __ = new boolean[$];
        int[] ___ = new int[$];
        int[][] ____ = new int[$][2];
        __[0] = true;
        int op = 0, answer = 0;
        for (int i = 1; i <= k; i++) {
            _[i] = Integer.MAX_VALUE;
            ___[i] = -1;
        }
        int cnt = 0;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j <= k; j++) {
                if (__[j] == true) {
                    continue;
                }
                if (_[j] > g[op][j]) {
                    _[j] = g[op][j];
                    ___[j] = op;
                }
            }
            int $$$ = -1;
            for (int j = 0; j <= k; j++) {
                if (__[j] == true) {
                    continue;
                }
                if ($$$ == -1 || _[$$$] > _[j]) {
                    $$$ = j;
                }
            }
            ____[cnt][0] = $$$;
            ____[cnt][1] = ___[$$$];
            cnt++;
            answer += _[$$$];
            op = $$$;
            __[op] = true;
        }
        System.out.println(answer);
        for (int i = 0; i < cnt; i++) {
            System.out.printf("%d %d\n", ____[i][0], ____[i][1]);
        }
    }

    public static void main(String[] args) {
        new Main().run();
    }

    public class FastIO {
        BufferedReader br;
        StringTokenizer st;
        PrintWriter out;

        public FastIO(InputStream in, OutputStream o) {
            br = new BufferedReader(new InputStreamReader(in));
            out = new PrintWriter(new OutputStreamWriter(o));
            eat("");
        }

        public FastIO() {
            br = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(new OutputStreamWriter(System.out));
            eat("");
        }

        public void eat(String s) {
            st = new StringTokenizer(s);
        }

        public String nextLine() {
            try {
                return br.readLine();
            } catch (IOException e) {
                throw new IOError(e);
            }
        }

        public boolean hasNext() {
            while (!st.hasMoreTokens()) {
                String s = nextLine();
                if (s == null)
                    return false;
                eat(s);
            }
            return true;
        }

        public String next() {
            hasNext();
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public void print(String ans) {
            out.print(ans);
            out.flush();
        }

        public void println(String ans) {
            out.println(ans);
            out.flush();
        }

        public void close() {
            out.close();
        }
    }
}
