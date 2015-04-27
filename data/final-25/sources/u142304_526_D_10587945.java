import java.io.*;
import java.util.*;
import java.util.List;

public class Main {
    private static StringTokenizer st;
    private static BufferedReader br;
    public static long MOD = 1000000007;

    public static void print(Object x) {
        System.out.println(x + "");
    }
    public static void printArr(long[] x) {
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < x.length; i++) {
            s.append(x[i] + " ");
        }
        print(s);
    }
    public static void printArr(int[] x) {
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < x.length; i++) {
            s.append(x[i] + " ");
        }
        print(s);
    }
    public static String join(Collection<?> x, String space) {
        if (x.size() == 0) return "";
        StringBuilder sb = new StringBuilder();
        boolean first = true;
        for (Object elt : x) {
            if (first) first = false;
            else sb.append(space);
            sb.append(elt);
        }
        return sb.toString();
    }

    public static String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();
            st = new StringTokenizer(line.trim());
        }
        return st.nextToken();
    }
    public static int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }
    public static long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }
    public static List<Integer> nextInts(int N) throws IOException {
        List<Integer> ret = new ArrayList<Integer>();
        for (int i = 0; i < N; i++) {
            ret.add(nextInt());
        }
        return ret;
    }

    public static class RollingHash {
        int n;
        long[] hashes;
        long[] aPow;
        public static long a = 31;

        public RollingHash(char[] s) {
            n = s.length;
            hashes = new long[n+1];
            aPow = new long[n];

            long hash = 0;
            for (int i = 1; i <= n; i++) {
                hash = ((hash * a) + s[i-1]) % MOD;
                hashes[i] = hash;
            }

            long pow = 1;
            for (int i = 0; i < n; i++) {
                aPow[i] = pow;
                pow = (pow * a) % MOD;
            }
        }

        public long hash(int i, int j) {
            long hash = hashes[j] - ((hashes[i] * aPow[j-i]) % MOD);
            return (hash + MOD) % MOD;
        }

        public boolean equal(int i, int i2, int length) {
            return hash(i, i+length) == hash(i2, i2+length);
        }
    }

    public static int firstMismatch(RollingHash hash, int n, int m, int k) {
        int max = Math.min(m, n-k*m);
        if (hash.equal(0, k*m, max)) return max+1;
        int i = 0;
        int j = max;
        while (i < j - 1) {
            int mid = (i+j)/2;
            if (hash.equal(0, k*m, mid)) i = mid;
            else j = mid;
        }
        return j;
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));

        int n = nextInt();
        int k = nextInt();

        char[] s = nextToken().toCharArray();
        RollingHash hash = new RollingHash(s);

        int[] sum = new int[n+2];
        outer : for (int m = 1; m * k <= n; m++) {
            for (int i = 0; i < k - 1; i++)
                if (!hash.equal(i*m, (i+1)*m, m)) continue outer;
            sum[m*k] += 1;
            sum[m*k + firstMismatch(hash, n, m, k)] -= 1;
        }

        int cur = 0;
        StringBuilder out = new StringBuilder();
        for (int i = 1; i <= n; i++) {
            cur += sum[i];
            out.append((cur > 0) ? "1" : "0");
        }
        print(out);
    }
}
