import java.io.*;
import java.util.*;
import java.math.*;

public class C implements Runnable {
	private final boolean useStandardIO = true;
	private final String inFile = ".in";
	private final String outFile = ".out";

	class State implements Comparable<State> {
		int size, cnt;

		State(int size, int cnt) {
			this.size = size;
			this.cnt = cnt;
		}

		@Override
		public int compareTo(State arg0) {
			return arg0.cnt - cnt;
		}
	}

	private void solve() throws IOException {
		PriorityQueue<State> q = new PriorityQueue<C.State>();
		int n = nextInt();
		int[] sz = new int[n];
		Random r = new Random(123);
		for (int i = 0; i < n; ++i) {
			sz[i] = nextInt();
			int t = r.nextInt(i + 1);
			int tmp = sz[i];
			sz[i] = sz[t];
			sz[t] = tmp;
		}
		Arrays.sort(sz);
		int cnt = 0, cur = -1;
		for (int i = 0; i <= n; ++i)
			if (i == 0 || i == n || sz[i] != sz[i - 1]) {
				if (cur != -1) {
					q.add(new State(cur, cnt));
				}
				if (i != n) {
					cnt = 1;
					cur = sz[i];
				}
			} else {
				++cnt;
			}
		List<String> ans = new ArrayList<String>();
		int[] k = new int[3];
		while (q.size() > 2) {
			State s1 = q.poll();
			State s2 = q.poll();
			State s3 = q.poll();

			k[0] = s1.size;
			k[1] = s2.size;
			k[2] = s3.size;
			Arrays.sort(k);
			ans.add(k[2] + " " + k[1] + " " + k[0]);
			s1.cnt--;
			s2.cnt--;
			s3.cnt--;
			if (s1.cnt > 0)
				q.add(s1);
			if (s2.cnt > 0)
				q.add(s2);
			if (s3.cnt > 0)
				q.add(s3);
		}
		writer.println(ans.size());
		for (String s : ans)
			writer.println(s);
	}

	public static void main(String[] args) {
		new Thread(null, new C(), "", 64 * 1024 * 1024).run();
	}

	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;

	public void run() {
		try {
			try {
				Locale.setDefault(Locale.US);
			} catch (Exception e) {
			}
			if (useStandardIO) {
				reader = new BufferedReader(new InputStreamReader(System.in));
				writer = new PrintWriter(System.out);
			} else {
				reader = new BufferedReader(new FileReader(inFile));
				writer = new PrintWriter(new FileWriter(outFile));
			}
			tokenizer = null;
			solve();
			// reader.close();
			writer.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	BigInteger nextBigInteger() throws IOException {
		return new BigInteger(nextToken());
	}

	String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}
}