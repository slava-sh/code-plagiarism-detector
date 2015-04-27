import java.io.*;
import java.math.BigInteger;
import java.util.Locale;
import java.util.StringTokenizer;


/**
 * User: Igor Kirov
 * Date: 13.06.2014
 */
public class C implements Runnable {
    class Room {
        char[][] c;
        int cost;
        int type;
        int idx;
        boolean used = false;

        public Room(int n, int m, int idx) throws IOException {
            c = new char[n][m];
            for (int i = 0; i < n; i++) {
                String s = nextToken();
                int j = 0;
                for (char cc : s.toCharArray()) {
                    c[i][j] = cc;
                    j++;
                }
            }
            cost = n * m;
            type = -1;
            this.idx = idx;
        }
    }

    private int getCost(Room a, Room b, int w) {
        int diff = 0;
        for (int i = 0; i < a.c.length; i++) {
            for (int j = 0; j < a.c[i].length; j++) {
                if (a.c[i][j] != b.c[i][j]) {
                    diff++;
                }
            }
        }
        return Math.min(a.c.length * a.c[0].length, diff * w);
    }

    private void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int k = nextInt();
        int w = nextInt();

        Room[] rooms = new Room[k];
        for (int t = 0; t < k; t++) {
            rooms[t] = new Room(n, m, t);
        }

        Room[] res = new Room[k];
        int[] type = new int[k];
        res[0] = rooms[0];
        type[0] = -1;
        rooms[0].used = true;

        for (int i = 1; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (rooms[j].used) {
                    continue;
                }
                int nc = getCost(rooms[j], res[i - 1], w);
                if (nc < rooms[j].cost) {
                    rooms[j].cost = nc;
                    rooms[j].type = i - 1;
                }
            }

            int min = Integer.MAX_VALUE;
            int idx = -1;
            for (int j = 0; j < k; j++) {
                if (rooms[j].used) {
                    continue;
                }
                if (rooms[j].cost < min) {
                    min = rooms[j].cost;
                    idx = j;
                }
            }

            res[i] = rooms[idx];
            type[i] = rooms[idx].type;
            res[i].used = true;
        }

        int ans = 0;
        for (int i = 0; i < k; i++) {
            ans += res[i].cost;
        }
        writer.println(ans);
        for (int i = 0; i < k; i++) {
            if (type[i] == -1) {
                writer.println((res[i].idx + 1) + " " + 0);
            } else {
                writer.println((res[i].idx + 1) + " " + (res[type[i]].idx + 1));
            }
        }
    }

    public static void main(String[] args) {
        new Thread(null, new C(), "", 64 * 1024 * 1024).start();
    }

    StringTokenizer tokenizer;
    BufferedReader reader;
    PrintWriter writer;

    public void run() {
        try {
            try {
                Locale.setDefault(Locale.US);
            } catch (Exception ignored) {
            }

            boolean oj = System.getProperty("ONLINE_JUDGE") != null;

            reader = new BufferedReader(oj ? new InputStreamReader(System.in) : new FileReader("C.in"));
            writer = new PrintWriter(oj ? new OutputStreamWriter(System.out) : new FileWriter("C.out"));

            tokenizer = null;

            solve();

            reader.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    private int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    private BigInteger nextBigInteger() throws IOException {
        return new BigInteger(nextToken());
    }

    private double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    private String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}