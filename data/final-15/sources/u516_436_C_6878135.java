/* CodeForces Template v0.23 by Sergey Esipenko */
import java.io.*;
import java.util.*;

import static java.lang.Math.*;
import static java.util.Arrays.fill;
import static java.util.Arrays.sort;

public class Main implements Runnable {
	/* START OF SOLUTION */
	
	static final Random RANDOM = new Random(7777L);
	
	void solve() throws IOException  {
		
		final int rNum = nextInt();
		final int cNum = nextInt();
		final int vNum = nextInt();
		final int factor = nextInt();
		
		final char[][] levels = new char [vNum][];
		for (int i = 0; i < vNum; i++) {
			levels[i] = new char [rNum * cNum];
			for (int r = 0; r < rNum; r++)
				System.arraycopy(nextToken().toCharArray(), 0, levels[i], r * cNum, cNum);
		}
		
		final int[][] g = new int [vNum][vNum];
		for (final int[] row : g)
			fill(row, rNum * cNum);
		
		for (int i = 0; i < vNum; i++) {
			g[i][i] = 0;
			for (int j = i + 1; j < vNum; j++) {
				g[i][j] = g[j][i] = min(rNum * cNum, factor * dist(levels[i], levels[j]));
			}
		}
		
		final int[] dist = new int [vNum];
		final int[] prev = new int [vNum];
		final boolean[] used = new boolean [vNum];
		fill(dist, rNum * cNum);
		fill(prev, -1);
		
		dist[0] = 0;
		
		int answerVal = rNum * cNum;
		final List<String> answerSeq = new ArrayList<String>();
		
		for (;;) {
			int v = -1;
			for (int i = 0; i < vNum; i++)
				if (!used[i] && (v == -1 || dist[v] > dist[i]))
					v = i;
			if (v == -1) break;
			
			used[v] = true;
			
			answerVal += dist[v];
			answerSeq.add((v + 1) + " " + (prev[v] + 1));
			
			for (int i = 0; i < vNum; i++) {
				if (used[i]) continue;
				if (dist[i] > g[v][i]) {
					dist[i] = g[v][i];
					prev[i] = v;
				}
			}
		}
		
		out.println(answerVal);
		for (final String line : answerSeq)
			out.println(line);
	}
	
	static int dist(char[] a, char[] b) {
		int dist = 0;
		for (int i = 0; i < a.length; i++)
			if (a[i] != b[i])
				dist++;
		return dist;
	}

	/* END OF SOLUTION */
	/************************************************************************** 
	 * Entry point
	 *************************************************************************/
	
	static final Main INSTANCE = new Main();
	static final boolean WRITE_LOG = true;
	static final long STACK_SIZE = 1L << 24; // < 0 for default stack size
	
	static long initTime;
	static boolean localRun = false;
	
	@SuppressWarnings("unused")
	public static void main(String[] args) throws IOException {
		try {
			initTime = System.currentTimeMillis();
			try {
				localRun = "true".equals(System.getProperty("LOCAL_RUN_7777"));
				if (localRun && new File("input.txt").exists())
					System.setIn(new FileInputStream("input.txt"));
			} catch (SecurityException e) {
				// Can't get property. It seems that solution is running in a secure
				// environment
			}
			if (STACK_SIZE < 0L) {
				INSTANCE.run();
			} else {
				new Thread(null, INSTANCE, "Solver", 1L << 24).start();
			}
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(999);
		}
	}

	@Override
	public void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			solve();
			out.close();
			in.close();
			writeLog("Total time: "
					+ (System.currentTimeMillis() - initTime) + " ms");
			writeLog("Memory status: " + memoryStatus());
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(999);
		}
	}
	
	/**************************************************************************
	 * Input 
	 *************************************************************************/
	BufferedReader in;
	PrintWriter out;
	StringTokenizer st = new StringTokenizer("");
	
	String nextToken() throws IOException {
		while (!st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
	
	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
	
	int[] nextIntArray(int size) throws IOException {
		int[] ret = new int [size];
		for (int i = 0; i < size; i++)
			ret[i] = nextInt();
		return ret;
	}
	
	long[] nextLongArray(int size) throws IOException {
		long[] ret = new long [size];
		for (int i = 0; i < size; i++)
			ret[i] = nextLong();
		return ret;
	}
	
	double[] nextDoubleArray(int size) throws IOException {
		double[] ret = new double [size];
		for (int i = 0; i < size; i++)
			ret[i] = nextDouble();
		return ret;
	}
	
	String nextLine() throws IOException {
		st = new StringTokenizer("");
		return in.readLine();
	}
	
	boolean isEof() throws IOException {
		while (!st.hasMoreTokens()) {
			String s = in.readLine();
			if (s == null)
				return true;
			st = new StringTokenizer(s);
		}
		return false;
	}
	
	/************************************************************************** 
	 * Output 
	 *************************************************************************/
	void printRepeat(String s, int count) {
		for (int i = 0; i < count; i++)
			out.print(s);
	}
	
	void printArray(int[] array) {
		if (array == null || array.length == 0)
			return;
		for (int i = 0; i < array.length; i++) {
			if (i > 0) out.print(' ');
			out.print(array[i]);
		}
		out.println();
	}
	
	void printArray(long[] array) {
		if (array == null || array.length == 0)
			return;
		for (int i = 0; i < array.length; i++) {
			if (i > 0) out.print(' ');
			out.print(array[i]);
		}
		out.println();
	}
	
	void printArray(double[] array) {
		if (array == null || array.length == 0)
			return;
		for (int i = 0; i < array.length; i++) {
			if (i > 0) out.print(' ');
			out.print(array[i]);
		}
		out.println();
	}
	
	void printArray(double[] array, String spec) {
		if (array == null || array.length == 0)
			return;
		for (int i = 0; i < array.length; i++) {
			if (i > 0) out.print(' ');
			out.printf(Locale.US, spec, array[i]);
		}
		out.println();
	}
	
	void printArray(Object[] array) {
		if (array == null || array.length == 0)
			return;
		boolean blank = false;
		for (Object x : array) {
			if (blank) out.print(' '); else blank = true;
			out.print(x);
		}
		out.println();
	}
	
	@SuppressWarnings("rawtypes")
	void printCollection(Collection collection) {
		if (collection == null || collection.isEmpty())
			return;
		boolean blank = false;
		for (Object x : collection) {
			if (blank) out.print(' '); else blank = true;
			out.print(x);
		}
		out.println();
	}
	
	/**************************************************************************
	 * Utility
	 *************************************************************************/
	
	static String memoryStatus() {
		return (Runtime.getRuntime().totalMemory()
				- Runtime.getRuntime().freeMemory() >> 20)
				+ "/" + (Runtime.getRuntime().totalMemory() >> 20) + " MB";
	}
	
	static void checkMemory() {
		System.err.println(memoryStatus());
	}
	
	static long getRunningTime() {
		return System.currentTimeMillis() - initTime;
	}
	
	static void chk(boolean f) {
		if (!f) throw new RuntimeException("Assert failed");
	}
	
	static void chk(boolean f, String format, Object ... args) {
		if (!f) throw new RuntimeException(String.format(format, args));
	}
	
	static void writeLog(String format, Object... args) {
		if (localRun && WRITE_LOG)
			System.err.println(String.format(Locale.US, format, args));
	}
	
	static void swap(int[] a, int i, int j) {
		int tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
	
	static void swap(long[] a, int i, int j) {
		long tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
	
	static void swap(double[] a, int i, int j) {
		double tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
	
	static void swap(Object[] a, int i, int j) {
		Object tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
	
	static void shuffle(int[] a, int from, int to) {
		for (int i = from; i <= to; i++)
			swap(a, i, from + RANDOM.nextInt(i - from + 1));
	}
	
	static void shuffle(long[] a, int from, int to) {
		for (int i = from; i <= to; i++)
			swap(a, i, from + RANDOM.nextInt(i - from + 1));
	}
	
	static void shuffle(double[] a, int from, int to) {
		for (int i = from; i <= to; i++)
			swap(a, i, from + RANDOM.nextInt(i - from + 1));
	}
	
	static void shuffle(Object[] a, int from, int to) {
		for (int i = from; i <= to; i++)
			swap(a, i, from + RANDOM.nextInt(i - from + 1));
	}
	
	static void shuffle(int[] a) {
		if (a == null) return;
		shuffle(a, 0, a.length - 1);
	}
	
	static void shuffle(long[] a) {
		if (a == null) return;
		shuffle(a, 0, a.length - 1);
	}
	
	static void shuffle(double[] a) {
		if (a == null) return;
		shuffle(a, 0, a.length - 1);
	}
	
	static void shuffle(Object[] a) {
		if (a == null) return;
		shuffle(a, 0, a.length - 1);
	}
	
	static long[] getPartialSums(int[] a) {
		final long[] sums = new long [a.length + 1];
		for (int i = 0; i < a.length; i++)
			sums[i + 1] = sums[i] + a[i];
		return sums;
	}
	
	static long[] getPartialSums(long[] a) {
		final long[] sums = new long [a.length + 1];
		for (int i = 0; i < a.length; i++)
			sums[i + 1] = sums[i] + a[i];
		return sums;
	}
	
	static int[] getOrderedSet(int[] a) {
		final int[] set = Arrays.copyOf(a, a.length);
		if (a.length == 0) return set;
		shuffle(set);
		sort(set);
		int k = 1;
		int prev = set[0];
		for (int i = 1; i < a.length; i++) {
			if (prev != set[i]) {
				set[k++] = prev = set[i];
			}
		}
		return Arrays.copyOf(set, k);
	}
	
	static long[] getOrderedSet(long[] a) {
		final long[] set = Arrays.copyOf(a, a.length);
		if (a.length == 0) return set;
		shuffle(set);
		sort(set);
		int k = 1;
		long prev = set[0];
		for (int i = 1; i < a.length; i++) {
			if (prev != set[i]) {
				set[k++] = prev = set[i];
			}
		}
		return Arrays.copyOf(set, k);
	}
	
	static int gcd(int x, int y) {
		x = abs(x);
		y = abs(y);
		while (x > 0 && y > 0) {
			if (x > y) {
				x %= y;
			} else {
				y %= x;
			}
		}
		return x + y;
	}
	
	static long gcd(long x, long y) {
		x = abs(x);
		y = abs(y);
		while (x > 0 && y > 0) {
			if (x > y) {
				x %= y;
			} else {
				y %= x;
			}
		}
		return x + y;
	}
}
