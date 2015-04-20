import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class exxJ {

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
		new exxJ().run();
	}
	
	public void solve() throws IOException{
		int n = nextInt();
		int h = nextInt();
		int arr[] = new int[n];
		long min = 1000000000;
		min = min*min;
		long y = min;
		
		for(int i = 0; i<n; i++){
			arr[i] = nextInt();
		}
		for(int i = 0; i<=n-h; i++){
			if(arr[i]==1 || arr[i]==0){
				long sum = 0;
				for(int j = i; j<i+h; j++){
					if(arr[j]<=j-i+1){
						sum+=j-i+1-arr[j];
					}else{
						sum = min+1;
						break;
					}
				}
				if(sum<min){
					min = sum;
				}
			}
		}
		if(min == y){
			out.println(-1);
		}else{
			out.println(min);
		}
		
	}
	
	public void run(){
		try{
			br=new BufferedReader(new FileReader("seq.in"));
			out=new PrintWriter("seq.out");
			solve();
			out.close();
		}catch (IOException e){
			e.printStackTrace();
			System.exit(1);
		}
	}

}
