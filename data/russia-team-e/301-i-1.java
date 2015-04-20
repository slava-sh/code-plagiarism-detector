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
			// TODO Auto-generated constructor stub
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

			 in = new FastScanner(new FileReader(new File("sochi.in")));
			 out = new PrintWriter(new FileWriter(new File("sochi.out")));

//			in = new FastScanner(new InputStreamReader(System.in));
//			out = new PrintWriter(new OutputStreamWriter(System.out));

			solve();

			out.close();

		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	void solve() throws NumberFormatException, IOException {
		ArrayList<Integer> ans = new ArrayList<Integer>();
		int n = in.nextInt();
		int d = in.nextInt();
		for (int i = 0; i < n; i++) {
			ans.add(in.nextInt());
		}
		if (ans.size() == 1) {
			out.print(ans.get(0));
			return;
		}
		Collections.sort(ans);
		int length = 0;
		while (ans.get(ans.size() - 1) >= 3 * d) {
			length += ans.get(ans.size() - 1) - 2 * d;
			ans.remove(ans.size() - 1);
		}
		int c = 2;
		for (int i = 0; i < 2; i++) {
			if (!ans.isEmpty() && ans.get(ans.size() - 1) >= 2 * d) {
				length += ans.get(ans.size() - 1) - d;
				ans.remove(ans.size() - 1);
				c--;
			}
		}
		length += c * d;
		out.print(length);
		return;

	}

	public static void main(String[] args) {
		new olymp().run();
	}

}
