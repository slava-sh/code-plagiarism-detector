//package olymp;

import java.util.*;
import java.io.*;

public class olymp {
	PrintWriter out;
	FastScanner in;

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(InputStreamReader isr) {
			br = new BufferedReader(isr);
		}

		String next() throws IOException {
			while (st == null || !st.hasMoreTokens()) {
				st = new StringTokenizer(br.readLine());
			}
			return st.nextToken();
		}

		int nextInt() throws NumberFormatException, IOException {
			return Integer.parseInt(next());
		}

		long nextLong() throws NumberFormatException, IOException {
			return Long.parseLong(next());
		}

	}

	void run() {
		try {

			in = new FastScanner(new FileReader(new File("che.in")));
			out = new PrintWriter(new FileWriter(new File("che.out")));

//			in = new FastScanner(new InputStreamReader(System.in));
//			out = new PrintWriter(new OutputStreamWriter(System.out));

			solve();

			out.close();

		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	int[] a;
	int x;
	int r;
	int left;
	
	void bin(int y){
		if (y == 1){
			left = x;
			x = (x + r) / 2;  
		}
		if (y == -1){
			r = x;
			x = (x + left) / 2;
		}
	}
	
	void solve() throws NumberFormatException, IOException {
		int n = in.nextInt();
		int k = in.nextInt();
		a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		Arrays.sort(a);
		int xp = 0;
		x = a[0];
		r = a[0];
		left = 1;
		boolean f = false;
		int y = 0;
		for (x = a[0]; !f; bin(y)){
			int l = a[0];
			int j = 1;
			while (j < n && l < k){
				l = l + Math.max(x, a[j] - l);
				j++;
			}
			if (j == n){
				if (l == k){
					y = 0;
				}
				if (l > k){
					y = -1;
				}
				if (l < k){
					y = 1;
				}
			} else {
				y = -1;
			}
			if (((l <= k && j == n)) && (xp == x)){
				f = true;
				y = 0;
			}
			xp = x;
			//out.println(l + " " + j  + " " + x + " " + y);
			
		}
		out.println(x);
	}

	public static void main(String[] args) {
		new olymp().run();
	}

}
