import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		QuickScanner in = new QuickScanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, QuickScanner in, PrintWriter out) {
        int n=in.nextInt()-1;
        int k=in.nextInt();
        int a[]=in.nextInts(k);
        int cnt[]=new int[k];
        int freeCnt;

        int t[]=new int[n];
        int r[]=new int[n];
        for(int i=0;i<n;i++)
        {
            t[i]=in.nextInt()-1;
            r[i]=in.nextInt();
        }

        int firstUnsatisfied=-1;
        for(int i=0;i<n;i++)
            if(r[i]==1)
            {
                firstUnsatisfied=i;
                break;
            }

        char[] res=new char[k];
        for(int i=0;i<k;i++)
            res[i]='N';

        if(firstUnsatisfied!=-1)
        {
            boolean canBeFinished[]=new boolean[k];
            Arrays.fill(canBeFinished, true);
            for(int i=firstUnsatisfied;i<n;i++)
                if(t[i]!=-1)
                    canBeFinished[t[i]]=false;

            freeCnt=0;
            Arrays.fill(cnt,0);
            for(int i=0;i<firstUnsatisfied;i++)
                if(t[i]!=-1)
                    cnt[t[i]]++;
                else
                    freeCnt++;
            int minID=-1;
            for(int i=0;i<k;i++)
            {
                if( canBeFinished[i] && a[i]-cnt[i]<=freeCnt )
                {
                    res[i]='Y';
                    if(minID==-1 || a[i]-cnt[i]<a[minID]-cnt[minID])
                        minID=i;
                }
            }
            freeCnt=a[minID]-cnt[minID];
            for(int i=0;i<firstUnsatisfied && freeCnt>0;i++)
                if(t[i]==-1)
                {
                    t[i]=minID;
                    freeCnt--;
                }
        }

        freeCnt=0;
        Arrays.fill(cnt,0);
        for(int i=0;i<n;i++)
            if(t[i]!=-1)
                cnt[t[i]]++;
            else
                freeCnt++;
        for(int i=0;i<k;i++)
        {
            if( a[i] - cnt[i] <=freeCnt)
                res[i]='Y';
        }
        out.println(res);
    }
}

class QuickScanner {
    BufferedReader in;
    StringTokenizer token;
    String delim;
    public QuickScanner(InputStream inputStream)
    {
        this.in=new BufferedReader(new InputStreamReader(inputStream));
        this.delim=" \n\t";
        this.token=new StringTokenizer("",delim);
    }

    public boolean hasNext()
    {
        while(!token.hasMoreTokens())
        {
            try {
                String s=in.readLine();
                if(s==null) return false;
                token=new StringTokenizer(s,delim);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
        }
        return true;
    }

    public String next()
    {
        hasNext();
        return token.nextToken();
    }

    public int nextInt()
    {
        return Integer.parseInt(next());
    }

    public int[] nextInts(int n)
    {
        int[] res=new int[n];
        for(int i=0;i<n;i++)
            res[i]=nextInt();
        return res;
    }

}

