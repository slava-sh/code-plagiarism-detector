import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {

	final String filename = "";

	public void solve() throws Exception {
		int n = iread();
		int[] r = new int[n];
		for (int i = 0; i < n; i++)
			r[i] = iread();
		Arrays.sort(r);
		PriorityQueue<Pair> pairs = new PriorityQueue<Main.Pair>();
		Pair cur = null;
		for (int i = 0; i < n; i++) {
			if (cur == null || cur.x != r[i]) {
				if (cur != null)
					pairs.add(cur);
				cur = new Pair(r[i], 1);
			} else
				cur.num++;
		}
		if (cur != null)
			pairs.add(cur);
		int[] x = new int[3];
		int[] ans = new int[3 * n];
		int k = 0;
		while (pairs.size() >= 3) {
			Pair a = pairs.poll(), b = pairs.poll(), c = pairs.poll();
			a.num--;
			b.num--;
			c.num--;
			x[0] = a.x;
			x[1] = b.x;
			x[2] = c.x;
			Arrays.sort(x);
			ans[k++] = x[2];
			ans[k++] = x[1];
			ans[k++] = x[0];
			if (a.num > 0)
				pairs.add(a);
			if (b.num > 0)
				pairs.add(b);
			if (c.num > 0)
				pairs.add(c);
		}
		out.write((k / 3) + "\n");
		while (k > 0) {
			k -= 3;
			out.write(ans[k] + " " + ans[k + 1] + " " + ans[k + 2] + "\n");
		}
	}

	class Pair implements Comparable<Pair> {
		int x, num;

		public Pair(int x, int num) {
			super();
			this.x = x;
			this.num = num;
		}

		@Override
		public int compareTo(Pair o) {
			return o.num - num;
		}
	}

	public void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new BufferedWriter(new OutputStreamWriter(System.out));
			// in = new BufferedReader(new FileReader(filename+".in"));
			// out = new BufferedWriter(new FileWriter(filename+".out"));
			solve();
			out.flush();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	public int iread() throws Exception {
		return Integer.parseInt(readword());
	}

	public double dread() throws Exception {
		return Double.parseDouble(readword());
	}

	public long lread() throws Exception {
		return Long.parseLong(readword());
	}

	BufferedReader in;

	BufferedWriter out;

	public String readword() throws IOException {
		StringBuilder b = new StringBuilder();
		int c;
		c = in.read();
		while (c >= 0 && c <= ' ')
			c = in.read();
		if (c < 0)
			return "";
		while (c > ' ') {
			b.append((char) c);
			c = in.read();
		}
		return b.toString();
	}

	public static void main(String[] args) {
		try {
			Locale.setDefault(Locale.US);
		} catch (Exception e) {

		}
		// new Thread(new Main()).start();
		new Thread(null, new Main(), "1", 1 << 25).start();
	}
}