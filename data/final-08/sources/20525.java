import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import java.util.Scanner;

public class S {
    private static final double[] in = new double[1100];

    private static int n;

    private static final class XD {
        private int x;
        private int y;
        private double l;
    }

    private static final XD[] ed = new XD[94000];

    static {
        for (int i = 0; i < ed.length; ++i) {
            ed[i] = new XD();
        }
    }

    private static int ec;
    private static final double[] dis = new double[1030];
    private static int nn;

    private static boolean f(double avg) {
        int i, j, k;
        for (i = 0; i <= nn; i++) dis[i] = 0;
        for (i = 0; i <= nn + 2; i++)
            for (j = 0; j < ec; j++) {
                if (dis[ed[j].y] > dis[ed[j].x] + avg - ed[j].l) {
                    dis[ed[j].y] = dis[ed[j].x] + avg - ed[j].l;
                }
            }
        for (j = 0; j < ec; j++) {
            if (dis[ed[j].y] > dis[ed[j].x] + avg - ed[j].l + 1e-8) {
                break;
            }
        }
        return j < ec;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(new InputStreamReader(System.in, StandardCharsets.UTF_8));
        PrintWriter writer = new PrintWriter(new OutputStreamWriter(System.out, StandardCharsets.UTF_8));

        int i, j;
        n = scanner.nextInt();

        for (i = 0; i <= n; i++) in[i] = scanner.nextDouble();
        nn = n * 3;
        for (i = 0; i <= nn; i++) {
            for (j = 0; j <= i && j <= n; j++) {
                int r = i - j + n - j;
                if (r < 0 || r > nn) continue;
                ed[ec].x = i;
                ed[ec].y = r;
                ed[ec].l = in[j];
                ec++;
            }
        }
        double l = 0, r = 1;
        for (int k = 0; k < 40; k++) {
            double m = (l + r) / 2;
            if (f(m)) l = m;
            else r = m;
        }
        writer.println(l);

        scanner.close();
        writer.close();
    }
}
