import java.io.*;
import java.util.*;

public class Main {
    private static class Curve implements Comparable<Curve> {
        private int index;
        private int[] X, Y;

        public Curve(int[] X, int[] Y, int index) {
            this.X = X;
            this.Y = Y;
            this.index = index;
        }

        @Override
        public int compareTo(Curve o) {
            /*for (int i = 0; i < X.length; ++i) {
                int trial = (new Integer(Y[i])).compareTo(o.Y[i]);
                if (trial != 0) {
                    return trial;
                }
            }*/
            int ptr = 0, ptrOther = 0;
            int last;
            while (ptr < X.length && ptrOther < o.X.length) {
                int trial = (ptr < X.length) ? X[ptr] : Integer.MAX_VALUE;
                int trialOther = (ptrOther < o.X.length) ? o.X[ptr] : Integer.MAX_VALUE;
                if (trial < trialOther) {
                    last = trial;
                    ++ptr;
                }
                else {
                    last = trialOther;
                    ++ptrOther;
                }
                int compare = (new Double(getPosition(last))).compareTo(o.getPosition(last));
                if (compare != 0) {
                    return compare;
                }
            }
            return 0;
        }

        public int getIndex() {
            return index;
        }

        public double getPosition(int x) {
            int leftSegment = 0, rightSegment = X.length - 1;
            while (leftSegment < rightSegment) {
                int mid = (leftSegment + rightSegment) >> 1;
                if (X[mid] <= x) {
                    leftSegment = mid + 1;
                } else {
                    rightSegment = mid;
                }
            }
            double res = Y[leftSegment - 1];
            double tangent = Y[leftSegment] - Y[leftSegment - 1];
            tangent /= X[leftSegment] - X[leftSegment - 1];
            res += tangent * (x - X[leftSegment - 1]);
            return res;
        }
    }

    private static class FastReader {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        public FastReader(InputStream inputStream) {
            reader = new BufferedReader(new InputStreamReader(inputStream), 1 << 16);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                }
                catch (IOException ex) {
                    throw new RuntimeException(ex);
                }
            }
            return tokenizer.nextToken();
        }

        public String nextLine() {
            try {
                return reader.readLine();
            }
            catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) {
        FastReader in = new FastReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int A = in.nextInt(), B = in.nextInt();
        int n = in.nextInt();
        Curve[] curves = new Curve[n];
        PriorityQueue<Integer> Q = new PriorityQueue<Integer>();
        Q.add(A);
        Q.add(B);
        for (int i = 1; i <= n; ++i) {
            int l = in.nextInt() + 1;
            int[] X = new int[l];
            int[] Y = new int[l];
            for (int j = 0; j < l; j++) {
                X[j] = in.nextInt();
                Y[j] = in.nextInt();
                Q.add(X[j]);
            }
            curves[i - 1] = new Curve(X, Y, i);
        }
        Arrays.sort(curves);
        int prev = Integer.MIN_VALUE;
        int[] answer = new int[]{-1, -1};
        outer:
        while (!Q.isEmpty()) {
            int next = Q.remove();
            if (prev == next) continue;
            double[] positions = new double[n];
            positions[0] = curves[0].getPosition(next);
            for (int i = 1; i < n; ++i) {
                positions[i] = curves[i].getPosition(next);
                if (positions[i] < positions[i - 1]) {
                    answer[0] = curves[i].getIndex();
                    answer[1] = curves[i - 1].getIndex();
                    break outer;
                }
            }
            prev = next;
        }

        if (answer[0] == -1) {
            out.println("Yes");
        }
        else {
            out.println("No");
            out.println(answer[0] + " " + answer[1]);
        }
        out.flush();
    }
}
