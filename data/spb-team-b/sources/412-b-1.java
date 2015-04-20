import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;


public class ChessB {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("chess.in"));
		PrintWriter pw = new PrintWriter(new File("chess.out"));
		int n = sc.nextInt();
		int a[] = new int[n];
		for (int i = 0;i<n;i++){
			a[i] = sc.nextInt();
		}
		int i = 1;
		while(a[i]>=i){			
			i++;
		}
		pw.println(i);
		for (int j = 1;j<=i;j++){
			pw.println(j+" "+j);
		}
		pw.close();
	}

}
