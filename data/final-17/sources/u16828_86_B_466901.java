import java.util.*;


public class Prob3B {

    public static void main(String... args) {
        Scanner in = new Scanner(System.in);
        int[][] a;
        int m, n;
        m = in.nextInt();
        n = in.nextInt();
        a = new int[m + 2][n + 2];

        for (int i = 0; i < m + 2; i++) {
            a[i][0] = a[i][n + 1] = -1;
        } // for
        for (int i = 0; i < n + 2; i++) {
            a[0][i] = a[m + 1][i] = -1;
        } // for

        for (int i = 0; i < m; i++) {
            String s = in.next();
            for (int j = 0; j < n; j++) {
                a[i + 1][j + 1] = s.charAt(j) == '.' ? 0 : -1;
            } // for
        } // for

        int x, y;
        y = 1;
        while (y <= m) {
            x = 1;
            int c1 = (y % 3) * 3 + 1;
            int c2 = 0;
            while (x <= n) {
                //System.out.println(y + " " + x + " " + a[y][x]);
                if (a[y][x] != 0) {
                    x++;
                    continue;
                } // if
                if (a[y][x + 1] == 0) {
                    a[y][x] = a[y][x + 1] = c1 + c2;
                    c2++;
                    c2 %= 3;
                    x += 2;
                    //System.out.println("A");
                    continue;
                } // if
                if (a[y + 1][x] == 0) {
                    a[y][x] = a[y + 1][x] = c1 + c2;
                    c2++;
                    c2 %= 3;
                    x++;
                    //System.out.println("B");
                    continue;
                } // if
                if (a[y][x - 1] != -1) {
                    a[y][x] = a[y][x - 1];
                    x++;
                    //System.out.println("C");
                    continue;
                } // if
                if (a[y - 1][x] != -1) {
                    a[y][x] = a[y - 1][x];
                    c2++;
                    c2 %= 3;
                    x++;
                    //System.out.println("D");
                    continue;
                } // if
                if (a[y][x + 1] != -1) {
                    a[y][x] = a[y][x + 1];
                    c2++;
                    c2 %= 3;
                    x += 2;
                    //System.out.println("E");
                    continue;
                } // if
                System.out.println("-1");
                return;
            } // while
            y++;
        } // while

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int v = a[i][j];
                System.out.print(v < 0 ? '#' : (char)('0' + v));
            } // for
            System.out.println();
        } // for

    } // main


} // class Prob3B
