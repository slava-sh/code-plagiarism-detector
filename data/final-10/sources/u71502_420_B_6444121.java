import java.io.InputStreamReader;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.PrintStream;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Reader;
import java.io.Writer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Nipuna Samarasekara
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    /////////////////////////////////////////////////////////////
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
   int n=in.nextInt(),m=in.nextInt();
      int[] not= new int[n+1];
    int[] io= new int[m];
    int[] who= new int[m];
        for (int i = 0; i < m; i++) {
            String s=in.next();
            if(s.charAt(0)=='+')io[i]=1;
            who[i]=in.nextInt();
        }
        for (int i = 0; i < m; i++) {
          if(not[who[i]]==0){
            if(io[i]==1&&i!=0){
                not[who[i]]=1;
               if(i>0&&io[i-1]==0&&who[i-1]==who[i]){
                   not[who[i]]=0;
               }
            }
            if(io[i]==0&&i!=m-1){
                not[who[i]]=1;
             //   System.out.println("dfkjdsbfv "+who[i]);
                if(i<m-1&&io[i+1]==1&&who[i+1]==who[i])not[who[i]]=0;

            } }
         //   deb(not);
        }
//        if(io[0]==1&&not[who[0]]==0){
//            int ww=who[0];
//         int ot=-1;
//            int chk=0;
//            boolean[] camein= new boolean[n+1];
//            for (int i = 1; i < m; i++) {
//              if(who[i]==ww){
//
//                break;
//              }
//              if(io[i]==1)camein[who[i]]=true;
//              else{
//                  if(!camein[who[i]]){
//                    chk++;
//                    break;
//                 }
//
//              }
//               // deb(camein);
//            }
//            if(chk>0)not[ww]=1;
//
//        }
//        if(io[m-1]==0&&not[who[m-1]]==0){
//           int ww=who[m-1];
//            int chk=0;
//            boolean[] camein= new boolean[n+1];
//            for (int i = m-2; i >= 0; i--) {
//                if(who[i]==ww){
//
//                    break;
//                }
//                if(io[i]==0)camein[who[i]]=true;
//                else{
//                    if(!camein[who[i]]){
//                        chk++;
//                    }
//
//                }
//            }
//            if(chk>0)not[ww]=1;
//
//
//
//
//
//
//        }

        boolean[] cin= new boolean[n+1];
        int cc=0;

        for (int i = m-1; i >=0 ; i--) {
           if(io[i]==0){
               cin[who[i]]=true;
               cc++;
           }
            if(io[i]==1){
                if(cin[who[i]]){
                    cin[who[i]]=false;
                    cc--;
                }
              if(cc!=0)not[who[i]]=1;
            }
        }

        cin= new boolean[n+1];
        cc=0;

        for (int i = 0; i < m ; i++) {
         if(io[i]==1){
             cin[who[i]]=true;
             cc++;
         }
            else{
             if(cin[who[i]]){
                 cin[who[i]]=false;
                 cc--;

             }
             if(cc!=0)not[who[i]]=1;

         }
        }


        int count=0;
        StringBuilder sb= new StringBuilder();
        for (int i = 1; i <=n; i++) {
          if(not[i]==0){
           sb.append(i+" ");
          count++;
          }
        }
        out.println(count);
        out.println(sb.toString());

    }
}

class FastScanner extends BufferedReader {

    public FastScanner(InputStream is) {
        super(new InputStreamReader(is));
    }

    public int read() {
        try {
            int ret = super.read();
//            if (isEOF && ret < 0) {
//                throw new InputMismatchException();
//            }
//            isEOF = ret == -1;
            return ret;
        } catch (IOException e) {
            throw new InputMismatchException();
        }
    }

    public String next() {
        StringBuilder sb = new StringBuilder();
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        if (c < 0) {
            return null;
        }
        while (c >= 0 && !isWhiteSpace(c)) {
            sb.appendCodePoint(c);
            c = read();
        }
        return sb.toString();
    }

    static boolean isWhiteSpace(int c) {
        return c >= 0 && c <= 32;
    }

    public int nextInt() {
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int ret = 0;
        while (c >= 0 && !isWhiteSpace(c)) {
            if (c < '0' || c > '9') {
                throw new NumberFormatException("digit expected " + (char) c
                        + " found");
            }
            ret = ret * 10 + c - '0';
            c = read();
        }
        return ret * sgn;
    }

    public String readLine() {
        try {
            return super.readLine();
        } catch (IOException e) {
            return null;
        }
    }

}

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }

    public FastPrinter(Writer out) {
        super(out);
    }


}

