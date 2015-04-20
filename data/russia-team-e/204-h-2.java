import java.util.*;
import java.io.*;

public class TaskH {
	FastScanner in;
	PrintWriter out;

	final String problem_name = "secure";

	public void solve() throws IOException {
		int n = in.nextInt();
		int m = in.nextInt();
		int[] la = new int[n];
		int[] xe = new int[n];
		Arrays.fill(la, 0);
		Arrays.fill(xe, 0);
		for (int i = 0; i < n; i++) {
			int t = in.nextInt();
			if (t == 1) {
				la[i] = 1;
			}
			if (t == 2) {
				xe[i] = 1;
			}
		}
		int[][] w = new int[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				w[i][j] = -1;
			}
		}
		int exit = -1;
		for (int i = 0; i < m; i ++) {
			int x = in.nextInt();
			int y = in.nextInt();
			int z = in.nextInt();
			w[x - 1][y - 1] = z;
			w[y - 1][x - 1] = z;
		}
		int min = 1000000000;
		int min1 = 0;
		int min2 = 0;
		for (int i = 0; i < n; i ++) {
			if (la[i] == 1) {
				int[] d = new int[n];
				Arrays.fill(d, 1000000000);
				d[i] = 0;
				for (int k = 0; k < (n - 1); k++) {
					for (int v = 0; v < n; v++) {
						for (int u = 0; u < n; u++) {
							if (w[v][u] != -1) {
								d[u] = Math.min(d[u], d[v] + w[v][u]);
							}
						}
					}
				}
				for (int j = 0; j < n; j++) {
					if (xe[j] == 1) {
						if (min > d[j]) {
							min = d[j];
							min1 = i;
							min2 = j;
							exit = 0;
						}
					}
				}
			}
		}
		if (exit == 0) {
		out.println((min1 + 1) + " " + (min2 + 1) + " " + min);
		}
		else {
			out.println(-1);
		}
	}

	public void run() {
		try {
			in = new FastScanner(new File(problem_name + ".in"));
			out = new PrintWriter(new File(problem_name + ".out"));

			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public String next() {
			while ((st == null) || (!st.hasMoreTokens())) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return (st.nextToken());
		}

		public int nextInt() {
			return (Integer.parseInt(next()));
		}

		public long nextLong() {
			return (Long.parseLong(next()));
		}

		public double nextDouble() {
			return (Double.parseDouble(next()));
		}
	}

	public static void main(String[] args) {
		new TaskH().run();
	}
}
