import java.io.*;
import java.util.*;

public class C {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int m = in.nextInt(), k = in.nextInt();
		m--;
		int[] a = new int[k];
		for (int i = 0; i < k; i++)
			a[i] = in.nextInt();
		int[] t = new int[m], r = new int[m];
		boolean[] good = new boolean[k];
		Arrays.fill(good, true);
		int all0 = 0;
		int before0 = 0;
		boolean dis = false;
		for (int i = 0; i < m; i++) {
			t[i] = in.nextInt();
			r[i] = in.nextInt();
			if (r[i] == 1)
				dis = true;
			if (t[i] == 0) {
				all0++;
			} else {
				a[t[i] - 1]--;
			}
			if (!dis && t[i] == 0)
				before0++;
			if (dis && t[i] != 0)
				good[t[i] - 1] = false;
		}
		boolean[] yes = new boolean[k];
		if (dis) {
			int best = -1;
			for (int i = 0; i < k; i++) {
				if (!good[i])
					continue;
				if (a[i] <= before0)
					yes[i] = true;
				if (best == -1 || a[i] < a[best])
					best = i;
			}
			all0 -= a[best];
		}
		for (int i = 0; i < k; i++)
			if (all0 >= a[i])
				yes[i] = true;
		for (boolean y : yes)
			out.print(y ? "Y" : "N");
		out.println();
	}

	void run() {
		in = new FastScanner();
		out = new PrintWriter(System.out);

		int t = in.nextInt();
		for (int i = 0; i < t; i++)
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
		new C().run();
	}
}