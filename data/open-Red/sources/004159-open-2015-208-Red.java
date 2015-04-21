import java.io.*;
import java.util.*;

public class Red {
	public static void main(String[] args) throws IOException {
		new Red().run();
	}

	BufferedReader in;
	PrintWriter out;
	StringTokenizer st;

	String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(in.readLine());
		}
		return st.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	void run() throws IOException {
		in = new BufferedReader(new FileReader("input.txt"));
		out = new PrintWriter("output.txt");
		solve();
		out.flush();
	}

	class Edge {
		int u;
		long w;
		int ind;

		public Edge() {
		}

		public Edge(int u, long w, int ind) {
			this.u = u;
			this.w = w;
			this.ind = ind;
		}
	}

	class Triple implements Comparable<Triple> {
		int v;
		int lastEdge;
		int dist;

		public Triple() {

		}

		public Triple(int v, int lastEdge, int dist) {
			this.v = v;
			this.lastEdge = lastEdge;
			this.dist = dist;
		}

		@Override
		public int compareTo(Triple arg0) {
			if (this.dist != arg0.dist) {
				return Integer.compare(this.dist, arg0.dist);
			}
			if (this.v != arg0.v) {
				return Integer.compare(this.v, arg0.v);
			}
			return Integer.compare(this.lastEdge, arg0.lastEdge);
		}

		@Override
		public boolean equals(Object o) {
			return this.compareTo((Triple) o) == 0;
		}

		@Override
		public String toString() {
			return this.v + " " + this.lastEdge + " " + this.dist;
		}
	}

	ArrayList<Edge>[] eds;
	int n;
	int d;

	final int inf = (int) 1e9 + 7;

	int dijkstra(int st, int fn) {
		ArrayList<Integer>[] dist = new ArrayList[n];
		LinkedList<Triple> min = new LinkedList<Triple>();
		for (int i = 0; i < n; i++) {
			dist[i] = new ArrayList<Integer>();
			for (int j = 0; j < eds[i].size(); j++) {
				dist[i].add(inf);
			}
		}
		for (int i = 0; i < eds[st].size(); i++) {
			dist[st].set(i, 0);
			min.add(new Triple(st, i, 0));
		}
		// for(int i = 0; i < n; i++){
		// System.out.println(dist[i]);
		// }
		// System.out.println();
		// for(int i = 0; i < n; i++){
		// System.out.println(dist[i]);
		// }
		// System.out.println();
		while (!min.isEmpty()) {
			Triple cur = min.pollFirst();
			for (Edge e : eds[cur.v]) {
				// System.out.println(cur.v + " "+e.u + " " + e.ind + " " + e.w
				// + " " + cur.lastEdge + " ");
				if ((Math.abs(e.w - eds[cur.v].get(cur.lastEdge).w) <= d || cur.v == st)
						&& dist[e.u].get(e.ind) > dist[cur.v].get(cur.lastEdge) + 1) {
					// min.remove(new Triple(e.u, e.ind, dist[e.u]
					// .get(e.ind)));
					dist[e.u].set(e.ind, dist[cur.v].get(cur.lastEdge) + 1);
					min.add(new Triple(e.u, e.ind, dist[e.u].get(e.ind)));
				}
			}

			// System.out.println(cur.v + " " + cur.lastEdge + " " + min);
		}
		// for(int i = 0; i < n; i++){
		// System.out.println(dist[i]);
		// }
		// System.out.println();
		int ans = inf;
		for (int i : dist[fn]) {
			ans = Math.min(ans, i);
		}
		if (ans == inf) {
			return -1;
		}
		return ans;
	}

	void solve() throws IOException {
		n = nextInt();
		int m = nextInt();
		d = nextInt();
		eds = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			eds[i] = new ArrayList<Edge>();
		}
		for (int i = 0; i < m; i++) {
			int a = nextInt() - 1;
			int b = nextInt() - 1;
			int w = nextInt();
			eds[a].add(new Edge(b, w, eds[b].size()));
			eds[b].add(new Edge(a, w, eds[a].size() - 1));
		}
		// for(int i = 0; i < n; i++) {
		// for(Edge e : eds[i]) {
		// System.out.println(i + " "+e.u + " " + e.w + " " + e.ind);
		// }
		// }
		int q = nextInt();
		for (; q > 0; q--) {
			int st = nextInt() - 1;
			int fn = nextInt() - 1;
			out.println(dijkstra(st, fn));
		}
	}
}
