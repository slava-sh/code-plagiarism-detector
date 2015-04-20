import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Dunes {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("dunes.in"));
		PrintWriter pw = new PrintWriter(new File("dunes.out"));
		int n = sc.nextInt();
		int m = sc.nextInt();
		int l[] = new int[n];
		int r[] = new int[n];
		int x[] = new int[n];
		for (int i = 0; i < n; i++) {
			l[i] = sc.nextInt();
			r[i] = sc.nextInt();
			x[i] = sc.nextInt();
		}
		// numbers of pieces
		int q[] = new int[m];
		for (int i = 0; i < m; i++) {
			q[i] = sc.nextInt();
		}
		// heights
		int h[] = new int[m];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (l[j] <= q[i] && q[i] <= r[j]) {
					if ((q[i] - l[j] + 1) % 2 == 0) {
						h[i] -= x[j];
					} else {
						h[i] += x[j];
					}
				}
			}
		}
		for (int i = 0; i < m; i++) {
			pw.println(h[i]);
		}
		pw.close();
	}
}
