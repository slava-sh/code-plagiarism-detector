
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
        int m1 = 0;
        int m2 = 0;
        int both = 0;
        
        
        long h[] = new long[n];
        for(int i=0; i<n; i++){
            h[i]=sc.nextLong();
            if(h[i]<=l2 && h[i]>=l1){
                if(h[i]<=l4 && h[i]>=l3){
                    both++;
                }else{
                    m1++;
                }
            }else{
                if(h[i]<=l4 && h[i]>=l3){
                    m2++; 
                }
            }
        }
        
        
        
        
        
       
        int p = 0;
        int v = 0;
       
         
         
         
        if(m<both){
            if(m%2==0){
                out.println("Draw");
            }else{
                out.println("Petya");
               
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

                out.println("Petya");
             
            }else{
                if(v>p){
 
                out.println("Vasya");
                   
                }else{
                    out.println("Draw");
                }
            }
                 
        }
         
        out.close();
    }
 
}