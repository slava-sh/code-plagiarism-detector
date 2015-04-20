import java.io.*;
import java.util.*;

public class B1 {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("che.in"));
		PrintWriter out = new PrintWriter("che.out"); 
		int n = in.nextInt();
		int r = in.nextInt();
		int[] a = new int[300100];
		for (int i = 1; i < n + 1; i++){
		   a[i] = in.nextInt();
		}
		long sum = 0;
		int l = 1;
		int i = 1;
		while (i < n + 1){
			while ((a[l] - a[i] <= r) && (l < n + 1)) {
				l++;
			}
			if (a[l] - a[i] < r){
				break;
			}
			else{
				sum += n - l + 1; 
			}
			i++;
		}
		out.print(sum);
		out.close();
	}
}
