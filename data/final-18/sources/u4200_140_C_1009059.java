import java.awt.*;
import java.io.*;
import java.math.*;
import java.util.*;

import static java.lang.Math.*;

public class CF100_C implements Runnable {

    BufferedReader in;
    PrintWriter out;
    StringTokenizer tok = new StringTokenizer("");

    public static void main(String[] args) {
        new Thread(null, new CF100_C(), "", 256 * (1L << 20)).start();
    }

    public void run() {
        try {
            long t1 = System.currentTimeMillis();
            if (System.getProperty("ONLINE_JUDGE") != null) {
                in = new BufferedReader(new InputStreamReader(System.in));
                out = new PrintWriter(System.out);
            } else {
                in = new BufferedReader(new FileReader("input.txt"));
                out = new PrintWriter("output.txt");
            }
            Locale.setDefault(Locale.US);
            solve();
            in.close();
            out.close();
            long t2 = System.currentTimeMillis();
            System.err.println("Time = " + (t2 - t1));
        } catch (Throwable t) {
            t.printStackTrace(System.err);
            System.exit(-1);
        }
    }

    String readString() throws IOException {
        while (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine());
        }
        return tok.nextToken();
    }

    int readInt() throws IOException {
        return Integer.parseInt(readString());
    }

    long readLong() throws IOException {
        return Long.parseLong(readString());
    }

    double readDouble() throws IOException {
        return Double.parseDouble(readString());
    }
    
    BigInteger readBigInteger() throws IOException {
        return new BigInteger(readString());
    }

    static class Utils {

        private Utils() {}
        
        
        private static final int MAGIC_VALUE = 50;
        

        public static void mergeSort(int[] a) {
            mergeSort(a, 0, a.length - 1);
        }
        public static void mergeSort(long[] a) {
            mergeSort(a, 0, a.length - 1);
        }
        public static void mergeSort(double[] a) {
            mergeSort(a, 0, a.length - 1);
        }


        private static void mergeSort(int[] a, int leftIndex, int rightIndex) {
            if (leftIndex < rightIndex) {
                if (rightIndex - leftIndex <= MAGIC_VALUE) {
                    insertionSort(a, leftIndex, rightIndex);
                } else {
                    int middleIndex = (leftIndex + rightIndex) / 2;
                    mergeSort(a, leftIndex, middleIndex);
                    mergeSort(a, middleIndex + 1, rightIndex);
                    merge(a, leftIndex, middleIndex, rightIndex);
                }
            }
        }
        private static void mergeSort(long[] a, int leftIndex, int rightIndex) {
            if (leftIndex < rightIndex) {
                if (rightIndex - leftIndex <= MAGIC_VALUE) {
                    insertionSort(a, leftIndex, rightIndex);
                } else {
                    int middleIndex = (leftIndex + rightIndex) / 2;
                    mergeSort(a, leftIndex, middleIndex);
                    mergeSort(a, middleIndex + 1, rightIndex);
                    merge(a, leftIndex, middleIndex, rightIndex);
                }
            }
        }
        private static void mergeSort(double[] a, int leftIndex, int rightIndex) {
            if (leftIndex < rightIndex) {
                if (rightIndex - leftIndex <= MAGIC_VALUE) {
                    insertionSort(a, leftIndex, rightIndex);
                } else {
                    int middleIndex = (leftIndex + rightIndex) / 2;
                    mergeSort(a, leftIndex, middleIndex);
                    mergeSort(a, middleIndex + 1, rightIndex);
                    merge(a, leftIndex, middleIndex, rightIndex);
                }
            }
        }

        
        private static void merge(int[] a, int leftIndex, int middleIndex, int rightIndex) {
            int length1 = middleIndex - leftIndex + 1;
            int length2 = rightIndex - middleIndex;
            int[] leftArray = new int[length1];
            int[] rightArray = new int[length2];
            System.arraycopy(a, leftIndex, leftArray, 0, length1);
            System.arraycopy(a, middleIndex + 1, rightArray, 0, length2);
            for (int k = leftIndex, i = 0, j = 0; k <= rightIndex; k++) {
                if (i == length1) {
                    a[k] = rightArray[j++];
                } else if (j == length2) {
                    a[k] = leftArray[i++];
                } else {
                    a[k] = leftArray[i] <= rightArray[j] ? leftArray[i++] : rightArray[j++];
                }
            }
        }
        private static void merge(long[] a, int leftIndex, int middleIndex, int rightIndex) {
            int length1 = middleIndex - leftIndex + 1;
            int length2 = rightIndex - middleIndex;
            long[] leftArray = new long[length1];
            long[] rightArray = new long[length2];
            System.arraycopy(a, leftIndex, leftArray, 0, length1);
            System.arraycopy(a, middleIndex + 1, rightArray, 0, length2);
            for (int k = leftIndex, i = 0, j = 0; k <= rightIndex; k++) {
                if (i == length1) {
                    a[k] = rightArray[j++];
                } else if (j == length2) {
                    a[k] = leftArray[i++];
                } else {
                    a[k] = leftArray[i] <= rightArray[j] ? leftArray[i++] : rightArray[j++];
                }
            }
        }
        private static void merge(double[] a, int leftIndex, int middleIndex, int rightIndex) {
            int length1 = middleIndex - leftIndex + 1;
            int length2 = rightIndex - middleIndex;
            double[] leftArray = new double[length1];
            double[] rightArray = new double[length2];
            System.arraycopy(a, leftIndex, leftArray, 0, length1);
            System.arraycopy(a, middleIndex + 1, rightArray, 0, length2);
            for (int k = leftIndex, i = 0, j = 0; k <= rightIndex; k++) {
                if (i == length1) {
                    a[k] = rightArray[j++];
                } else if (j == length2) {
                    a[k] = leftArray[i++];
                } else {
                    a[k] = leftArray[i] <= rightArray[j] ? leftArray[i++] : rightArray[j++];
                }
            }
        }

        
        private static void insertionSort(int[] a, int leftIndex, int rightIndex) {
            for (int i = leftIndex + 1; i <= rightIndex; i++) {
                int current = a[i];
                int j = i - 1;
                while (j >= leftIndex && a[j] > current) {
                    a[j + 1] = a[j];
                    j--;
                }
                a[j + 1] = current;
            }
        }
        private static void insertionSort(long[] a, int leftIndex, int rightIndex) {
            for (int i = leftIndex + 1; i <= rightIndex; i++) {
                long current = a[i];
                int j = i - 1;
                while (j >= leftIndex && a[j] > current) {
                    a[j + 1] = a[j];
                    j--;
                }
                a[j + 1] = current;
            }
        }
        private static void insertionSort(double[] a, int leftIndex, int rightIndex) {
            for (int i = leftIndex + 1; i <= rightIndex; i++) {
                double current = a[i];
                int j = i - 1;
                while (j >= leftIndex && a[j] > current) {
                    a[j + 1] = a[j];
                    j--;
                }
                a[j + 1] = current;
            }
        }

    }

    // solution
    
    void debug(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }
    
    class Snow implements Comparable<Snow> {
        int x, i;

        public Snow(int x, int i) {
            this.x = x;
            this.i = i;
        }

        public int compareTo(Snow o2) {
            return x - o2.x;
        }

        @Override
        public String toString() {
            return "Snow [x=" + x + ", i=" + i + "]";
        }
        
        
        
    }
    
    //XXX[] b;
    ArrayList<XXX> b = new ArrayList<XXX>();
    HashMap<Integer, XXX> map = new HashMap<Integer, XXX>();
    int[][] c;
    
    class XXX implements Comparable<XXX>{
        int cnt;
        int R = -1;
        ArrayDeque<Integer> ind;
        public XXX(int cnt, int what) {
            this.cnt = cnt;
            this.R = what;
            ind = new ArrayDeque<Integer>();
        }
        
        
        @Override
        public String toString() {
            return "XXX [cnt=" + cnt + ", what=" + R + ", ind=" + ind + "]";
        }


        public int compareTo(XXX o) {
            if (this.cnt == o.cnt) return this.R - o.R;
            return o.cnt - cnt;
        }

        @Override
        public boolean equals(Object obj) {
            XXX x = (XXX) obj;
            return this.compareTo(x) == 0;
        }
        
        
        
    }
    
    void save(Snow[] a, int n) {
        for (Snow s : a) {
            if (map.containsKey(s.x)) {
                XXX xx = map.get(s.x);
                xx.ind.add(s.i);
                xx.cnt++;
                map.put(s.x, xx);
            } else {
                XXX xx = new XXX(1, s.x);
                xx.ind.add(s.i);
                map.put(s.x, xx);
            }
        }
        b = new ArrayList<XXX>(map.values());
        /*TreeMap<Integer, Integer> map = new TreeMap<Integer, Integer>();
        for (int i = 0, val = 0; i < n; i++) {
            if (!map.containsKey(a[i].x)) {
                map.put(a[i].x, val++);
            }
        }
        for (int i = 0; i < n; i++) {
            a[i].x = map.get(a[i].x);
        }
        int len = map.size();
        b = new XXX[len];
        for (int i = 0; i < len; i++) {
            b[i] = new XXX(0, -1);
        }
        for (int i = 0; i < n; i++) {
            b[a[i].x].cnt++;
            if (b[a[i].x].R == -1) {
                b[a[i].x].R = a[i].x;
            }
        }
        for (int i = 0; i < n; i++) {
            b[a[i].x].ind.add(a[i].i);
        }*/
    }

    class Answer {
        int a,b,c;

        public Answer(int a, int b, int c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }

        @Override
        public String toString() {
            return (a) + " " + (b) + " " + (c);
        }
        
    }
    
    void solve() throws IOException {
        int n = readInt();
        Snow[] a = new Snow[n];
        for (int i = 0; i < n; i++) {
            a[i] = new Snow(readInt(), i);
        }
        //Arrays.sort(a);
        save(a, n);
        //debug(b);
        TreeSet<XXX> set = new TreeSet<XXX>();
        for (XXX xx : b) {
            set.add(xx);
        }
        ArrayList<Answer> ans = new ArrayList<Answer>();
        int[] ddd = new int[3];
        while (true) {
            if (set.size() < 3) {
                break;
            }
            XXX x1 = set.pollFirst();
            XXX x2 = set.pollFirst();
            XXX x3 = set.pollFirst();
            
            ddd[0] = x1.R;
            ddd[1] = x2.R;
            ddd[2] = x3.R;
            Arrays.sort(ddd);
            
            /*if (x1.R < x2.R && x1.R < x3.R) {
                ddd[0] = x1.ind.peekLast();
                if (x2.R < x3.R) {
                    ddd[1] = x2.ind.peekLast();
                    ddd[2] = x3.ind.peekLast();
                } else {
                    ddd[1] = x3.ind.peekLast();
                    ddd[2] = x2.ind.peekLast();
                }
            }

            if (x2.R < x1.R && x2.R < x3.R) {
                ddd[0] = x2.ind.peekLast();
                if (x1.R < x3.R) {
                    ddd[1] = x1.ind.peekLast();
                    ddd[2] = x3.ind.peekLast();
                } else {
                    ddd[1] = x3.ind.peekLast();
                    ddd[2] = x1.ind.peekLast();
                }
            }
            
            if (x3.R < x1.R && x3.R < x2.R) {
                ddd[0] = x3.ind.peekLast();
                if (x1.R < x2.R) {
                    ddd[1] = x1.ind.peekLast();
                    ddd[2] = x2.ind.peekLast();
                } else {
                    ddd[1] = x2.ind.peekLast();
                    ddd[2] = x1.ind.peekLast();
                }
            }*/
            
            x1.ind.pollLast();
            x2.ind.pollLast();
            x3.ind.pollLast();
            
            ans.add(new Answer(ddd[2], ddd[1], ddd[0]));
            
            x1.cnt--; x2.cnt--; x3.cnt--;
            
            if (x1.cnt > 0) set.add(x1);
            if (x2.cnt > 0) set.add(x2);
            if (x3.cnt > 0) set.add(x3);
        }
        out.println(ans.size());
        for (Answer aa : ans) {
            out.println(aa);
        }
    }

}
