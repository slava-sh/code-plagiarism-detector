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
		// System.out.println(n);
		if (i + 1 == k || i == primeDivs.size()) {
			return (n + 1) / 2;
		}

		long cur = primeDivs.get(i);
		// System.out.println(cur + " " + n);
		return getAns(i + 1, k, (n / cur)) * ((cur + 1) / 2);
	}

	long stupidAns(long n, int k) {
		if (k == 1) {
			return (n + 1) / 2;
		}
		long best = Long.MAX_VALUE;
		for (int i = 1; i <= n; i++) {
			if (n % i == 0) {
				best = Math.min(best, ((i + 1) / 2) * stupidAns(n / i, 1));
			}
		}
		return best;
	}

	void solve() throws IOException {
		long n = nextLong();
		int k = nextInt();
		if (k <= 2) {
			out.println(stupidAns(n, k));
		}
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
		Collections.sort(primeDivs, new Comparator<Long>() {

			@Override
			public int compare(Long arg0, Long arg1) {
				if (arg0 % 2 == 0 && arg1 % 2 == 0) {
					return Long.compare(arg0, arg1);
				}
				if (arg0 % 2 == 0 && arg1 % 2 == 1) {
					return -1;
				}

				if (arg0 % 2 == 1 && arg1 % 2 == 0) {
					return 1;
				}
				return Long.compare(arg1, arg0);
			}
		});
		out.println(getAns(0, k, n));
	}
}
