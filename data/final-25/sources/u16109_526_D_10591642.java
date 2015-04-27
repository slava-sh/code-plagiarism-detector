import java.io.InputStreamReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Andrey Rechitsky (arechitsky@gmail.com)
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        char []s = in.next().toCharArray();
        int[] p = new int[n];
        p[0] = 0;
        for (int i = 1; i < n; i++) {
            boolean repeat = true;
            int tmp = p[i-1];
            while (repeat){
                repeat = false;
                if (s[i]==s[tmp]) p[i] = tmp+1;
                else if (tmp==0) p[i] = 0;
                else{
                    tmp = p[tmp-1];
                    repeat = true;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (k==1){
                out.print("1");
                continue;
            }
            if (i+1<k){
                out.print("0");
                continue;
            }
            if (p[i]*2<i+1){
                out.print("0");
                continue;
            }
            int tmp = i+1-p[i];
            int c = (i+1)/tmp/k;
            int r = i+1-c*tmp*k;
            out.print(r<=tmp*c?"1":"0");
        }
        out.printLine();
    }
}

class FastScanner {

    private BufferedReader reader;
    private StringTokenizer st;

    public FastScanner(InputStream stream) {
        this.reader = new BufferedReader(new InputStreamReader(stream));
        this.st = new StringTokenizer("");
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public String next(){
        while (!st.hasMoreTokens()){
            st = new StringTokenizer(readLine());
        }
        return st.nextToken();
    }

    private String readLine() {
        try {
            String line = reader.readLine();
            if (line==null) throw new InputMismatchException();
            return line;
        } catch (IOException e) {
            throw new InputMismatchException();
        }
    }

}

class FastPrinter {
    private final PrintWriter writer;

    public FastPrinter(OutputStream outputStream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public void close() {
        writer.close();
    }

    public void printLine() {
        writer.println();
    }

    public void print(String s) {
        writer.print(s);
    }

}
