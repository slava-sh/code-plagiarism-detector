import java.util.*;
import java.io.*;

public class TaskE {
	FastScanner in;
	PrintWriter out;

	final String problem_name = "numbers";

	class StringPair implements Comparable<StringPair> {
		String a;
		String b;
		int length;

		StringPair(String a, String b) {
			this.a = a;
			this.b = b;
			length = a.length() + b.length();
		}

		public int compareTo(StringPair o) {
			if (a.equals(o.a) && b.equals(o.b)) {
				return 0;
			}
			return 1;
		}

		public String toString() {
			return ("+" + a + "(" + b + ")");
		}
	}

	public void solve() throws IOException {
		int n = in.nextInt();
		TreeMap<String, StringPair> codes = new TreeMap<String, StringPair>();
		for (int i = 0; i < n; i++) {
			String c = in.next();
			int k = in.nextInt();
			for (int j = 0; j < k; j++) {
				String l = in.next();
				String cl = c + l;
				codes.put(cl, new StringPair(c, l));
			}
		}
		int m = in.nextInt();
		for (int i = 0; i < m; i++) {
			String a = in.next();
			StringPair sp = null;
			for (int j = 4; j <= 8; j++) {
				String key = a.substring(0, j);
				sp = codes.get(key);
				if (a.charAt(j) == '0') {
					sp = null;
				}
				if (sp != null) {
					break;
				}
			}
			if (sp == null) {
				out.println("Incorrect");
				continue;
			}
			out.print(sp.toString());
			switch (sp.length) {
			case 4:
				out.println(a.substring(4, 7) + "-" + a.substring(7, 9) + "-"
						+ a.substring(9));
				break;
			case 5:
				out.println(a.substring(5, 7) + "-" + a.substring(7, 9) + "-" + a.substring(9));
				break;
			case 6:
				out.println(a.substring(6, 9) + "-" + a.substring(9));
				break;
			case 7:
				out.println(a.substring(7,9) + "-" + a.substring(9));
				break;
			case 8:
				out.println(a.substring(8));
				break;
			}
		}
	}

	public void run() {
		try {
			in = new FastScanner(new File(problem_name + ".in"));
			out = new PrintWriter(new File(problem_name + ".out"));

			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public String next() {
			while ((st == null) || (!st.hasMoreTokens())) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return (st.nextToken());
		}

		public int nextInt() {
			return (Integer.parseInt(next()));
		}

		public long nextLong() {
			return (Long.parseLong(next()));
		}

		public double nextDouble() {
			return (Double.parseDouble(next()));
		}
	}

	public static void main(String[] args) {
		new TaskE().run();
	}
}