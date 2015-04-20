import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class E {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("game.in"));
		PrintWriter out = new PrintWriter(new File("game.out"));
//		Scanner in = new Scanner(System.in);
		long n = in.nextLong();
		long m = in.nextLong();
		long l1 = in.nextLong();
		long r1 = in.nextLong();
		long l2 = in.nextLong();
		long r2 = in.nextLong();
		long countOnlyOne = 0;
		long countOnlyTwo = 0;
		long countBoth = 0;
		for (int i = 0; i < n; i++) {
			long curret = in.nextLong();
			if (curret >= l1 && curret >= l2 && curret <= r1 && curret <= r2) {
				countBoth++;
			} else if (curret >= l1 && curret <= r1) {
				countOnlyOne++;
			} else if (curret >= l2 && curret <= r2) {
				countOnlyTwo++;
			}
		}
		long first = 0;
		long second = 0;
		while (m > 0) {
			if (countBoth + countOnlyOne + countOnlyTwo == 0) {
				break;
			}
			if (countBoth > 0) {
				countBoth--;
				m--;
				first++;
			} else if (countOnlyOne > 0) {
				countOnlyOne--;
				m--;
				first++;
			}
			if (countBoth > 0 && m > 0) {
				countBoth--;
				m--;
				second++;
			} else if (countOnlyTwo > 0 && m > 0) {
				countOnlyTwo--;
				m--;
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
