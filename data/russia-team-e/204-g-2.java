import java.util.*;
import java.io.*;

public class TaskG {
	FastScanner in;
	PrintWriter out;

	final String problem_name = "prizes";

	public void solve() throws IOException {
		int m = in.nextInt();
		int n = in.nextInt();
		int min = Math.min(m, n);
		int max = Math.max(m, n);
		if (min == 1) {
			out.println((max + 1) / 4);
		} else {
			out.println((min + 1) / 4);
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
		new TaskG().run();
	}
}