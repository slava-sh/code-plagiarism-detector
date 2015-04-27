import java.io.*;
import java.util.*;

public class Main {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt(), k = in.nextInt();
		char[] s = in.next().toCharArray();
		int[] z = new int[n];
		for (int i = 1, l = 0, r = 0; i < n; ++i) {
			if (i <= r)
				z[i] = Math.min(r - i + 1, z[i - l]);
			while (i + z[i] < n && s[z[i]] == s[i + z[i]])
				++z[i];
			if (i + z[i] - 1 > r) {
				l = i;
				r = i + z[i] - 1;
			}
		}
		char[] ans = new char[n];
		for (int i = 0; i < n; i++)
			ans[i] = '0';
		TreeSet<Integer> free = new TreeSet<>();
		for (int i = 0; i < n; i++) {
			free.add(i);
		}
		for (int st = 1; st <= n; st++) {
			if (st % k == 0) {
				int lenAB = st / k;
				if (k == 1 || z[lenAB] >= lenAB * (k - 1)) {
					if (st == n) {
						ans[n - 1] = '1';
						continue;
					}
					int lenA = Math.min(lenAB, z[st]);
					while (true) {
						Integer x = free.ceiling(st - 1);
						if (x == null)
							break;
						if (x < st + lenA) {
							free.remove(x);
							ans[x] = '1';
						} else {
							break;
						}
					}
				}
			}
		}
		out.println(new String(ans));
	}

	void run() {
		in = new FastScanner();
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(in.br.readLine());
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new Main().run();
	}
}