import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * Created by spb on 09.11.2014.
 */
public class TaskE {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("game.in"));
        PrintWriter writer = new PrintWriter("game.out");

        String[] input = reader.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);

        input = reader.readLine().split(" ");
        int l1 = Integer.parseInt(input[0]);
        int r1 = Integer.parseInt(input[1]);

        input = reader.readLine().split(" ");
        int l2 = Integer.parseInt(input[0]);
        int r2 = Integer.parseInt(input[1]);

        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        int[] a = new int[n];
        int left1 = -1, right1 = -1;
        int left2 = -1, right2 = -1;
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(tokenizer.nextToken());
        }
        Arrays.sort(a);

        for (int i = 0; i < n; i++) {
            if (left1 == -1 && a[i] >= l1) {
                left1 = i;
                right1 = i;
            }
            if (left2 == -1 && a[i] >= l2) {
                left2 = i;
                right2 = i;
            }

            if (a[i] <= r1) {
                right1 = i;
            }
            if (a[i] <= r2) {
                right2 = i;
            }
        }

        boolean b1 = false;
        if (left1 == -1 || right1 == -1) {
            b1 = true;
        }
        boolean b2 = false;
        if (right2 == -1 || left2 == -1) {
            b2 = true;
        }

        if (b1 && b2) {
            writer.println("Draw");
            writer.close();
            System.exit(0);
        }
        if (b1) {
            writer.println("Vasya");
            writer.close();
            System.exit(0);
        }
        if (b2) {
            writer.println("Petya");
            writer.close();
            System.exit(0);
        }

        int points1 = 0;
        int points2 = 0;

        int common = Math.min(right1, right2) - Math.max(left1, left2) + 1;
        boolean first = true;
        if (common < 0) {
            common = 0;
        }

        int only1 = right1 - left1 - common + 1;
        int only2 = right2 - left2 - common + 1;

        if (only1 < 0) only1 = 0;
        if (only2 < 0) only2 = 0;

        if (m <= common) {

            if (m % 2 == 0) {
                points1 = m / 2;
                points2 = points1;
            } else {
                points1 = m / 2 + 1;
                points2 = points1 - 1;
                first = false;
            }
            m = 0;

        } else {

            if (common % 2 == 0) {
                points1 = common / 2;
                points2 = points1;
            } else {
                points1 = common / 2 + 1;
                points2 = points1 - 1;
                first = false;
            }
            m -= common;

        }


        while (m > 0) {
            if (only1 == 0 && only2 == 0) break;

            if (first) {
                if (only1 > 0) {
                    only1--;
                    points1++;
                    m--;
                }
            } else {
                if (only2 > 0) {
                    only2--;
                    points2++;
                    m--;
                }
            }
            first = !first;
        }


        if (points1 == points2) {
            writer.println("Draw");
        } else if (points1 > points2) {
            writer.println("Petya");
        } else {
            writer.println("Vasya");
        }
        writer.close();
    }

}
