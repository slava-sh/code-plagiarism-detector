import static java.util.Arrays.*;

import java.util.*;

public class C {

	public C () {
		final int N = sc.nextInt(), M = sc.nextInt();
		int K = sc.nextInt(), W = sc.nextInt();
		char [][][] B = new char [K][][];
		for (int k : rep(K))
			B[k] = sc.nextChars(N);

		final int [][] G = new int [K][K];
		int [] RN = rep(N), RM = rep(M);
		for (int k : rep(K))
			for (int m : rep(k))
				for (int i : RN)
					for (int j : RM)
						if (B[k][i][j] != B[m][i][j])
							G[k][m] = G[m][k] += W;

		Comparator<int[]> C = new Comparator<int[]>() {
			public int compare(int [] x, int [] y) {
				int Lx = x[1] == -1 ? (N*M) : G[x[0]][x[1]];
				int Ly = y[1] == -1 ? (N*M) : G[y[0]][y[1]];
				return Lx - Ly;
			}
		};

		PriorityQueue<int[]> Q = new PriorityQueue<>(10, C);
		for (int k : rep(K)) Q.add(new int [] { k, -1 });
		int [] P = new int [K]; fill(P, -2); int [][] res = new int [K][]; int T = 0;

		for (int k = 0; k < K; ) {
			int [] z = Q.poll();
			int y = z[0], x = z[1];
			if (P[y] != -2)
				continue;
			int L = x == -1 ? (N*M) : G[x][y];
			T += L; P[y] = x;
			res[k++] = new int [] { y+1, x+1 };
			for (int v : rep(K))
				if (P[v] == -2)
					Q.add(new int [] { v, y });
		}

		print(T);
		println(res);
	}

	private static int [] rep(int N) { return rep(0, N); }
	private static int [] rep(int S, int T) { if (T <= S) return new int [0]; int [] res = new int [T-S]; for (int i = S; i < T; ++i) res[i-S] = i; return res; }
	////////////////////////////////////////////////////////////////////////////////////
	private final static IOUtils.MyScanner sc = new IOUtils.MyScanner();
	private static void print (Object o, Object ... A) { IOUtils.print(o, A); }
	private static void println (Object o) { IOUtils.println(o); }
	private static class IOUtils {
		public static class MyScanner {
			public String next() { newLine(); return line[index++]; }
			public int nextInt() { return Integer.parseInt(next()); }
			public char [] nextChars() { return next ().toCharArray (); }
			public char [][] nextChars(int N) {
				char [][] res = new char [N][];
				for (int i = 0; i < N; ++i)
					res[i] = nextChars();
				return res;
			}
			//////////////////////////////////////////////
			private boolean eol() { return index == line.length; }
			private String readLine() {
				try {
					return r.readLine();
				} catch (Exception e) {
					throw new Error (e);
				}
			}
			private final java.io.BufferedReader r;
			private MyScanner () { this(new java.io.BufferedReader(new java.io.InputStreamReader(System.in))); }
			private MyScanner (java.io.BufferedReader r) {
				try {
					this.r = r;
					while (!r.ready())
						Thread.sleep(1);
					start();
				} catch (Exception e) {
					throw new Error(e);
				}
			}
			private String [] line;
			private int index;
			private void newLine() {
				if (line == null || eol()) {
					line = split(readLine());
					index = 0;
				}
			}
			private String [] split(String s) { return s.length() > 0 ? s.split(" ") : new String [0]; }
		}
		private static String build(Object o, Object ... A) { return buildDelim(" ", o, A); }
		private static String buildDelim(String delim, Object o, Object ... A) {
			StringBuilder b = new StringBuilder();
			append(b, o, delim);
			for (Object p : A)
				append(b, p, delim);
			return b.substring(delim.length());
		}
		//////////////////////////////////////////////////////////////////////////////////
		private static void start() { if (t == 0) t = millis(); }
		private static void append(StringBuilder b, Object o, String delim) {
			if (o.getClass().isArray()) {
				int len = java.lang.reflect.Array.getLength(o);
				for (int i = 0; i < len; ++i)
					append(b, java.lang.reflect.Array.get(o, i), delim);
			} else if (o instanceof Iterable<?>)
				for (Object p : (Iterable<?>) o)
					append(b, p, delim);
			else {
				if (o instanceof Double)
					o = new java.text.DecimalFormat("#.############").format(o);
				b.append(delim).append(o);
			}
		}
		private static java.io.PrintWriter pw = new java.io.PrintWriter(System.out);
		private static void print(Object o, Object ... A) { pw.println(build(o, A)); }
		private static void println(Object o) {
			if (o.getClass().isArray()) {
				int len = java.lang.reflect.Array.getLength(o);
				for (int i = 0; i < len; ++i)
					print(java.lang.reflect.Array.get(o, i));
			} else if (o instanceof Iterable<?>)
				for (Object p : (Iterable<?>) o)
					print(p);
			else
				print(o);
		}
		private static void err(Object o, Object ... A) { System.err.println(build(o, A)); }
		private static void exit() {
			IOUtils.pw.close();
			System.out.flush();
			err("------------------");
			err(IOUtils.time());
			System.exit(0);
		}
		private static long t;
		private static long millis() { return System.currentTimeMillis(); }
		private static String time() { return "Time: " + (millis() - t) / 1000.0; }
	}
	public static void main (String[] args) { new C(); IOUtils.exit(); }
}
