import java.util.*;
import java.io.*;

public class A {
	FastScanner in;
	PrintWriter out;

	int[] p;

	void calcPrefix(char[] str) {
		int n = str.length;
		for (int i = 1; i < n; ++i) {
			int j = p[i - 1];
			while (j > 0 && str[i] != str[j])
				j = p[j - 1];
			if (str[i] == str[j])
				++j;
			p[i] = j;
		}
	}

	public void solve() throws IOException {
		int n = in.nextInt();
		int m = in.nextInt();
		char[] s = in.next().toCharArray(), t = in.next().toCharArray();
		int[][] nextIn = new int[26][n];
		for (char c = 'a'; c <= 'z'; c++) {
			nextIn[c - 'a'][n - 1] = -1;
			for (int i = n - 2; i >= 0; i--) {
				if (s[i] == c)
					nextIn[c - 'a'][i] = i;
				else
					nextIn[c - 'a'][i] = nextIn[c - 'a'][i + 1];
			}
		}
		
		char[] str = new char[n + m + 1];
		p = new int[n + m + 1];
		boolean[] canStart = new boolean[n];
		Arrays.fill(canStart, true);
		for (char ct = 'a'; ct <= 'z'; ct++) {
			boolean[] canCurrent = new boolean[n];
			for (char cs = 'a'; cs <= 'z'; cs++) {
				for (int i = 0; i < m; i++)
					str[i] = (ct == t[i] ? '1' : '0');
				str[m] = '$';
				int start = m + 1;
				for (int i = 0; i < n; i++)
					str[start + i] = (cs == s[i] ? '1' : '0');
				calcPrefix(str);
				for (int i = start + m - 1; i < start + n; i++) {
					if (p[i] == m)
						canCurrent[i - start - m + 1] = true;
				}
			}
			for (int i = 0; i < n; i++) {
				if (!canCurrent[i])
					canStart[i] = false;
			}
		}
		ArrayList<Integer> ans = new ArrayList<>();
		nextStart:
		for (int st = 0; st < n; st++) {
			if (!canStart[st])
				continue;
			
			char[] to = new char[26];
			for (char c = 'a'; c <= 'z'; c++) {
				int idx = nextIn[c - 'a'][st];
				if (idx != -1 && idx < st + m) {
					char c2 = t[idx - st];
					//System.out.println(c + " " + c2);
					if (to[c - 'a'] != 0 && to[c - 'a'] != c2)
						continue nextStart;
					to[c - 'a'] = c2;
					if (to[c2 - 'a'] != 0 && to[c2 - 'a'] != c)
						continue nextStart;
					to[c2 - 'a'] = c;
				}
			}
			ans.add(st);
		}
		out.println(ans.size());
		for (int x : ans)
			out.print((x + 1) + " ");
	}

	public void run() {
		try {
			in = new FastScanner();
			out = new PrintWriter(System.out);

			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] arg) {
		new A().run();
	}
}