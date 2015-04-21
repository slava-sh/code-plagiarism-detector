import java.io.*;
import java.util.*;

public class Main {
    private static class FastReader {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        public FastReader(InputStream inputStream) {
            reader = new BufferedReader(new InputStreamReader(inputStream), 1 << 16);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                }
                catch (IOException ex) {
                    throw new RuntimeException(ex);
                }
            }
            return tokenizer.nextToken();
        }

        public String nextLine() {
            try {
                return reader.readLine();
            }
            catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) {
	    FastReader in = new FastReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        long n = in.nextLong();
        int k = in.nextInt();
        HashMap<ArrayList<Integer>, Long>[] dp = new HashMap[k];
        for (int i = 0; i < k; ++i) {
            dp[i] = new HashMap<ArrayList<Integer>, Long>();
        }
        ArrayList<Long> factors = factorize(n);
        int factorsCount = factors.size() / 2;
        long[] primes = new long[factorsCount];
        int[] powers = new int[factorsCount];
        for (int i = 0; i < factorsCount; ++i) {
            primes[i] = factors.get(2 * i);
            long power = factors.get(2 * i + 1);
            powers[i] = (int)power;
        }
        int[] trialPowers = new int[factorsCount];
        while (trialPowers[0] >= 0) {
            long d = evaluate(primes, trialPowers);
            ArrayList<Integer> list = new ArrayList<Integer>();
            for (int i : trialPowers) {
                list.add(i);
            }
            dp[0].put(list, E(d));
            nextPowers(trialPowers, powers);
        }
        for (int i = 1; i < k; ++i) {
            trialPowers = new int[factorsCount];
            while (trialPowers[0] >= 0) {
                ArrayList<Integer> list = new ArrayList<Integer>();
                for (int p : trialPowers) {
                    list.add(p);
                }
                long value = Long.MAX_VALUE;
                int[] lowTrialPowers = new int[factorsCount];
                while (lowTrialPowers[0] >= 0) {
                    ArrayList<Integer> lowList = new ArrayList<Integer>();
                    ArrayList<Integer> dualList = new ArrayList<Integer>();
                    for (int idx = 0; idx < factorsCount; ++idx) {
                        lowList.add(lowTrialPowers[idx]);
                        dualList.add(trialPowers[idx] - lowTrialPowers[idx]);
                    }
                    long trialValue = dp[i - 1].get(dualList) * dp[0].get(lowList);
                    if (trialValue < value) {
                        value = trialValue;
                    }
                    dp[i].put(list, value);
                    nextPowers(lowTrialPowers, trialPowers);
                }
                nextPowers(trialPowers, powers);
            }
        }
        /*for (int i = 1; i < k; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = Integer.MAX_VALUE;
                for (int d = 1; d <= j; ++d) {
                    if (j % d == 0) {
                        int trial = dp[i - 1][j / d] * dp[0][d];
                        if (trial < dp[i][j]) {
                            dp[i][j] = trial;
                        }
                    }
                }
            }
        }
        out.println(dp[k - 1][n]);
        */
        ArrayList<Integer> list = new ArrayList<Integer>();
        for (int p : powers) {
            list.add(p);
        }
        out.println(dp[k - 1].get(list));
        out.flush();
    }

    private static long evaluate(long[] primes, int[] trialPowers) {
        long res = 1;
        for (int i = 0; i < primes.length; ++i) {
            for (int j = 0; j < trialPowers[i]; ++j) {
                res *= primes[i];
            }
        }
        return res;
    }

    private static void nextPowers(int[] trialPowers, int[] powers) {
        boolean isLast = true;
        for (int i = trialPowers.length - 1; i >= 0; --i) {
            if (trialPowers[i] < powers[i]) {
                trialPowers[i]++;
                isLast = false;
                break;
            }
            else {
                trialPowers[i] = 0;
            }
        }
        if (isLast) trialPowers[0] = -1;
    }

    private static ArrayList<Long> factorize(long n) {
        ArrayList<Long> res = new ArrayList<Long>();
        for (long i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                res.add(i);
                int power = 0;
                while (n % i == 0) {
                    n /= i;
                    ++power;
                }
                res.add((long)power);
            }
        }
        if (n > 1) {
            res.add(n);
            res.add(1l);
        }
        return res;
    }

    private static long E(long n) {
        return (n >> 1) + (n & 1);
    }
}
