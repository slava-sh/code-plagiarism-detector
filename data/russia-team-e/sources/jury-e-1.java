import java.io.*;
import java.util.*;

public class numbers_av {

	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		Map<String, Integer> stateN = new HashMap<String, Integer>();

		for (int i = 0; i < n; i++) {
			String start = in.nextToken();
			int k = in.nextInt();
			for (int j = 0; j < k; j++) {
				stateN.put(start + in.nextToken(), start.length());
			}
		}

		int q = in.nextInt();
		for (int i = 0; i < q; i++) {
			String number = in.nextToken();

			String part12 = null;
			int stateLen = -1;
			for (int len = 1; len <= number.length(); len++) {
				String check = number.substring(0, len);
				if (stateN.containsKey(check) && number.charAt(len) != '0') {
					if (part12 != null) {
						throw new AssertionError();
					}

					part12 = check;
					stateLen = stateN.get(check);
				}
			}

			if (part12 == null) {
				out.println("Incorrect");
				continue;
			}

			out.println(String.format("+%s(%s)%s",
					part12.substring(0, stateLen), part12.substring(stateLen),
					formatLastPart(number.substring(part12.length()))));
		}
	}

	private String formatLastPart(String s) {
		if (s.length() < 3 || s.length() > 7) {
			throw new AssertionError();
		}

		String ans = "";
		int i = s.length();
		while (i - 4 >= 0) {
			ans = "-" + s.substring(i - 2, i) + ans;
			i -= 2;
		}
		ans = s.substring(0, i) + ans;
		return ans;
	}

	void run() {
		try {
			in = new FastScanner("numbers.in");
			out = new PrintWriter("numbers.out");
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
		new numbers_av().run();
	}
}
