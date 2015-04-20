import java.util.*;
import java.io.*;

public class D {
	public static void main(String[] args) throws FileNotFoundException {
		File filein = new File("dunes.in"), fout = new File("dunes.out");
		Scanner in = new Scanner(filein);
		PrintWriter out = new PrintWriter(fout);
//		Scanner in = new Scanner(System.in);
//		PrintWriter out = new PrintWriter(System.out);
		int n = in.nextInt(), m = in.nextInt();
		int[][] wind = new int[n][3];
		for (int i = 0; i < n; i++) {
			wind[i][0] = in.nextInt();
			wind[i][1] = in.nextInt();
			wind[i][2] = in.nextInt();
		}
		int[] fin = new int[m];
		for (int i = 0; i < m; i++) {
			fin[i] = in.nextInt();
		}
		int[] dune = new int[m];
		Arrays.fill(dune, 0);
		for (int i = 0; i < n; i++) {
			int L = wind[i][0], R = wind[i][1], F = wind[i][2];
			for (int j = 0; j < m; j++) {
				if (fin[j] >= L && fin[j] <= R) {
					dune[j] += ((fin[j] - L) % 2 == 0? F : -F);
				}
			}
		}
		for (int i = 0; i < m; i++) {
			out.println(dune[i]);
		}
		in.close();
		out.close();
	}
}
