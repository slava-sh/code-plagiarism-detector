import java.io.*;
import java.util.*;


public class ProblemA {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("abcd.in"));
		PrintWriter out = new PrintWriter(new File ("abcd.out"));
		int n = in.nextInt();
		for (int i = 0; i < n; i++){
			int number = in.nextInt();
			
			String string = number + "" ;
			if (number < 1000){
				string = "0" + string;
			}
			if (number < 100){
				string = "0" + string;
			}
			if (number < 10){
				string = "0" + string;
			}
			
			
			
			
			int n1 = Integer.parseInt("" + string.charAt(0) + string.charAt(1));
			int n2 = Integer.parseInt("" + string.charAt(2) + string.charAt(3));
			
			if (((n1 * n1) + (n2 * n2)) % 7 == 1){
				out.println("YES");
				
			} else{
				out.println("NO");
			}
		}
		in.close();
		out.close();
	}

}
