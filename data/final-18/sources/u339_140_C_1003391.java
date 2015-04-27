import java.io.*;
import java.math.*;
import java.util.*;
import java.awt.geom.*;

import static java.lang.Math.*;

public class Solution implements Runnable {
	
	class State implements Comparable <State> {
		int value, count;
		public State(int value, int count) {
			this.value = value;
			this.count = count;
		}
		@Override
		public int compareTo(State o) {
			if (this.count > o.count) return -1;
			if (this.count < o.count) return 1;
			return this.value - o.value;
		}
	}

	HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
	
	int asize = 0;
	
	int answer [][];
	
	TreeSet<State> set = new TreeSet<Solution.State>();
	
	public void solve() throws Exception {
		int n = nextInt();
		answer = new int [n][3];
		for (int i = 0; i < n; i++) {
			int value = nextInt();
			if (!map.containsKey(value)) {
				map.put(value, 1);
			} else {
				int vl = map.get(value);
				map.put(value, vl + 1);
			}
		}
		for (Integer key : map.keySet()) {
			int value = map.get(key);
			set.add(new State(key, value));
		}
		boolean flag = false;
		while (true) {
			ArrayList<State> toAdd = new ArrayList<Solution.State>();
			ArrayList<Integer> ints = new ArrayList<Integer>();
			for (int i = 0; i < 3; i++) {
				if (set.size() == 0) {
					flag = true;
					break;
				}
				State first = set.pollFirst();
				first.count--;
				toAdd.add(first);
				ints.add(first.value);
			}
			if (flag) break;

			Collections.sort(ints);
			for (int i = 2; i >= 0; i--)
				answer[asize][2-i] = ints.get(i);
			asize++;
			for (int i = 0 ; i < 3; i++) {
				if (toAdd.get(i).count > 0) {
					set.add(toAdd.get(i));
				}
			}
		}
		out.println(asize);
		for (int i = 0; i < asize; i++) {
			for (int j = 0; j < 3; j++) {
				out.print(answer[i][j]+" ");
			}
			out.println();
		}
	}
	
		
	/********************************************************************************************/
	/* THERE IS INPUT */

	BufferedReader in;
	PrintWriter out;
	StringTokenizer st;

	long stime=0;
	
	private String next() throws Exception {
		while (st == null || !st.hasMoreElements())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}

	private int nextInt() throws Exception {
		return Integer.parseInt(next());
	}

	private long nextLong() throws Exception {
		return Long.parseLong(next());
	}

	private double nextDouble() throws Exception {
		return Double.parseDouble(next());
	}
	
	public void run() {
		try {
			//Locale.setDefault(Locale.US);
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(new OutputStreamWriter(System.out));
			//in = new BufferedReader(new FileReader(fname+".in"));
			//out = new PrintWriter(new FileWriter(fname+".out"));
			solve();
		} catch (Exception ex) {
			throw new RuntimeException(ex);
		} finally {
			out.close();
		}
	}
	
	public static void main(String[] args) throws Exception {
		new Thread(null, new Solution(), "", 1 << 25).start();
	}

	
}
