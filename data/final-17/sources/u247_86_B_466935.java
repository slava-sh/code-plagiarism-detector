import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.Arrays;

public class B85 {

    static StreamTokenizer in;
    static PrintWriter out;
    
    static int nextInt() throws IOException {
        in.nextToken();
        return (int)in.nval;
    }
    
    static String nextString() throws IOException {
        in.nextToken();
        return in.sval;
    }

    public static void main(String[] args) throws IOException {
        in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
        out = new PrintWriter(System.out);

        in.ordinaryChars('.', '.');
        in.wordChars('.', '.');
        
        in.ordinaryChars('#', '#');
        in.wordChars('#', '#');
        
        n = nextInt();
        m = nextInt();
        map = new int[n][m];
        for (int i = 0; i < n; i++) {
            String s = nextString();
            for (int j = 0; j < m; j++)
                map[i][j] = s.charAt(j) == '.' ? 0 : -1;
        }
        
        p = 1;
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (map[i][j] == 0) {
                    fill(i, j, i+1, j);
                    if (map[i][j] == 0)
                        fill(i, j, i, j+1);
                }
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (map[i][j] == 0) {
                    connect(i, j, i, j-1);
                    if (map[i][j] == 0)
                        connect(i, j, i-1, j);
                    if (map[i][j] == 0)
                        connect(i, j, i, j+1);
                    if (map[i][j] == 0) {
                        out.println("-1");
                        out.flush();
                        return;
                    }
                }
        
        ans = new int[n][m];
        b = new boolean[n][m];
        for (int[] a : ans)
            Arrays.fill(a, -1);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (ans[i][j] == -1 && map[i][j] != -1)
                    paint(i, j);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                out.print(ans[i][j] == -1 ? "#" : ans[i][j]);
            out.println();
        }
        
        out.flush();
    }

    static int n, m, p;
    static int[][] map, ans;
    static boolean[][] b;
    
    static void fill(int x, int y, int x1, int y1) {
        if (x < 0 || x >= n || y < 0 || y >= m) return;
        if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m) return;
        if (map[x1][y1] != 0) return;
        map[x][y] = map[x1][y1] = p++;
    }
    
    static void connect(int x, int y, int x1, int y1) {
        if (x < 0 || x >= n || y < 0 || y >= m) return;
        if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m) return;
        if (map[x1][y1] == -1) return;
        map[x][y] = map[x1][y1];
    }
    
    static void paint(int x, int y) {
        int s = search(x, y, map[x][y]);
        int c = -1;
        for (int i = 0;; i++)
            if ((s&(1 << i)) == 0) {
                c = i;
                break;
            }
        paint(x, y, map[x][y], c);
    }
    
    static int search(int x, int y, int clr) {
        if (x < 0 || x >= n || y < 0 || y >= m) return 0;
        if (map[x][y] == clr) {
            if (b[x][y]) return 0;
            b[x][y] = true;
            return search(x+1, y, clr)|search(x-1, y, clr)|
                    search(x, y+1, clr)|search(x, y-1, clr);
        }
        else {
            return ans[x][y] == -1 ? 0 : (1 << ans[x][y]);
        }
    }
    
    static void paint(int x, int y, int clr, int q) {
        if (x < 0 || x >= n || y < 0 || y >= m) return;
        if (map[x][y] != clr) return;
        if (ans[x][y] != -1) return;
        ans[x][y] = q;
        paint(x+1, y, clr, q);
        paint(x-1, y, clr, q);
        paint(x, y+1, clr, q);
        paint(x, y-1, clr, q);
    }
}
