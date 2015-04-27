import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
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

	static long mod = 1_000_000_007;

	public static void main(String[] args) throws IOException {
		tokenizer = null;
		// reader = new BufferedReader(new FileReader("run.in"));
		// writer = new PrintWriter(new FileWriter("run.out"));
		reader = new BufferedReader(new InputStreamReader(System.in, "ISO-8859-1"));
		writer = new PrintWriter(System.out);
		banana();
		reader.close();
		writer.close();
	}

	static void banana() throws IOException {
		int n = nextInt();
		int m = nextInt();
		long mod = nextLong();

		int gcount = 2 * n;
		int value[] = new int[n];
		Arrays.fill(value, 2);

		for (int i = 0; i < m; ++i) {
			String s = nextToken();

			List<Integer> c = new ArrayList<Integer>();
			for (int j = 0; j < s.length(); ++j)
				if (s.charAt(j) == '1')
					c.add(j);

			if (c.size() != 2) {
				System.out.println(0);
				return;
			}
			value[c.get(0)]--;
			value[c.get(1)]--;
			gcount -= 2;
		}

		List<Integer> res = new ArrayList<Integer>();
		for (int i = 0; i < n; ++i) {
			if (value[i] < 0) {
				System.out.println(0);
				return;
			}
			if (value[i] > 0)
				res.add(value[i]);
		}

		n = res.size();
		n += 10;

		long f[][] = new long[n][n];

		f[0][0] = 1;

		for (int i = 1; i < n; ++i) {
			if (i % 2 == 1)
				f[i][0] = 0;
			else
				f[i][0] = (i * (i - 1) / 2 * f[i - 2][0]) % mod;
		}

		for (int j = 1; j < n; ++j)
			for (int i = 0; i < n; ++i) {
				if (i >= 2) {
					f[i][j] = (f[i][j] + i * (i - 1) / 2 * f[i - 2][j]) % mod;
				}
				if (j >= 1) {
					f[i][j] = (f[i][j] + (i * j ) * f[i][j - 1]) % mod;
				}
				if (j >= 2 && i + 2 < n) {
					f[i][j] = (f[i][j] + j * (j - 1) / 2 * f[i + 2][j - 2]) % mod;
				}
			}
		
		int ones = 0;
		int twos = 0;
		for (int i = 0; i < res.size(); ++i)
		{
			if (res.get(i) == 1)
				++ones;
			if (res.get(i) == 2)
				++twos;
		}
		
		System.out.println(f[ones][twos]);
	}
}