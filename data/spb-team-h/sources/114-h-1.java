import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;

/**
 * Created by spb on 09.11.2014.
 */
public class TaskH {

    public static void main(String[] args) throws IOException{
        BufferedReader reader = new BufferedReader(new FileReader("names.in"));
        PrintWriter writer = new PrintWriter("names.out");

        int n = Integer.parseInt(reader.readLine());
        String[][] names = new String[n][3];
        String[] input;
        HashMap<String, Integer> count = new HashMap<String, Integer>();
        for (int i = 0; i < n; i++) {
            input = reader.readLine().split(" ");
            names[i][2] = input[2];
            names[i][0] = input[0];
            names[i][1] = input[1];

            if (count.containsKey(input[0])) {
                count.put(input[0], count.get(input[0]) + 1);
            } else {
                count.put(input[0], 1);
            }

            if (count.containsKey(input[1])) {
                count.put(input[1], count.get(input[1]) + 1);
            } else {
                count.put(input[1], 1);
            }

            if (count.containsKey(input[2])) {
                count.put(input[2], count.get(input[2]) + 1);
            } else {
                count.put(input[2], 1);
            }
        }

        String[] list = new String[n];
        StringBuilder builder;
        for (int i = 0; i < n; i++) {
            builder = new StringBuilder();
            if (count.get(names[i][0]) < 2) {
                builder.append(names[i][0]).append(" ").append(names[i][1]).append(" ").append(names[i][2]);
            } else {
                builder.append(names[i][2]).append(" ").append(names[i][0]).append(" ").append(names[i][1]);
            }
            list[i] = builder.toString();
        }
        Arrays.sort(list);

        builder = new StringBuilder();
        for (String item : list) {
            builder.append(item).append("\n");
        }
        writer.println(builder.toString());
        writer.close();
    }

}