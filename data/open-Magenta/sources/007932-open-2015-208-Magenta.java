import java.io.*;
import java.util.*;

public class MagnetaRand {
	public static void main(String[] args) throws IOException {
		new MagnetaRand().run();
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
		Random r = new Random();
		// char[] num = { 'R', 'D', 'L', 'U' };
		// int[] lastNum = { 1, 1, 1, 1, 2, 2 };
		// int last = 0;
		do {
			if (r.nextInt(2) == 0) {
				out.println('R');
			} else {
				out.println('D');
			}
			// out.println(num[r.nextInt(4)]);
			out.flush();
			s = nextToken();
			// last = (last + 1) % 6;
		} while (s.equals("N"));
	}
}
