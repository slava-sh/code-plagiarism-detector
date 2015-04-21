package olimp;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;
import java.util.StringTokenizer;

public class Green {
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

	static class Road {
		int t;
		int to;

		public Road(int to, int t) {
			this.t = t;
			this.to = to;
		}
	}

	static ArrayList<Long> fact(long d) {
		ArrayList<Long> ans = new ArrayList<Long>();
		for (long i = 1; i * i <= d; i++) {
			//			System.out.println(i);
			if (d % i == 0) {
				ans.add(i);
				if (i * i != d)
					ans.add(d / i);
			}
		}
		Collections.sort(ans);
		return ans;
	}

	static long divTwo(long d) {
		return ((d & 1) == 1? 1 : 0) + (d >> 1);
	}

	static long[][] d;
	static ArrayList<Long> sizes;
	//	static HashMap

	static int find(long d) {
		int L = 0, R = sizes.size(), M;
		while (R - L > 1) {
			M = (R + L) >> 1;
			if (sizes.get(M) > d) {
				R = M;
			} else {
				L = M;
			}
		}
		return L;
	}

	static long get(int size, int K) {// money on N person 
		if (d[size][K] != 0) 
			return d[size][K];
		long currentSize = sizes.get(size);
		d[size][K] = Long.MAX_VALUE;
		for (int i = 0; i < size; i++) {
			if (sizes.get(size) % sizes.get(i) == 0)
				d[size][K] = Math.min(d[size][K], divTwo(sizes.get(i)) * get(find(currentSize / sizes.get(i)), K - 1));
		}
		return d[size][K];
	}

	public static void main(String[] args) throws IOException {
		//		FastScanner in = new FastScanner(new File("input.txt"));
		//		PrintWriter out = new PrintWriter(new File("output.txt"));
		FastScanner in = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
//		Random r = new Random();
		long N = in.nextLong();
		int K = in.nextInt();
//		long N = Math.abs((r.nextLong() % 1000000000000000L));
//		int K = 10;
//		long t = System.currentTimeMillis();
		sizes = fact(N);
		int size = sizes.size();
		d = new long[size][K + 1];
		for (int i = 0; i < size; i++) {
			d[i][1] = divTwo(sizes.get(i));
		}
		out.println(get(sizes.size() - 1, K));
//		out.println(System.currentTimeMillis() - t);
		out.close();
		in.close();
	}
}
