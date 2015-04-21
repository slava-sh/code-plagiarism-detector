import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;


public class Cyan {
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
	
	public static class Line implements Comparable<Line>{
		int[] pointsX;
		int[] pointsY;
		int number;
		
		int currentX = 0;
		
		public Line(int[] x, int[] y, int number) {
			pointsX = x;
			pointsY = y;
			this.number = number;
		}

		@Override
		public int compareTo(Line arg0) {
//			for (int i = 0; i < pointsY.length; )
			return pointsY[0] - arg0.pointsY[0];
		}
	}
	
	public static int check(Line a, Line b) { // 3 - error; -1 - a lowwer; 1 - a bigger; 0 - equal;
		int aBigger = 0;
		if (a.pointsY[0] > b.pointsY[0]) {
			aBigger = 1;
		} else if (a.pointsY[0] < b.pointsY[0]) {
			aBigger = -1;
		}
		int pos = 1;
		for (int i = 0; i < a.pointsX.length; i++) {
			while (b.pointsX[pos] < a.pointsX[i]) {
				pos++;
			}
			double k = (b.pointsY[pos] - b.pointsY[pos - 1]) / (b.pointsX[pos] - b.pointsX[pos - 1]);
			double yB = (b.pointsY[pos - 1] + k * (a.pointsX[i] - b.pointsX[pos - 1]));
			if (yB != a.pointsY[i]) {
				if (yB > a.pointsY[i] + 0.0000001) {
					if (aBigger == 1) {
						return 3;
					}
					aBigger = -1;
				} else if (yB < a.pointsY[i] - 0.0000001) {
					if (aBigger == -1) {
						return 3;
					}
					aBigger = 1;
				}
			}
		}
		pos = 1;
		for (int i = 0; i < b.pointsX.length; i++) {
			while (a.pointsX[pos] < b.pointsX[i]) {
				pos++;
			}
			double k = (a.pointsY[pos] - a.pointsY[pos - 1]) / (a.pointsX[pos] - a.pointsX[pos - 1]);
			double yB = (a.pointsY[pos - 1] + k * (b.pointsX[i] - a.pointsX[pos - 1]));
			if (yB != b.pointsY[i]) {
				if (yB > b.pointsY[i] + 0.0000001) {
					if (aBigger == -1) {
						return 3;
					}
					aBigger = 1;
				} else if (yB < b.pointsY[i] - 0.0000001) {
					if (aBigger == 1) {
						return 3;
					}
					aBigger = -1;
				}
			}
		}
		return aBigger;
	}
	
	static class Event implements Comparable<Event>{
		int x;
		int lineInSort;
		
		public Event(int x, int lineInSort) {
			this.x = x;
			this.lineInSort = lineInSort;
		}

		@Override
		public int compareTo(Event arg0) {
			return x - arg0.x;
		}
		
		
	}
	
	static boolean flag = false;
	
	static int one;
	static int two;
	public static void main(String[] args) throws NumberFormatException, IOException {
		FastScanner in = new FastScanner(new File("input.txt"));
		PrintWriter out = new PrintWriter(new File("output.txt"));
//		FastScanner in = new FastScanner();
//		PrintWriter out = new PrintWriter(System.out);
		int A = in.nextInt();
		int B = in.nextInt();
		int N = in.nextInt();
		Line[] lines = new Line[N];
		for (int i = 0; i < N; i++) {
			int L = in.nextInt();
			int[] x = new int[L + 1];
			int[] y = new int[L + 1];
			for (int j = 0; j < L + 1; j++) {
				x[j] = in.nextInt();
				y[j] = in.nextInt();
			}
			lines[i] = new Line(x, y, i + 1);
		}
		Arrays.sort(lines, new Comparator<Line>() {
			public int compare(Line arg0, Line arg1) {
				if (flag) {
					return 0;
				}
				int comp = check(arg0, arg1);
				if (comp == 3) {
					flag = true;
					one = arg0.number;
					two = arg1.number;
				}
				return comp;
			}
			
		});
		if (flag) {
			out.println("No");
			out.println(one + " " + two);
			out.close();
			return;
		}
		for (int i = 0; i < lines.length - 1; i++) {
			if (check(lines[i], lines[i + 1]) < 0) {
				if (flag) {
					out.println("No");
					out.println(lines[i].number + " " + lines[i + 1].number);
					out.close();
					return;
				}
			}
		}
		out.println("Yes");
		out.close();
	}
}
