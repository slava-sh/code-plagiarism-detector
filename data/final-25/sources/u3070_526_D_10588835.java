import java.io.*;
import java.util.*;

public class D {

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
		String str = next();
		if (k == 1) {
			for (int i = 0; i < n; i++) {
				out.print(1);
			}
			out.println();
			return;
		}
		int[] z = zfun(str);
		int[] type = new int[n];
		for (int i = 1; i < n; i++) {
			if ((i+1) % k != 0) {
				continue;
			}
			int len = (i+1) / k;
			int shareLen = len * (k-1);
			if (z[len] >= shareLen) {
				type[i] = 1;
			}
		}
		
		int last = -1;
		for (int i = 1; i<n; i++) {
			if (type[i - 1] == 1) {
				last = Math.max(last, i+Math.min(z[i],(i)/k)-1);
			}
			if (i <= last && type[i] == 0) {
				type[i] = 2;
			}
		}
		for (int i = 0; i < n; i++) {
			if (type[i] == 2) {
				type[i] = 1;
			}
			out.print(type[i]);			
		}
		
	}

	private int[] zfun(String str) {
		int n = str.length();
		int[] z = new int[n];
		int l = 0, r = 0;
		for (int i=1; i<n; ++i) {
			if (i <= r) {
				z[i] = Math.min(r-i+1, z[i-l]);
			}
			while (i+z[i] < n && str.charAt(z[i]) == str.charAt(i+z[i])) {
				++z[i];
			}
			if (i+z[i]-1 > r) {
				l = i;
				r = i+z[i]-1;
			}
		}
		return z;
	}

	void run() throws IOException {
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D().run();
	}

	BufferedReader in;
	PrintWriter out;
	StringTokenizer st;

	String next() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String temp = in.readLine();
			if (temp == null) {
				return null;
			}
			st = new StringTokenizer(temp);
		}
		return st.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	long nextLong() throws IOException {
		return Long.parseLong(next());
	}

}
