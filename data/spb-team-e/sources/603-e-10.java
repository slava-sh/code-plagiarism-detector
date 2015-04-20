
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;
 
 
 
public class exE {
    public static void main (String[]args) throws FileNotFoundException{
        Scanner sc = new Scanner(new File("game.in"));
        PrintWriter out = new PrintWriter("game.out");
        int n=sc.nextInt();
		long m=sc.nextLong();
		long l1=sc.nextLong();
		long l2=sc.nextLong();
		long l3=sc.nextLong();
		long l4=sc.nextLong();
		long h[]=new long[n];
		long both=0;
		long p=0;
		long v=0;
		for(int i=0; i<n; i++){
			h[i]=sc.nextLong();
			if(h[i]<=l2 && h[i]>=l1){
				if(h[i]<=l4 && h[i]>=l3){
					both++;
				}else{
					p++;
				}
			}else{
				if(h[i]<=l4 && h[i]>=l3){
					v++; 
				}
			}
		}
		
		if(m<=both){
			if(m%2==0){
				out.println("Draw");
			}else{
				out.println("Petya");
			}
		}else{
			String str="";
			if(both%2==0){
				str="V";
				p=p-both/2;
				v=v-both/2;
			}else{
				str="P";
				p=p-(both+1)/2;
				v=v-(both-1)/2;
			}
			m=m-both;
			while(m!=0){
				if(p==0){
					if(v==0){
						if(str=="V"){
							out.println("Draw");
						}else{
							out.println("Petya");
						}
					}else{
						if(v==p+1 && str.equals("P")){
							out.println("Draw");
						}else{
							if(m==1){
								out.println("Petya");	
							}else{
								out.println("Vasya");
							}
						}
					}
					break;
				}
				if(v==0){
					out.println("Petya");
					break;
				}
				if(str.equals("P")){
					v--;
					str="V";
				}else{
					p--;
					str="P";
				}
				m--;
			}
			
			if(m==0){
				if(str.equals("P")){
					out.println("Petya");
				}else{
					out.println("Draw");
				}
			}
		
		}

         
        out.close();
    }
 
}