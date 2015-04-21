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
import java.util.Iterator;
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
		HashSet<Road>[] roadsG = new HashSet[n];
		for (int i = 0; i < n; i++) {
			roadsG[i] = new HashSet<Road>();
		}
		int from, to, t;
		for (int i = 0; i < m; i++) {
			from = in.nextInt() - 1;
			to = in.nextInt() - 1;
			t = in.nextInt();
			roadsG[from].add(new Road(to, t));
			roadsG[to].add(new Road(from, t));
		}
		int Q = in.nextInt();
		cicle : for (int it = 0; it < Q; it++) {
			HashSet<Road>[] roads = new HashSet[n];
			for (int i = 0; i < n; i++) 
				roads[i].addAll(roadsG[i]);
			Queue<Step> q = new ArrayDeque<Step>();
			from = in.nextInt() - 1;
			to = in.nextInt() - 1;
			for (Road road : roads[from]) {
				q.add(new Step(road.to, road.t, 1));
			}
			Road road;
			while (!q.isEmpty()) {
				Step step = q.poll();
				if (step.to == to) {
					out.println(step.time);
					continue cicle;
				}
				Iterator<Road> iter = roads[step.to].iterator();
				while (iter.hasNext()) {
					road = iter.next();
					if (Math.abs(road.t - step.lastT) <= D) {
						q.add(new Step(road.to, road.t, step.time + 1));
						iter.remove();
					}
				}
			}
			out.println(-1);
		}
		out.close(); 
		in.close();
	}
}
