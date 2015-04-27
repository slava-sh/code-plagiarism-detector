import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class Main {
	
	public static void main(String[] args) throws IOException{
		
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		
		TaskA solver = new TaskA();
		solver.solve(in, out);
		
		out.close();
		
	}

}

class TaskA{
	
	public void solve(InputReader in, OutputWriter out){
		
		
		int L = in.nextInt();
		s = in.nextLine();
		int n = s.length();
		/*
		boolean flag=false;
		int i;
		for(i=0; i<L && i<n; i++){
			boolean f=n%(i+1)==0;
			int i1=0, i2 = i;
			for(int j=i+1; j+i<n && f; j+=i+1){
				f&=equals(i1,i2,j,j+i);
			}
			if(f){
				//System.out.println(i1+" "+i2);
				flag=true;
				break;
			}
		}
		
		if(flag){
			out.writeln(1);
			out.write(s.substring(0,i+1));
			return;
		}
		
		*/
		
		int aI1=-1,aI2=0,aI3=0,aI4=0;
		for(int i=0; i<L; i++){
			int[] p = pf(s.substring(0,i+1)+"#"+s);
			
			/*
			for(int j=0; j<p.length; j++)
				System.out.print(p[j]+" ");
			System.out.println();
			*/
	
			int j1;
			for(j1=2*(i+1); j1<p.length; j1+=i+1){
				if(p[j1]!=i+1) break; 
			}
			
			int j2;
			for(j2=j1; j2<p.length; j2++)
				if(p[j2]==i+1) break;
			
			
			
			j1-=i+2; j2-=i+2;
			
			
			if(j1-i>=n){
				j1=j2=n;
			}else if(j2>=n){
				j1-=i; j2=n-1;
			}else{
				j1-=i; j2-=i+1;
			}
			
			//j1-=i; if(j2!=n+i+2) j2-=i+1; else j2--;
			//j2 = Math.max(j2,j1);
			
			
			
			//if(n%(i+1)!=0 && j1>=n) { j1=n-n%(i+1); j2=n; }
			//if(j1>n) { j1=j2=n; }
			
			
			int i1=0,i2=i,i3=j1,i4=j2;
			int len1=i2-i1+1, len2=i4-i3+1;
			
			if(j1<n && j2<n){
				p = pf(s.substring(j1,j2+1));
				if(len2-p[len2-1]!=0 && len2%(len2-p[len2-1])==0){
					j2 = j1+len2-p[len2-1]-1;
					i3 = j1; i4 = j2;
				}
				
				len2 = i4-i3+1;
			}
			
			
			if(!(i1>=0 && i1<n && i2>=0 && i2<n && len1>=0 && len1<=L && len2>=0 && len2<=L)){
				continue;
			}
			
			//System.out.println(i1+" "+i2+" "+i3+" "+i4);
			boolean flag=true;
			for(int j=0; j<n; ){
				if(j+len1<=n && equals(i1,i2,j,j+len1-1)){
					j+=len1;
					continue;
				}else if(j+len2<=n && equals(i3,i4,j,j+len2-1)){
					j+=len2; 
					continue;
				}else{
					flag=false;
					break;
				}
					
			}
			
			if(flag){
				if(i3==n){
					out.writeln(1);
					out.writeln(s.substring(i1, i2+1));
					return;
				}else if(len1<=L && len2<=L){;
					aI1=i1; aI2=i2+1; aI3=i3; aI4=i4+1;
				}
			}
			
		}
		if(aI1!=-1){
			out.writeln(2);
			out.writeln(s.substring(aI1,aI2));
			out.writeln(s.substring(aI3,aI4));
		}else{
			out.writeln(3);
			out.writeln("a");
			out.writeln("b");
			out.writeln("c");
		}
		
		
		

	}
	
	int[] pf(String s){
		int n = s.length();
		int[] ans = new int[n];
		for(int i=1; i<n; i++){
			int j = ans[i-1];
			while(j>0 && s.charAt(i)!=s.charAt(j))
				j = ans[j-1];
			

			if(s.charAt(i)==s.charAt(j)) j++;
			ans[i] = j;
		}
		return ans;
	}
	
	boolean equals(int i1, int j1, int i2, int j2){
		int len = j1-i1+1;
		for(int i=0; i<len; i++)
			if(s.charAt(i1+i)!=s.charAt(i2+i)) return false;
		
		return true;
	}
	String s;
}

class InputReader{
	
	public InputReader(InputStream inputStream){
		reader = new BufferedReader(new InputStreamReader(inputStream));
		tokenizer = null;
	}
	
	public String next(){
		while(tokenizer==null || !tokenizer.hasMoreTokens()){
			try {
				tokenizer = new StringTokenizer(reader.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		
		return tokenizer.nextToken();
	}
	
	public String nextLine(){
		
		tokenizer = null;
		try {
			return reader.readLine();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}
	
	public int nextInt(){
		return Integer.parseInt(next());
	}
	
	public int[] nextIntArr(int n){
		int[] ans = new int[n];
		for(int i=0; i<n; i++)
			ans[i] = nextInt();
		
		return ans;
	}
	
	BufferedReader reader;
	StringTokenizer tokenizer;
}

class OutputWriter{
	
	public OutputWriter(OutputStream outputStream){
		
		out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
	}
	
	public void write(Object ...o){
		for(Object x : o)
			out.print(x);
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
	
	PrintWriter out;
}
