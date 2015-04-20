import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class PrH {
	public static void main(String[] args) throws IOException {
		new PrH().run();
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

	void run() throws IOException {
		in = new BufferedReader(new FileReader("secure.in"));
		out = new PrintWriter("secure.out");
		solve();
		out.flush();
	}

	long inf = (long) 1e15;

	ArrayList<edge>[] reb;
	long[] d;
	int[] bel;

	class edge implements Comparable<edge> {
		int w;
		int v;

		public edge() {

		}

		public edge(int w, int v) {
			this.w = w;
			this.v = v;
		}

		@Override
		public int compareTo(edge o) {
			if (w < o.w) {
				return -1;
			}
			if (w > o.w) {
				return 1;
			}
			return 0;
		}

		@Override
		public boolean equals(Object o) {
			edge a = (edge) o;
			if (a.compareTo(this) == 0) {
				return true;
			}
			return false;
		}
	}

	public class pair implements Comparable<pair> {
		int v;
		long w;

		public pair(int v, long w) {
			this.v = v;
			this.w = w;
		}

		@Override
		public int compareTo(pair o) {
			if (w < o.w) {
				return -1;
			}
			if (w > o.w) {
				return 1;
			}
			if (v < o.v) {
				return -1;
			}
			if (v > o.v) {
				return 1;
			}
			return 0;
		}

		@Override
		public boolean equals(Object o) {
			pair a = (pair) o;
			if (a.compareTo(this) == 0 && a.v == this.v) {
				return true;
			}
			return false;
		}
	}

	void dijkstra(int st) {
		TreeSet<pair> fmin = new TreeSet<>();
		for (int i = 0; i < d.length; i++) {
			d[i] = inf;
			fmin.add(new pair(i, d[i]));
		}
		d[st] = 0;

		for (int i = 0; i < d.length; i++) {
			int v = (fmin.pollFirst()).v;
			for (edge tem : reb[v]) {
				if (d[tem.v] > d[v] + tem.w) {
					fmin.remove(new pair(tem.v, d[tem.v]));
					d[tem.v] = d[v] + tem.w;
					fmin.add(new pair(tem.v, d[tem.v]));
				}
			}
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		bel = new int[n];
		reb = new ArrayList[n];
		d = new long[n];
		for (int i = 0; i < n; i++) {
			bel[i] = nextInt();
			reb[i] = new ArrayList<>();
		}

		for (int i = 0; i < m; i++) {
			int v = nextInt() - 1;
			int u = nextInt() - 1;
			int w = nextInt();
			reb[v].add(new edge(w, u));
			reb[u].add(new edge(w, v));
		}
		long min = inf;
		int u = -1;
		int v = -1;
		for (int i = 0; i < n; i++) {
			if (bel[i] == 1) {
				dijkstra(i);
				for (int j = 0; j < n; j++) {
					if (bel[j] == 2 && d[j] < min) {
						min = d[j];
						u = i;
						v = j;
					}
				}
			}
		}
		if (u == -1) {
			out.println(-1);
		} else {
			out.println((u + 1) + " " + (v + 1) + " " + min);
		}
	}
}