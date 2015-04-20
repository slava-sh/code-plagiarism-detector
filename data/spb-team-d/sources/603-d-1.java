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
		int m=nextInt();
		long l[]=new long[n];
		long r[]=new long[n];
		long x[]=new long[n];
		long q[]=new long[m];
		long arr[]=new long[m];
		for(int i=0; i<n; i++){
			l[i]=nextLong();
			r[i]=nextLong();
			x[i]=nextLong();
		}
		for(int i=0; i<m; i++){
			q[i]=nextLong();
		}
		
		for(int i=0; i<m; i++){
			for(int g=0; g<n; g++){
				if(q[i]>=l[g] && q[i]<=r[g]){
					if(l[g]%2==q[i]%2){
						arr[i]=arr[i]+x[g];
					}else{
						arr[i]=arr[i]-x[g];
					}
				}
			}
		}
		
		for(int i=0; i<m; i++){
			out.println(arr[i]);
		}
		
	}
	
	public void run(){
		try{
			br=new BufferedReader(new FileReader("dunes.in"));
			out=new PrintWriter("dunes.out");
			solve();
			out.close();
		}catch (IOException e){
			e.printStackTrace();
			System.exit(1);
		}
	}

}
