import java.io.*;
import java.util.*;

public class Blue {
	public static void main(String[] args) throws IOException {
		new Blue().run();
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
		in = new BufferedReader(new FileReader("input.txt"));
		out = new PrintWriter("output.txt");
		solve();
		out.flush();
	}

	HashSet<String> pam1;
	HashMap<String, Integer> pam;
	HashSet<String> best;

	void gen(int i, int l, String s) {
		if (i == s.length()) {
			if (best == null || pam1.size() < best.size()) {
				// System.out.println("!!! " + pam1);
				best = new HashSet<String>(pam1);
			}
			return;
		}

		for (int j = i + 2; j <= Math.min(i + l, s.length()); j++) {
			String et = s.substring(i, j);
			if (pam.containsKey(et)) {
				int temp = pam.get(et);
				pam.remove(et);
				pam.put(et, temp + 1);
				gen(j, l, s);
				pam.remove(et);
				pam.put(et, temp + 1);
			} else {
				pam.put(et, 1);
				pam1.add(et);
				gen(j, l, s);
				pam.remove(et);
				pam1.remove(et);
			}
		}
	}

	void solve() throws IOException {
		int l = nextInt();
		String s = nextToken();
		pam = new HashMap<String, Integer>();
		pam1 = new HashSet<String>();
		gen(0, l, s);
		out.println(best.size());
		for (String t : best) {
			out.println(t);
		}
	}
}
