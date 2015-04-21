

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Yellow {
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

	static class Tree {
		int[] array;
		//		int[] debug;
		int n;

		public Tree(int n) {
			array = new int[n * 4];
			//			debug = new int[n];
			this.n = n;
		}

		public void set(int i, int L, int R, int index, int value) {
			if (R - L == 1) {
				array[i] = value;
				return;
			}
			int M = (R + L) >> 1;
			if (index < M) {
				set((i << 1) + 1, L, M, index, value);
			} else {
				set((i << 1) + 2, M, R, index, value);
			}
			array[i] = array[(i << 1) + 1] + array[(i << 1) + 2];
		}

		public int findIndex(int i, int L, int R, int number) {
			if(R - L == 1) {
				return L;
			}
			int M = (R + L) >> 1;
			if (array[2 * i + 1] > number) {
				return findIndex(2 * i + 1, L, M, number);
			} else {
				return findIndex(2 * i + 2, M, R, number - array[2 * i + 1]);
			}
		}

		public int getSum(int i, int L, int R, int a, int b) {
			if (L >= b || R <= a) {
				return 0;
			}
			if (a <= L && R <= b) {
				return array[i];
			}
			int M = (R + L) >> 1;
			return getSum(2 * i + 1, L, M, a, b) + getSum(2 * i + 2, M, R, a, b);
		}

		public int getRigthIndex(int index) {
			int sum = getSum(0, 0, n, 0, index + 1);
			return findIndex(0, 0, n, sum - 1);
		}

		public int findIndex(int number) {
			return findIndex(0, 0, n, number);
		}

		public int getSize() {
			return array[0];
		}

		public void set(int index, int value) {
			//			debug[index] = value;
			set(0, 0, n, index, value);
		}
	}

	public static class Segment {
		int l, r, type;

		public Segment(int l, int r, int type) {
			this.l = l;
			this.r = r;
			this.type = type;
		}

		public int length() {
			return r - l;
		}
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		FastScanner in = new FastScanner(new File("input.txt"));
		PrintWriter out = new PrintWriter(new File("output.txt"));
		//		FastScanner in = new FastScanner();
		//		PrintWriter out = new PrintWriter(System.out);
		int N = in.nextInt();
		int[] array = new int[N];
		for (int i = 0; i < array.length; i++) {
			array[i] = in.nextInt();
		}
		Segment[] segs = new Segment[N];
		int lastStart = 0;
		Tree tree = new Tree(N);
		for (int i = 1; i < N; i++) {
			if (array[i] != array[i - 1]) {
				tree.set(lastStart, 1);
				segs[lastStart] = new Segment(lastStart, i, array[lastStart]);
				lastStart = i;
			}
		}
		segs[lastStart] = new Segment(lastStart, N, array[lastStart]);
		tree.set(lastStart, 1);
		int Q = in.nextInt();
		for (int i = 0; i < Q; i++) {
			if (i != 0){
				out.println(tree.getSize());
				//				out.println(Arrays.toString(tree.debug));
			}
			int index = in.nextInt() - 1;
			int type = in.nextInt();
			int cur = tree.getRigthIndex(index);
			if (segs[cur].type == type) {
				continue;
			}
			if (segs[cur].l < index && index < segs[cur].r - 1) {
				segs[index + 1] = new Segment(index + 1, segs[cur].r, segs[cur].type);
				segs[cur].r = index;
				segs[index] = new Segment(index, index + 1, type);
				tree.set(index, 1);
				tree.set(index + 1, 1);
				continue;
			}
			int number = tree.getSum(0, 0, N, 0, segs[cur].l);
			int next = (number == tree.getSize() - 1? -1 : tree.findIndex(number + 1));
			int prev = (number == 0? -1 : tree.findIndex(number - 1));
			if (segs[cur].length() == 1) {
				if (prev == -1 && next == -1) {
					segs[cur].type = type;
					continue;
				}
				if (prev == -1 || segs[prev].type != type) {
					if (next != -1 && segs[next].type == type) {
						tree.set(next, 0);
						segs[cur].r = segs[next].r;
					} else {
						segs[cur].type = type;
					}
					continue;
				}
				if (next == -1 || segs[next].type != type) {
					if (prev != -1 && segs[prev].type == type) {
						tree.set(cur, 0);
						segs[prev].r = segs[cur].r;
					} else {
						segs[cur].type = type;
					}
					continue;
				}
				tree.set(cur, 0);
				tree.set(next, 0);
				segs[prev].r = segs[next].r;
				continue;
			}
			if (index == segs[cur].l) {
				if (prev != -1 && segs[prev].type == type) {
					tree.set(index, 0);
					tree.set(index + 1, 1);
					segs[index + 1] = segs[index];
					segs[index + 1].l++;
					segs[prev].r = index + 1;
				} else {
					tree.set(index + 1, 1);
					segs[index + 1] = segs[index];
					segs[index + 1].l++;
					segs[index + 1].type = segs[cur].type;
					segs[cur] = new Segment(index, index + 1, type);
				}
				continue;
			}
			if (index == segs[cur].r - 1) {
				if (next != -1 && segs[next].type == type) {
					tree.set(index + 1, 0);
					tree.set(index, 1);
					segs[index] = segs[next];
					segs[next].l--;
					segs[cur].r--;
				} else {
					tree.set(index, 1);
					segs[index + 1] = new Segment(index, index + 1, type);
					segs[cur].r--;
				}
				continue;
			}
		}
		out.println(tree.getSize());
		out.close();
	}
}
