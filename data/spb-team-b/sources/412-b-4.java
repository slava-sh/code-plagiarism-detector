import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;


public class ChessB {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("chess.in"));
		int n = sc.nextInt();
		int a[] = new int[n];
		for (int i = 0;i<n;i++){
			a[i] = sc.nextInt();
		}
		sc.close();
		PrintWriter pw = new PrintWriter(new File("chess.out"));
		/*int i = 0;
		while(a[i]>=i+1){			
			if (i<n-1){
				i++;
			} else {
				break;
			}
		}*/
		int k = 1;
		for (int i = 1 ;i<n;i++){
			if (a[i]>=i + 1){
				k++;
			}
		}
		pw.println(k);
		for (int j = 1;j<=k;j++){
			pw.println(j+" "+j);
		}
		pw.close();
	}

}
