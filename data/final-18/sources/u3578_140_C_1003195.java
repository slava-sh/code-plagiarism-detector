import java.util.*;
import java.util.Map.Entry;
import java.lang.*;
import java.math.*;
import java.io.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;

public class C{
    Scanner sc=new Scanner(System.in);

    int INF=1<<28;
    double EPS=1e-9;

    int n;
    int[] rs;

    void run(){
        n=sc.nextInt();
        rs=new int[n];
        for(int i=0; i<n; i++){
            rs[i]=sc.nextInt();
        }
        solve();
    }

    void solve(){
        HashMap<Integer, Integer> map=new HashMap<Integer, Integer>();
        for(int i=0; i<n; i++){
            if(!map.containsKey(rs[i])){
                map.put(rs[i], 0);
            }
            map.put(rs[i], map.get(rs[i])+1);
        }

        TreeSet<R> set=new TreeSet<R>();
        for(Entry<Integer, Integer> entry : map.entrySet()){
            set.add(new R(entry.getKey(), entry.getValue()));
        }

        LinkedList<Answer> list=new LinkedList<Answer>();
        R[] array=new R[3];
        for(; set.size()>=3;){
            for(int i=0; i<3; i++){
                array[i]=set.pollFirst();
            }
            list.add(new Answer(array[0].r, array[1].r, array[2].r));
            for(int i=0; i<3; i++){
                array[i].s--;
                if(array[i].s>0){
                    set.add(array[i]);
                }
            }
        }
        println(""+list.size());
        for(Answer ans : list){
            StringBuffer sb=new StringBuffer();
            sb.append(ans.i1);
            sb.append(" ");
            sb.append(ans.i2);
            sb.append(" ");
            sb.append(ans.i3);
            println(sb.toString());
        }
    }

    class Answer{
        int i1, i2, i3;

        Answer(int i1, int i2, int i3){
            int[] is=new int[]{-i1, -i2, -i3};
            sort(is);
            this.i1=-is[0];
            this.i2=-is[1];
            this.i3=-is[2];
        }
    }

    class R implements Comparable<R>{
        int r, s;

        R(int r, int s){
            this.r=r;
            this.s=s;
        }

        @Override
        public int compareTo(R r){
            if(this.s!=r.s){
                return r.s-this.s;
            }else{
                return r.r-this.r;
            }
        }
    }

    void println(String s){
        System.out.println(s);
    }

    void print(String s){
        System.out.print(s);
    }

    void debug(Object... os){
        System.err.println(Arrays.deepToString(os));
    }

    public static void main(String[] args){
        new C().run();
    }
}
