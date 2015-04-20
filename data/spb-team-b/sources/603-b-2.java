import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("chess.in"));
		PrintWriter out = new PrintWriter("chess.out");
		int n = sc.nextInt();
		int arr[] = new int[n];
		int arr1[] = new int[n];
		int arr2[] = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = sc.nextInt();
			arr1[i] = -1;
			arr2[i] = -1;
		}
		int a = 0;
		int res = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] > a ) {
				res++;
				a++;
				arr1[res - 1] = i+1;
				arr2[res - 1] = a;
			}
		}
		int t = 0;
		out.println(res);
		while(t<n && arr1[t] != -1 ){
			out.print(arr1[t]+" ");
			out.println(arr2[t]+" ");
			t++;
		}
		sc.close();
		out.close();
	}
}
