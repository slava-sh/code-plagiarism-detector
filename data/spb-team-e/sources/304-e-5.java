import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class E {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("game.in"));
		PrintWriter out = new PrintWriter(new File("game.out"));
//		Scanner in = new Scanner(System.in);
//		PrintWriter out = new PrintWriter(System.out);
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
			long current = in.nextLong();
			if (current >= l1 && current >= l2 && current <= r1 && current <= r2) {
				countBoth++;
			} else if (current >= l1 && current <= r1) {
				countOnlyOne++;
			} else if (current >= l2 && current <= r2) {
				countOnlyTwo++;
			}
		}
		long first = 0;
		long second = 0;
		while (m > 0) {
			if (countBoth > 0) {
				countBoth--;
				first++;
			} else if (countOnlyOne > 0) {
				countOnlyOne--;
				first++;
			}
			m--;
			if (countBoth > 0 && m > 0) {
				countBoth--;
				second++;
			} else if (countOnlyTwo > 0 && m > 0) {
				countOnlyTwo--;
				second++;
			}
			m--;
			if (countBoth + countOnlyOne + countOnlyTwo == 0) {
				break;
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
