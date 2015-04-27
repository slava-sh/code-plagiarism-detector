import java.util.*;
import java.io.*;


public class Main {
	public static void main(String[] args) throws IOException{
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		
		//InputStream inputStream = new FileInputStream("input.txt");
		//OutputStream outputStream = new FileOutputStream("output.txt");
		
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		
		TaskB solver = new TaskB();
		solver.solve(in, out);
		
		
		out.close();
	}
}

class TaskB {
    public void solve(InputReader in, OutputWriter out) {
    	
    	int n = in.nextInt(), m = in.nextInt();
    	char[] type = new char[m];
    	int[] ind = new int[m];
    	for(int i=0; i<m; i++){
    		type[i] = in.next().charAt(0);
    		ind[i] = in.nextInt()-1;
    	}
    	
    	int cur=0;
    	int[] last = new int[n];
    	for(int i=0; i<m; i++){
    		if(type[i]=='-' && last[ind[i]]==0)
    			cur++;
    		if(type[i]=='+')
    			last[ind[i]] = i+1;
    	}
    	
    	boolean[] f = new boolean[n];
    	Arrays.fill(f, true);
    	boolean[] g = new boolean[n];
    	int cnt=0;
    	for(int i=0; i<m; i++){
    		if(type[i]=='+'){
    			if(cur>0) f[ind[i]]=false;
    			cur++;
    			if(cur==1) { if(!g[ind[i]]) cnt++;g[ind[i]]=true; }
    		}else{
    			if(cur>1) f[ind[i]]=false;
    			if(cur==1) { if(!g[ind[i]]) cnt++;g[ind[i]]=true;  }
    			cur--;
    		}
    	}
    	if(cnt>1){
    		for(int i=0; i<n; i++)
    			if(g[i]) f[i]=false;
    	}
    	
    	int ans=0;
    	for(int i=0; i<n; i++)
    		if(f[i]) ans++;
    	out.writeln(ans);
    	for(int i=0; i<n; i++)
    		if(f[i]) out.write((i+1)+" ");
    }
 
}

class InputReader{
	
	BufferedReader reader;
	StringTokenizer tokenizer;
	
	public InputReader(InputStream stream){
		tokenizer = null;
		reader = new BufferedReader(new InputStreamReader(stream));
	}
	
	public String next(){
		while(tokenizer==null || !tokenizer.hasMoreTokens()){
			try {
				tokenizer = new StringTokenizer(reader.readLine());
			} catch (IOException e) {
				throw new RuntimeException();
			}
		}
		
		return tokenizer.nextToken();
	}
	
	public String nextLine(){
		tokenizer = null;
		try {
			return reader.readLine();
		} catch (IOException e) {
			throw new RuntimeException();
		}
	}
	
	public int nextInt(){
		return Integer.parseInt(next());
	}
	
	public long nextLong(){
		return Long.parseLong(next());
	}
	
	public int[] nextIntArray(int n){
		int[] res = new int[n];
		for(int i=0; i<n; i++)
			res[i] = nextInt();
		
		return res;
	}
	
}

class OutputWriter{
	
	PrintWriter out;
	
	public OutputWriter(OutputStream stream){
		out = new PrintWriter(new BufferedWriter(
				new OutputStreamWriter(stream)));
	}
	
	public void write(Object ...o){
		for(Object cur : o)
			out.print(cur);
	}
	
	public void writeln(Object ...o){
		write(o);
		out.println();
	}
	
	public void flush(){
		out.flush();
	}
	
	public void close(){
		out.close();
	}
	
}
	
