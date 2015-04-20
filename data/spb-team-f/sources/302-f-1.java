import java.io.*;
import java.util.*;
import java.lang.*;

public class F1 {
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

    ArrayList<Long> divisors(long n) {
        ArrayList<Long> ans = new ArrayList<Long>();
        for (long i = 1; i * i <= n; ++i) {
            if (i * i == n)
                ans.add(i);
            else if (n % i == 0) {
                ans.add(i);
                ans.add(n / i);
            }
        }
        return(ans);
    }


    long a, b;
    long gcd, lcd;

    long lcd(long x, long y) {
        return x * y / gcd(x, y);
    }

    long gcd(long x, long y) {
        if (y == 0)
            return x;
        return gcd(y, x % y);
    }

    void init() {
        gcd = gcd(a, b);
        lcd = lcd(a, b);
    }

    boolean check(long x) {
        return gcd(x, a * b / x) == gcd && lcd(x, a * b / x) == lcd;
    }

    long sqr(long x) {
        return x * x;
    }

    void solve() throws IOException {
        a = nextLong();
        b = nextLong();
        init();
        ArrayList<Long> divsa = divisors(a);
        ArrayList<Long> divsb = divisors(b);
        ArrayList<Long> divs = new ArrayList<Long>();
        for (int i = 0; i < divsa.size(); ++i)
            for (int j = 0; j < divsb.size(); ++j)
                if (divsa.get(i) * divsb.get(j) <= 3037000499L && sqr(divsa.get(i) * divsb.get(j)) <= a * b)
                    divs.add(divsa.get(i) * divsb.get(j));
        long min = Long.MAX_VALUE;
        long minx = -1;
        long miny = -1;
        for (long i : divs) {
            if (check(i) && a * b / i - i < min) {
                min = a * b / i - i;
                minx = i;
                miny = a * b / i;
            }
        }
        out.print(minx + " " + miny);
    }

    void run() {
        try {
            br = new BufferedReader(new FileReader("gcm.in"));
            out = new PrintWriter("gcm.out");
            solve();
        } catch (Exception e) {
            e.printStackTrace();
        }
        out.close();
    }



    public static void main(String[] args) {
        new F1().run();
    }
}

