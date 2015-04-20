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

			in = new FastScanner(new FileReader(new File("fence.in")));
			out = new PrintWriter(new FileWriter(new File("fence.out")));

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
		r = a[0] + 1;
		x = a[0];
		left = 0;
		boolean f = false;
		int y = 2;
		while (r - left > 1 && y != 0) {
			int l = a[0];
			int j = 1;
			
			while (j < n && l <= k){
				l = l + Math.max(x, a[j] - l);
				j++;
				//out.println(j + " " + l);
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
				//out.println(n + " " + k);
			}
			
			if (y == 1){
				left = x;
				x = (x + r) / 2;  
			}
			if (y == -1){
				r = x;
				x = (x + left) / 2;
			}
			
			/*if (Math.abs(x - xp) < 1){
				f = true;
				y = 0;
			}
			xp = x;*/
			//out.println(l + " " + j  + " " + x + " " + y);
			//out.println(left + " " + r + " " + x + " " + y + " " + l + " " + j);
			
		}
		out.println(x);
	}

	public static void main(String[] args) {
		new olymp().run();
	}

}
