import java.io.*;
import java.util.*;

public class ZStupidOlive {
	public static void main(String[] args) throws IOException {
		new ZStupidOlive().run();
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
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out, true);
		solve();
		out.flush();
	}

	int[] t;

	void set(int i, int l, int r, int ind, int val) {
		if (l + 1 == r) {
			t[i] = val;
			return;
		}
		int m = (l + r) / 2;
		if (m > ind) {
			set(2 * i + 1, l, m, ind, val);
		} else {
			set(2 * i + 2, m, r, ind, val);
		}
		t[i] = t[2 * i + 1] + t[2 * i + 2];
	}

	int sum(int i, int l, int r, int a, int b) {
		if (l >= b || r <= a) {
			return 0;
		}
		if (l >= a && r <= b) {
			return t[i];
		}
		int m = (l + r) / 2;
		return sum(2 * i + 1, l, m, a, b) + sum(2 * i + 2, m, r, a, b);
	}

	void solve() throws IOException {
		int n = nextInt();
		t = new int[4 * n + 4];
		int[] a = new int[n];
		int minv = 0;
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
			set(0, 0, n, a[i] - 1, 1);
			minv += sum(0, 0, n, a[i], n);
		}
		int besti = -1;
		int bestj = -1;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (a[i] > a[j]) {
					int temp = a[i];
					a[i] = a[j];
					a[j] = temp;
					int nov = 0;
					t = new int[4 * n + 4];
					for (int k = 0; k < n; k++) {
						set(0, 0, n, a[k] - 1, 1);
						nov += sum(0, 0, n, a[k], n);
					}

					temp = a[i];
					a[i] = a[j];
					a[j] = temp;
					if (nov < minv) {
						minv = nov;
						besti = i + 1;
						bestj = j + 1;
					}
				}
			}
		}
		out.println(besti + " " + bestj);
		// if (rmax == 0) {
		// out.println("-1 -1");
		// return;
		// }
		// t = new int[4 * n + 4];
		// int lmax = 0;
		// int lmaxi = 0;
		// for (int i = n - 1; i > -1; i--) {
		// set(0, 0, n, a[i] - 1, 1);
		// int temp = sum(0, 0, n, 0, a[i] - 1);
		// if (temp >= lmax) {
		// lmax = temp;
		// lmaxi = i;
		// }
		// }
		// out.println((lmaxi + 1) + " " + (rmaxi + 1));
	}
}
