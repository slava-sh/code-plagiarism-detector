import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class A {
	public static void main(String[] args) throws FileNotFoundException{
		Scanner sc = new Scanner(new File("abcd.in"));
		PrintWriter out = new PrintWriter("abcd.out");
		int t = sc.nextInt();
		sc.nextLine();
		for(int i = 0;i<t;i++){
			String s = sc.nextLine();
			int a = Integer.parseInt(s.substring(0,2));
			int b = Integer.parseInt(s.substring(2,4));
			long c = a*a + b*b;
			if(c%7 == 1){
				out.println("YES");
			}else{
				out.println("NO");
			}
		}
		sc.close();
		out.close();
	}
}
