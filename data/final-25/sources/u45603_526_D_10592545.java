import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader reader;
	static StringTokenizer tokenizer;
	static PrintWriter writer;

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	static boolean eof = false;

	static String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	public static void main(String[] args) throws IOException {
		tokenizer = null;
		// reader = new BufferedReader(new FileReader("input.txt"));
		// writer = new PrintWriter(new FileWriter("output.txt"));
		reader = new BufferedReader(new InputStreamReader(System.in, "ISO-8859-1"));
		writer = new PrintWriter(System.out);
		banana();
		reader.close();
		writer.close();
	}

	static long c, hr, hb, wr, wb;

	static long gcd(long x, long y) {
		if (y == 0)
			return x;
		return gcd(y, x % y);
	}

	static long lcm(long x, long y) {
		return x * y / gcd(x, y);
	}

	static void old() throws IOException {
		c = nextLong();
		hr = nextLong();
		hb = nextLong();
		wr = nextLong();
		wb = nextLong();

		long max = 0;
		long lcm = lcm(wr, wb);
		long costLcm = Math.max((lcm / wr) * hr, (lcm / wb) * hb);
		max += (c / lcm) * costLcm;

		c = c % lcm;

		while (c / wr < 1000000 && max > 0) {
		}
		
		long add = 0;
		for (int i = 0; i <= c / wr; ++i) {
			add = Math.max(add, i * hr + ((c - i * wr) / wb) * hb);
		}

		System.out.println(add + max);
	}

	static int[] z(String s) {
		int n = s.length();
		int z[] = new int[n + 1];
		for (int i = 1, l = 0, r = 0; i < n; ++i) {
			if (i <= r)
				z[i] = Math.min(r - i + 1, z[i - l]);
			while (i + z[i] < n && s.charAt(z[i]) == s.charAt(i + z[i]))
				++z[i];
			if (i + z[i] - 1 > r) {
				l = i;
				r = i + z[i] - 1;
			}
		}

		z[n] = 1;
		return z;
	}

	static void n() throws IOException {
		int n = nextInt();
		int k = nextInt();

		String s = nextToken();

		int z[] = z(s);

		int x[] = new int[n + 10];

		for (int i = 1; i <= n / k; ++i) {
			if (z[i] >= i * (k - 1)) {
				int first = i * k - 1;
				int last = i * k + Math.min(z[i * k], i);
				x[first]++;
				x[last]--;
			}
		}

		int cur = 0;

		for (int i = 0; i < n; ++i) {
			cur += x[i];
			if (i == 0 && k == 1) {
				writer.print(1);
				continue;
			}

			if (cur > 0) {
				writer.print(1);
			} else {
				writer.print(0);
			}
		}
	}

	static void banana() throws IOException {
		n();
	}
}