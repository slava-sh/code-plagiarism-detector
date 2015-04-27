import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;


public class B {
    static StreamTokenizer st;
    static class Sort implements Comparable<Sort> {
        int val,cnt;
        public int compareTo(Sort arg0) {
            if (this.cnt < arg0.cnt)
                return 1;
            return 0;
        }
    }
    static class Que_elements implements Comparable<Que_elements> {
        int val, cnt;
        public int compareTo(Que_elements arg0) {
            if (this.cnt==arg0.cnt)
                return -(this.val-arg0.val);
            return -(this.cnt-arg0.cnt);
        }
        public Que_elements(int val, int cnt) {
            this.val = val;
            this.cnt = cnt;
        }
    }
    
    public static void main(String[] args) throws IOException{
        st = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        int n = nextInt();
        int[]a = new int[n+1];
        for (int i = 1; i <= n; i++) {
            a[i] = nextInt();
        }
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        int t = 0;
        Sort[]b = new Sort[n+1];
        for (int i = 1; i <= n; i++) {
            if (map.get(a[i])==null) {
                t++;
                b[t] = new Sort();
                b[t].val = a[i];
                b[t].cnt = 1;
                map.put(a[i], t);
            }
            else {
                int r = map.get(a[i]);
                b[r].cnt++;
            }
        }
        if (t < 3) {
            System.out.println(0);
            return;
        }
        Arrays.sort(b, 1, t+1);
        PriorityQueue<Que_elements> q = new PriorityQueue<Que_elements>();
        for (int i = 1; i <= t; i++) {
            q.add(new Que_elements(b[i].val, b[i].cnt));
        }
        int k = 0;
        int[][]ans = new int[n][3];
        while (true) {
            Que_elements k1 = q.poll();
            Que_elements k2 = q.poll();
            Que_elements k3 = q.poll();
            if (k3.cnt==0) 
                break;
            k++;
            ans[k][0] = k1.val;
            ans[k][1] = k2.val;
            ans[k][2] = k3.val;
            k1.cnt--;
            k2.cnt--;
            k3.cnt--;
            q.add(k1);
            q.add(k2);
            q.add(k3);
        }
        pw.println(k);
        int[]p = new int[3];
        for (int i = 1; i <= k; i++) {
            for (int j = 0; j < 3; j++) {
                p[j] = ans[i][j];
            }
            Arrays.sort(p);
            for (int j = 2; j >= 0; j--) {
                pw.print(p[j]+" ");
            }
            pw.println();
        }
        pw.close();
    }

    private static int nextInt() throws IOException{
        st.nextToken();
        return (int) st.nval;
    }
}
/*
10
1 2 3 1 2 3 4 4 4 4
*/