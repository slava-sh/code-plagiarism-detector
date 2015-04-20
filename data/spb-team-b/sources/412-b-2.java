import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;


public class ChessB {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int a[] = new int[n];
		for (int i = 0;i<n;i++){
			a[i] = sc.nextInt();
		}
		sc.close();
		PrintWriter pw = new PrintWriter(new File("chess.out"));
		int i = 0;
		while(a[i]>=i+1){			
			if (i<n-1){
				i++;
			} else {
				break;
			}
		}
		System.out.println(i);
		for (int j = 1;j<=i;j++){
			System.out.println(j+" "+j);
		}
		pw.close();
	}

}
