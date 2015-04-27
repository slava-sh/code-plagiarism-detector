import java.io.*;
import java.util.*;

public class Main {
//	static Scanner in;
	static PrintWriter out;
	static StreamTokenizer in; static int next() throws Exception {in.nextToken(); return (int) in.nval;}

	static ArrayList<Long> point;

	static void go(long[] p) {
		int k = p.length;
		if (k <= 2) {
			if (k == 2) {
				int[] yy = new int[] {(int)(p[0] & ((1L << 31) - 1)), (int)(p[1] & ((1L << 31) - 1))};
				int[] xx = new int[] {(int)(p[0] >> 31), (int)(p[1] >> 31)};
				point.add(((long)xx[0] << 31) + yy[1]);
			}
			return;
		}

		int l = k/2;
		long xx = p[l] >> 31;
		for (int i = 0; i < k; i++) point.add((xx << 31) + (p[i] & ((1L << 31) - 1)));
		long[] a = new long[l];
		long[] b = new long[k - l];
		for (int i = 0; i < l; i++) a[i] = p[i];
		for (int i = l; i < k; i++) b[i - l] = p[i];
		go(a);
		go(b);
	}

	public static void main(String[] args) throws Exception {
//		in = new Scanner(System.in);
		out = new PrintWriter(System.out);
		in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));

		int n = next();

		int[] x = new int[n];
		int[] y = new int[n];

		for (int i = 0; i < n; i++) {
			x[i] = next() + 1000000000;
			y[i] = next() + 1000000000;
		}

		long[] p = new long[n];
		for (int i = 0; i < n; i++) p[i] = ((long) x[i] << 31) + y[i];

		Arrays.sort(p);

		point = new ArrayList<Long>();

		for (int i = 0; i < n; i++) point.add(p[i]);

		go(p);

		Collections.sort(point);
		int count = 1;
		for (int i = 1; i < point.size(); i++) if (!point.get(i).equals(point.get(i - 1))) count++;

		out.println(count);

		for (int i = 0; i < point.size(); i++) if (i == 0 || !point.get(i).equals(point.get(i - 1))) {
			long xx = point.get(i) >> 31;
			long yy = point.get(i) & ((1L << 31) - 1);
			xx -= 1000000000;
			yy -= 1000000000;
			out.println(xx + " " + yy);
		}

//		out.println(10000);
//		for (int i = 0; i < 10000; i++) out.println(i + " " + i);

		out.close();
	}
}