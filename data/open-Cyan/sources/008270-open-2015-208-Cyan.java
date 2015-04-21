import java.io.*;
import java.util.*;

public class CyanStupid {
	public static void main(String[] args) throws IOException {
		new CyanStupid().run();
	}

	BufferedReader in;
	PrintWriter out;
	StringTokenizer st;

	String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(in.readLine());
		}
		return st.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	void run() throws IOException {
		in = new BufferedReader(new FileReader("input.txt"));
		out = new PrintWriter("output.txt");
		solve();
		out.flush();
	}

	long vecCross(long x1, long y1, long x2, long y2) {
		return x1 * y2 - x2 * y1;
	}

	int sign(long a) {
		if (a > 0) {
			return 1;
		}
		if (a < 0) {
			return -1;
		}
		return 0;
	}

	void solve() throws IOException {
		int a = nextInt();
		int b = nextInt();
		int n = nextInt();
		long[][] lxs = new long[n][];
		long[][] lys = new long[n][];
		for (int i = 0; i < n; i++) {
			int num = nextInt() + 1;
			lxs[i] = new long[num];
			lys[i] = new long[num];
			for (int j = 0; j < num; j++) {
				lxs[i][j] = nextInt();
				lys[i][j] = nextInt();
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int l = 0;
				int r = 0;
				int min = sign(lys[i][l] - lys[j][r]);
				int max = min;
				l++;
				r++;
				while (l < lxs[i].length && r < lxs[j].length) {
					while (l < lxs[i].length && lxs[i][l] < lxs[j][r]) {
						int temp = sign(vecCross(lxs[j][r] - lxs[j][r - 1],
								lys[j][r] - lys[j][r - 1], lxs[i][l]
										- lxs[j][r - 1], lys[i][l]
										- lys[j][r - 1]));
						min = Math.min(min, temp);
						max = Math.max(max, temp);
						l++;
					}
					while (l < lxs[i].length && r < lxs[j].length
							&& lxs[i][l] == lxs[j][r]) {
						int temp = sign(lys[i][l] - lys[j][r]);
						min = Math.min(min, temp);
						max = Math.max(max, temp);
						l++;
						r++;
					}
					while (l < lxs[i].length && r < lxs[j].length
							&& lxs[i][l] > lxs[j][r]) {
						int temp = sign(vecCross(lxs[j][r] - lxs[i][l - 1],
								lys[j][r] - lys[i][l - 1], lxs[i][l]
										- lxs[i][l - 1], lys[i][l]
										- lys[i][l - 1]));
						min = Math.min(min, temp);
						max = Math.max(max, temp);
						r++;
					}
					if (min * max < 0) {
						out.println("No");
						out.println((i + 1) + " " + (j + 1));
						return;
					}
				}
			}
		}
		out.println("Yes");
	}
}
