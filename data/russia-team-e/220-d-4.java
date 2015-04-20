import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class PrD {
	public static void main(String[] args) throws IOException {
		new PrD().run();
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

	void run() throws IOException {
		in = new BufferedReader(new FileReader("fence.in"));
		out = new PrintWriter("fence.out");
		solve();
		out.flush();
	}

	boolean can(int x, int[] d, int k) {
		int end1 = 0;
		for (int i = 0; i < d.length; i++) {
			if (d[i] < x) {
				return false;
			}
			end1 += Math.max(x, d[i] - end1);
		}
		if (end1 > k) {
			return false;
		}
		return true;
	}

	int binSearch(int l, int r, int[] d, int k) {
		if (l == r - 1) {
			return l;
		}
		int m = (l + r) / 2;
		if (can(m, d, k)) {
			return binSearch(m, r, d, k);
		} else {
			return binSearch(l, m, d, k);
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		Arrays.sort(a);
		int x = binSearch(0, k + 1, a, k);
		out.println(x);
	}
}
