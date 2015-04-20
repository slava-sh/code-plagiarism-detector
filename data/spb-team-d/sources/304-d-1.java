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
		int max = 0;
		for (int i = 0; i < m; i++) {
			fin[i] = in.nextInt();
			if (fin[i] > max) 
				max = fin[i];
		}
		int[] dune = new int[max + 1];
		Arrays.fill(dune, 0);
		for (int i = 0; i < n; i++) {
			int L = wind[i][0], R = wind[i][1], F = wind[i][2];
			boolean what = true;
			for (int j = L; j <= R; j++) {
				dune[j] += (what? F : -F);
				what = !what;
			}
		}
		for (int i = 0; i < m; i++) {
			out.println(dune[fin[i]]);
		}
		in.close();
		out.close();
	}
}
