import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class exJ {
	public static void main(String[]args) throws FileNotFoundException{
		Scanner sc = new Scanner(new File("seq.in"));
		PrintWriter out = new PrintWriter("seq.out");
		int n = sc.nextInt();
		int h = sc.nextInt();
		int arr[] = new int[n];
		long min = 1000000000;
		min = min*min;
		long y = min;
		
		for(int i = 0; i<n; i++){
			arr[i] = sc.nextInt();
		}
		for(int i = 0; i<=n-h; i++){
			if(arr[i]==1 || arr[i]==0){
				long sum = 0;
				for(int j = i; j<i+h; j++){
					if(arr[j]<=j-i+1){
						sum+=j-i+1-arr[j];
					}else{
						sum = min+1;
						break;
					}
				}
				if(sum<min){
					min = sum;
				}
			}
		}
		if(min == y){
			out.println(-1);
		}else{
			out.println(min);
		}
		out.close();
	}

}
