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
			long sum1 = 0;
			for (int j = 0; j<n-2;j++){
				sum1+=(a[n-2]-a[j]);
			}
			long sum2 = a[n-1];
			Arrays.sort(a);
			while(i>=0){
				if (sum1<=sum2){
					break;
				} else {
					sum1-=a[i];
					sum2+=a[i];
					i--;
				}
			}
			out.println(n-i+1);
		}
		out.close();
	}

}
