import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("chess.in"));
		PrintWriter out = new PrintWriter(new File("chess.out"));
		int n = in.nextInt();
		int[][] ans = new int[n][2];
		int p = 0;
		for (int i = 0; i < n; i++) {
			int h = in.nextInt() - 1;
			if ((p == 0) || (ans[p - 1][1] < h)) {
				ans[p][0] = i;
				ans[p][1] = i;
				p++;
			}
		}
		out.println(p);
		for (int i = 0; i < p; i++) {
			out.println((ans[i][0] + 1) + " " + (ans[i][1] + 1));
		}
		in.close();
		out.close();
	}

}
