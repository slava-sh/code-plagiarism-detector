import java.util.*;
import java.math.*;
import java.io.*;
public class C {
    public static long time = 0;
    public static void main(String[] args) throws Exception {
        time = System.currentTimeMillis();
        
        IN = System.in;
        OUT = System.out;
        in = new BufferedReader(new InputStreamReader(IN));
        out = new PrintWriter(OUT, FLUSH);
        solveOne();
        out.flush();
    }
    
    public static void solveOne() throws Exception {
        int n = nextInt();
        int m = nextInt();
        int k = nextInt();
        int w = nextInt();
        char[][][] levels = new char[k][n][];;
        for (int i = 0 ; i < k ;i++){
            for (int j = 0; j < n;j ++){
                levels[i][j] = nextString().toCharArray();
            }
        }
        int[][] cost = new int[k][k];
        PriorityQueue<int[]> q = new PriorityQueue<>(k * k, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[2] - o2[2];
            }
        });
        for (int i = 0; i < k; i++){
            for (int j = i + 1; j < k; j++){
                int[] cur = {i, j, diff(levels[i], levels[j]) * w};
                cost[i][j] = cur[2];
                q.add(cur);
//              px("edge", cur);
            }
        }
//      px(q.size());
//      for (int[] e: cost) px(e);
        DisjointUnionSet djs = new DisjointUnionSet(k);
        boolean[][] al = new boolean[k][k];
        int finalCost = n * m * k;
        for (;q.size() > 0;){
            int[] edge = q.poll();
            int p1 = djs.getPartitionId(edge[0]);
            int p2 = djs.getPartitionId(edge[1]);
//          px(edge, p1 == p2, edge[2]);
            if (edge[2] > n * m) break;
            if (p1 != p2){
                
                djs.unionElement(edge[0], edge[1]);
                finalCost -= n * m - edge[2];
                al[edge[1]][edge[0]] = true;
                al[edge[0]][edge[1]] = true;
            }
        }
//      for (boolean[] e: al) px(e);
        pn(finalCost);
        boolean[] ex = new boolean[k];
        for (int i = 0 ; i < k; i++){
            if (!ex[i]){
                dfs(i, -1, ex, k, al);
            }
        }
    }
    public static void dfs(int at, int from, boolean[] ex, int k, boolean[][] al){
        ex[at] = true;
        
        pn((at + 1) + " " + (from + 1));
        for (int i = 0 ; i < k; i++){
            if (!ex[i] && al[i][at]){
//              px(i, at);
                dfs(i, at, ex, k, al);
            }
        }
    }
    public static final int COST = 2;
    public static int diff(char[][] a, char[][] b){
        int fin = 0;
        for (int i = 0 ; i < a.length; i++){
            for (int j =0 ; j < a[0].length; j++){
                if (a[i][j] != b[i][j]){
                    fin++;
                }
            }
        }
        return fin;
    }
    
    public static class DisjointUnionSet {
        int[] parent;
        int[] rank;
        DisjointUnionSet (int length){
            parent = new int[length];
            rank = new int[length];
            for (int i= 0 ; i < length; i++) parent[i] = i;
        }
        /*
         * Return the partition number.
         */
        int getPartitionId(int x){
            if (parent[x] != x) parent[x] = getPartitionId(parent[x]);
            return parent[x];
        }
        /*
         * Join the two partion that "x" and "y" are in.
         */
        void unionElement(int x, int y){
            int k1 = getPartitionId(x);
            int k2 = getPartitionId(y);
            if (k1 == k2) return;
            if (rank[k1] < rank[k2]) parent[k1] = k2;
            else if (rank[k1] > rank[k2]) parent[k2] = k1;
            else{
                parent[k2] = k1;
                rank[k1]++;
            }
        }
    }

    
    
    public static void solveTwo() throws Exception {
        
    }
    
    public static void solveThree() throws Exception {
        
    }
    
    public static BufferedReader in;
    public static StringTokenizer st;
    public static InputStream IN;
    public static OutputStream OUT;
    public static String nextString() throws Exception {
        for (;st == null || !st.hasMoreTokens();){
            String k1 = in.readLine();
            if (k1 == null) return null;
            st = new StringTokenizer(k1);
        }
        return st.nextToken();
    }
    public static int nextInt () throws Exception {
        return Integer.parseInt(nextString());
    }
    public static long nextLong() throws Exception{
        return Long.parseLong(nextString());
    }
    public static double nextDouble() throws Exception{
        return Double.parseDouble(nextString());
    }
    private static int[] nextIntArray(int n1) throws Exception {
        int[] l1 = new int[n1];
        for (int i = 0 ;i < n1; i++){
            l1[i] = nextInt();
        }
        return l1;
    }
    private static long[] nextLongArray(int n1) throws Exception {
        long[] l1 = new long[n1];
        for (int i = 0 ;i < n1; i++){
            l1[i] = nextLong();
        }
        return l1;
    }
    private static int[][] nextIntGrid(int x, int y) throws Exception {
        int[][] l1 = new int[x][y];
        for (int i =0; i < x; i++){
            for (int j = 0; j < y; j++){
                l1[i][j] = nextInt();
            }
        }
        return l1;
    }
    public static void px(Object ... l1){
        System.out.println(Arrays.deepToString(l1));
    }
    public static boolean FLUSH = false;
    public static PrintWriter out;
    public static void p(Object ... l1){
        for (int i = 0; i < l1.length; i++){
            if (i != 0) out.print(' ');
            out.print(l1[i].toString());
        }
    }
    public static void pn(Object ... l1){
        for (int i = 0; i < l1.length; i++){
            if (i != 0) out.print(' ');
            out.print(l1[i].toString());
        }
        out.println();
    }
    
    public static void pn(Collection l1){
        boolean first = true;
        for (Object e: l1){
            if (first) first = false;
            else out.print(' ');
            out.print(e.toString());
        }
        out.println();
    }
    
    private static BigInteger bi(long n1){
        return BigInteger.valueOf(n1);
    }
    
    private static double usedTime(){
        return (System.currentTimeMillis()-time)*0.001;
    }
    private static Random usingRandomGenerator = new Random(System.currentTimeMillis());
    private static void sort(double[] l1){
        for (int i = 0 ;  i< l1.length; i++){
            int q = i + usingRandomGenerator.nextInt(l1.length - i);
            double t = l1[i];
            l1[i] = l1[q];
            l1[q] = t;
        }
        Arrays.sort(l1);
    }
    private static void sort(int[] l1){
        for (int i = 0 ;  i< l1.length; i++){
            int q = i + usingRandomGenerator.nextInt(l1.length - i);
            int t = l1[i];
            l1[i] = l1[q];
            l1[q] = t;
        }
        Arrays.sort(l1);
    }
    private static void sort(long[] l1){
        for (int i = 0 ;  i< l1.length; i++){
            int q = i + usingRandomGenerator.nextInt(l1.length - i);
            long t = l1[i];
            l1[i] = l1[q];
            l1[q] = t;
        }
        Arrays.sort(l1);
    }
    
    
    
}