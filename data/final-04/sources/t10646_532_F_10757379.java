import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * Created by aksenov on 17.04.2015.
 */
public class F {
    FastScanner in;
    PrintWriter out;

    public class Letter implements Comparable<Letter> {
        long hash;
        int id;

        public Letter(long hash, int id) {
            this.hash = hash;
            this.id = id;
        }

        public int compareTo(Letter l) {
            return Long.compare(l.hash, hash);
        }
    }

    public void solve() throws IOException {
        int n = in.nextInt();
        int m = in.nextInt();

        int[] mod = new int[]{179424691, 179425811, 179426339};
        int p = 43;

        char[] s = in.next().toCharArray();
        char[] t = in.next().toCharArray();

        boolean[] good = new boolean[s.length];

        Arrays.fill(good, true);

        for (int ttt = 0; ttt < mod.length; ttt++) {
            long[] pow = new long[t.length + 1];
            pow[0] = 1;
            for (int i = 1; i < pow.length; i++) {
                pow[i] = (pow[i - 1] * p) % mod[ttt];
            }

            long[] ht = new long[26];
            for (int i = 0; i < t.length; i++) {
                for (int j = 0; j < 26; j++) {
                    ht[j] = (ht[j] * p + (t[i] == 'a' + j ? 1 : 0)) % mod[ttt];
                }
            }

            Letter[] lt = new Letter[26];
            for (int i = 0; i < lt.length; i++) {
                lt[i] = new Letter(ht[i], i);
            }
            Arrays.sort(lt);

            long[] hs = new long[26];
            for (int i = 0; i < s.length; i++) {
                for (int j = 0; j < 26; j++) {
                    hs[j] = (hs[j] * p + (s[i] == 'a' + j ? 1 : 0)) % mod[ttt];
                }
                if (i >= t.length) {
                    int td = s[i - t.length] - 'a';
                    hs[td] = (hs[td] + (mod[ttt] - pow[t.length])) % mod[ttt];
                }

                if (i < t.length - 1) {
                    good[i] = false;
                    continue;
                }
                Letter[] qhs = new Letter[26];
                for (int j = 0; j < qhs.length; j++) {
                    qhs[j] = new Letter(hs[j], j);
                }
                Arrays.sort(qhs);

                int[] pair = new int[26];
                Arrays.fill(pair, -1);
                for (int j = 0; j < qhs.length; j++) {
                    if (qhs[j].hash == 0) {
                        break;
                    }
                    if (qhs[j].hash != lt[j].hash) {
                        good[i] = false;
                        break;
                    }
                    if ((pair[qhs[j].id] != lt[j].id && pair[qhs[j].id] != -1) || (pair[lt[j].id] != qhs[j].id && pair[lt[j].id] != -1)) {
                        good[i] = false;
                        break;
                    }
                    pair[qhs[j].id] = lt[j].id;
                    pair[lt[j].id] = qhs[j].id;
                }
            }
        }

        int total = 0;
        for (int i = 0; i < s.length; i++) {
            if (good[i])
                total++;
        }
        out.println(total);
        for (int i = 0; i < s.length; i++) {
            if (good[i]) {
                out.print((i - t.length + 2) + " ");
            }
        }

    }

    public void run() {
        try {
            in = new FastScanner();
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

        FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
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

    public static void main(String[] arg) {
        new F().run();
    }
}

