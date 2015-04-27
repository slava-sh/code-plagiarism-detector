import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.LinkedList;
import java.util.StringTokenizer;


public class C {
	
	static class Scanner{
		BufferedReader rd = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tk;
		public Scanner(){
			rd = new BufferedReader(new InputStreamReader(System.in));
		}
		String next() throws IOException{
			while(tk == null  || !tk.hasMoreTokens())
				tk = new StringTokenizer(rd.readLine());
			return tk.nextToken();
		}
		int nextInt() throws NumberFormatException, IOException{
			return Integer.valueOf(next());
		}
		long nextLong() throws NumberFormatException, IOException{
			return Long.valueOf(next());
		}
		double nextDouble() throws NumberFormatException, IOException{
			return Double.valueOf(next());
		}
	}
	
	static class Node{
		int id;
		LinkedList<Edge> v;
		boolean visited;
		public Node(int a){
			id = a;
			v = new LinkedList<Edge>();
			visited = false;
		}
	}
	
	
	static int print(int idx, int parent){
		if (ns[idx].visited)
			return 0;
		ns[idx].visited = true;
		sb.append((idx+1) + " " + (parent+1) + "\n");
		int ret = 0;
		for(Edge e: ns[idx].v){
			int h = e.a;
			int w = e.w;
			if (h == parent)
				continue;
			ret += print(h, idx) + w;
		}
		return ret;
	}
	
	
	static class Edge implements Comparable<Edge>{
		int w;
		int a,b;
		public Edge(int aa, int bb, int ww){
			a = aa;
			b = bb;
			w = ww;
		}
		@Override
		public int compareTo(Edge o) {
			return w - o.w;
		}
	}
	
	static int diff(int a, int b){
		char[][] t1 = mazes[a];
		char[][] t2 = mazes[b];
		int diff =0;
		for(int i = 0; i < N; i++)
			for(int j = 0; j < M; j++)
				if (t1[i][j] != t2[i][j])
					diff++;
		return diff * W;
	}
	
	static int N, M, K, W;
	static char[][][] mazes;
	static int[] parent;
	static Node[] ns; 
	static StringBuilder sb;
	
	static int find(int x){
		if (x != parent[x])
			parent[x] = find(parent[x]);
		return parent[x];
	}
	
	static void merge(int a, int b){
		parent[find(a)] = find(b);
	}
	
	public static void main(String args[]) throws NumberFormatException, IOException{
		Scanner sc = new Scanner();
		N = sc.nextInt();
		M = sc.nextInt();
		K = sc.nextInt();
		W = sc.nextInt();
		mazes = new char[K][N][];
		for(int k = 0; k < K; k++)
			for(int i = 0; i < N; i++)
				mazes[k][i] = sc.next().toCharArray();
		LinkedList<Edge> es = new LinkedList<Edge>();
		for(int i = 0; i < K; i++)
			for(int j = i + 1; j < K; j++)
				es.add(new Edge(i, j, diff(i,j)));
		Collections.sort(es);
		parent = new int[K];
		for(int i = 0; i < K; i++)
			parent[i] = i;
		int worst = N * M;
		ns = new Node[K];
		for(int i = 0; i < K; i++)
			ns[i] = new Node(i);
		for(Edge e: es){
			if (e.w >= worst)
				break;
			if (find(e.a) == find(e.b))
				continue;
			merge(e.a, e.b);
			Edge tmp = new Edge(e.b, e.a, e.w);
			ns[e.a].v.add(tmp);
			tmp = new Edge(e.a, e.b, e.w);
			ns[e.b].v.add(tmp);
		}
		int costo = 0;
		sb = new StringBuilder();
		for(int i = 0; i < K; i++)
			if (!ns[i].visited)
				costo += print(i, -1) + worst;
		System.out.println(costo);
		System.out.print(sb.toString());
	}

}
