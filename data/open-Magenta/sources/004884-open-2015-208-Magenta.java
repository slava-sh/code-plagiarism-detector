import java.io.*;
import java.util.*;

public class Magenta2 {
	public static void main(String[] args) throws IOException {
		new Magenta2().run();
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
		char[] num = { 'R', 'D', 'L', 'D', 'R', 'U' };
		int[] lastNum = { 1, 1, 1, 1, 2, 2 };
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
			if (last != 0 && last != 3) {
				lastNum[last] += 2;
			}
			last = (last + 1) % 6;
		} while (s.equals("N"));
	}
}
