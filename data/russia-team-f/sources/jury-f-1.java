import java.io.*;
import java.util.*;

public class polygon_av {

	FastScanner in;
	PrintWriter out;

	final static Point ORIGIN = new Point(0, 0);

	void solve() {
		int n = in.nextInt();
		Point[] a = new Point[n];
		for (int i = 0; i < n; i++) {
			a[i] = new Point(in.nextInt(), in.nextInt());
		}
		double shiftX = a[0].x, shiftY = a[0].y;
		for (int i = 0; i < n; i++) {
			a[i].x -= shiftX;
			a[i].y -= shiftY;
		}
		
		angles = new double[n];
		int m = in.nextInt();
		for (int i = 0; i < m; i++) {
			solve(a, new Point(in.nextInt() - shiftX, in.nextInt() - shiftY));
		}
	}

	double[] angles;
	int ptr = 0;

	private void solve(Point[] a, Point nail) {
		double r2 = nail.norm2();
		ptr = 0;
		for (int i = 0; i < a.length; i++) {
			Point from = a[i], to = a[(i + 1) % a.length];
			addIntersections(from, to, r2);			
		}
		
		double nailAngle = Math.atan2(nail.y, nail.x);
		if (ptr == 0) {
			out.println("360 360");
			return;
		}
		
		double max= Integer.MIN_VALUE, min = Integer.MAX_VALUE;
		for (int i = 0; i < ptr; i++) {
			double check = angles[i];
			if (check > nailAngle) {
				min = Math.min(min, check);
			}
			if (check + 2 * Math.PI > nailAngle) {
				min = Math.min(min, check + 2 * Math.PI);
			}
			if (check < nailAngle) {
				max = Math.max(max, check);
			}
			if (check - 2 * Math.PI < nailAngle) {
				max = Math.max(max, check - 2 * Math.PI);
			}
		}
		
		max = (nailAngle - max) * 180 / Math.PI;
		min = (min - nailAngle) * 180 / Math.PI;
		
		out.println(min + " " + max);
	}

	private void addIntersections(Point from, Point to, double r2) {
		double fromNorm = from.norm2(), toNorm = to.norm2();
		if (fromNorm < r2 && toNorm < r2) {
			return;
		}

		Line line = new Line(from, to);
		Point p = line.proj(ORIGIN);
		double dist2 = ORIGIN.distTo2(p);

		if (dist2 > r2) {
			return;
		}

		double shift = Math.sqrt(r2 - dist2);
		
		Point delta = new Point(to.x - from.x, to.y - from.y);
		double len = delta.norm();
		delta.x /= len;
		delta.y /= len;
		
		Point p1 = new Point(p.x + delta.x * shift, p.y + delta.y * shift);
		Point p2 = new Point(p.x - delta.x * shift, p.y - delta.y * shift);
			
		if (atSegm(from, to, p1)) {
			angles[ptr++] = Math.atan2(p1.y, p1.x);
		}
		if (atSegm(from, to, p2)) {
			angles[ptr++] = Math.atan2(p2.y, p2.x);
		}
	}
	
	boolean atSegm(Point a, Point b, Point p) {
		double sm1 = scalMul(a, b, p), sm2 = scalMul(b, a, p);
		return sm1 >= 0 && sm2 >= 0;
	}
	
	double scalMul(Point a, Point b, Point c) {
		return (b.x - a.x) * (c.x - a.x) + (b.y - a.y) * (c.y - a.y);
	}
	
	double vectMul(Point a, Point b, Point c) {
		return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	}

	static class Point {
		double x, y;

		public Point(double x, double y) {
			this.x = x;
			this.y = y;
		}

		double norm2() {
			return x * x + y * y;
		}

		double norm() {
			return Math.sqrt(norm2());
		}

		double distTo2(Point other) {
			double dx = x - other.x, dy = y - other.y;
			return dx * dx + dy * dy;
		}

		@Override
		public String toString() {
			return "[" + x + ", " + y + "]";
		}
	}

	static class Line {
		double a, b, c;

		public Line(Point a, Point b) {
			this.a = b.y - a.y;
			this.b = a.x - b.x;
			this.c = -(this.a * a.x + this.b * a.y);
		}

		public Point proj(Point p) {
			double dist = (a * p.y + b * p.x + c) / (a * a + b * b);
			return new Point(p.x - a * dist, p.y - b * dist);
		}
	}

	void run() {
		try {
			in = new FastScanner("polygon.in");
			out = new PrintWriter("polygon.out");
			solve();
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(String s) {
			try {
				br = new BufferedReader(new FileReader(s));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(nextToken());
		}

		long nextLong() {
			return Long.parseLong(nextToken());
		}

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}

	public static void main(String[] args) {
		new polygon_av().run();
	}
}
