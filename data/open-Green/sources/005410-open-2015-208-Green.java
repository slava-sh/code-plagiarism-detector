import java.io.*;
import java.util.*;

public class GreenMayBe {
	public static void main(String[] args) throws IOException {
		new GreenMayBe().run();
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

	final long inf = (long) 1e15 + 7;

	void solve() throws IOException {
		long n = nextLong();
		int k = nextInt();
		ArrayList<Long> divs = new ArrayList<Long>();
		for (long i = 1; i * i <= n; i++) {
			if (n % i == 0) {
				divs.add(i);
				if (i * i != n) {
					divs.add(n / i);
				}
			}
		}
		Collections.sort(divs);
		HashMap<Long, Integer> getInd = new HashMap<Long, Integer>();
		for (int i = 0; i < divs.size(); i++) {
			getInd.put(divs.get(i), i);
		}
		long[][] d = new long[k + 1][divs.size()];
		for (int i = 0; i < k + 1; i++) {
			for (int j = 0; j < divs.size(); j++) {
				d[i][j] = inf;
			}
		}
		d[0][0] = 1;
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < divs.size(); j++) {
				if (d[i][j] != inf) {
					long ost = n / divs.get(j);
					for (int t1 = 0; t1 <= getInd.get(ost); t1++) {
						Long t = divs.get(t1);
						if (ost % t == 0) {
							d[i + 1][getInd.get(divs.get(j) * t)] = Math.min(
									d[i + 1][getInd.get(divs.get(j) * t)],
									d[i][j] * (t + 1) / 2);
						}
					}
				}
			}
		}
		// System.out.println(Arrays.deepToString(d));
		out.println(d[k][divs.size() - 1]);
	}
}
