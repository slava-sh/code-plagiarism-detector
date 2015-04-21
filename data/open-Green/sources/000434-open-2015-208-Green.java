import java.io.*;
import java.util.*;

public class Green {
	public static void main(String[] args) throws IOException {
		new Green().run();
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

	ArrayList<Long> primeDivs;

	long getAns(int i, int k, long n) {
		if (i == k || i == primeDivs.size()) {
			return (n + 1) / 2;
		}
		long cur = primeDivs.get(i);
		// System.out.println(cur + " " + n);
		return getAns(i + 1, k, (n / cur)) * ((cur + 1) / 2);
	}

	void solve() throws IOException {
		long n = nextLong();
		int k = nextInt();
		primeDivs = new ArrayList<Long>();
		long n1 = n;
		for (long i = 2; i * i <= n; i++) {
			while (n1 % i == 0) {
				n1 /= i;
				primeDivs.add(i);
			}
		}
		if (n1 != 1) {
			primeDivs.add(n1);
		}
		out.println(getAns(0, k, n));
	}
}
