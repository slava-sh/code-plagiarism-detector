import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;



public class exG {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("merlin.in"));
		PrintWriter out = new PrintWriter("merlin.out");
		int n = sc. nextInt();
		int arr[] = new int[n];
		long sum=0;
		for(int i = 0; i<n; i++){
		arr[i] = sc.nextInt();
		sum+=arr[i];
		}
		Arrays.sort(arr);
		for(int i = n-1; i>0; i--){
			double u = (double)(sum/i);
			if((double)arr[i-1]<=u){
				out.println(n-i);
				break;
			}
		}
		out.close();
	}

}
