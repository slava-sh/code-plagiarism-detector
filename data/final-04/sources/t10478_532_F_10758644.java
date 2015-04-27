import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class F {

	Random rnd = new Random(23);
	long osn = 31;

	void solve() throws IOException {
		long mod = genMod();
		int n = nextInt();
		int m = nextInt();
		String first = next();
		String second = next();
		Map<Long,Integer> hashes = new HashMap<Long,Integer>();
		int zeros = 0;
		for (char c = 'a'; c <= 'z'; c++) {
			long hash = 0;
			for (int i = 0; i < second.length(); i++) {
				hash = hash * osn;
				if (second.charAt(i) == c) {
					hash++;
				}
				hash %= mod;
			}
			if (hash != 0) {
				hashes.put(hash,c-'a'); 
			}
		}

		long pow = 1;
		for (int i = 0; i < second.length() - 1; i++) {
			pow = (pow * osn) % mod;
		}

		long[] hs = new long[26];
		
		List<Integer> answers = new ArrayList<>();
		for (int i = 0; i < first.length(); i++) {
			if (i - second.length() >= 0) {
				hs[first.charAt(i - second.length()) - 'a'] += (mod - pow);
				hs[first.charAt(i - second.length()) - 'a'] %= mod;
			}
			for (int j = 0; j < 26; j++) {
				hs[j] = (hs[j] * osn) % mod;
			}
			hs[first.charAt(i) - 'a'] = (hs[first.charAt(i) - 'a'] + 1) % mod;
			if (i >= second.length()-1) {
				boolean fl = true;
				for (int j = 0; j < 26; j++) {
					if (hs[j] == 0) {
						continue;
					}
					if (!hashes.containsKey(hs[j])) {
						fl = false;
					} else {
						int c = hashes.get(hs[j]);
						fl &= (hs[c] == 0) || (hashes.containsKey(hs[c]) && hashes.get(hs[c]) == j); 
					}
					if (!fl) {
						break;
					}
				}
				if (fl) {
					answers.add(i - second.length() + 2);
				}
			}
		}
		
		out.println(answers.size());
		for (int i = 0; i < answers.size() - 1; i++) {
			out.print(answers.get(i) + " ");
		}
		if (answers.size() > 0) {
			out.println(answers.get(answers.size() - 1));
		}

	}

	private long genMod() {
		long max = (long) (1e+14);
		long rand = rnd.nextLong() % max;
		rand = (rand + 2 * max) % max;
		return BigInteger.valueOf(rand + max).nextProbablePrime().longValue();
	}

	void run() throws IOException {
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new F().run();
	}

	BufferedReader in;
	PrintWriter out;
	StringTokenizer st;

	String next() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String temp = in.readLine();
			if (temp == null) {
				return null;
			}
			st = new StringTokenizer(temp);
		}
		return st.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	long nextLong() throws IOException {
		return Long.parseLong(next());
	}

}
