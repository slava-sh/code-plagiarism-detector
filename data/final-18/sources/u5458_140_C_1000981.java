import java.io.*;
import java.util.*;

public class b {
    BufferedReader in;
    PrintWriter out;
    StringTokenizer st;

    boolean can_read() throws Exception {
        return in.ready() || st.hasMoreTokens();
    }

    void init(boolean file, String name) throws Exception {
        st = new StringTokenizer(" ");
        if (file) {
            in = new BufferedReader(new FileReader(name+".in"));
            out = new PrintWriter(new File(name + ".out"));
        } else {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
        }
    }

    String _token() throws Exception {
        while (!st.hasMoreTokens() && in.ready()) {
            st = new StringTokenizer(in.readLine());
        }
        return st.nextToken();
    }

    int _int() throws Exception {
        return Integer.parseInt(_token());
    }

    double _double() throws Exception {
        return Double.parseDouble(_token());
    }

    long _long()throws Exception {
        return Long.parseLong(_token());
    }

    class Pair implements Comparable<Pair>
    {
        int x,y;
        Pair(){}
        Pair(int X, int Y) {
            x = X;
            y = Y;
        }
        
        public int compareTo(Pair b) {
            if (x != b.x)
                return b.x - x;
            return b.y - y;
        }
    }

    void do_solve() throws Exception {
        int n = _int();
        ArrayList<int[]>ans = new ArrayList<int[]>(0);
        TreeMap<Integer, Integer> m = new TreeMap<Integer, Integer>();
        for(int i=0;i<n;i++) {
            int x = _int();
            if (m.containsKey(x)) {
                int w = m.get(x);
                m.remove(x);
                m.put(x,w+1);
            } else {
                m.put(x,1);
            }
        }
        TreeSet<Pair> m2 = new TreeSet<Pair>();
        for(int q = m.firstKey(); ; q=m.higherKey(q)) {
            m2.add(new Pair(m.get(q),q));
            if (q == m.lastKey()) 
                break;
        }
        while (m2.size() >= 3) {
            Pair a = m2.pollFirst();
            Pair b = m2.pollFirst();
            Pair c = m2.pollFirst();

            int t [] = new int[]{a.y,b.y,c.y};
            Arrays.sort(t);

            ans.add(t);
            
            if (a.x > 1) {
                m2.add(new Pair(a.x-1,a.y));
            }
            if (b.x > 1) {
                m2.add(new Pair(b.x-1,b.y));
            }
            if (c.x > 1) {
                m2.add(new Pair(c.x-1,c.y));
            }
        }
        out.println(ans.size());
        for(int i=0;i<ans.size();i++) {
            out.println(ans.get(i)[2] +" "+ans.get(i)[1] +" "+ans.get(i)[0]);
        }
    }

    public void mainProgram()throws Exception {
        init(false, "b");
        while(can_read()) {
            do_solve();
        }
        out.close();
    }

    public static void main(String[] args) throws Exception {
        long T = System.currentTimeMillis();
        new b().mainProgram();
        System.err.println((System.currentTimeMillis() - T) + " ms");
    }
}
