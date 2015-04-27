import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;

public class Main {
	private static final String TASKNAME = "b";

	private void solve() throws Exception {
		int n = nextInt();
		int m = nextInt();
		char[][] grid = new char[n][];
		for (int i = 0; i < n; ++i) {
			grid[i] = nextToken().toCharArray();
		}
		int[][] ans = new int[n][m];
		int[] dx = { 1, 0, -1, 0 };
		int[] dy = { 0, 1, 0, -1 };
		int[] masks = new int[(int) 2e6];

		int count = 1;

		final int m2 = masks.length - 1;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (grid[i][j] == '#') {
					ans[i][j] = m2;
					continue;
				}
				if (ans[i][j] != 0) {
					continue;
				}
				boolean ok = false;
				for (int dir = 0; dir < 4; ++dir) {
					int ni = i + dy[dir];
					int nj = j + dx[dir];
					if (ni < 0 || ni >= n || nj < 0 || nj >= m || grid[ni][nj] == '#' || ans[ni][nj] != 0) {
						continue;
					}
//					System.err.println("" + i + " " + j + " " + ni + " " + nj + " " + count);
					ans[ni][nj] = ans[i][j] = count++;
					ok = true;
					break;
				}
				for (int dir = 0; !ok && dir < 4; ++dir) {
					int ni = i + dy[dir];
					int nj = j + dx[dir];
					if (ni < 0 || ni >= n || nj < 0 || nj >= m || grid[ni][nj] == '#') {
						continue;
					}
					ok = true;
					ans[i][j] = ans[ni][nj];
					break;
				}
//				System.err.println("" + i + " " + j);
				if (!ok) {
//					System.err.println("" + i + " " + j);
					println("-1");
					return;
				}
			}
//			System.err.println();
		}
//		for (int i = 0; i < n; ++i) {
//			System.err.println(Arrays.toString(ans[i]));
//		}

//		System.err.println("count = " + count);
		int[] cnt = new int[(int)2e6];
		int[] color = new int[(int)2e6];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (ans[i][j] == m2) {
					continue;
				}
				if (color[ans[i][j]] > 0) {
					continue;
				}
				int mask = 0;
				for (int r = Math.max(i - 2, 0); r <= Math.min(n - 1, i + 2); ++r) {
					for (int c = Math.max(j - 2, 0); c <= Math.min(m - 1, j + 2); ++c) {
						if (ans[r][c] == ans[i][j]) {
//							System.err.println("" + r + " " + c + " = " + i + " " + j);
							for (int dir = 0; dir < 4; ++dir) {
								int nr = r + dx[dir];
								int nc = c + dy[dir];
								if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
//									System.err.println("ans = " + ans[i][j] + " fc " + color[ans[nr][nc]]);
									mask |= 1 << color[ans[nr][nc]];
								}
							}
						}
					}
				}
//				System.err.println(mask);
				boolean found = false;
				for (int c = 1; c <= 10; ++c) {
					if ((mask & (1 << c)) == 0) {
						color[ans[i][j]] = c;
//						System.err.println(c);
						found = true;
						break;
					}
				}
				++cnt[ans[i][j]];
				if (cnt[ans[i][j]] > 5) {
					throw new AssertionError();
				}
				if (!found) {
					throw new AssertionError();
				}
			}
		}
		

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (ans[i][j] == m2) {
					print('#');
				} else {
					print((char) ('0' -1 + color[ans[i][j]]));
				}
			}
			println("");
		}
	}

	private void run() {
		try {
			reader = new BufferedReader(new InputStreamReader(System.in));
			writer = new PrintWriter(new OutputStreamWriter(System.out));
//			reader = new BufferedReader(new FileReader(TASKNAME + ".in"));
//			writer = new PrintWriter(new File(TASKNAME + ".out"));

			solve();

			reader.close();
			writer.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(13);
		}
	}

	public static void main(String[] args) {
		long time = System.currentTimeMillis();
		Locale.setDefault(Locale.US);
		new Main().run();
		System.err.printf("%.3f\n", (System.currentTimeMillis() - time) * 1e-3);
	}

	private StringTokenizer tokenizer;
	private PrintWriter writer;
	private BufferedReader reader;

	private String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	private int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	private long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	private double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	private void print(Object o) {
		writer.print(o);
	}

	private void println(Object o) {
		writer.println(o);
	}

	private void printf(String format, Object... args) {
		writer.printf(format, args);
	}
}
