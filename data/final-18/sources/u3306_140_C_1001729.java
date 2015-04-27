import static java.util.Arrays.deepToString;

import java.io.*;
import java.math.*;
import java.util.*;
import java.util.Map.Entry;

public class C {

	static class O implements Comparable<O> {
		int r, cnt;

		O(int r, int cnt) {
			this.r = r;
			this.cnt = cnt;
		}

		public int compareTo(O o) {
			if (o.cnt == cnt)
				return o.r - r;
			return o.cnt - cnt;
		}
	}

	static void solve(int[] r) {
		ArrayList<int[]> ans = new ArrayList<int[]>();
		TreeMap<Integer, Integer> map = new TreeMap<Integer, Integer>();
		for (int R : r) {
			Integer have = map.get(R);
			int nhave = have != null ? have + 1 : 1;
			map.put(R, nhave);
		}
		TreeSet<O> set = new TreeSet<O>();
		for (Entry<Integer, Integer> e : map.entrySet()) {
			set.add(new O(e.getKey(), e.getValue()));
		}
		outer: while (true) {
			O[] e = new O[3];
			for (int i = 0; i < 3; i++) {
				e[i] = set.pollFirst();
				if (e[i] == null)
					break outer;
			}
			ans.add(new int[] { e[0].r, e[1].r, e[2].r });
			for (int i = 0; i < 3; i++) {
				int nhave = e[i].cnt - 1;
				if (nhave > 0) {
					set.add(new O(e[i].r, nhave));
				}
			}
		}
		writer.println(ans.size());
		for (int[] arr : ans) {
			Arrays.sort(arr);
			writer.println(arr[2] + " " + arr[1] + " " + arr[0]);
		}
	}

	public static void main(String[] args) throws Exception {
		reader = new BufferedReader(new InputStreamReader(System.in));
		writer = new PrintWriter(System.out);

		setTime();
		int n = nextInt();
		int[] r = new int[n];
		for (int i = 0; i < n; i++) {
			r[i] = nextInt();
		}
		solve(r);
		printTime();
		printMemory();

		writer.close();
	}

	static BufferedReader reader;
	static PrintWriter writer;
	static StringTokenizer tok = new StringTokenizer("");
	static long systemTime;

	static void debug(Object... o) {
		System.err.println(deepToString(o));
	}

	static void setTime() {
		systemTime = System.currentTimeMillis();
	}

	static void printTime() {
		System.err.println("Time consumed: " + (System.currentTimeMillis() - systemTime));
	}

	static void printMemory() {
		System.err.println("Memory consumed: "
				+ (Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory()) / 1000 + "kb");
	}

	static String next() {
		while (!tok.hasMoreTokens()) {
			String w = null;
			try {
				w = reader.readLine();
			} catch (Exception e) {
				e.printStackTrace();
			}
			if (w == null)
				return null;
			tok = new StringTokenizer(w);
		}
		return tok.nextToken();
	}

	static int nextInt() {
		return Integer.parseInt(next());
	}

	static long nextLong() {
		return Long.parseLong(next());
	}

	static double nextDouble() {
		return Double.parseDouble(next());
	}

	static BigInteger nextBigInteger() {
		return new BigInteger(next());
	}
}