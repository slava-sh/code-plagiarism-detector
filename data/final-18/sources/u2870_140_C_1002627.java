//package round100;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class C {

	static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static PrintWriter out = new PrintWriter(System.out);
	
	static String nextToken() throws IOException{
		while (st==null || !st.hasMoreTokens()){
			String s = bf.readLine();
			if (s == null)
				return null;
			st = new StringTokenizer(s);
		}
		
		return st.nextToken();
	}
	
	static int nextInt() throws IOException{
		return Integer.parseInt(nextToken());
	}
	
	static long nextLong() throws IOException{
		return Long.parseLong(nextToken());
	}
	
	static String nextStr() throws IOException{
		return nextToken();
	}
	
	static double nextDouble() throws IOException{
		return Double.parseDouble(nextToken());
	}
	
	static BigInteger nextBigInt() throws IOException{
		return new BigInteger(nextToken());
	}
	
	public static void main(String[] args) throws IOException{
		int n = nextInt();
		Map<Integer, Integer> map = new HashMap<Integer, Integer>();
		for (int i = 0; i < n; i++) {
			int a = nextInt();
			Integer c = map.get(a);
			if (c == null) {
				map.put(a, 1);
			} else {
				map.put(a, c + 1);
			}
		}
		
		
		
		PriorityQueue<Pair> pq = new PriorityQueue<Pair>();
		ArrayList<Triple> res = new ArrayList<Triple>();
		
		for (int a: map.keySet()) {
			pq.add(new Pair(a, map.get(a)));
		}
		
		while (pq.size() >= 3) {
			Pair p1 = pq.poll();
			Pair p2 = pq.poll();
			Pair p3 = pq.poll();
			
			res.add(new Triple(p1.val, p2.val, p3.val));
			p1.num--;
			if (p1.num > 0) {
				pq.add(p1);
			}
			
			p2.num--;
			if (p2.num > 0) {
				pq.add(p2);
			}
			
			p3.num--;
			if (p3.num > 0) {
				pq.add(p3);
			}
		}
		
		out.println(res.size());
		for (Triple t: res) {
			out.println(t.a + " " + t.b + " " + t.c);
		}
		out.flush();
	}
	
	static class Pair implements Comparable<Pair>{
		int val;
		int num;
		
		Pair(int v, int n) {
			val = v;
			num = n;
		}
		
		@Override
		public int compareTo(Pair p) {
			return p.num - num;
		}
	}
	
	static class Triple {
		int a;
		int b;
		int c;
		
		Triple(int p, int q, int r) {
			a = Math.max(Math.max(p, q), r);
			c = Math.min(Math.min(p, q), r);
			if (a == p) {
				b = Math.max(q, r);
			} else if (a == q) {
				b = Math.max(p, r);
			} else {
				b = Math.max(p, q);
			}
		}
	}
}
