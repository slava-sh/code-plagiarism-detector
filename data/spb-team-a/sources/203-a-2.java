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
		BufferedReader in = new BufferedReader(new FileReader(new File("abcd.in")));
		PrintWriter out = new PrintWriter("abcd.out");
		st[0] = new StringTokenizer(in.readLine());
		int amount = readInt(in);
		int newNumber;
		int aB;
		int cD;
		for(int i = 0; i < amount; i++) {
			newNumber = readInt(in);
			aB = newNumber / 100;
			cD = newNumber % 100;
			if ((aB * aB + cD * cD) % 7 == 1) {
				out.println("YES");
			} else {
				out.println("NO");
			}
		}
		out.close();
		in.close();
	}
}
