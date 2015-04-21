import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;



public class Olive {

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

		public Tree(int n) {
			array = new int[n << 2];
		}

		public int get(int i, int L, int R, int a, int b) {
			if (L >= b || R <= a) {
				return 0;
			} 
			if (a <= L && R <= b) {
				return array[i];
			}
			int M = (R + L) >> 1;
			return get((i << 1) + 1, L, M, a, b) + get((i << 1) + 2, M, R, a, b);
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
	}

	public static long calculate(int[] array) {
		Tree tree = new Tree(array.length);
		long ans = 0;
		for (int i = 0; i < array.length; i++) {
			ans += tree.get(0, 0, array.length, array[i], array.length);
			tree.set(0, 0, array.length, array[i], 1);
		}
		return ans;
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		FastScanner in = new FastScanner(new File("input.txt"));
		PrintWriter out = new PrintWriter(new File("output.txt"));
		//		FastScanner in = new FastScanner();
		//		PrintWriter out = new PrintWriter(System.out);
		int N = in.nextInt();
		int[] array = new int[N];
		for (int i = 0; i < N; i++) {
			array[i] = in.nextInt() - 1;
		}
		int pos1 = -1, pos2 = -1;
		long ans = calculate(array);
		//		System.out.println(ans);
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				swap(array, i, j);
				long current = calculate(array);
				swap(array, i, j);
				if (current < ans) {
					ans = current;
					pos1 = i + 1;
					pos2 = j + 1;
				}
			}
		}
		out.print(pos1 + " " + pos2);
		out.close();
	}

	public static void swap(int[] array, int i, int j) {
		int help = array[i];
		array[i] = array[j];
		array[j] = help;
	}
}
