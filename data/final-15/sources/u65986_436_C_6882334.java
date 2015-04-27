import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Vadim Semenov
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int rows = in.nextInt();
        int columns = in.nextInt();
        int counter = in.nextInt();
        int cost = in.nextInt();
        int mul = rows * columns;
        int[][] levels = new int[counter][mul];
        for (int i = 0; i < counter; i++) {
            int ptr = 0;
            for (int x = 0; x < rows; x++) {
                char[] cur = in.next().toCharArray();
                for (char ch : cur) levels[i][ptr++] = ch;
            }
        }
        distance = new int[counter][counter];
        List<Integer> good = new ArrayList<>();
        int[] count = new int[mul + 1];
        for (int i = 0; i < counter; i++) {
            for (int j = 0; j < i; j++) {
                int diff = 0;
                for (int x = 0; x < mul; x++)
                    if (levels[i][x] != levels[j][x]) diff++;
                distance[i][j] = distance[j][i] = cost * diff;
                if (distance[i][j] < mul) {
                    good.add(i * counter + j);
                    count[distance[i][j]]++;
                }
            }
            distance[i][i] = mul;
        }
        int idx = 0;
        for (int i = 0; i < count.length; i++) {
            int temp = count[i];
            count[i] = idx;
            idx += temp;
        }
        if (idx != good.size()) throw new AssertionError(idx + " " + good.size());
        int[] sorted = new int[good.size()];
        for (int i : good) {
            int x = i / counter;
            int y = i % counter;
            sorted[count[distance[x][y]]++] = i;
        }
        DSU dsu = new DSU(counter);
        int[] best = new int[counter];
        Arrays.fill(best, -1);
        boolean[] used = new boolean[counter];
        List<Integer>[] outgoing = new List[counter];
        for (int i = 0; i < counter; i++) outgoing[i] = new ArrayList<>();
        for (int i = 0; i < sorted.length; i++) {
            int x = sorted[i] / counter;
            int y = sorted[i] % counter;
            int px = dsu.get(x);
            int py = dsu.get(y);
            if (px == py) continue;
            outgoing[x].add(y);
            outgoing[y].add(x);
            dsu.union(px, py);
        }
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < counter; i++) if (!used[i]) {
            if (outgoing[i].size() > 0) {
                answer += mul;
                dfs(i, outgoing, used, -1, result);
            } else {
                answer += mul;
                used[i] = true;
                result.append((i + 1) + " 0\n");
            }
        }
        out.println(answer);
        out.print(result);
    }
    int[][] distance;
    int answer;

    private void dfs(int vertex, List<Integer>[] outgoing, boolean[] used, int parent, StringBuilder result) {
        result.append((vertex + 1) + " " + (parent + 1));
        result.append("\n");
        used[vertex] = true;
        for (int to : outgoing[vertex]) if (!used[to]) {
            answer += distance[vertex][to];
            dfs(to, outgoing, used, vertex, result);
        }
    }

    class DSU {
        int[] parent;
        int[] weight;

        DSU (int size) {
            parent = new int[size];
            weight = new int[size];
            for (int i = 0; i < size; i++) parent[i] = i;
        }

        int get(int v) {
            return parent[v] == v ? v : (parent[v] = get(parent[v]));
        }

        void union(int v, int u) {
            int pv = get(v);
            int pu = get(u);
            if (pv == pu) return;
            if (weight[pv] < weight[pu]) { int t = pu; pu = pv; pv = t; }
            if (weight[pv] == weight[pu]) weight[pv]++;
            parent[pu] = pv;
        }
    }
}

class InputReader {
    private final BufferedReader reader;
    private StringTokenizer tokenizer;

    public InputReader(InputStream in) {
        reader = new BufferedReader(new InputStreamReader(in));
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(readLine());
        }
        return tokenizer.nextToken();
    }

    public String readLine() {
        String line = null;
        try {
            line = reader.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return line;
    }
}

