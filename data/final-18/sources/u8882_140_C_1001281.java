import java.io.*;
import java.util.*;
import java.util.Map.Entry;

public class C implements Runnable {
    private MyScanner in;
    private PrintWriter out;

    private void solve() {
        int n = in.nextInt();
        HashMap<Integer, Integer> rs = new HashMap<Integer, Integer>();
        for (int i = 0; i < n; ++i) {
            int r = in.nextInt();
            if (rs.containsKey(r)) {
                rs.put(r, rs.get(r) + 1);
            } else {
                rs.put(r, 1);
            }
        }
        TreeSet<Item> items = new TreeSet<Item>();
        for (Entry<Integer, Integer> e : rs.entrySet()) {
            items.add(new Item(e.getKey(), e.getValue()));
        }
        ArrayList<Integer> ans = new ArrayList<Integer>();
        int[] temp = new int[3];
        Item[] it = new Item[3];
        while (items.size() >= 3) {
            for (int i = 0; i < 3; ++i) {
                it[i] = items.first();
                items.remove(it[i]);
                temp[i] = it[i].r;
            }
            Arrays.sort(temp);
            for (int i = 2; i >= 0; --i) {
                ans.add(temp[i]);
            }
            for (int i = 0; i < 3; ++i) {
                if (it[i].num > 1) {
                    --it[i].num;
                    items.add(it[i]);
                }
            }
        }
        out.println(ans.size() / 3);
        for (int i = 0; i < ans.size(); i += 3) {
            for (int j = 0; j < 3; ++j) {
                out.print(ans.get(i + j) + " ");
            }
            out.println();
        }
    }

    @Override
    public void run() {
        in = new MyScanner();
        out = new PrintWriter(System.out);
        solve();
        in.close();
        out.close();
    }

    public static void main(String[] args) {
        new C().run();
    }
    
    static class Item implements Comparable<Item> {
        public int r, num;
        
        public Item(int r, int num) {
            this.r = r;
            this.num = num;
        }

        @Override
        public int compareTo(Item o) {
            if (num != o.num) {
                return o.num - num;
            }
            return r - o.r;
        }
    }

    static class MyScanner {
        private BufferedReader br;
        private StringTokenizer st;

        public MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public void close() {
            try {
                br.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        private String nextToken() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                    return null;
                }
            }
            return st.nextToken();
        }

        public String nextLine() {
            try {
                st = null;
                return br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
                return null;
            }
        }

        public String next() {
            return nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextToken());
        }

        public long nextLong() {
            return Long.parseLong(nextToken());
        }

        public double nextDouble() {
            return Double.parseDouble(nextToken());
        }
    }
}