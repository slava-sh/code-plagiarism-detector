import java.io.*;
import java.util.*;

public class secure_av {

	FastScanner in;
	PrintWriter out;
	
	final int INF = Integer.MAX_VALUE / 2;
	
	List<Edge>[] graph;

	void solve() {
		int n = in.nextInt(), m = in.nextInt();
		
		boolean[] black = new boolean[n], white = new boolean[n];
		for (int i = 0; i < n; i++) {
			int type = in.nextInt();
			if (type == 1) {
				black[i] = true;
			} else if (type == 2) {
				white[i] = true;
			}
		}
		
		graph = new List[n];
		for (int i = 0; i < n; i++) {
			graph[i] = new ArrayList<>();
		}
		
		for (int i = 0; i < m; i++) {
			int from = in.nextInt() - 1, to = in.nextInt() - 1, length = in.nextInt();
			graph[from].add(new Edge(to, length));
			graph[to].add(new Edge(from, length));
		}
		
		
		TreeSet<Vertex> set = new TreeSet<>();
		int[] distance = new int[n];
		int[] nearest = new int[n];
		Arrays.fill(distance, INF);
		Arrays.fill(nearest, -1);

		for (int i = 0; i < n; i++) {
			if (black[i]) {
				distance[i] = 0;
				nearest[i] = i;
				set.add(new Vertex(i, distance[i]));
			}
		}

		
		while (!set.isEmpty()) {
			Vertex min = set.pollFirst();
			if (min.distance == INF) {
				break;
			}
			if (white[min.id]) {
				out.println((nearest[min.id] + 1) + " " + (min.id + 1) + " " + min.distance);
				return;
			}
			
			for (Edge edge: graph[min.id]) {
				int end = edge.endPoint;
				Vertex vertex = new Vertex(end, distance[end]);
				
				if (distance[end] > min.distance + edge.length) {
					set.remove(vertex);
					
					distance[end] = min.distance + edge.length;
					nearest[end] = nearest[min.id];
					vertex.distance = distance[end];
					
					set.add(vertex);
				}
			}
		}
		
		out.println(-1);
	}
	
	class Edge {
		int endPoint, length;

		public Edge(int endPoint, int length) {
			this.endPoint = endPoint;
			this.length = length;
		}
	}
	
	class Vertex implements Comparable<Vertex> {
		int distance, id;
		public Vertex(int id, int distance) {
			this.id = id;
			this.distance = distance;
		}
		
		@Override
		public int compareTo(Vertex o) {
			int cmp = Integer.compare(distance, o.distance);
			if (cmp != 0) {
				return cmp;
			}
			return Integer.compare(id, o.id);
		}
	}

	void run() {
		try {
			in = new FastScanner("secure.in");
			out = new PrintWriter("secure.out");
			solve();
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(String s) {
			try {
				br = new BufferedReader(new FileReader(s));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(nextToken());
		}

		long nextLong() {
			return Long.parseLong(nextToken());
		}

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}

	public static void main(String[] args) {
		new secure_av().run();
	}
}
