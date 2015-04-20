import java.io.*;
import java.util.*;

public class a1 {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("abcd.in"));
		PrintWriter out = new PrintWriter("abcd.out");
		int t = in.nextInt();
		for (int i = 0; i < t; i++) {
			String s = in.next();
			int a = ((int) (s.charAt(0)) - (int) ('0')) * 10 + ((int) (s.charAt(1)) - (int) ('0'));
			int b = ((int) (s.charAt(2)) - (int) ('0')) * 10 + ((int) (s.charAt(3)) - (int) ('0'));
			if ((a * a + b * b) % 7 == 1){
				out.println("YES");
			}
			else{
				out.println("NO");
			}
		}
		out.close();
	}
}
