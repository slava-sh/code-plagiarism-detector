import java.util.*;
import java.io.*;

public class che_dk {

	void solve() throws IOException {
		int n = nextInt();
		int r = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		Arrays.sort(a);
		long ans = 0;
		int j = 0;
		for (int i = 0; i < n; i++) {
			if (j <= i) j = i + 1;
			while (j < n && a[j] - a[i] <= r) {
				j++;
			}
			ans += (n - j);
		}
		out.println(ans);
	}
	
	void run() throws IOException {
		br = new BufferedReader(new FileReader("che.in"));
		out = new PrintWriter("che.out");
		solve();
		br.close();
		out.close();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer stok;

	String nextToken() throws IOException {
		while (stok == null || !stok.hasMoreTokens()) {
			String s = br.readLine();
			if (s == null) {
				return null;
			}
			stok = new StringTokenizer(s);
		}
		return stok.nextToken();
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

	char nextChar() throws IOException {
		return (char) (br.read());
	}

	String nextLine() throws IOException {
		return br.readLine();
	}

	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		new che_dk().run();
	}
}