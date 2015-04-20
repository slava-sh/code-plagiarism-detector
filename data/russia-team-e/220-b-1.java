import java.io.*;
import java.util.StringTokenizer;


public class PrB {
	public static void main(String[] args) throws IOException {
		new PrB().run();
	}
	BufferedReader in;
	PrintWriter out;
	StringTokenizer st;
	String nextToken() throws IOException {
		while(st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(in.readLine());
		}
		return st.nextToken();
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
	
	void run() throws IOException {
		in = new BufferedReader(new FileReader("che.in"));
		out = new PrintWriter("che.out");
		solve();
		out.flush();
	}
	
	int binSearch(int l, int r, int[] d, int et, int w) {
		if(l == r - 1 || l == r) {
			if(d[r] - d[et] <= w) {
				return r+1;
			}
			return r;
		}
		int m = (l+r)/2;
		if(d[m] - d[et] > w) {
			return binSearch(l, m, d, et, w);
		}else {
			return binSearch(m, r, d, et, w);
		}
	}
	
	
	void solve() throws IOException {
		int n = nextInt();
		int r = nextInt();
		int[] d = new int[n];
		for(int i = 0; i < n; i++) {
			d[i] = nextInt();
		}
		int ans = 0;
		for(int i = 0; i < n - 1; i++) {
			int k = binSearch(i, n - 1, d, i, r);
			ans += (n - k);
		}
		out.println(ans);
	}
}
