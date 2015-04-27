
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeSet;

/**
 *
 *
 * @author pttrung
 */
public class C {

    //   public static long x, y, gcd;
    public static PrintWriter out;

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner();

        out = new PrintWriter(System.out);
        //   System.out.println(Integer.MAX_VALUE);
        // PrintWriter out = new PrintWriter(new FileOutputStream(new File("output.txt")));
        int n = in.nextInt();
        int m = in.nextInt();
        int k = in.nextInt();
        int w = in.nextInt();

        ArrayList<Edge>[] map = new ArrayList[k + 1];
        for (int i = 0; i < map.length; i++) {
            map[i] = new ArrayList();
        }
        for (int i = 0; i < k; i++) {
            map[k].add(new Edge(i, k, n * m));
        }
        String[][] data = new String[k][n];
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n; j++) {
                data[i][j] = in.next();
            }
        }
        for (int z = 0; z < k; z++) {
            for (int h = z + 1; h < k; h++) {
                int dif = 0;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        if (data[z][i].charAt(j) != data[h][i].charAt(j)) {
                            dif++;
                        }
                    }
                }
                map[z].add(new Edge(h, z, dif * w));
                map[h].add(new Edge(z, h, dif * w));
            }
        }
        PriorityQueue<Edge> q = new PriorityQueue();
        boolean[] check = new boolean[k + 1];

        q.add(new Edge(k, k, 0));
        int total = 0;
        StringBuilder result = new StringBuilder();
        while (!q.isEmpty()) {
            Edge e = q.poll();
            if (!check[e.index]) {
                check[e.index] = true;
                total += e.w;
                if(e.index != k){
                    if(e.pa == k){
                        result.append((e.index + 1)).append(" ").append("0").append("\n");
                    }else{
                        result.append((e.index + 1)).append(" ").append((e.pa + 1)).append("\n");
                    }
                }
                for(Edge o : map[e.index]){
                    q.add(o);
                }
            }
        }
        out.println(total);
        out.println(result.toString());

        out.close();
    }

    public static class Edge implements Comparable<Edge> {

        int index, pa, w;

        public Edge(int index, int pa, int w) {
            this.index = index;
            this.pa = pa;
            this.w = w;
        }

        @Override
        public int compareTo(Edge o) {
            return w - o.w;
        }
    }

    public static int dist(Point a, Point b) {
        return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    }

    public static Point clock(Point p, int n, int m) {
        Point result = new Point(p.y, n - p.x + 1);
        return result;
    }

    public static Point anti_clock(Point p, int n, int m) {
        Point result = new Point(m - p.y + 1, p.x);
        return result;
    }

    public static int cross(Point a, Point b) {
        int val = a.x * b.y - a.y * b.x;
        return val;
    }

    public static long pow(long a, long b) {
        if (b == 0) {
            return 1;
        }
        if (b == 1) {
            return a;
        }
        long val = pow(a, b / 2);
        if (b % 2 == 0) {
            return val * val;
        } else {
            return val * val * a;
        }
    }

    public static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);










    }

    public static class Point implements Comparable<Point> {

        int x, y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Point o) {
            if (x != o.x) {
                return x - o.x;
            } else {
                return y - o.y;
            }
        }

        @Override
        public int hashCode() {
            int hash = 7;
            hash = 59 * hash + this.x;
            hash = 59 * hash + this.y;
            return hash;
        }

        @Override
        public boolean equals(Object obj) {
            if (obj == null) {
                return false;
            }
            if (getClass() != obj.getClass()) {
                return false;
            }
            final Point other = (Point) obj;
            if (this.x != other.x) {
                return false;
            }
            if (this.y != other.y) {
                return false;
            }
            return true;
        }
    }
//    public static void extendEuclid(long a, long b) {
//        if (b == 0) {
//            x = 1;
//            y = 0;
//            gcd = a;
//            return;
//        }
//        extendEuclid(b, a % b);
//        long x1 = y;
//        long y1 = x - (a / b) * y;
//        x = x1;
//        y = y1;
//
//    }

    public static class FT {

        int[] data;

        FT(int n) {
            data = new int[n];
        }

        public void update(int index, int value) {
            while (index < data.length) {
                data[index] += value;
                index += (index & (-index));
            }
        }

        public int get(int index) {
            int result = 0;
            while (index > 0) {
                result += data[index];
                index -= (index & (-index));
            }
            return result;

        }
    }

    static class Scanner {

        BufferedReader br;
        StringTokenizer st;

        public Scanner() throws FileNotFoundException {
            // System.setOut(new PrintStream(new BufferedOutputStream(System.out), true));
            br = new BufferedReader(new InputStreamReader(System.in));
            //  br = new BufferedReader(new InputStreamReader(new FileInputStream(new File("input.txt"))));
        }

        public String next() {

            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (Exception e) {
                    throw new RuntimeException();
                }
            }
            return st.nextToken();
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public String nextLine() {
            st = null;
            try {
                return br.readLine();
            } catch (Exception e) {
                throw new RuntimeException();
            }
        }

        public boolean endLine() {
            try {
                String next = br.readLine();
                while (next != null && next.trim().isEmpty()) {
                    next = br.readLine();
                }
                if (next == null) {
                    return true;
                }
                st = new StringTokenizer(next);
                return st.hasMoreTokens();
            } catch (Exception e) {
                throw new RuntimeException();
            }
        }
    }
}
