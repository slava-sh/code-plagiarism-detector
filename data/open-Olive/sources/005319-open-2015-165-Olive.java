import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;



public class Olive2 {

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
		int[][] lowwer = new int[N][N]; // count of number on [0; i) which lowwer, than j;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				lowwer[i][j] = (array[i] < j? 1 : 0);
				if (i > 0)
					lowwer[i][j] += lowwer[i - 1][j];
			}
		}
		int dx = 0;
		int pos1 = -1, pos2 = -1;
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				int currentDx = -bigger(lowwer, i, j, array[j]) + lowwer(lowwer, i, j, array[j]) +
						bigger(lowwer, i, j, array[i]) - lowwer(lowwer, i, j, array[i]) + (array[j] < array[i]? -1 : 1);
				if (currentDx < dx) {
					dx = currentDx;
					pos1 = i + 1;
					pos2 = j + 1;
				}
			}
		}
		out.print(pos1 + " " + pos2);
		out.close();
	}

	public static int lowwer(int[][] array, int from, int to, int value) { //(from; to)
		if (to - from < 1)
			return 0;
		return array[to - 1][value] - array[from][value];
	}

	public static int bigger(int[][] array, int from, int to, int value) { //(from; to)
		if (to - from < 1)
			return 0;
		return to - from - 1 - lowwer(array, from, to, value);
	}
}
