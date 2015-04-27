/* Codeforces Template v0.25 by Sergey Esipenko */
import java.io.*;
import java.util.*;

import static java.lang.Math.*;
import static java.util.Arrays.fill;
import static java.util.Arrays.sort;

public class Solution implements Runnable {
	/* START OF SOLUTION */
	
	static final Random RANDOM = new Random(7777L);
	
	void solve() throws IOException  {
		
		final int n = nextInt();
		final int k = nextInt();
		final char[] s = nextToken().toCharArray();
		
		if (k == 1) {
			for (int i = 0; i < n; i++) {
				out.print('1');
			}
			out.println();
			return;
		}
		
		int[] z = zFunction(s);
		int[] pi = piFunction(s);
		
		int[] blockLengths = new int [n + 1];
		
		for (int i = 0; i < n; i++) {
			final int l = i + 1;
			final int m = l - pi[l - 1];
			if (l % m == 0) {
				final int rep = l / m;
				if (rep % k == 0) {
					final int blockLen = rep / k * m;
					blockLengths[l] = blockLen;
				}
			}
		}
		
		writeLog(Arrays.toString(z));
		writeLog(Arrays.toString(blockLengths));
		
		int[] pot = new int [n + 2];
		
		for (int i = 1; i <= n; i++) {
			if (blockLengths[i] > 0) {
				final int rangeLen = min(blockLengths[i], z[i]);
				pot[i - 1]++;
				pot[i + rangeLen]--;
			}
		}
		
		char[] answer = new char [n];
		int balance = 0;
		for (int i = 0; i < n; i++) {
			balance += pot[i];
			answer[i] = balance > 0 ? '1' : '0';
		}
		out.println(answer);
	}
	
	int[] zFunction(char[] s) {
		int len = s.length;
		int[] z = new int [len + 1];
		int l = 0;
		int r = 0;
		for (int i = 1, j; i < len; i++)
			if (i > r) {
				for (j = 0; i + j < len && s[j] == s[i + j]; j++);
				z[i] = j;
				l = i;
				r = i + j - 1;
			} else {
				if (z[i - l] < r - i + 1) {
					z[i] = z[i - l];
				} else {
					for (j = 1; r + j < len && s[r + j] == s[r - i + j]; j++);
					z[i] = r - i + j;
					l = i;
					r = r + j - 1;
				}
			}
		return z;
	}
	
	int[] piFunction(char[] s) {
		int len = s.length;
		int[] pi = new int [len];
		for (int i = 1, j; i < len; pi[i] = s[j] == s[i] ? j + 1 : j, i++)
			for (j = pi[i - 1]; j > 0 && s[i] != s[j]; j = pi[j - 1]);
		return pi;
	}
	
	/* END OF SOLUTION */
	/************************************************************************** 
	 * Entry point
	 *************************************************************************/
	
	static final Solution INSTANCE = new Solution();
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
	
	void printIf(final boolean condition, final String msgIfTrue, final String msgIfFalse) {
		out.println(condition ? msgIfTrue : msgIfFalse);
	}
	
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
