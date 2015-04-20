import java.io.*;
import java.util.*;

public class d1 {
	static int sign(int l, int r, int q){
		if ((q - l + 1) % 2 == 1){
			return 1;
		}
		else{
			return -1;
		}
	}
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("dunes.in"));
		PrintWriter out = new PrintWriter("dunes.out");
		int n = in.nextInt();
		int m = in.nextInt();
		int winds[] = new int[n];
		int winds_l[] = new int[n];
		int winds_r[] = new int[n]; 
		for (int i = 0; i < n; i++) {
			winds_l[i] = in.nextInt();
			winds_r[i] = in.nextInt();
			winds[i] = in.nextInt();
		}
		for (int i = 0; i < m; i++) {
			int q = in.nextInt();
			long sum = 0;
			for (int j = 0; j < n; j++) {
				if ((q <= winds_r[j]) && (q >= winds_l[j])){
					sum = (long) sum + winds[j] * sign(winds_l[j], winds_r[j], q);
				}
			}
			out.println(sum);
		}
		out.close();
	}
}
