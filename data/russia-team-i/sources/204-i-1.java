import java.util.*;
import java.io.*;

public class TaskI {
	FastScanner in;
	PrintWriter out;

	final String problem_name = "sochi";

	public void solve() throws IOException {
		int n = in.nextInt();
		int d = in.nextInt();
		ArrayList<Integer> d3 = new ArrayList<Integer>();
		ArrayList<Integer> d2 = new ArrayList<Integer>();
		int ans1 = 0;
		for (int i = 0; i < n; i++) {
			int x = in.nextInt();
			ans1 = Math.max(ans1, x);
			if (x <= (2 * d)) {
				continue;
			}
			if (x >= (3 * d)) {
				d3.add(x);
			} else {
				d2.add(x);
			}
		}
		if ((d2.size() == 0) && (d3.size() == 0)) {
			out.println(ans1);
			return;
		}
		int ans = 0;
		Collections.sort(d2);
		for (int z : d3) {
			ans += z - (d * 2);
		}
		if (d2.size() == 0) {
			ans += 2 * d;
		}
		if (d2.size() == 1) {
			ans += d2.get(0);
		}
		if (d2.size() > 1) {
			ans += d2.get(d2.size() - 1) + d2.get(d2.size() - 2) - (2 * d);
		}
		out.println(ans);
	}

	public void run() {
		try {
			in = new FastScanner(new File(problem_name + ".in"));
			out = new PrintWriter(new File(problem_name + ".out"));

			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public String next() {
			while ((st == null) || (!st.hasMoreTokens())) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return (st.nextToken());
		}

		public int nextInt() {
			return (Integer.parseInt(next()));
		}

		public long nextLong() {
			return (Long.parseLong(next()));
		}

		public double nextDouble() {
			return (Double.parseDouble(next()));
		}
	}

	public static void main(String[] args) {
		new TaskI().run();
	}
}