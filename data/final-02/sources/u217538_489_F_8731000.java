import java.io.*; 
import java.util.*; 

public class Main {
	BufferedReader in; 
	PrintWriter out;
	StringTokenizer st; 

	String next() {
		while (st==null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(in.readLine());
			} catch (Exception e) {}
		}
		return st.nextToken(); 
	}

	int nextInt() {
		return Integer.parseInt(next()); 
	}
	long nextLong() {
		return Long.parseLong(next()); 
	}
	
	public void run() throws Exception {
		in = new BufferedReader(new InputStreamReader(System.in));
		int n = nextInt(), m = nextInt();
		long mod = nextLong();
		int [] r = new int [n];

		for(int i = 0; i < m; ++i) {
			int ones = 0;
			String s = next();
		 	for(int j = 0; j < n; ++j)
		 	{
		 	 	int x = (int)s.charAt(j) - '0';
		 	 	ones += x;
		 	 	r[j] += x;
		 	}
		 	if(ones != 2) {
		 	 	System.out.println(0);
		 	 	System.exit(0);
		 	}
		}
		
		int one = 0, two = 0;
		
		for(int i = 0; i < n; ++i) {
		 	if(r[i] > 2) {
		 	 	System.out.println(0);
		 	 	System.exit(0);
		 	}
		 	if(r[i] == 1) one++;
		 	if(r[i] == 2) two++;
		}

		long [][][] dp = new long [2][n + 1][n + 1];

		dp[(m & 1)][one][two] = 1;
		for(int i = m; i < n; ++i) {
			
			int cur = (i & 1), next = 1 - cur;

			for(int k = 0; k <= n; ++k)
				for(int j = 0; j <= n; ++j)
					dp[next][j][k] = 0;

		 	for(int j = 0; j <= n; ++j)
		 		for(int k = 0; k <= n; ++k) {
		 		 	if(dp[cur][j][k] == 0) continue;
		 		 	int z = n - j - k;
		 		 	if(z < 0) break;
		 		 	if(z > 1 && j + 2 <= n) {
		 		 		long mul = ((z * (z - 1)) / 2) % mod;
		 		 	 	dp[next][j + 2][k] += (dp[cur][j][k] * mul) % mod;
		 		 	 	dp[next][j + 2][k] %= mod;
		 		 	}
		 		 	if(z > 0 && j > 0 && j + 1 <= n && k + 1 <= n) {
		 		 	 	long mul = (z * j) % mod;
		 		 	 	dp[next][j][k + 1] += (dp[cur][j][k] * mul) % mod;
		 		 	 	dp[next][j][k + 1] %= mod;
		 		 	}
		 		 	if(j > 1 && k + 2 <= n) {
		 		 		long mul = (j * (j - 1)) / 2;
		 		 		mul %= mod;
		 		 	 	dp[next][j - 2][k + 2] += (dp[cur][j][k] * mul) % mod;
		 		 	 	dp[next][j - 2][k + 2] %= mod;
		 		 	}
		 		}
		}
	      System.out.println(dp[(n&1)][0][n] % mod);
	}

	public static void main(String[] args) throws Exception {
		new Main().run(); 
	}
}