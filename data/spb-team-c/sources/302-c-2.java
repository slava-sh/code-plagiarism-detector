import java.io.*;
import java.util.*;
import java.lang.*;

public class C {
    BufferedReader br;
    StringTokenizer in;
    PrintWriter out;

    String nextToken() throws IOException {
        while (in == null || !in.hasMoreTokens()) {
            in = new StringTokenizer(br.readLine());
        }
        return in.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    class Pair implements Comparable<Pair> {
        int a;
        int c;

        public Pair(int a, int c) {
            this.a = a;
            this.c = c;
        }

        @Override
        public int compareTo(Pair o) {
            if (this.a < o.a) {
                return -1;
            }
            if (this.a > o.a) {
                return 1;
            }
            if (this.c < o.c) {
                return -1;
            }
            if (this.c > o.c) {
                return 1;
            }
            return 0;
        }
    }

    int n;
    int[] eatpre;
    int[] eatpost;
    int[] postsum;
    int[] presum;
    Pair[] arr;

    int check(int i, int a, int b, int sum, boolean[] f) {
        if (i > 0 && eatpre[i - 1] <= sum && !f[0]) {
            sum += presum[i];
            f[0] = true;
        }
        if (i + 2 < n && eatpost[i + 2] <= sum && !f[1]) {
            sum += postsum[i + 1];
            f[1] = true;
        }
        if (arr[i].a - a <= sum && !f[2]) {
            sum += arr[i].a - a;
            f[2] = true;
        }
        if (arr[i + 1].a - b <= sum && !f[3]) {
            sum += arr[i].a - a;
            f[3] = true;
        }
        return sum;
    }

    int check1(int a, int b, int sum, boolean[] f) {
        if (2 < n && eatpost[2] <= sum && !f[1]) {
            sum += postsum[1];
            f[1] = true;
        }
        if (arr[0].a - a <= sum && !f[2]) {
            sum += arr[0].a - a;
            f[2] = true;
        }
        if (arr[1].a - b <= sum && !f[3]) {
            sum += arr[0].a - a;
            f[3] = true;
        }
        return sum;
    }

    int check2(int a, int b, int sum, boolean[] f) {
        int i = n - 2;
        if (eatpre[i - 1] <= sum && !f[0]) {
            sum += presum[i];
            f[0] = true;
        }
        if (arr[i].a - a <= sum && !f[2]) {
            sum += arr[i].a - a;
            f[2] = true;
        }
        if (arr[i + 1].a - b <= sum && !f[3]) {
            sum += arr[i].a - a;
            f[3] = true;
        }
        return sum;
    }

    void solve() throws IOException {
        n = nextInt();
        arr = new Pair[n];
        for (int i = 0; i < n; i++) {
            arr[i] = new Pair(nextInt(), nextInt());
        }
        Arrays.sort(arr);
        presum = new int[n + 1];
        for (int i = 0; i < n; i++) {
            presum[i + 1] = presum[i] + arr[i].a;
        }
        postsum = new int[n + 1];
        for (int i = n - 1; i > -1; i--) {
            postsum[i] = postsum[i + 1] + arr[i].a;
        }
        eatpre = new int[n];
        eatpre[0] = arr[0].a + 1;
        for (int i = 1; i < n; i++) {
            eatpre[i] = Math.max(eatpre[i - 1], arr[i].a - presum[i] + 1);
        }
        eatpost = new int[n];
//        eatpost[n - 1] = arr[n - 1].a + 1;
        for (int i = 0; i < n; i++) {
            int cur = 0;
            for (int j = i; j < n; j++) {
                if (cur <= arr[j].a) {
                    eatpost[i] += arr[j].a + 1 - cur;
                    cur += arr[j].a + 1 - cur;
                }
                cur += arr[j].a;
            }
        }
        int min = Integer.MAX_VALUE;
        // i = 0
        for (int a = 0; a <= arr[0].a; a++) {
            for (int b = 0; b <= arr[1].a; b++) {

                int sum = a + b;
                boolean[] f = new boolean[4];
                sum = check1(a, b, sum, f);
                sum = check1(a, b, sum, f);
                sum = check1(a, b, sum, f);
                check1(a, b, sum, f);
                if (f[1] && f[2] && f[3] && a * arr[0].c + b * arr[1].c < min) {
                    //out.print(a + " " + b + " " + 0);
                    min = a * arr[0].c + b * arr[1].c;
                }
            }
        }
        // i = n - 2

        int i = n - 2;
        for (int a = 0; a <= arr[i].a; a++) {
            for (int b = 0; b <= arr[i + 1].a; b++) {
                int sum = a + b;
                boolean[] f = new boolean[4];
                sum = check2(a, b, sum, f);
                sum = check2(a, b, sum, f);
                sum = check2(a, b, sum, f);
                check2(a, b, sum, f);
                if (f[0] && f[2] && f[3] && a * arr[i].c + b * arr[i + 1].c < min) {
                    //out.print(a + " " + b + " " + i);
                    min = a * arr[i].c + b * arr[i + 1].c;
                }
            }
        }

        for (i = 1; i < n - 2; i++) {
            for (int a = 0; a <= arr[i].a; a++) {
                for (int b = 0; b <= arr[i + 1].a; b++) {
                    int sum = a + b;
                    boolean[] f = new boolean[4];
                    sum = check(i, a, b, sum, f);
                    sum = check(i, a, b, sum, f);
                    sum = check(i, a, b, sum, f);
                    check(i, a, b, sum, f);
                    if (f[0] && f[1] && f[2] && f[3] && a * arr[i].c + b * arr[i + 1].c < min) {
                        //out.print(a + " " + b + " " + 0);
                        min = a * arr[i].c + b * arr[i + 1].c;
                    }
                }
            }
        }
        out.print(min);
    }

    void run() throws IOException {
        br = new BufferedReader(new FileReader("conquest.in"));
        out = new PrintWriter("conquest.out");
        solve();
        out.close();
    }


    public static void main(String[] args) throws IOException {
        new C().run();
    }
}
