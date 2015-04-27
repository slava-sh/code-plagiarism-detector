import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class CMST {

    public static void main(String[] args) {
        MyScanner in = new MyScanner();

        int n = in.nextInt();
        int m = in.nextInt();
        int k = in.nextInt();
        int w = in.nextInt();

        char[][][] level = new char[k][n][];

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n; j++) {
                level[i][j] = in.next().toCharArray();
            }
        }

        int[][] totalCost = new int[k][k];

        PriorityQueue<Edge> edges = new PriorityQueue<Edge>();

        for (int x = 0; x < k; x++) {
            for (int y = x + 1; y < k; y++) {
                int cost = 0;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        if (level[x][i][j] != level[y][i][j]) {
                            cost++;
                        }
                    }
                }

                cost *= w;
                cost = Math.min(cost, n * m);

                totalCost[x][y] = cost;
                totalCost[y][x] = cost;

            }
        }

        int cost = n * m;

        boolean[] added = new boolean[k];
        ArrayList<Integer> order = new ArrayList<Integer>();
        int[] num = new int[k];

        order.add(0);
        added[0] = true;
        num[0] = -1;

        for (int i = 1; i < k; i++) {
            edges.add(new Edge(0, i, totalCost[0][i]));
        }

        while (!edges.isEmpty()) {
            Edge next = edges.poll();
            if (added[next.b]) continue;

            added[next.b] = true;

            cost += next.cost;
            order.add(next.b);

            if (next.cost != n * m) {
                num[next.b] = next.a;
            }
            else {
                num[next.b] = -1;
            }

            for (int i = 0; i < k; i++) {
                if (!added[i]) {
                    edges.add(new Edge(next.b, i, totalCost[next.b][i]));
                }
            }
        }

        System.out.println(cost);
        for (Integer i : order) {

            System.out.println((i + 1) + " " + (num[i] + 1));
        }

    }

    public static class Edge implements Comparable<Edge> {
        int a, b;
        int cost;

        public Edge(int a, int b, int c) {
            this.a = a;
            this.b = b;
            this.cost = c;
        }

        @Override
        public int compareTo(Edge arg0) {
            return Integer.compare(cost, arg0.cost);
        }
    }

    public static class DisjointSets {
        int N; // The number of disjoint items
        int[] arr;

        public DisjointSets(int numElements) {
            this.N = numElements;
            arr = new int[N];
            for (int i = 0; i < N; i++) {
                arr[i] = -1;
            }
        }

        public void union(int a, int b) {
            int root1 = find(a);
            int root2 = find(b);
            if (root1 == root2) return;
            if (arr[root2] < arr[root1]) {
                arr[root1] = root2;
            }
            else {
                if (arr[root1] == arr[root2]) {
                    arr[root1]--;
                }
                arr[root2] = root1;
            }
            N--;
        }

        public int find(int a) {
            if (arr[a] < 0) return a;
            arr[a] = find(arr[a]);
            return arr[a];
        }
    }

    //-----------MyScanner class for faster input----------
    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        public MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

    }
    //--------------------------------------------------------    
}
