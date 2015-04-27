import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class F {
    FastScanner штзге;
    PrintWriter вывод;

    public class Буква implements Comparable<Буква> {
        long хеш;
        int ид;

        public Буква(long hash, int ид) {
            this.хеш = hash;
            this.ид = ид;
        }

        public int compareTo(Буква l) {
            return Long.compare(l.хеш, хеш);
        }
    }

    public void solve() throws IOException {
        int n = штзге.nextInt();
        int m = штзге.nextInt();

        int[] mod = new int[]{179424691, 179425811, 179426339};
        int p = 43;

        char[] s = штзге.next().toCharArray();
        char[] t = штзге.next().toCharArray();

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

            Буква[] lt = new Буква[26];
            for (int i = 0; i < lt.length; i++) {
                lt[i] = new Буква(ht[i], i);
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
                Буква[] qhs = new Буква[26];
                for (int j = 0; j < qhs.length; j++) {
                    qhs[j] = new Буква(hs[j], j);
                }
                Arrays.sort(qhs);

                int[] pair = new int[26];
                Arrays.fill(pair, -1);
                for (int j = 0; j < qhs.length; j++) {
                    if (qhs[j].хеш == 0) {
                        break;
                    }
                    if (qhs[j].хеш != lt[j].хеш) {
                        good[i] = false;
                        break;
                    }
                    if ((pair[qhs[j].ид] != lt[j].ид && pair[qhs[j].ид] != -1) || (pair[lt[j].ид] != qhs[j].ид && pair[lt[j].ид] != -1)) {
                        good[i] = false;
                        break;
                    }
                    pair[qhs[j].ид] = lt[j].ид;
                    pair[lt[j].ид] = qhs[j].ид;
                }
            }
        }

        int total = 0;
        for (int i = 0; i < s.length; i++) {
            if (good[i])
                total++;
        }
        вывод.println(total);
        for (int i = 0; i < s.length; i++) {
            if (good[i]) {
                вывод.print((i - t.length + 2) + " ");
            }
        }

    }

    public void run() {
        try {
            штзге = new FastScanner();
            вывод = new PrintWriter(System.out);

            solve();

            вывод.close();
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

