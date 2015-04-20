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
		BufferedReader in = new BufferedReader(new FileReader(new File("seq.in")));
		PrintWriter out = new PrintWriter("seq.out");
//		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
//		PrintWriter out = new PrintWriter(System.out);
		st[0] = new StringTokenizer(in.readLine());
		int n = readInt(in);
		int h = readInt(in);
		int[][] seq = new int[n][2];
		int numberZOO = 0;
		int result;
		int d = 80000001;
		for (int i = 0; i < n; i++) {
			seq[i][0] = readInt(in);
			if (seq[i][0] == 0 || seq[i][0] == 1) {
				seq[i][1] = 0;
			} else {
				seq[i][1] = 1;
			}
			numberZOO += seq[i][1];
		}
		for (int i = 0; i <= n - h; i++) {
			if (seq[i][1] == 0) {
				int td = 0;
				boolean flag = false;
				for (int j = i; j < i + h; j++) {
					if (seq[j][0] > j - i + 1) {
						flag = true;
						break;
					} else {
						td += j - i + 1 - seq[j][0]; 
					}
				}
				if (!flag) {
					d = Math.min(d, td);
				}
			}
		}
		out.print(d == 80000001 ? -1 : d);
		out.close();
		in.close();
	}
}
