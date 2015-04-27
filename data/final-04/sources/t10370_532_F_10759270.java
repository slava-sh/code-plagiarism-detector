import java.io.*;
import java.util.*;

public class taskF {

	private static final long BASE = 2;
	private static final long MOD = 1000000007;
	private static long POW = 1;

	void solve() throws IOException {
		nextInt();
		nextInt();
		String s = nextToken();
		String t = nextToken();
		for (int i = 0; i < t.length() - 1; i++) {
			POW = POW * BASE;
			POW = POW % MOD;
		}
		int n = s.length();
		long[] hashS = get(s, t.length());
		long[] hashT = get(t, t.length());

		ArrayList<Integer> ans = new ArrayList<Integer>();
		for (int i = 0; i < n - t.length() + 1; i++) {
			if (match(hashT, hashS)) {
				ans.add(i + 1);
			}
//			System.err.println(Arrays.toString(hashT) + " "
//					+ Arrays.toString(hashS));
//			System.err.println(i);
			if (i < n - t.length())
				move(hashS, i, s, t.length());
		}

		out.println(ans.size());
		for (int x : ans) {
			out.print(x + " ");
		}
	}

	private void move(long[] hashS, int x, String s, int t) {
		int c = s.charAt(x) - 'a';
		hashS[c] = (hashS[c] - POW + MOD) % MOD;
		for (int j = 0; j < 26; j++) {
			hashS[j] = hashS[j] * BASE;
			if (s.charAt(x + t) - 'a' == j) {
				hashS[j]++;
			}
			hashS[j] %= MOD;
		}
		return;
	}

	private long[] get(String t, int n) {
		long[] res = new long[26];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 26; j++) {
				res[j] = res[j] * BASE;
				if (t.charAt(i) - 'a' == j) {
					res[j]++;
				}
				res[j] %= MOD;
			}
		}
		return res;
	}

	private boolean match(long[] hs, long[] ht) {
		int n = 26;
		HashMap<Long, Integer> wh = new HashMap<>();

		for (int i = 0; i < 26; i++) {
			if (ht[i] != 0)
				wh.put(ht[i], i);
		}
//		System.err.println(wh);
		boolean[] was = new boolean[n];

		for (int i = 0; i < n; i++) {
			if (was[i]) {
				continue;
			}
			if (hs[i] == 0) {
				continue;
			}
			if (!wh.containsKey(hs[i])) {
				return false;
			}
			int j = wh.get(hs[i]);
//			System.err.println(i + " " + j);
			if (was[j]) {
//				System.err.println("FALSE");
				return false;
			}
			if (ht[i] != hs[j] || hs[j] != ht[i]) {
				return false;
			}
			if (ht[i] == 0 && hs[j] == 0) {
				was[i] = true;
				was[j] = true;
				continue;
			}
			
		}
		return true;
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;

	void run() {
		try {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			// br = new BufferedReader(new FileReader(new File("taskF.in")));
			// out = new PrintWriter("taskF.out");

			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
		new taskF().run();
	}

	String nextToken() throws IOException {
		while ((st == null) || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine());
		return st.nextToken();
	}

	int nextInt() throws NumberFormatException, IOException {
		return Integer.parseInt(nextToken());
	}

	double nextDouble() throws NumberFormatException, IOException {
		return Double.parseDouble(nextToken());
	}

	long nextLong() throws NumberFormatException, IOException {
		return Long.parseLong(nextToken());
	}
}
