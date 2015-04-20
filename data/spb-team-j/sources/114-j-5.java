import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * Created by spb on 09.11.2014.
 */
public class TaskJ {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("seq.in"));
        PrintWriter writer = new PrintWriter("seq.out");

        String[] input = reader.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int h = Integer.parseInt(input[1]);
        int[] a = new int[n];
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        int[] d = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(tokenizer.nextToken());
            if (i > 0) {
                d[i - 1] = a[i] - a[i - 1];
            }
        }
//        int[] aCopy = a.clone();
//        int[] dCopy = d.clone();

        long minPrice = Long.MAX_VALUE;
        for (int i = 0; i < n - h + 1; i++) {
//            a = aCopy.clone();
//            d = dCopy.clone();
            if (a[i] > 1) continue;
            long currentPrice = 0;
            if (a[i] == 0) {
                currentPrice++;
                d[i]--;
            }

            int lastDj = d[i];
//            int lastAj = a[i];
            for (int j = i; j < i + h - 1; j++) {
                if (lastDj == 1) continue;
                if (lastDj > 1) {
                    currentPrice = Long.MAX_VALUE;
                    break;
                }


                long x = 1 - lastDj;
                currentPrice += x;
//                a[j + 1] += x;
                lastDj = (int) (d[j + 1] - x);
            }

            minPrice = Math.min(minPrice, currentPrice);
        }
        if (minPrice == Long.MAX_VALUE) {
            writer.println(-1);
        } else {
            writer.println(minPrice);
        }
        writer.close();
    }

}
