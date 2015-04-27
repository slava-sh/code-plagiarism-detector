import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.Arrays;

public class E48 {

	static StreamTokenizer in;
	static PrintWriter out;
	
	static int nextInt() throws IOException {
		in.nextToken();
		return (int)in.nval;
	}
	
	static String nextString() throws IOException {
		in.nextToken();
		return in.sval;
	}

	public static void main(String[] args) throws IOException {
		in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
		out = new PrintWriter(System.out);

		int h = nextInt(), t = nextInt();
		r = nextInt();
		
		n = nextInt();
		a = new int[n+1][];
		for (int i = 1; i <= n; i++)
			a[i] = new int[]{nextInt(), nextInt()};
		
		m = nextInt();
		b = new int[m+1][];
		for (int i = 1; i <= m; i++)
			b[i] = new int[]{nextInt(), nextInt()};
		
		int win = Integer.MIN_VALUE, lose = Integer.MIN_VALUE;
		int[][] d = new int[r+1][r+1];
		for (int[] dd : d)
			Arrays.fill(dd, -1);
		
		int[][] q = new int[(r+1)*(r+1)][];
		int start = 0, finish = 0;
		
		d[h][t] = 0;
		q[finish++] = new int[]{h, t};
		
		L : while (finish > start) {
			int[] cur = q[start++];
			int hh = cur[0], tt = cur[1];
			
			for (int i = 1; i <= hh && i < a.length; i++) {
				int hhh = hh - i + a[i][0];
				int ttt = tt + a[i][1];
				if (hhh == 0 && ttt == 0) {
					win = d[hh][tt] + 1;
					break L;
				}
				else if (hhh + ttt > r) {
					
				}
				else if (d[hhh][ttt] == -1) {
					q[finish++] = new int[]{hhh, ttt};
					d[hhh][ttt] = d[hh][tt] + 1;
				}
			}
			
			for (int i = 1; i <= tt && i < b.length; i++) {
				int hhh = hh + b[i][0];
				int ttt = tt - i + b[i][1];
				if (hhh == 0 && ttt == 0) {
					win = d[hh][tt] + 1;
					break L;
				}
				else if (hhh + ttt > r) {
					
				}
				else if (d[hhh][ttt] == -1) {
					q[finish++] = new int[]{hhh, ttt};
					d[hhh][ttt] = d[hh][tt] + 1;
				}
			}
		}
		
		if (win != Integer.MIN_VALUE) {
			out.println("Ivan");
			out.println(win);
		}
		else if (draw(h, t)) {
			out.println("Draw");
		}
		else {
			out.println("Zmey");
			out.println(longest(h, t));
		}
		
		out.flush();
	}
	
	static int r;
	static int n, m;
	static int[][] a, b;
	static int[][] clr;
	
	static boolean draw(int h, int t) {
		clr = new int[r+1][r+1];
		return !go(h, t);
	}
	
	static boolean go(int h, int t) {
		clr[h][t] = 1;
		
		for (int i = 1; i <= h && i < a.length; i++) {
			int hhh = h - i + a[i][0];
			int ttt = t + a[i][1];
			
			if (hhh + ttt <= r) {
				if (clr[hhh][ttt] == 0) {
					if (!go(hhh, ttt)) return false;
				}
				else if (clr[hhh][ttt] == 1) {
					return false;
				}
			}
		}
		
		for (int i = 1; i <= t && i < b.length; i++) {
			int hhh = h + b[i][0];
			int ttt = t - i + b[i][1];
			
			if (hhh + ttt <= r) {
				if (clr[hhh][ttt] == 0) {
					if (!go(hhh, ttt)) return false;
				}
				else if (clr[hhh][ttt] == 1) {
					return false;
				}
			}
		}
		
		clr[h][t] = 2;
		
		return true;
	}
	
	static int longest(int h, int t) {
		clr = new int[r+1][r+1];
		return go1(h, t);
	}
	
	static int go1(int h, int t) {
		if (clr[h][t] != 0) return clr[h][t];
		
		int res = 1;
		
		for (int i = 1; i <= h && i < a.length; i++) {
			int hhh = h - i + a[i][0];
			int ttt = t + a[i][1];
			
			if (hhh + ttt <= r) {
				res = Math.max(res, go1(hhh, ttt) + 1);
			}
		}
		
		for (int i = 1; i <= t && i < b.length; i++) {
			int hhh = h + b[i][0];
			int ttt = t - i + b[i][1];
			
			if (hhh + ttt <= r) {
				res = Math.max(res, go1(hhh, ttt) + 1);
			}
		}
		
		return clr[h][t] = res;
	}
}
