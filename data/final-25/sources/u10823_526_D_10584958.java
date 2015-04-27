import java.io.*;
import java.util.*;
import java.math.*;

public class D implements Runnable {
	private static BufferedReader in;
	private static PrintWriter out;
	private static StringTokenizer st;
	private static Random rnd;

	private void solve() throws IOException {
		int stringLength = nextInt(), repeatsCount = nextInt();
		String letters = nextToken();
		int[] z = buildZFunction(letters);
		z[0] = letters.length();
		int[] sums = new int[stringLength + 1];
		for (int ABlength = 1; ABlength * repeatsCount <= stringLength; ABlength++) {
			boolean ok = true;
			for (int i = 0; i < repeatsCount && ok; i++) {
				int j = i * ABlength;
				if (z[j] < ABlength)
					ok = false;
			}
			if (ok) {
				int pos = ABlength * repeatsCount;
				if (pos == stringLength) {
					addRange(sums, pos - 1, pos - 1);
				} else {
					int maxALength = Math.min(ABlength, z[pos]);
					addRange(sums, pos - 1, pos - 1 + maxALength);
				}
			}
		}
		int cur = 0;
		for (int i = 0; i < stringLength; i++) {
			cur += sums[i];
			out.print(cur > 0 ? '1' : '0');
		}
		out.println();
	}

	private void addRange(int[] sums, int i, int j) {
		sums[i] += 1;
		sums[j + 1] -= 1;
	}

	private int[] buildZFunction(String letters) {
		int l = 0, r = -1;
		int[] z = new int[letters.length()];
		for (int i = 1; i < letters.length(); i++) {
			if (l <= i && i <= r)
				z[i] = Math.min(r - i, z[i - l]);
			while (i + z[i] < letters.length()
					&& letters.charAt(i + z[i]) == letters.charAt(z[i])) {
				++z[i];
			}
			if (i + z[i] > r) {
				l = i;
				r = i + z[i];
			}
		}
		return z;
	}

	public static void main(String[] args) {
		new D().run();
	}

	public void run() {
		try {
			final String className = this.getClass().getName().toLowerCase();

			try {
				in = new BufferedReader(new FileReader(className + ".in"));
				out = new PrintWriter(new FileWriter(className + ".out"));
				// in = new BufferedReader(new FileReader("input.txt"));
				// out = new PrintWriter(new FileWriter("output.txt"));
			} catch (FileNotFoundException e) {
				in = new BufferedReader(new InputStreamReader(System.in));
				out = new PrintWriter(System.out);
			}

			rnd = new Random();

			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(42);
		}
	}

	private String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = in.readLine();

			if (line == null)
				return null;

			st = new StringTokenizer(line);
		}

		return st.nextToken();
	}

	private int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	private long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	private double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}