import java.io.*;
import java.util.*;
import java.util.Map.Entry;

public class C {

	class Edge implements Comparable<Edge> {
		int f, t, c;

		Edge(int f, int t, int c) {
			this.f = f;
			this.t = t;
			this.c = c;
		}

		@Override
		public int compareTo(Edge e) {
			return c - e.c;
		}

	}

	int[] dsu = new int[1024], rank = new int[1024], s;

	int[][] q;
	Edge[] edge;

	int get(int v) {
		if (v == dsu[v]) {
			return v;
		}
		return dsu[v] = get(dsu[v]);
	}

	void union(int u, int v) {
		u = get(u);
		v = get(v);
		if (u != v) {
			if (rank[u] == rank[v]) {
				++rank[u];
			}

			if (rank[u] < rank[v]) {
				dsu[u] = v;
			} else {
				dsu[v] = u;
			}

		}
	}

	void run() throws IOException {
		int n = ni(), m = ni(), k = ni(), w = ni();

		char[][][] level = new char[k][n][];
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < n; j++) {
				level[i][j] = nl().toCharArray();
			}
		}

		int[][] d = new int[k + 1][k + 1];
		for (int i = 0; i <= k; i++) {
			d[i][0] = d[0][i] = n * m;
			dsu[i] = i;
		}

		for (int i = 0; i < k; i++) {
			for (int j = i + 1; j < k; j++) {
				int cur = 0;
				for (int x = 0; x < n; x++) {
					for (int y = 0; y < m; y++) {
						if (level[i][x][y] != level[j][x][y]) {
							++cur;
						}
					}
				}
				d[i + 1][j + 1] = d[j + 1][i + 1] = cur * w;
			}
		}

		int h = k * (k + 1) / 2, p = 0;
		edge = new Edge[h];

		for (int i = 0; i <= k; i++) {
			for (int j = i + 1; j <= k; j++, p++) {
				edge[p] = new Edge(i, j, d[i][j]);
			}
		}

		Arrays.sort(edge);
		p = 0;
		int sum = 0;

		q = new int[k + 1][2 * k + 2];
		s = new int[k + 1];

		for (int i = 0; i < h; i++) {
			Edge ed = edge[i];
			if (get(ed.f) != get(ed.t)) {
				sum += ed.c;
				union(ed.f, ed.t);

				q[ed.f][s[ed.f]++] = ed.t;
				q[ed.t][s[ed.t]++] = ed.f;

			}
		}
		pw.println(sum);

		p = 0;
		dfs(0, -1);

	}

	void dfs(int v, int g) {
		if (g != -1) {
			pw.println(v + " " + g);
		}
		for (int i = s[v] - 1; i >= 0; --i) {
			int u = q[v][i];
			if (u != g) {
				dfs(u, v);
			}
		}

		
	}

	int gcd(int a, int b) {
		return (b == 0) ? (a) : (gcd(b, a % b));
	}

	int[] na(int a_len) throws IOException {
		int[] _a = new int[a_len];
		for (int i = 0; i < a_len; i++)
			_a[i] = ni();
		return _a;
	}

	String next() throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine());
		return st.nextToken();
	}

	int ni() throws IOException {
		return Integer.parseInt(next());
	}

	long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	String nl() throws IOException {
		return br.readLine();
	}

	void tr(String debug) {
		if (!OJ)
			pw.println(" " + debug);
	}

	static PrintWriter pw;
	static BufferedReader br;
	static StringTokenizer st;
	static boolean OJ;

	public static void main(String[] args) throws IOException {
		long timeout = System.currentTimeMillis();
		OJ = System.getProperty("ONLINE_JUDGE") != null;
		pw = new PrintWriter(System.out);
		br = new BufferedReader(OJ ? new InputStreamReader(System.in) : new FileReader(new File("C.txt")));

		while (br.ready())
			new C().run();
		if (!OJ) {
			pw.println("----------------");
			pw.println(System.currentTimeMillis() - timeout);
		}
		br.close();
		pw.close();
	}

}
