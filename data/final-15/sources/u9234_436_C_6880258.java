import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader reader;
	static StringTokenizer tokenizer;
	static PrintWriter writer;

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	static String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	public static void main(String[] args) throws IOException {
		tokenizer = null;
		reader = new BufferedReader(new InputStreamReader(System.in));
		writer = new PrintWriter(System.out);
		banana();
		reader.close();
		writer.close();
	}

	static int[] parent;

	static int find_set(int v) {
		if (v == parent[v])
			return v;
		return parent[v] = find_set(parent[v]);
	}

	static boolean union_sets(int a, int b) {
		a = find_set(a);
		b = find_set(b);
		if (a != b) {
			parent[b] = a;
			return true;
		}
		return false;
	}

	static void banana() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int k = nextInt();
		int w = nextInt();
		int[][] d = new int[k][k];
		int X = m * n;

		char[][] mas = new char[k][n * m];
		for (int t = 0; t < k; t++) {
			for (int i = 0; i < n; i++) {
				String s = nextToken();
				for (int j = 0; j < m; j++) {
					mas[t][i * m + j] = s.charAt(j);
				}
			}
		}

		for (int i = 0; i < k; i++) {
			for (int j = i; j < k; j++) {
				for (int x = 0; x < X; x++) {
					d[i][j] += mas[i][x] == mas[j][x] ? 0 : w;
					d[j][i] += mas[i][x] == mas[j][x] ? 0 : w;
				}
			}
		}

		for (int i = 0; i < k; i++) {
			for (int j = i; j < k; j++) {
				d[j][i] = d[i][j];
			}
		}

		ArrayList<Edge> al = new ArrayList<Edge>();
		for (int i = 0; i < k; i++) {
			for (int j = i + 1; j < k; j++) {
				if (d[i][j] < X) {
					al.add(new Edge(i, j, d[i][j]));
				}
			}
		}

		parent = new int[k];
		for (int i = 0; i < k; i++) {
			parent[i] = i;
		}

		boolean[][] got = new boolean[k][k];

		int count = 0;
		int total = 0;
		Collections.sort(al);
		for (Edge e : al) {
			if (union_sets(e.u, e.v)) {
				got[e.u][e.v] = true;
				total += d[e.u][e.v];
				count++;
			}
		}

		total += (k - count) * X;
		writer.println(total);

		ArrayList<ArrayList<Integer>> g = new ArrayList<ArrayList<Integer>>();
		for (int i = 0; i < k; i++) {
			g.add(new ArrayList<Integer>());
		}

		for (int i = 0; i < k; i++) {
			for (int j = i + 1; j < k; j++) {
				if (got[i][j]) {
					g.get(i).add(j);
					g.get(j).add(i);
				}
			}
		}

		boolean[] used = new boolean[k];
		for (int i = 0; i < k; i++) {
			if (parent[i] == i) {
				LinkedList<Integer> ll = new LinkedList<Integer>();
				ll.add(i);
				used[i] = true;
				writer.println((i + 1) + " 0");
				while (!ll.isEmpty()) {
					int curr = ll.pollFirst();
					ArrayList<Integer> curral = g.get(curr);
					for (int j = 0; j < curral.size(); j++) {
						int next = curral.get(j);
						if (!used[next]) {
							ll.add(next);
							used[next] = true;
							writer.println((next + 1) + " " + (curr + 1));
						}
					}
				}
			}
		}

	}
}

class Edge implements Comparable<Edge> {
	int u;
	int v;
	int w;

	public Edge(int u, int v, int w) {
		super();
		this.u = u;
		this.v = v;
		this.w = w;
	}

	@Override
	public int compareTo(Edge o) {
		return w - o.w;
	}
}