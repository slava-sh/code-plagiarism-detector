import java.io.IOException;
import java.io.InputStreamReader;
import java.io.FileReader;
import java.util.PriorityQueue;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.AbstractCollection;
import java.io.Writer;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Agostinho Junior (junior94)
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
	OutputWriter out;
	InputReader in;
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		this.in = in; this.out = out;
		int n = in.readInt();
		int m = in.readInt();
		int k = in.readInt();
		int w = in.readInt();
		boolean[] visited = new boolean[k + 1];
		char[][][] grid = new char[k + 1][n][];
		for (int i = 1; i <= k; i++) {
			for (int j = 0; j < n; j++) {
				grid[i][j] = in.readLine().toCharArray();
			}
		}
		PriorityQueue<Node> queue = new PriorityQueue<>();
		queue.add(new Node(0, 1, 0));
		StringBuffer ans = new StringBuffer();
		int total = n * m;
		while (!queue.isEmpty()) {
			Node node = queue.poll();
			int index = node.index;
			if (!visited[index]) {
				visited[index] = true;
				if (index == 1) {
					ans.append("1 0\n");
				} else {
					if (node.cost < n * m) {
						total += node.cost;
						ans.append(String.format("%d %d\n", node.index, node.parent));
					} else {
						total += n * m;
						ans.append(String.format("%d 0\n", node.index));
					}
				}
				for (int i = 1; i <= k; i++) if (!visited[i]) {
					int cost = 0;
					for (int a = 0; a < n; a++) {
						for (int b = 0; b < m; b++) {
							if (grid[index][a][b] != grid[i][a][b]) {
								cost++;
							}
						}
					}
					queue.add(new Node(index, i, cost * w));
				}
			}
		}
		out.printfln("%d\n%s", total, ans);
	}
}

class Node implements Comparable<Node> {
	final int parent;
	final int index;
	final int cost;
	public Node(int parent, int index, int cost) {
		this.parent = parent;
		this.index = index;
		this.cost = cost;
	}
	public int compareTo(Node other) {
		return cost - other.cost;
	}
	public String toString() {
		return String.format("parent: %d, index: %d, cost: %d", parent, index, cost);
	}
}

class OutputWriter {
	private PrintWriter output;
	public OutputWriter() {
		this(System.out);
	}
	public OutputWriter(OutputStream out) {
		output = new PrintWriter(out);
	}
	public OutputWriter(Writer writer) {
		output = new PrintWriter(writer);
	}

	public void printfln(String format, Object... o) {
		output.printf(format + "\n", o);
	}

	public void close() {
		output.close();
	}
}

class InputReader {
	private BufferedReader input;
	private StringTokenizer line = new StringTokenizer("");
	public InputReader() {
		this(System.in);
	}
	public InputReader(InputStream in) {
		input = new BufferedReader(new InputStreamReader(in));
	}
	public InputReader(String s) {
		try {
			input = new BufferedReader(new FileReader(s));
		} catch(IOException io) { io.printStackTrace(); System.exit(0);}
	}
	public void fill() {
		try {
			if(!line.hasMoreTokens()) line = new StringTokenizer(input.readLine());
		} catch(IOException io) { io.printStackTrace(); System.exit(0);}
	}

	public int readInt() {
		fill();
		return Integer.parseInt(line.nextToken());
	}

	public String readLine() {
		String s = "";
		try {
			s = input.readLine();
		} catch(IOException io) {io.printStackTrace(); System.exit(0);}
		return s;
	}
}

