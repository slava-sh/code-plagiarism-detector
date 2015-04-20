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
			String str="";
			if(both%2==0){
				str="V";
			}else{
				str="P";
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
							out.println("Vasya");
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

	}
	
	public void run(){
		try{
			br=new BufferedReader(new FileReader("game.in"));
			out=new PrintWriter("game.out");
			solve();
			out.close();
		}catch (IOException e){
			e.printStackTrace();
			System.exit(1);
		}
	}
	
}
