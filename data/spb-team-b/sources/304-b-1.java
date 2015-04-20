import java.util.*;
import java.io.*;


public class B {
	public static void main(String[] args) throws FileNotFoundException {
				File fin = new File("chess.in"), fout = new File("chess.out");
		Scanner in = new Scanner(fin);
		PrintWriter out = new PrintWriter(fout);
		int n = in.nextInt();
		int min = 0;
		for (int i = 0; i < n; i++) {
			int a = in.nextInt();
			if (a > min) 
				min++;
		}
		out.println(min);
		for (int i = 0; i < min; i++) {
			out.println((i + 1) + " " + (i + 1));
		}
		in.close();
		out.close();
	}
}
