import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

import olimp.template.FastScanner;


public class Blue {
	static class FastScanner {
		BufferedReader reader;
		StringTokenizer tokens;

		public FastScanner(File file) {
			try {
				reader = new BufferedReader(new FileReader(file));
			} catch (FileNotFoundException e) {}
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
		//		FastScanner in = new FastScanner(new File("input.txt"));
		//		PrintWriter out = new PrintWriter(new File("output.txt"));
		FastScanner in = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int L = in.nextInt();
		String s = in.next();
		if (L >= s.length()) {
			out.print(1);
			out.close();
		}
		boolean[] check = new boolean[3];
		check[0] = s.indexOf('a') != -1;
		check[1] = s.indexOf('b') != -1;
		check[2] = s.indexOf('c') != -1;
		int ans = 0;
		for (int i = 0; i < 3; i++) {
			if (check[i])
				ans++;
		}
		out.println(ans);
		out.close();
		in.close();
	}
}
