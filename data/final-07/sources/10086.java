import java.io.*;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;

public class A {
	BufferedReader in;
	StringTokenizer str;
	PrintWriter out;
	String SK;

	String next() throws IOException {
		while ((str == null) || (!str.hasMoreTokens())) {
			SK = in.readLine();
			if (SK == null)
				return null;
			str = new StringTokenizer(SK);
		}
		return str.nextToken();
	};

	int nextInt() throws IOException {
		return Integer.parseInt(next());
	};

	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	};

	long nextLong() throws IOException {
		return Long.parseLong(next());
	};

	class point implements Comparable<point> {
		int x, y;

		public point(int x1, int y1) {
			x = x1;
			y = y1;
		}

		@Override
		public int compareTo(point o) {
			return x - o.x;
		}

	}

	class point1 implements Comparable<point1> {
		int x, y;

		public point1(int x1, int y1) {
			x = x1;
			y = y1;
		}

		@Override
		public int compareTo(point1 o) {
			return y - o.y;
		}

	}

	int res = 0;

	void solvcn(int lx, int ly, int rx, int ry, point[] x) {
		if ((lx > rx) || (ly > ry))
			return;
		if (x.length == 0)
			return;
		if ((lx == rx) || (ly == ry)) {
			res += x.length;
			return;
		}
		int n = x.length;
		int midx = (lx + rx) / 2;
		int t1x = 0;
		int t2x = 0;
		for (int i = 0; i < n; i++) {
			if (x[i].x < midx)
				t1x++;
			if (x[i].x > midx)
				t2x++;

		}
		int zany[] = new int[ry - ly + 1];
		for (int i = 0; i < n; i++) {
			zany[x[i].y - ly] = 1;
		}
		for (int i = 0; i < ry - ly + 1; i++)
			res += zany[i];
		point a[] = new point[t1x];
		t1x = 0;
		for (int i = 0; i < n; i++)
			if (x[i].x < midx) {
				a[t1x] = x[i];
				t1x++;
			}
		solvcn(lx, ly, midx - 1, ry, a);

		a = new point[t2x];
		t2x = 0;
		for (int i = 0; i < n; i++)
			if ((x[i].x > midx)) {
				a[t2x] = x[i];
				t2x++;
			}
		solvcn(midx + 1, ly, rx, ry, a);
	}

	void solvout(int lx, int ly, int rx, int ry, point[] x) {
		if ((lx > rx) || (ly > ry))
			return;
		if (x.length == 0)
			return;
		if (((lx == rx) || (ly == ry))) {
			for (int i = 0; i < x.length; i++)
				System.out.println(resx[x[i].x] + " " + resy[x[i].y]);
			return;
		}
		int n = x.length;
		int midx = (lx + rx) / 2;
		int t1x = 0;
		int t2x = 0;
		for (int i = 0; i < n; i++) {
			if (x[i].x < midx)
				t1x++;
			if (x[i].x > midx)
				t2x++;

		}
		;
		int zany[] = new int[ry - ly + 1];
		for (int i = 0; i < n; i++) {
			zany[x[i].y - ly] = 1;
		}
		for (int i = 0; i < ry - ly + 1; i++)
			if (zany[i] == 1)
				System.out.println(resx[midx] + " " + resy[i + ly]);
		point a[] = new point[t1x];
		t1x = 0;
		for (int i = 0; i < n; i++)
			if (x[i].x < midx) {
				a[t1x] = x[i];
				t1x++;
			}
		solvout(lx, ly, midx - 1, ry, a);

		a = new point[t2x];
		t2x = 0;
		for (int i = 0; i < n; i++)
			if ((x[i].x > midx)) {
				a[t2x] = x[i];
				t2x++;
			}
		solvout(midx + 1, ly, rx, ry, a);
	}

	int resx[];
	int resy[];

	void solve() throws IOException {
		int n = nextInt();
		resx=new int[n];
		resy=new int[n];
		point[] x = new point[n];
		point1[] y = new point1[n];
		for (int i = 0; i < n; i++) {
			x[i] = new point(nextInt(), nextInt());
			y[i] = new point1(x[i].x, x[i].y);
		}
		HashMap<Integer, Integer> ab = new HashMap<Integer, Integer>();
		Arrays.sort(x);
		Arrays.sort(y);
		int tx = 0;
		int ty = 0;
		int last = Integer.MIN_VALUE;
		for (int i = 0; i < n; i++) {
			if (x[i].x != last) {
				resx[tx] = x[i].x;
				tx++;
				last = x[i].x;
			}
			x[i].x = tx - 1;
		}
		last = Integer.MIN_VALUE;
		for (int i = 0; i < n; i++) {
			if (y[i].y != last) {
				resy[ty] = y[i].y;
				ty++;
				last = y[i].y;
				ab.put(y[i].y, ty - 1);
			}
		}
		for (int i = 0; i < n; i++)
			x[i].y = ab.get(x[i].y);
		solvcn(0, 0, tx, ty, x);
		System.out.println(res);
		solvout(0, 0, tx, ty, x);
	};

	void run() throws IOException {

		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new A().run();
	}

}
