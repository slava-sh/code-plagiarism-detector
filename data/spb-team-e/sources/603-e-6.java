import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;



public class exE {
	public static void main (String[]args) throws FileNotFoundException{
		Scanner sc = new Scanner(new File("game.in"));
		PrintWriter out = new PrintWriter("game.out");
		int n = sc.nextInt();
		int m = sc.nextInt();
		int l1 = sc.nextInt();
		int l2 = sc.nextInt();
		int l3 = sc.nextInt();
		int l4 = sc.nextInt();
		int m1 = l2-l1+1;
		int m2 = l4-l3+1;
		int both = l2-l3+1;
		boolean flag = true;
		
		if(l1>l3){
			flag = false;
			int t = m1;
			m1=m2;
			m2=t;
			both=l3-l2+1;
		}
		int p = 0;
		int v = 0;
		if(both<0){
			both = 0;
		}
		
		
		
		if(m<both){
			if(m%2==0){
				out.println("Draw");
			}else{
				if(flag==true){
				out.println("Petya");
				}else{
					out.println("Vasya");
				}
			}
		}else{
			int k = m-both;
			int n1=0;
			int n2=0;
			if(both%2==0){
				p=both/2;
				v=both/2;
				if(k%2==0){
					n1=k/2;
					n2 = k/2;
				}else{
					n1= k/2+1;
					n2 = k/2;
				}
			}else{
				p= both/2+1;
				v = both/2;
				if(k%2==0){
					n1=k/2;
					n2 = k/2;
				}else{
					n2= k/2+1;
					n1 = k/2;
				}
			}

			m1 = m1-both;
			m2 = m2-both;
			

			if(n1>=m1){

				p+=m1;
				v+=(k-m1);

			}else{
				if(n2>=m2){
					v+=m2;
					p+=k-m2;
				}else{
					v+=n1;
					p+=n2;
				}

			}

			if(p>v){
				if(flag==true){
				out.println("Petya");
				}else{
					out.println("Vasya");
				}
			}else{
				if(v>p){
					if(flag ==true){
				out.println("Vasya");
					}else{
						out.println("Petya");
					}
				}else{
					out.println("Draw");
				}
			}
				
		}
		
		out.close();
	}

}
