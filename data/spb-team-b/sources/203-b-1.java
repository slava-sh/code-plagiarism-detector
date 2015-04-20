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
		BufferedReader in = new BufferedReader(new FileReader(new File("chess.in")));
		PrintWriter out = new PrintWriter("chess.out");
//		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
//		PrintWriter out = new PrintWriter(System.out);
		st[0] = new StringTokenizer(in.readLine());
		int n = readInt(in);
		int i = 0;
		for(; i < n; i++) {
			if (readInt(in) < i + 1) {
				break;
			}
		}
		out.println(i);
		out.close();
		in.close();
	}
}
