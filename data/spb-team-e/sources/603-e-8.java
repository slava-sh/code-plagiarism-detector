
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;
 
 
public class Main {
 
    BufferedReader br;
    StringTokenizer in;
    PrintWriter out;
    public String nextToken() throws IOException{
        while(in==null || !in.hasMoreTokens()){
            in=new StringTokenizer(br.readLine());
        }
        return in.nextToken();
    }
         
    public int nextInt() throws IOException{
        return Integer.parseInt(nextToken());
    }
     
    public double nextDouble() throws IOException{
        return Double.parseDouble(nextToken());
    }
     
    public long nextLong() throws IOException{
        return Long.parseLong(nextToken());
    }
     
    public static void main(String[] args) throws IOException{
        new Main().run();
    }
     
    public void solve() throws IOException{
        int n=nextInt();
        long m=nextLong();
        long l1=nextLong();
        long l2=nextLong();
        long l3=nextLong();
        long l4=nextLong();
        long h[]=new long[n];
        long both=0;
        long p=0;
        long v=0;
        for(int i=0; i<n; i++){
            h[i]=nextLong();
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
            m=m-both;
            if(v+p<=m){
            	if(both%2==0){
            		if(v>p){
            			out.println("Vasya");
            		}else{
            			if(v==p){
            				out.println("Draw");
            			}else{
            				out.println("Petya");
            			}
            		}
            	}else{
               		if(v>p+1){
            			out.println("Vasya");
            		}else{
            			if(v==p+1){
            				out.println("Draw");
            			}else{
            				out.println("Petya");
            			}
            		}
            	}
            }else{
            	int l=0;
            	if(both%2==0){
            		l=1;
            	}
            	while(m!=0){
            		if(p!=0){
            			if(v!=0){
            				if(l==1){
            					p--;
            				}else{
            					v--;
            				}
            				m--;
            			}else{
            				out.println("Petya");
            			}
            		}else{
            			if(v!=0){
            				if(both%2==1){
            					if(p+1==v){
            						out.println("Draw");
            					}else{
            						out.println("Vasya");
            					}
            				}else{
            					out.println("Vasya");
            				}
            			}else{
            				out.println("Draw");
            			}
            		}
            	}
            }
        }
 
    }
     
    public void run(){
        try{
            br=new BufferedReader(new FileReader("game.in"));
            out=new PrintWriter(System.out);
            solve();
            out.close();
        }catch (IOException e){
            e.printStackTrace();
            System.exit(1);
        }
    }
     
}