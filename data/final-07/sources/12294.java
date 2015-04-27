import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.IDN;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Locale;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class B {
	private static final String TASKNAME = "b";

	HashSet<Long> added = new HashSet<Long>();
	long mul = (int) 2e9;
	int[] addX = new int[(int)2e5 + 10];
	int[] addY = new int[(int)2e5 + 10];
	int size = 0;
//	ArrayList<Integer> addX = new ArrayList<Integer>((int)2e5);
//	ArrayList<Integer> addY = new ArrayList<Integer>((int)2e5);

	private void solve() throws IOException {
		int n = nextInt();
		final int[] xs = new int[n];
		final int[] ys = new int[n];
		Integer[] indices = new Integer[n];
		for (int i = 0; i < n; ++i) {
			xs[i] = nextInt();
			ys[i] = nextInt();
			indices[i] = i;
			added.add(xs[i] * mul + ys[i]);
		}
		Arrays.sort(indices, new Comparator<Integer>() {
			@Override
			public int compare(Integer o1, Integer o2) {
				int d = xs[o1] - xs[o2];
				if (d == 0) {
					return ys[o1] - ys[o2];
				}
				return d;
			}

		});

		perm(xs, indices);
		perm(ys, indices);
		add(0, n - 1, xs, ys);

		StringBuilder builder = new StringBuilder();
		builder.append(""+(n + size));
		builder.append('\n');
//		println((n + addX.size()));
		for (int i = 0; i < n; ++i) {
			builder.append(xs[i] + " " + ys[i]);
			builder.append('\n');
//			println(xs[i] + " " + ys[i]);
		}
		for (int i = 0; i < size; ++i) {
			builder.append(addX[i] + " " + addY[i]);
			builder.append('\n');
//			println(addX.get(i) + " " + addY.get(i));
		}
		
		println(builder.toString());
	}

	private void perm(int[] xs, Integer[] indices) {
		int n = xs.length;
		int[] t = new int[n];
		for (int i = 0; i < n; ++i) {
			t[i] = xs[indices[i]];
		}
		System.arraycopy(t, 0, xs, 0, n);
	}

	private void add(int l, int r, int[] xs, int[] ys) {
		if (l >= r || xs[l] == xs[r]) {
			return;
		}
		int divX = (xs[l] + xs[r]) / 2;

		int rightStart = -1;
		for (int i = l; i <= r; ++i) {
			int ax = divX;
			int ay = ys[i];
			if (added.add(ax * mul + ay)) {
				addX[size] = ax;
				addY[size] = ay;
				++size;
			}
			if (xs[i] >= divX && rightStart == -1) {
				rightStart = i;
			}
		}
//		 System.err.println(l + " " + r + " " + divX + " " + rightStart);
		if (rightStart - 1 != r) {
			add(l, rightStart - 1, xs, ys);
		}
		if (l != rightStart) {
			add(rightStart, r, xs, ys);
		}
	}

	private void run() {
		try {
			reader = new BufferedReader(new InputStreamReader(System.in));
			writer = new PrintWriter(System.out);
//			reader = new BufferedReader(new FileReader(TASKNAME + ".in"));
//			writer = new PrintWriter(new BufferedWriter(new FileWriter(TASKNAME + ".out")));

			solve();
			
//			for (int i = 0; i < (int)1e4; ++i) {
//				println(((int)1e9 - i) + " " + ((int)1e9 - i));
//			}

			reader.close();
			writer.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(13);
		}
	}

	private String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	private int nextInt() throws NumberFormatException, IOException {
		return Integer.parseInt(nextToken());
	}

	private double nextDouble() throws NumberFormatException, IOException {
		return Double.parseDouble(nextToken());
	}

	private long nextLong() throws NumberFormatException, IOException {
		return Long.parseLong(nextToken());
	}

	private void print(Object o) {
		writer.print(o);
	}

	private void println(Object o) {
		writer.println(o);
	}

	private void printf(String format, Object... o) {
		writer.printf(format, o);
	}

	public static void main(String[] args) {
		final long startTime = System.currentTimeMillis();
		Locale.setDefault(Locale.US);
		new B().run();
		System.err.printf("%.3f",
				(System.currentTimeMillis() - startTime) * 1e-3);
	}

	private BufferedReader reader;
	private StringTokenizer tokenizer;
	private PrintWriter writer;

}
