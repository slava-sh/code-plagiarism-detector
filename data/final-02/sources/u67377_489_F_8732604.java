import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;


public class F {
    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter out;

    int MOD;
    public void solve() throws IOException {
        int N = nextInt();
        int M = nextInt();
        MOD = nextInt();

        int[] cnt = new int[N];
        Arrays.fill(cnt, 2);
        for (int i = 0; i < M; i++) {
            String S = reader.readLine();
            for (int j = 0; j < S.length(); j++) {
                if (S.charAt(j) == '1') cnt[j]--;
            }
        }

        int init1 = 0;
        int init2 = 0;
        for (int i = 0; i < N; i++) {
            if (cnt[i] == 2) init2++;
            if (cnt[i] == 1) init1++;
        }

        long[][] C = generate_combo(N, 2);

        long[][] dp = new long[N+1][N+1];
        dp[init2][init1] = 1;
        for (int i = N; i >= 0; i--) {
            for (int j = N; j >= 0; j--) {
                if (dp[i][j] == 0) continue;

                if (i - 2 >= 0) {
                    dp[i - 2][j + 2] = mod_add(mod_time(dp[i][j], C[i][2]), dp[i - 2][j + 2]);
                }
                if (i - 1 >= 0 && j - 1 >= 0) {
                    dp[i - 1][j] = mod_add(mod_time(mod_time(dp[i][j], i), j), dp[i - 1][j]);
                }
                if (j - 2 >= 0) {
                    dp[i][j-2] = mod_add(mod_time(dp[i][j], C[j][2]), dp[i][j-2]);
                }
            }
        }

        out.println(dp[0][0]);

    }

    public long mod_time(long n1, long n2){
        return (n1 * n2) % MOD;
    }
    public long mod_add(long n1, long n2){
        return (n1 + n2) % MOD;
    }
    public long[][] generate_combo(int max_row, int max_col){
        long[][] result = new long[max_row+1][max_col+1];
        for(int i = 0; i <= max_row; i++){
            result[i][0] = 1;
            for(int j = 1; j <= Math.min(i, max_col); j++){
                result[i][j] = result[i-1][j-1] + result[i-1][j];
                if(result[i][j] >= MOD) result[i][j] -= MOD;
            }
        }
        return result;
    }

    /**
     * @param args
     */
    public static void main(String[] args) {
        new F().run();
    }

    public void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
            out = new PrintWriter(System.out);
            solve();
            reader.close();
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
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

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

}
