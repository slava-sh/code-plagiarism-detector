import java.io.*;
import java.util.*;

public class MagentaCakeIsALie {
	public static void main(String[] args) throws IOException {
		new MagentaCakeIsALie().run();
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

	void solve() throws IOException {
		String s = null;
		char[] num = { 'U', 'L', 'D', 'R' };
		int[] lastNum = { 1, 1, 2, 2 };
		int last = 0;
		do {
			for (int i = 0; i < lastNum[last]; i++) {
				out.println(num[last]);
				out.flush();
				s = nextToken();
				if (!s.equals("N")) {
					return;
				}
			}
			lastNum[last] += 2;
			last = (last + 1) % 4;
		} while (s.equals("N"));
	}
}
