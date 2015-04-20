import java.util.*;
import java.io.*;

public class ABCDCode {
	public static void main(String[] args) throws FileNotFoundException {
		File fin = new File("abcd.in"), fout = new File("abcd.out");
		Scanner in = new Scanner(fin);
		PrintWriter out = new PrintWriter(fout);
		int n = in.nextInt();
		String str = in.nextLine();
		
		for (int i = 0; i < n; i++) {
			String s = in.nextLine();
			String s1 = "" + s.charAt(0) + s.charAt(1);
			String s2 = "" + s.charAt(2) + s.charAt(3);
			int a = Integer.parseInt(s1), b = Integer.parseInt(s2);
			if ((a * a + b * b) % 7 == 1) {
				out.println("YES");
			} else {
				out.println("NO");
			}
		}
		in.close();
		out.close();
	}
}
