import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Queue;
import java.util.StringTokenizer;


public class Red {
	static class FastScanner {
		BufferedReader reader;
		StringTokenizer tokens;

		public FastScanner(File file) {
			try {
				reader = new BufferedReader(new FileReader(file));
			} catch (FileNotFoundException e) {}
		}

		public FastScanner() {
			reader = new BufferedReader(new InputStreamReader(System.in));
		}

		public String next() throws IOException {
			while (tokens == null || !tokens.hasMoreTokens()) 
				tokens = new StringTokenizer(reader.readLine());
			return tokens.nextToken();
		}

		public int nextInt() throws NumberFormatException, IOException {
			return Integer.parseInt(next());
		}

		public long nextLong() throws NumberFormatException, IOException {
			return Long.parseLong(next());
		}

		public double nextDouble() throws NumberFormatException, IOException {
			return Double.parseDouble(next());
		}

		public void close() throws IOException {
			reader.close();
		}
	}

	public static class Step {
		int to;
		int lastT;
		int time;

		public Step(int to, int lastT, int time) {
			super();
			this.to = to;
			this.lastT = lastT;
			this.time = time;
		}
	}

	static class Road {
		int t;
		int to;

		public Road(int to, int t) {
			this.t = t;
			this.to = to;
		}
	}

	public static void main(String[] args) throws IOException {
		FastScanner in = new FastScanner(new File("input.txt"));
		PrintWriter out = new PrintWriter(new File("output.txt"));
		//		FastScanner in = new FastScanner();
		//		PrintWriter out = new PrintWriter(System.out);
		int n = in.nextInt();
		int m = in.nextInt();
		long D = in.nextInt();
		ArrayList<Road>[] roads = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			roads[i] = new ArrayList<Road>();
		}
		int from, to, t;
		for (int i = 0; i < m; i++) {
			from = in.nextInt() - 1;
			to = in.nextInt() - 1;
			t = in.nextInt();
			roads[from].add(new Road(to, t));
			roads[to].add(new Road(from, t));
		}
		int Q = in.nextInt();
		cicle : for (int it = 0; it < Q; it++) {
			HashSet<Integer>[] vis = new HashSet[n];
			for (int i = 0; i < n; i++) 
				vis[i] = new HashSet<Integer>();
			Queue<Step> q = new ArrayDeque<Step>();
			from = in.nextInt() - 1;
			to = in.nextInt() - 1;
			for (Road road : roads[from]) {
				q.add(new Step(road.to, road.t, 1));
			}
			while (!q.isEmpty()) {
				Step step = q.poll();
				if (step.to == to) {
					out.println(step.time);
					continue cicle;
				}
				for (Road road : roads[step.to]) {
					if (Math.abs(road.t - step.lastT) <= D && !vis[road.to].contains(road.t)) {
						q.add(new Step(road.to, road.t, step.time + 1));
						vis[road.to].add(road.t);
					}
				}
			}
			out.println(-1);
		}
		out.close(); 
		in.close();
	}
}
