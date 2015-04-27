import java.io.*;
import java.util.*;
import java.math.*;

public class Main implements Runnable {
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;
	private Random rnd;
	
	final String filename = "codeforces";
	
	class Pair implements Comparable<Pair> {
		int val, howMuch;
		
		Pair(int val, int howMuch) {
			this.val = val;
			this.howMuch = howMuch;
		}
		
		public int compareTo(Pair another) {
			int howMuchDiff = this.howMuch - another.howMuch;
			
			if(howMuchDiff != 0) return -howMuchDiff;
			
			return (this.val - another.val);
		}
	}
	
	public void solve() throws IOException {
		HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
		
		int n = nextInt();
		
		for(int i = 0; i < n; i++) {
			int val = nextInt();
			
			int curVal = 0;
			if(map.containsKey(val)) curVal = map.get(val);
			
			map.put(val, curVal + 1);
		}
		
		PriorityQueue<Pair> t = new PriorityQueue<Pair>();
		
		for(int val : map.keySet()) {
			t.add(new Pair(val, map.get(val)));
		}
		
		int res = 0;
		int[][] resArray = new int[n][3];
		
		while(t.size() >= 3) {
			Pair first = t.poll();
			Pair second = t.poll();
			Pair third = t.poll();
			
			resArray[res][0] = first.val;
			resArray[res][1] = second.val;
			resArray[res][2] = third.val;
			
			if(first.howMuch > 1) {
				first.howMuch -= 1;
				t.add(first);
			}
			
			if(second.howMuch > 1) {
				second.howMuch -= 1;
				t.add(second);
			}
			
			if(third.howMuch > 1) {
				third.howMuch -= 1;
				t.add(third);
			}
			
			++res;
		}
		
		out.println(res);
		
		for(int i = 0; i < res; i++) {
			Arrays.sort(resArray[i]);
			
			out.println(resArray[i][2] + " " + resArray[i][1] + " " + resArray[i][0]);
		}
	}
		
	public static void main(String[] args) {
		new Main().run();
	} 
	
	public void run() {
		try {
			try {
				in = new BufferedReader(new FileReader(filename + ".in"));
				out = new PrintWriter(new FileWriter(filename + ".out"));
			} catch(FileNotFoundException e) {
				in = new BufferedReader(new InputStreamReader((System.in)));
				out = new PrintWriter(System.out);
			}
			
			st = null;
			rnd = new Random();
			
			solve();
			
			out.close();
		} catch(IOException e) {
			e.printStackTrace();
		}	
	}
	
	private String nextToken() throws IOException, NullPointerException {
		while(st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(in.readLine());
		}
		
		return st.nextToken();
	}
	
	private int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
	
	private long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}
	
	private double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

}