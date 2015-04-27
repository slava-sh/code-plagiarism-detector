
import java.io.*;
import java.util.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
public class Main{
    public static void main(String[]args){
        InputStream in = System.in;
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        try{
//          in = new BufferedInputStream(new FileInputStream(new File("input.txt")));
//          out = new PrintWriter(new BufferedOutputStream(new FileOutputStream("output.txt")));
        }catch (Exception e) {
        }
        new Main().run(in,out);
        out.flush();
    }
    private void debug(Object...os){
        System.err.println(deepToString(os));
    }

    private void run(InputStream in,PrintWriter out){
        int n = nextInt(in);
        int[] as=new int[n];
        for(int i=0;i<n;i++)as[i]=nextInt(in);
        sort(as);
        int m=0;
        for(int i=0;i<n;){
            int j=i;
            while(j<n && as[i]==as[j])j++;
            m++;
            i=j;
        }
        E[] es=new E[m];
        m=0;
        for(int i=0;i<n;){
            int j=i;
            while(j<n && as[i]==as[j])j++;
            es[m] = new E(j-i, as[i]);
            m++;
            i=j;
        }
        PriorityQueue<E> que=new PriorityQueue<E>();
        for(E e:es)que.offer(e);
        
        ArrayList<String>res=new ArrayList<String>();
        while(!que.isEmpty()){
            if(que.size()<3)break;
            E[] e2=new E[3];
            for(int i=0;i<3;i++){
                e2[i] = que.poll();
            }
            int[] vs=new int[3];
            for(int i=0;i<3;i++)vs[i] = e2[i].val;
            sort(vs);
            res.add(String.format("%d %d %d",vs[2],vs[1],vs[0]));
            for(int i=0;i<3;i++){
                if(e2[i].num>1){
                    que.offer(new E(e2[i].num-1, e2[i].val));
                }
            }
        }
        out.println(res.size());
        for(String s:res)out.println(s);
    }
    class E implements Comparable<E>{
        int num;
        int val;
        public E(int num, int val) {
            super();
            this.num = num;
            this.val = val;
        }
        public int compareTo(E o) {
            return - (num-o.num);
        }
        @Override
        public String toString() {
            return "E [num=" + num + ", val=" + val + "]";
        }
        
    }

    private String nextLine(InputStream in) {
        try {
            StringBuilder res = new StringBuilder("");
            int c = in.read();
            if(c==-1)return null;
            while (c=='\n' || c=='\r'){
                c = in.read();
                if(c==-1)return null;
            }
            do {
                res.append((char) c);
                c=in.read();
            } while (c!='\n' && c!='\r');
            return res.toString();
        } catch (Exception e) {
            return null;
        }
    }

    private String next(InputStream in) {
        try {
            StringBuilder res = new StringBuilder("");
            int c = in.read();
            if(c==-1)return null;
            while (Character.isWhitespace(c)){
                c = in.read();
                if(c==-1)return null;
            }
            do {
                res.append((char) c);
            } while (!Character.isWhitespace(c = in.read()));
            return res.toString();
        } catch (Exception e) {
            return null;
        }
    }

    private int nextInt(InputStream in){
        try{
            int c=in.read();
            if(c==-1) return c;
            while(c!='-'&&(c<'0'||'9'<c)){
                c=in.read();
                if(c==-1) return c;
            }
            if(c=='-') return -nextInt(in);
            int res=0;
            do{
                res*=10;
                res+=c-'0';
                c=in.read();
            }while('0'<=c&&c<='9');
            return res;
        }catch(Exception e){
            return -1;
        }
    }

    private long nextLong(InputStream in){
        try{
            int c=in.read();
            if(c==-1) return c;
            while(c!='-'&&(c<'0'||'9'<c)){
                c=in.read();
                if(c==-1) return c;
            }
            if(c=='-') return -nextLong(in);
            long res=0;
            do{
                res*=10;
                res+=c-'0';
                c=in.read();
            }while('0'<=c&&c<='9');
            return res;
        }catch(Exception e){
            return -1;
        }
    }
}