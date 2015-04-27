import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;


public class C {	
	BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter out;
    
	public void solve() throws IOException {				
		int N = nextInt();
        int M = nextInt();
        int K = nextInt();
        int W = nextInt();

        if (K == 1) {
            out.println(N * M);
            out.println("1 0");
            return;
        }

		char[][][] map = new char[K][N][];
        for (int k = 0; k < K; k++) {
            for (int i = 0; i < N; i++) {
                map[k][i] = reader.readLine().toCharArray();
            }
        }

        int edgeCnt = K * (K-1) / 2;
        int[][] edges = new int[edgeCnt][];
        int edgeInc = 0;
        for (int k1 = 0; k1 < K; k1++) {
            for (int k2 = k1+1; k2 < K; k2++) {
                int diff = 0;
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < M; j++) {
                        if (map[k1][i][j] != map[k2][i][j]) diff++;
                    }
                }
                edges[edgeInc++] = new int[] {diff, k1, k2};
            }
        }

        Arrays.sort(edges, new Comparator<int[]>() {
            @Override
            public int compare(int[] a, int[] b) {
                return a[0] - b[0];
            }
        });

        int[] parents = new int[K];
        int[] ranks = new int[K];
        for (int i = 0; i < K; i++) {
            parents[i] = i;
        }

        ArrayList<int[]>[] ns = new ArrayList[K];
        for (int k = 0; k < K; k++) {
            ns[k] = new ArrayList<int[]>();
        }

        for (int i = 0; i < edgeCnt; i++) {
            int diff = edges[i][0];
            int v1 = edges[i][1];
            int v2 = edges[i][2];
            if (isSameGroup(parents, v1, v2)) continue;
            union(parents, ranks, v1, v2);
            ns[v1].add(new int[] {v2, diff * W});
            ns[v2].add(new int[] {v1, diff * W});
        }


        int full = N * M;
        long ans = 0;
        ArrayList<int[]> steps = new ArrayList<int[]>();
        boolean[] reached = new boolean[K];
        Queue<Integer> queue = new LinkedList<Integer>();
        queue.add(0);
        reached[0] = true;
        steps.add(new int[] {0, -1});
        ans += full;

        while (!queue.isEmpty()) {
            int cur = queue.poll();
            for (int[] e: ns[cur]) {
                if (reached[e[0]]) continue;

                if (e[1] > full) {
                    steps.add(new int[] {e[0], -1});
                    ans += full;
                } else {
                    steps.add(new int[] {e[0], cur});
                    ans += e[1];
                }
                queue.add(e[0]);
                reached[e[0]] = true;
            }
        }

        out.println(ans);
        for (int[] step: steps) {
            out.println( (step[0] + 1) + " " + (step[1] + 1));
        }
    }

    public int getRoot(int[] parents, int node) {
        if (node != parents[node]) {
            parents[node] = getRoot(parents, parents[node]);
        }
        return parents[node];
    }

    public boolean isSameGroup(int[] parents, int n1, int n2) {
        return getRoot(parents, n1) == getRoot(parents, n2);
    }

    public void union(int[] parents, int[] ranks, int n1, int n2) {
        int root1 = getRoot(parents, n1);
        int root2 = getRoot(parents, n2);
        if (root1 == root2) return;

        if (ranks[root1] < ranks[root2]) {
            parents[root1] = root2;
        } else if (ranks[root2] < ranks[root1]) {
            parents[root2] = root1;
        } else {
            parents[root1] = root2;
            ranks[root2]++;
        }
    }

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		new C().run();
	}
	
	public void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
            out = new PrintWriter(System.out);
            solve();
            reader.close();
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

}
