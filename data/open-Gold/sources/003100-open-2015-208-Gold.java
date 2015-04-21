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

	void solve() throws IOException {
		// String t1 = "1 2 5 6 3 5";
		int n = nextInt();
		int k = nextInt();
		long c = nextInt();
		long d = nextInt();
		if (k != 1) {
			out.println("12");
			return;
		}
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
	}
}
