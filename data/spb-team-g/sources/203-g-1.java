package olimp;

import java.io.*;
import java.util.*;

public class Pysch2 {
	static StringTokenizer[] st = new StringTokenizer[1];
	public static int readInt(BufferedReader in) throws Exception {
		for (; !st[0].hasMoreTokens(); ) {
			st[0] = new StringTokenizer(in.readLine());
		}
		return Integer.parseInt(st[0].nextToken());
	}
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(new File("merlin.in")));
		PrintWriter out = new PrintWriter("merlin.out");
//		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
//		PrintWriter out = new PrintWriter(System.out);
		st[0] = new StringTokenizer(in.readLine());
		int n = readInt(in);
		int[] e = new int[n];
		long a = 0;
		for (int i = 0; i < e.length; i++) {
			e[i] = readInt(in);
			a += e[i];
		}
		Arrays.sort(e);
		for (int i = e.length; i >= 0; i--) {
			if (a / (double) i >= e[i - 1]) {
				out.print(e.length - i);
				out.close();
				in.close();
				return;
			}
		}
		out.close();
		in.close();
	}
}
