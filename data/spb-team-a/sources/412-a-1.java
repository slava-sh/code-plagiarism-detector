import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class a {
	public static void main(String[] args) throws FileNotFoundException{
		Scanner sc = new Scanner(new File("abcd.in"));
		PrintWriter pw = new PrintWriter(new File("abcd.out"));
		int n = sc.nextInt();
		
		for(int i = 0; i < n; i++){
			int a = sc.nextInt();
			if(((a/100)*(a/100) + (a%100)*(a%100))%7 == 1){
				pw.println("YES");
			}else{
				pw.println("NO");
			}
		}
		pw.close();
	}

}
