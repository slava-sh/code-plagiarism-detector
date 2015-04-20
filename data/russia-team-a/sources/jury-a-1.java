import static java.lang.Math.*;
import java.io.*;
import java.math.*;
import java.util.*;

public class binary_ni_java {
	MyScanner in;
	PrintWriter out;
	final static int MOD = 1000000007;

	class Edge {
		int to;
		int cost;

		public Edge(int to, int cost) {
			this.to = to;
			this.cost = cost;
		}
	}

	ArrayList<Edge> g[];
	int color[];
	int color2[];

	@SuppressWarnings("unchecked")
	void solve() throws Exception {
		int n = in.nextInt();
		int z[] = new int[n];
		for (int i = 0; i < n; i++) {
			z[i] = in.nextInt();
			if (i + z[i] > n) {
				out.println(0);
				return;
			}
		}
		if (z[0] != -1 && z[0] != 0) {
			out.println(0);
			return;
		}
		g = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<binary_ni_java.Edge>();
		}
		for (int i = 1; i < n; i++) {
			if (z[i] == -1) {
				continue;
			}
			int u = 0;
			int v = i;
			for (int k = 0; k < z[i]; k++) {
				g[u].add(new Edge(v, 0));
				g[v].add(new Edge(u, 0));
				u++;
				v++;
			}
			if (v < n) {
				g[u].add(new Edge(v, 1));
				g[v].add(new Edge(u, 1));
			}
		}
		color = new int[n];
		Arrays.fill(color, -1);
		int cc = 0;
		for (int i = 0; i < n; i++) {
			if (color[i] == -1) {
				if (!dfs(i, 0)) {
					out.println(0);
					return;
				}
				cc++;
			}
		}
		long answer = 1;
		for (int i = 0; i < cc; i++) {
			answer = (answer * 2) % MOD;
		}
		out.println(answer);
	}

	private boolean dfs(int v, int c) {
		if (color[v] != -1) {
			return color[v] == c;
		}
		color[v] = c;
		for (Edge e : g[v]) {
			if (!dfs(e.to, (c + e.cost) % 2)) {
				return false;
			}
		}
		return true;
	}

	public void run() {
		try {
			in = new MyScanner("binary.in");
			out = new PrintWriter("binary.out");
			solve();
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(42);
		}
	}

	public static void main(String[] args) {
		new binary_ni_java().run();
	}

	class MyScanner {
		BufferedReader br;
		StringTokenizer st;

		MyScanner(String file) {
			try {
				br = new BufferedReader(new FileReader(new File(file)));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				System.exit(42);
			}
		}

		MyScanner() {
			try {
				br = new BufferedReader(new InputStreamReader(System.in));
			} catch (Exception e) {
				e.printStackTrace();
				System.exit(42);
			}
		}

		String nextToken() throws Exception {
			while (st == null || (!st.hasMoreTokens())) {
				st = new StringTokenizer(br.readLine());
			}
			return st.nextToken();
		}

		int nextInt() throws Exception {
			return Integer.parseInt(nextToken());
		}

		double nextDouble() throws Exception {
			return Double.parseDouble(nextToken());
		}

		long nextLong() throws Exception {
			return Long.parseLong(nextToken());
		}

		BigInteger nextBigInteger(int radix) throws Exception {
			return new BigInteger(nextToken(), radix);
		}
	}

}
