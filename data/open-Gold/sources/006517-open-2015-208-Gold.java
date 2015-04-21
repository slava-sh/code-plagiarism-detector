import java.io.*;
import java.util.*;

public class Gold {
	public static void main(String[] args) throws IOException {
		new Gold().run();
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

	final long inf = (long) 1e15 + 9;

	void solve() throws IOException {
		// String t1 = "1 2 5 6 3 5";
		int n = nextInt();
		int k = nextInt();
		long c = nextInt();
		long d = nextInt();
		// if (k != 1) {
		// out.println("12");
		// return;
		// }
		if (k == 1) {
			int[] a = new int[n];
			int[] b = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = nextInt();
				b[i] = nextInt();
			}
			long ans = 0;
			for (int i = 0; i < n; i++) {
				ans += (b[i] - a[i]) * d;
				if (i < n - 1 && (a[i + 1] - b[i]) * d > c) {
					ans += c;
				} else if (i < n - 1) {
					ans += (a[i + 1] - b[i]) * d;
				}
			}
			out.println(ans);
			return;
		}
		// if (n <= 100 && k <= 100) {
		int[] a = new int[n];
		int[] b = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
			b[i] = nextInt();
		}
		long ans = 0;
		for (int i = 0; i < n; i++) {
			ans += (b[i] - a[i]) * d;
		}
		long[][] min = new long[n][k];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < k; j++) {
				min[i][j] = inf;
			}
		}
		min[0][0] = 0;

		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < k; j++) {
				if (min[i][j] != inf) {
					min[i + 1][0] = Math.min(min[i + 1][0], min[i][j] + c);
					min[i + 1][j] = Math.min(min[i + 1][j], d
							* (a[i + 1] - b[i]) + min[i][j]);
					if (j + 1 < k) {
						min[i + 1][j + 1] = Math.min(min[i + 1][j + 1],
								min[i][j]);
					}
				}
			}
		}
		long adAns = inf;
		for (int j = 0; j < k; j++) {
			adAns = Math.min(min[n - 1][j], adAns);
		}
		if (adAns == inf) {
			out.println((b[n - 1] - a[0]) * d);
		} else {
			ans += adAns;
			out.println(ans);
		}
		// }
	}
}
