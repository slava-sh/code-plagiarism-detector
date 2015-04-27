import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import java.util.Scanner;

public class S {
    private static final int co = 200;

    private static final double[] d = new double[211];
    private static final double[] p = new double[211];

    private static final int[] ss = new int[40011];
    private static final int[] ff = new int[40011];
    private static final double[] dd = new double[40011];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(new InputStreamReader(System.in, StandardCharsets.UTF_8));
        PrintWriter writer = new PrintWriter(new OutputStreamWriter(System.out, StandardCharsets.UTF_8));

        int n = scanner.nextInt();
        for (int i = 0; i <= n; ++i) p[i] = scanner.nextDouble();
        int m = 0;

        for (int i = 0; i <= co; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (j <= i) {
                    ++m;
                    ss[m] = i;
                    ff[m] = i + n - 2 * j;
                    if (ff[m] > co) ff[m] = co;
                    dd[m] = 1 - p[j];
                }
            }
        }

        double ll = 0.0;
        double rr = 1.0;

        for (int it = 1; it <= 25; ++it) {
            double mid = (ll + rr) * 0.5D;
            for (int i = 0; i <= co; ++i) d[i] = 0;
            int u = 0;

            for (int z = 0; z <= co + 1; ++z) {
                for (int i = 1; i <= m; ++i) {
                    if (d[ss[i]] + dd[i] - mid < d[ff[i]]) {
                        d[ff[i]] = d[ss[i]] + dd[i] - mid;
                        u = z;
                    }
                }
            }

            if (u == co + 1) rr = mid;
            else ll = mid;
        }

        writer.println(1.0D - (ll + rr) * 0.5D);

        scanner.close();
        writer.close();
    }
}
