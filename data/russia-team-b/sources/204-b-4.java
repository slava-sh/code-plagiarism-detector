import java.util.*;
import java.io.*;

public class TaskB {
	FastScanner in;
	PrintWriter out;

	final String problem_name = "che";

	public void solve() throws IOException {
		int n = in.nextInt();
		int r = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		int ans = 0;
		int k = n - 1;
		int i = k;
		int j = k;
		while ((i) > 0) {
			while ((a[j] - a[i] <= r) && (i > 0)) {
				i--;
			}
			int exit = 1;
			while ((a[j] - a[i] > r) && (j >= 0)) {
				j--;
				exit = 0;
			}
			if (exit == 0){
			j++;
			}
			if (a[j] - a[i] > r) {
				ans += (k - j + 1) * (i + 1);
			}
			j--;
			k = j;
		}
		out.println(ans);
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
		new TaskB().run();
	}
}