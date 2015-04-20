import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class Merlint {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("merlin.in"));		
		PrintWriter out = new PrintWriter(new File("merlin.out"));
		int n =sc.nextInt();
		int a[] = new int[n];
		for (int i = 0;i<n;i++){
			a[i] = sc.nextInt();
		}
		boolean ok = true;
		for (int i = 1;i<n;i++){
			if (a[i]!=a[0]){
				ok = false;
			}
		}
		if (ok) {
			out.println(0);
		} else {
			int i = n-1;
			int sum1 = 0;
			int sum2 = 0;
			Arrays.sort(a);
			while(i>=0){
				sum1=0;
				sum2+=a[i];
				for (int j = 0; j<i-1;j++){
					sum1+=(a[i-1]-a[j]);
				}
				if (sum1<=sum2){
					break;
				} else {
					i--;
				}
			}
			out.println(n-i);
		}
		out.close();
	}

}
