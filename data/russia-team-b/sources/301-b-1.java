//package olymp;

import java.util.*;
import java.io.*;

public class olymp {
	PrintWriter out;
	FastScanner in;

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(InputStreamReader isr) {
			br = new BufferedReader(isr);
		}

		String next() throws IOException {
			while (st == null || !st.hasMoreTokens()) {
				st = new StringTokenizer(br.readLine());
			}
			return st.nextToken();
		}

		int nextInt() throws NumberFormatException, IOException {
			return Integer.parseInt(next());
		}

		long nextLong() throws NumberFormatException, IOException {
			return Long.parseLong(next());
		}

	}

	void run() {
		try {

			in = new FastScanner(new FileReader(new File("che.in")));
			out = new PrintWriter(new FileWriter(new File("che.out")));

//			in = new FastScanner(new InputStreamReader(System.in));
//			out = new PrintWriter(new OutputStreamWriter(System.out));

			solve();

			out.close();

		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	void solve() throws NumberFormatException, IOException {
		int n = in.nextInt();
		int r = in.nextInt();
		int[] street = new int[n];
		for (int i = 0; i < n; i++) {
			street[i] = in.nextInt();
		}
		long ans = 0;
		int i = 0;
		int j = 1;
		while (j < n && i < n) {
			if (street[j] - street[i] > r) {
				ans += n - j;
				i++;
			} else {
				j++;
			}
		}
		out.print(ans);
	}

	public static void main(String[] args) {
		new olymp().run();
	}

}
