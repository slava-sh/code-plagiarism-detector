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
		BufferedReader in = new BufferedReader(new FileReader(new File("gcm.in")));
		PrintWriter out = new PrintWriter("gcm.out");
//		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
//		PrintWriter out = new PrintWriter(System.out);
		st[0] = new StringTokenizer(in.readLine());
		int a = readInt(in);
		int b = readInt(in);
		int gcm = gcm(a, b);
		int ab = a * b;
		int x = (int) Math.sqrt(ab);
		while (ab % x != 0 || gcm(x, ab / x) != gcm) {
			x++;
		}
		int y = ab / x;
		out.println(Math.min(x, y) + " " + Math.max(x, y));
		out.close();
		in.close();
	}
	public static int gcm(int a, int b) {
		for (; a != 0 && b != 0; ) {
			int ta = Math.max(a, b) % Math.min(a, b);
			b = Math.min(a, b);
			a = ta;
		}
		return a + b;
	}
}
