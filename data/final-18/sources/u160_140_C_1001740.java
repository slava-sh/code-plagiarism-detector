import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.Arrays;

public class C implements Runnable {

    public void solve() throws IOException {
        int n = nextInt();
        int[] a = new int[n];
        for ( int i = 0; i < n; i ++ ) {
            a[i] = nextInt();
        }
        Arrays.sort( a );
        int l = 0;
        int r = a.length / 3;
        while ( l < r ) {
            int m = ( l + r + 1 ) / 2;
            if ( can( m, a ) != null ) {
                l = m;
            } else {
                r = m - 1;
            }
        }
        int[][] res = can( l, a );
        out.println( l );
        if ( res != null ) {
            for ( int[] s : res ) {
                out.println( s[2] + " " + s[1] + " " + s[0] );
            }
        }
    }

    private int[][] can( int m, int[] a ) {
        int[][] r = new int[m][3];
        int last = 0;
        int cnt = 0;
        int row = 0;
        int pos = 0;
        for ( int x : a ) {
            if ( x == last ) {
                cnt ++;
            } else {
                last = x;
                cnt = 1;
            }
            if ( cnt > m ) {
                continue;
            }
            r[pos][row] = x;
            pos ++;
            if ( pos >= m ) {
                row ++;
                pos = 0;
            }
            if ( row >= 3 ) {
                break;
            }
        }
        if ( row >= 3 ) {
            return r;
        } else {
            return null;
        }
    }

    public StreamTokenizer in;

    public PrintWriter out;

    C() throws IOException {
        in = new StreamTokenizer( new InputStreamReader( System.in ) );
        out = new PrintWriter(System.out);
    }

    int nextInt() throws IOException {
        in.nextToken();
        return ( int ) in.nval;
    }

    void check(boolean f, String msg) {
        if (!f) {
            out.close();
            throw new RuntimeException(msg);
        }
    }

    void close() throws IOException {
        out.close();
    }

    public void run() {
        try {
            solve();
            close();
        } catch (Exception e) {
            e.printStackTrace(out);
            out.flush();
            throw new RuntimeException(e);
        }
    }

    public static void main(String[] args) throws IOException {
        new Thread(new C()).start();
    }
}