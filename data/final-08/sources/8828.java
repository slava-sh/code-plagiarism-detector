import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import java.util.Scanner;

import static java.lang.StrictMath.max;

public class S {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(new InputStreamReader(System.in, StandardCharsets.UTF_8));
        PrintWriter writer = new PrintWriter(new OutputStreamWriter(System.out, StandardCharsets.UTF_8));

        int n = scanner.nextInt();
        double[] ps = new double[n + 1];

        for (int i = 0; i < ps.length; ++i) {
            ps[i] = scanner.nextDouble();
        }

        double ret = 0.0D;

        for (int a = 0; a < n; ++a) {
            for (int b = a + 1; b < n + 1; ++b) {
                if (2 * a > n || 2 * b < n) {
                    continue;
                }

                double ca = (0.5 * n - b) / (a - b);
                double cb = (0.5 * n - a) / (b - a);

                ret = max(ret, ca * ps[a] + cb * ps[b]);
            }
        }

        writer.printf("%.9f%n", ret);

        scanner.close();
        writer.close();
    }
}
