import java.io.*;
import java.util.*;


public class ProblemB {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("chess.in"));
		PrintWriter out = new PrintWriter(new File("chess.out"));
		int n = in.nextInt();
		int[] cols = new int[n];
		for (int i = 0; i < n; i++){
			cols[i] = in.nextInt();
		}
		String[] ans = new String [n];
		int counter = 0;
		
		for (int i = 0; i < n; i++){
			if (cols[i] <= i){
				break;
			}
			counter++;
			ans[i] = (i + 1) + " " + (counter);
		}
		out.println(counter);
		for (int i = 0; i < n; i++){
			if (ans[i] != null){
				out.println(ans[i]);
			}
		}
		in.close();
		out.close();
	}

}
