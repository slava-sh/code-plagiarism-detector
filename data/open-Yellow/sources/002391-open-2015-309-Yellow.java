import java.io.*;
import java.util.*;

public class Main {
    private static class SegmentTree {
        int[] road, tree;

        public SegmentTree(int[] r) {
            road = r;
            tree = new int[road.length * 4];
            buildTree(0, 0, road.length - 1);
        }

        private void buildTree(int v, int queryLeft, int queryRight) {
            if (queryLeft == queryRight) {
                tree[v] = 1;
            } else {
                int mid = (queryLeft + queryRight) / 2;
                buildTree(v*2+1, queryLeft, mid);
                buildTree(v*2+2, mid+1, queryRight);
                tree[v] = tree[v*2+1] + tree[v*2+2];
                if (road[mid] == road[mid + 1]) {
                    --tree[v];
                }
            }
        }

        public void update(int index, int type) {
            road[index] = type;
            update(0, 0, road.length - 1, index);
        }

        private void update(int v, int queryLeft, int queryRight, int index) {
            if (queryLeft == queryRight) {
                tree[v] = 1;
            } else {
                int mid = (queryLeft + queryRight) / 2;
                if (index <= mid) {
                    update(2*v+1, queryLeft, mid, index);
                } else {
                    update(2*v+2, mid+1, queryRight, index);
                }
                tree[v] = tree[v*2+1] + tree[v*2+2];
                if (road[mid] == road[mid + 1]) {
                    --tree[v];
                }
            }
        }

        public int getResult() {
            return tree[0];
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

        int n = in.nextInt();
        int[] A = new int[n];
        for (int i = 0; i < n; i++) {
            A[i] = in.nextInt();
        }
        SegmentTree T = new SegmentTree(A);
        int Q = in.nextInt();
        for (int i = 0; i < Q; i++) {
            int index = in.nextInt(), type = in.nextInt();
            --index;
            T.update(index, type);
            out.println(T.getResult());
        }

        out.flush();
    }
}
