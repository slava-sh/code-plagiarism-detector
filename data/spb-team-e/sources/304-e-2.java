import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class E {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("game.in"));
		PrintWriter out = new PrintWriter(new File("game.out"));
//		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		int l1 = in.nextInt();
		int r1 = in.nextInt();
		int l2 = in.nextInt();
		int r2 = in.nextInt();
		int countOnlyOne = 0;
		int countOnlyTwo = 0;
		int countBoth = 0;
		for (int i = 0; i < n; i++) {
			int curret = in.nextInt();
			if (curret > l1 && curret > l2 && curret < r1 && curret < r2) {
				countBoth++;
			} else if (curret > l1 && curret < r1) {
				countOnlyOne++;
			} else if (curret > l2 && curret < r2) {
				countOnlyTwo++;
			}
		}
		int first = 0;
		int second = 0;
		for (int M = m; M > 0;) {
			if (countBoth + countOnlyOne + countOnlyTwo == 0) {
				break;
			}
			if (countBoth > 0) {
				countBoth--;
				M--;
				first++;
			} else if (countOnlyOne > 0) {
				countOnlyOne--;
				M--;
				first++;
			}
			if (countBoth > 0 && M > 0) {
				countBoth--;
				M--;
				second++;
			} else if (countOnlyTwo > 0 && M > 0) {
				countOnlyTwo--;
				M--;
				second++;
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
		in.close();
	}
}
