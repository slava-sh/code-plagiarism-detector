import java.io.*;
import java.util.*;
public class Pysch {
	static StringTokenizer[] st = new StringTokenizer[1];
	public static int readInt(BufferedReader in) throws Exception {
		for (; !st[0].hasMoreTokens(); ) {
			st[0] = new StringTokenizer(in.readLine());
		}
		return Integer.parseInt(st[0].nextToken());
	}
	public static void main(String[] args) throws Exception {
		/*
		BufferedReader in = new BufferedReader(new FileReader(new File("gcm.in")));
		PrintWriter out = new PrintWriter("gcm.out");
//		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
//		PrintWriter out = new PrintWriter(System.out);
		st[0] = new StringTokenizer(in.readLine());
		int a = readInt(in);
		int b = readInt(in);
		long gcm = gcm(a, b);
		long ab = a * b;
		long x = (long) Math.sqrt(ab) - 1;
		while (ab % x != 0 || gcm(x, ab / x) != gcm) {
			x++;
		}
		long y = ab / x;
		out.println(Math.min(x, y) + " " + Math.max(x, y));
		out.close();
		in.close();
		*/
		BufferedReader in = new BufferedReader(new FileReader(new File("game.in")));
		PrintWriter out = new PrintWriter("game.out");
//		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
//		PrintWriter out = new PrintWriter(System.out);
		st[0] = new StringTokenizer(in.readLine());
		int n = readInt(in), a = readInt(in), l1 = readInt(in), r1 = readInt(in), l2 = readInt(in), r2 = readInt(in);
		int x = 0, y = 0, xy = 0;
		for (int i = 0; i < n; i++) {
			int v = readInt(in);
			if (l1 <= v && v <= r1 && !(l2 <= v && v <= r2)) x++;
			if (!(l1 <= v && v <= r1) && l2 <= v && v <= r2) y++;
			if (l1 <= v && v <= r1 && l2 <= v && v <= r2) xy++;
		}
		y += xy / 2;
		x += xy / 2;
		if (xy % 2 == 1) x++;
		if (a % 2 == 0) {
			if (Math.min(x, y) >= a / 2) {
				out.print("Draw");
			} else {
				if (x > y) out.print("Petya");
				if (x < y) out.print("Vasya");
				if (x == y) out.print("Draw");
			}
		} else {
			if (x == 0) {
				if (y == 0) {
					out.print("Draw");
				} else {
					out.print("Vasya");
				}
			} else {
				x--; a--;
				if (Math.min(x, y) >= a / 2) {
					out.print("Petya");
				} else {
					if (x + 1 > y) out.print("Petya");
					if (x + 1 < y) out.print("Vasya");
					if (x + 1 == y) out.print("Draw");
				}
			}
		}
		out.close();
		in.close();
	}
	/*
	public static long gcm(long a, long b) {
		for (; a != 0 && b != 0; ) {
			long ta = Math.max(a, b) % Math.min(a, b);
			b = Math.min(a, b);
			a = ta;
		}
		return a + b;
	}
	*/
}
