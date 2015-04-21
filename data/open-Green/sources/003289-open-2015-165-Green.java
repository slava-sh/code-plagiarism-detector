

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

public class AnotherGreen {
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

	static long[] d;
	static int[] optimum;
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

	static long get(int size) {// money on N person 
		if (d[size] != 0) 
			return d[size];
		long currentSize = sizes.get(size);
		d[size] = divTwo(currentSize);
		optimum[size] = 0;
		for (int i = 1; i < size; i++) {
			if (sizes.get(size) % sizes.get(i) == 0) {
				long ans = divTwo(sizes.get(i)) * divTwo(currentSize / sizes.get(i));
				if (d[size] > ans) {
//					System.out.println("!!");
					d[size] = ans;
					optimum[size] = i;
				}
			}
		}
		return d[size];
	}

	static long get(int size, int K) {
		if (K == 1) {
			return divTwo(sizes.get(size));
		}
		get(size);
//		System.out.println(optimum[size]);
		return divTwo(sizes.get(optimum[size])) * get(find(sizes.get(size) / sizes.get(optimum[size])), K - 1);
	}

	public static void main(String[] args) throws IOException {
		//		FastScanner in = new FastScanner(new File("input.txt"));
		//		PrintWriter out = new PrintWriter(new File("output.txt"));
		FastScanner in = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		//		for (int it = 0; it < 1; it++) {
		//		Random r = new Random();
		long N = in.nextLong();
		int K = in.nextInt();
		//		long N = 355687428096000L;
		//		int K = 10;
//		long t = System.currentTimeMillis();
		sizes = fact(N);
		int size = sizes.size();
		d = new long[size];
		optimum = new int[size];
		//		}
				out.println(get(sizes.size() - 1, K));
		//		out.println(System.currentTimeMillis() - t);
		out.close();
		in.close();
	}
}
