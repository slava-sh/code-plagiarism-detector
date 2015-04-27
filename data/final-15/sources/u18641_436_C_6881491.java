import java.io.*;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Author: Sergey Paramonov
 * Date: 13.06.14
 * Time: 19:03
 */
public class Zepto_20140613_C {

    Scanner scanner = new Scanner(System.in);
    BufferedReader buffered = new BufferedReader(new InputStreamReader(System.in));
    StreamTokenizer input = new StreamTokenizer(buffered);

    static PrintWriter output = new PrintWriter(new BufferedOutputStream(System.out));

    int nextInt() throws Exception {
        input.nextToken();
        return (int) input.nval;
    }

    static void flushAndClose() {
        output.flush();
        System.out.flush();
        output.close();
    }

    void main() throws Exception {
        String[] str = buffered.readLine().split(" ");
        int n = Integer.valueOf(str[0]);
        int m = Integer.valueOf(str[1]);
        int k = Integer.valueOf(str[2]);
        int w = Integer.valueOf(str[3]);

        char[][][] c = new char[k][n][m];
        for (int i=0; i<k; i++) {
            for (int j=0; j<n; j++) {
                String s = buffered.readLine();
                for (int q=0; q<m; q++) {
                    c[i][j][q] = s.charAt(q);
                }
            }
        }

        int[][] r = new int[k][k];
        boolean[][] b = new boolean[k][k];

        for (int i=0; i<k; i++) {
            for (int j=i; j<k; j++) {
                int R = 0;
                boolean B = true;
                for (int x=0; x<n; x++) {
                    for (int y=0; y<m; y++) {
                        if (c[i][x][y] != c[j][x][y]) {
                            R++;
                        }
                    }
                }
                R *= w;

                if (R >= n*m) {
                    R = n*m;
                    B = false;
                }
                r[i][j] = R;
                b[i][j] = B;
                r[j][i] = R;
                b[j][i] = B;
            }
        }

        int[] sum = new int[k];
        for (int i=0; i<k; i++) {
            sum[i] = 0;
            for (int j=0; j<k; j++) {
                sum[i] += r[i][j];
            }
        }

        int[][] ans = new int[k][2];
        boolean[] was = new boolean[k];
        Arrays.fill(was, false);
        int[] cur = new int[k];
        Arrays.fill(cur, n*m);
        int[] curb = new int[k];
        Arrays.fill(curb, 0);
        int ANS = 0;

        for (int i=0; i<k; i++) {
            int minc = n*m + 100500;
            int minsum = 2000000000;
            int p = -1;
            for (int j=0; j<k; j++) {
                if (!was[j] && (cur[j] < minc || (cur[j] == minc && sum[j] < minsum))) {
                    p = j;
                    minc = cur[j];
                    minsum = sum[j];
                }
            }

            was[p] = true;
            ANS += minc;
            ans[i][0] = p+1;
            ans[i][1] = curb[p];
            for (int j=0; j<k; j++) {
                if (cur[j] > r[p][j]) {
                    cur[j] = r[p][j];
                    curb[j] = b[p][j] ? (p+1) : 0;
                }
            }
        }

        System.out.println(ANS);
        for (int i=0; i<k; i++) {
            System.out.println(ans[i][0] + " " + ans[i][1]);
        }
    }

    public static void main(String[] args) throws Exception {
        new Zepto_20140613_C().main();
        flushAndClose();
    }

}
