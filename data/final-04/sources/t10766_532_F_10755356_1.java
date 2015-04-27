import java.io.*;
import java.util.*;

public class SolF {

    FastScanner input;
    PrintWriter vyvod;

    void solve() {
        int cnt = input.nextInt(), tax = input.nextInt();
        String troka = input.nextToken(), kusok = input.nextToken();
        List<Integer> result = new ArrayList<Integer>();

        int[] x = encode(kusok), y = encode(troka);
        int[][] sledS = calcNext(troka), sledT = calcNext(kusok);

        int[] pf = new int[x.length];
        for (int _ = 1; _ < x.length; _++) {
            int sd = pf[_ - 1];
            while (sd > 0 && !ravn(x, _ - sd, _, x, sd)) {
                sd = pf[sd - 1];
            }
            if (ravn(x, _ - sd, _, x, sd)) {
                sd++;
            }
            pf[_] = sd;
        }

        int re = 0;
        for (int _ = 0; _ < y.length; _++) {
            while (re > 0 && !ravn(y, _ - re, _, x, re)) {
                re = pf[re - 1];
            }
            if (ravn(y, _ - re, _, x, re)) {
                re++;
            }
            if (re == x.length) {
                result.add(_ - x.length + 1);
                re = pf[re - 1];
            }
        }

        List<Integer> answw = new ArrayList<Integer>();
        for (int p : result) {
            int[] mapStr = new int[26];
            int[] asqq = new int[26];
            boolean flaf = true;
            Arrays.fill(mapStr, -1);
            Arrays.fill(asqq, -1);

            for (int l = 0; l < 26; l++) {
                int ps = sledS[l][p];
                if (ps - p >= kusok.length()) {
                    continue;
                }

                int corrT = kusok.charAt(ps - p) - 'a';
                if (asqq[corrT] != -1) {
                    flaf = false;
                    break;
                }
                asqq[corrT] = l;
                mapStr[l] = corrT;
            }

            for (int i = 0; i < 26; i++) {
                if (asqq[i] == -1) {
                    continue;
                }
                int j = asqq[i];
                if ((mapStr[i] != -1 && mapStr[i] != j) || (asqq[j] != -1 && asqq[j] != i)) {
                    flaf = false;
                    break;
                }
            }

            if (flaf) {
                answw.add(p);
            }
        }
        vyvod.println(answw.size());
        for (int i = 0; i < answw.size(); i++) {
            vyvod.print((answw.get(i) + 1) + " ");
        }
    }

    boolean ravn(int[] fst, int l, int r, int[] snd, int pos) {
        int val1 = -1;
        if (fst[r] != -1 && fst[r] <= r - l) {
            val1 = fst[r];
        }
        return val1 == snd[pos];
    }

    private int[][] calcNext(String s) {
        int[][] next = new int[26][s.length()];
        int[] last = new int[26];
        Arrays.fill(last, s.length());

        for (int i = 0; i < 26; i++) {
            next[i][s.length() - 1] = s.length();
        }
        for (int i = s.length() - 1; i >= 0; i--) {
            if (i + 1 < s.length()) {
                for (int j = 0; j < 26; j++) {
                    next[j][i] = next[j][i + 1];
                }
            }
            next[s.charAt(i) - 'a'][i] = i;
        }
        return next;
    }
    public static void main(String[] args) {
        new SolF().run();
    }

    int[] encode(String gib) {
        int[] post = new int[256];
        Arrays.fill(post, -1);
        int[] ssd = new int[gib.length()];
        for (int _ = 0; _ < gib.length(); _++) {
            char c = gib.charAt(_);
            if (post[c] == -1) {
                ssd[_] = -1;
            } else {
                ssd[_] = _ - post[c];
            }
            post[c] = _;
        }
        return ssd;
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public FastScanner(String s) {
            try {
                br = new BufferedReader(new FileReader(s));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(nextToken());
        }

        long nextLong() {
            return Long.parseLong(nextToken());
        }

        double nextDouble() {
            return Double.parseDouble(nextToken());
        }
    }

    void run() {
        input = new FastScanner();
        vyvod = new PrintWriter(System.out);
        solve();
        vyvod.close();
    }

}
