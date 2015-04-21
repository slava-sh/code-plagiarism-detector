import java.io.*;
import java.util.*;

public class Main {
    private static ArrayList<Edge>[] G;

    private static class Edge implements Comparable<Edge> {
        int to, temperature;
        public Edge(int to, int temp) {
            this.to = to;
            temperature = temp;
        }

        @Override
        public int compareTo(Edge o) {
            if (temperature < o.temperature) return -1;
            if (temperature > o.temperature) return 1;
            else return 0;
        }
    }

    private static class FastReader {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        public FastReader(InputStream inputStream) {
            reader = new BufferedReader(new InputStreamReader(inputStream), 1 << 16);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                }
                catch (IOException ex) {
                    throw new RuntimeException(ex);
                }
            }
            return tokenizer.nextToken();
        }

        public String nextLine() {
            try {
                return reader.readLine();
            }
            catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) {
	    FastReader in = new FastReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt(), m = in.nextInt(), d = in.nextInt();
        G = new ArrayList[n];
        for (int i = 0; i < n; ++i) {
            G[i] = new ArrayList<Edge>();
        }
        for (int i = 0; i < m; i++) {
            int from = in.nextInt(), to = in.nextInt(),
                temp = in.nextInt();
            --from; --to;
            G[from].add(new Edge(to, temp));
            G[to].add(new Edge(from, temp));
        }
        int Q = in.nextInt();
        for (int q = 0; q < Q; ++q) {
            int a = in.nextInt() - 1, b = in.nextInt() - 1;
            out.println(bfs(a, b, d));
        }

        out.flush();
    }

    private static int bfs(int a, int b, int delta) {
        Queue<Integer> vertices = new ArrayDeque<Integer>();
        vertices.add(a);
        Queue<Integer> temperatures = new ArrayDeque<Integer>();
        temperatures.add(Integer.MAX_VALUE);
        Queue<Integer> distances = new ArrayDeque<Integer>();
        distances.add(0);
        Set<ArrayList<Integer>> used = new HashSet<ArrayList<Integer>>();
        while (!vertices.isEmpty()) {
            int vertex = vertices.remove(),
                temp   = temperatures.remove(),
                dist   = distances.remove();
            ArrayList<Integer> usedElement = new ArrayList<Integer>();
            usedElement.add(vertex); usedElement.add(temp);
            if (vertex == b) {
                return dist;
            }
            else {
                int left = 0, right = G[vertex].size()-1;
                if (temp < Integer.MAX_VALUE) {
                    while (left < right) {
                        int mid = (left + right) / 2;
                        if (G[vertex].get(mid).temperature >= temp - delta) {
                            right = mid;
                        } else {
                            left = mid + 1;
                        }
                    }
                }
                int edgeLeft = left;
                left = 0; right = G[vertex].size()-1;
                if (temp < Integer.MAX_VALUE) {
                    while (left < right) {
                        int mid = (left + right) / 2 + ((left + right) & 1);
                        if (G[vertex].get(mid).temperature <= temp + delta) {
                            left = mid;
                        } else {
                            right = mid - 1;
                        }
                    }
                }
                int edgeRight = right;
                for (int i = edgeLeft; i <= edgeRight; ++i) {
                    Edge e = G[vertex].get(i);
                    boolean isOK = true;
                    if (temp < Integer.MAX_VALUE) {
                        int diff = temp - e.temperature;
                        if (diff < -delta || diff > delta) {
                            isOK = false;
                        }
                    }
                    if (isOK) {
                        usedElement = new ArrayList<Integer>();
                        usedElement.add(e.to); usedElement.add(e.temperature);
                        if (!used.contains(usedElement)) {
                            used.add(usedElement);
                            if (e.to == b) {
                                return dist + 1;
                            } else {
                                vertices.add(e.to);
                                temperatures.add(e.temperature);
                                distances.add(dist + 1);
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
}
