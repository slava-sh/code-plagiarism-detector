import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class ECopy {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("game.in"));
		PrintWriter out = new PrintWriter(new File("game.out"));
//		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		int onlyOne = 0;
		int onlyTwo = 0;
		int both = 0;
		int l1 = in.nextInt();
		int r1 = in.nextInt();
		int l2 = in.nextInt();
		int r2 = in.nextInt();
		for (int i = 0; i < n; i++) {
			int curret = in.nextInt();
			if (l1 <= curret && curret <= r1 && l2 <= curret && curret <= r2) {
				both++;
			} else if (l1 <= curret && curret <= r1) {
				onlyOne++;
			} else  if (l2 <= curret && curret <= r2) {
				onlyTwo++;
			}
		}
		int first = 0;
		int second = 0;
		while (m > 0) {
			if (onlyOne + onlyTwo + both == 0) {
				break;
			}
			if (both > 0) {
				first++;
				both--;
				m--;
			} else if (onlyOne > 0) {
				first++;
				onlyOne--;
				m--;
			}
			if (both > 0 && m > 0) {
				second++;
				both--;
				m--;
			} else if (onlyTwo > 0 && m > 0) {
				second++;
				onlyTwo--;
				m--;
			}
		}
		if (first > second) {
			out.println("Petya");
		} else if (second > first) {
			out.println("Vasya");
		} else {
			out.println("Draw");
		}
		out.close();
	}
}
