import java.io.*;
import java.util.*;


public class ProblemD {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("dunes.in"));
		PrintWriter out = new PrintWriter(new File("dunes.out"));
		int n = in.nextInt();
		int m = in.nextInt();
		int[] L = new int[n];
		int[] r = new int[n];
		int[] x = new int[n];
		int[] h = new int[m];
		for (int i = 0; i < n; i++){
			L[i] = in.nextInt();
			r[i] = in.nextInt();
			x[i] = in.nextInt();
		}
		int[] q = new int[m];
		for (int i = 0; i < m; i++){
			q[i] = in.nextInt();
		}
		for (int i = 0; i < n; i++){
			
			for (int j = 0; j < m; j++){
				if ((q[j] >= L[i]) && (q[j] <= r[i])){
					if ((q[j] - L[i]) % 2 == 0){
					h[j] += x[i];
					} else{
					h[j] -= x[i];
					}
				}
			}
		}
		for (int i = 0; i < m; i++){
			out.println(h[i]);
		}
		
		in.close();
		out.close();
	}

}
