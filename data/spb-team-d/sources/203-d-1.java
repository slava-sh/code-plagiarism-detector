import java.io.*;
import java.util.*;
public class Pysch {
	static StringTokenizer[] st = new StringTokenizer[1];
	public static int readInt(BufferedReader in) throws Exception {
		for (; !st[0].hasMoreTokens(); ) {
			st[0] = new StringTokenizer(in.readLine());
		}
		return Integer.parseInt(st[0].nextToken());
	}
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(new File("dunes.in")));
		PrintWriter out = new PrintWriter("dunes.out");
//		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
//		PrintWriter out = new PrintWriter(System.out);
		st[0] = new StringTokenizer(in.readLine());
		int n = readInt(in), m = readInt(in);
		int[][] evs = new int[n * 2 + m][3];
		for (int i = 0; i < n; i++) {
			int b = readInt(in), e = readInt(in), s = readInt(in);
			evs[i * 2] = new int[]{b, 0, s};
			evs[i * 2 + 1] = new int[]{e, 1 + b, s};
		}
		for (int i = 0; i < m; i++) {
			int x = readInt(in);
			evs[n * 2 + i] = new int[]{x, 1, 0};
		}
		Arrays.sort(evs, new Comparator<int[]>() {
			@Override
			public int compare(int[] o1, int[] o2) {
				int a = Integer.compare(o1[0], o2[0]);
				if (a == 0) {
					return Integer.compare(o1[1], o2[1]);
				}
				return a;
			}
		});
		int d = 0;
		for (int i = 0; i < evs.length; i++) {
			if (evs[i][1] == 0) {
				d += evs[i][2] * (evs[i][0] % 2 == 0 ? 1 : -1);
			} else if (evs[i][1] == 1) {
				out.println(d * (evs[i][0] % 2 == 0 ? 1 : -1));
			} else {
				d -= evs[i][2] * (evs[i][1] % 2 != 0 ? 1 : -1);
			}
		}
		out.close();
		in.close();
	}
}
