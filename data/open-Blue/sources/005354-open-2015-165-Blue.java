import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Blue {
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
		//		FastScanner in = new FastScanner(new File("input.txt"));
		//		PrintWriter out = new PrintWriter(new File("output.txt"));
		FastScanner in = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int L = in.nextInt();
		s = in.next();
		if (L >= s.length()) {
			out.println(1);
			out.print(s);
			out.close();
			return;
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
		if (ans == 1) {
			out.println(1);
			for (int i = 0; i < 3; i++) {
				if (check[i])
					out.println((char) ('a' + i));
			}
			out.close();
		}
		
		{ // try do by 1 word
			cicle : for (int l = 2; l <= L; l++) {
				if (s.length() % l != 0) {
					continue;
				}
				for (int i = 1; (i + 1) * l <= s.length(); i++) {
					if (!equals(s, 0, i * l, l)) {
						continue cicle;
					}
				}
				out.println(1);
				out.print(s.substring(0, l));
				out.close();
				return;
			}
		}
		
		if (ans == 3){ // try do by 2 words
			for (L1 = 1; L1 <= L; L1++) {
				beginTwo = L1;
				for (;beginTwo + L1 <= s.length(); beginTwo += L1) {
					if (!equals(s, 0, beginTwo, L1)) {
						break;
					}
				}
				for (L2 = 1; L2 <= L; L2++) {
					d = new int[s.length()];
					if (can(beginTwo + L2)) {
						out.println(2);
						out.println(s.substring(0, L1));
						out.print(s.substring(beginTwo, beginTwo + L2));
						out.close();
						return;
					}
				}
			}
		}
		out.println(ans);
		for (int i = 0; i < 3; i++) {
			if (check[i])
				out.println((char) ('a' + i));
		}
		out.close();
		in.close();
	}

	public static boolean equals(String s, int l, int r, int length) {
		if (l + length > s.length() || r + length > s.length())
			return false;
		for (int i = 0; i < length; i++) {
			if (s.charAt(l + i) != s.charAt(r + i)) {
				return false;
			}
		}
		return true;
	}
	static String s;
	static int[] d;
	static int L1;
	static int L2;
	static int beginTwo;
	
	static boolean can(int from) {
		if (from == s.length()) {
			return true;
		}
		if (d[from] != 0) {
			return d[from] == 1;
		}
		if (equals(s, from, 0, L1) && can(from + L1)) {
			d[from] = 1;
			return true;
		}
		if (equals(s, from, beginTwo, L2) && can(from + L2)) {
			d[from] = 1;
			return true;
		}
		return false;
	}
}
