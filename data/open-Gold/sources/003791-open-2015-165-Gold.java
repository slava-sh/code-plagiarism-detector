import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;



public class Gold {

	static class FastScanner {
		BufferedReader reader;
		StringTokenizer tokens;

		public FastScanner(File file) {
			try {
				reader = new BufferedReader(new FileReader(file));
			} catch (FileNotFoundException e) {
			}
		}

		public FastScanner() {
			reader = new BufferedReader(new InputStreamReader(System.in));
		}

		public String next() throws IOException {
			while (tokens == null || !tokens.hasMoreTokens())
				tokens = new StringTokenizer(reader.readLine());
			return tokens.nextToken();
		}

		public int nextInt() throws NumberFormatException, IOException {
			return Integer.parseInt(next());
		}

		public long nextLong() throws NumberFormatException, IOException {
			return Long.parseLong(next());
		}

		public double nextDouble() throws NumberFormatException, IOException {
			return Double.parseDouble(next());
		}

		public void close() throws IOException {
			reader.close();
		}
	}


	public static void main(String[] args) throws IOException {
		FastScanner in = new FastScanner(new File("input.txt"));
		PrintWriter out = new PrintWriter(new File("output.txt"));
		//		FastScanner in = new FastScanner();
		//		PrintWriter out = new PrintWriter(System.out);
		int N = in.nextInt();
		int K = in.nextInt();
		long C = in.nextInt();
		long D = in.nextInt();
		long[] times = new long[N + 1];
		long[] lengths = new long[N + 1];
		for (int i = 0; i < N; i++) {
			times[i] = in.nextInt();
			lengths[i] = in.nextInt() - times[i];
		}
		times[N] = times[N - 1] + lengths[N - 1];
		long[][][] d = new long[2][N + 1][K + 1]; // 1 - ligth
		for (int i = 0; i <= N; i++) {
			for  (int j = 0; j <= K; j++) {
				d[0][i][j] = Long.MAX_VALUE;
				d[1][i][j] = Long.MAX_VALUE;
			}
		}
		d[0][0][K] = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= K; j++) {

				// ligth now
				if (d[1][i][j] != Long.MAX_VALUE) {
					d[1][i + 1][j] = Math.min(d[1][i + 1][j], d[1][i][j] + (times[i + 1] - times[i]) * D);
					d[0][i + 1][j] = Math.min(d[0][i + 1][j], d[1][i][j] + lengths[i] * D);
				}
				// off now
				if (d[0][i][j] != Long.MAX_VALUE) {
					if (j == 0) {
						d[1][i + 1][K - 1] = Math.min(d[1][i + 1][K - 1], d[0][i][j] + (times[i + 1] - times[i]) * D + C);
						d[0][i + 1][K - 1] = Math.min(d[0][i + 1][K - 1], d[0][i][j] + lengths[i] * D + C);
					} else {
						d[1][i + 1][j - 1] = Math.min(d[1][i + 1][j - 1], d[0][i][j] + (times[i + 1] - times[i]) * D);
						d[0][i + 1][j - 1] = Math.min(d[0][i + 1][j - 1], d[0][i][j] + lengths[i] * D);
					}
				}
			}
		}
		long ans = Long.MAX_VALUE;
		for (int i = 0; i <= K; i++) {
			ans = Math.min(ans, d[1][N][i]);
			ans = Math.min(ans, d[0][N][i]);
		}
		out.println(ans);
		out.close();
	}
}
