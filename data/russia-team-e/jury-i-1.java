import java.io.*;
import java.util.*;

public class sochi_av {

	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt(), d = in.nextInt();
		int[] a  = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		
		Arrays.sort(a);
		int countGreater3d = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] >= 3 * d) {
				countGreater3d++;
			}
		}
		
		int canTake = Math.min(countGreater3d + 2, n);
		int length = 0;
		int sum = 0;
		
		for (int i = 0; i < canTake; i++) {
			int val = a[n - i - 1];
			sum += val;
			length = Math.max(length, sum - 2 * i * d);
		}
		
		out.println(length);
	}

	void run() {
		try {
			in = new FastScanner("sochi.in");
			out = new PrintWriter("sochi.out");
			solve();
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(String s) {
			try {
				br = new BufferedReader(new FileReader(s));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(nextToken());
		}

		long nextLong() {
			return Long.parseLong(nextToken());
		}

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}

	public static void main(String[] args) {
		new sochi_av().run();
	}
}
