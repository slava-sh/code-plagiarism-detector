import java.io.*;
import java.util.*;

public class YellowBetter {
	public static void main(String[] args) throws IOException {
		new YellowBetter().run();
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

	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		int sum = 1;
		for(int i = 0; i < n; i++) {
			a[i] = nextInt();
			if(i > 0 && a[i] != a[i-1]) {
				sum++;
			}
		}
		int m = nextInt();
		for(; m > 0; m--) {
			int ind = nextInt() - 1;
			int val = nextInt();
			int before = 0;
			for(int i = ind - 1; i <= ind +1; i++) {
				if(i > -1 && i < n && a[i] != a[ind]) {
					before++;
				}
			}
			a[ind] = val;
			int after = 0;
			for(int i = ind - 1; i <= ind +1; i++) {
				if(i > -1 && i < n && a[i] != a[ind]) {
					after++;
				}
			}
			sum += after - before;
			out.println(sum);
		}
	}
}
