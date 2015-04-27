import java.util.*;
import java.io.*;
public class Main
{
    static class Number implements Comparable<Number>
    {
        int num,count;
        public Number(int n,int c)
        {
            num=n;
            count=c;
        }
        public int compareTo(Number o)
        {
            return o.count-count;
        }
    }
    public static void main(String[] args)
    {

        try
        {
            Parserdoubt pd=new Parserdoubt(System.in);
            StringBuffer sb=new StringBuffer();
            int n=pd.nextInt();
            int arr[]=new int[n];
            for(int i=0;i<n;i++)
                arr[i]=pd.nextInt();
            Arrays.sort(arr);
            PriorityQueue<Number> q=new PriorityQueue<Number>();
            int ans=0;
            int c=1;
            for(int i=1;i<arr.length;i++)
            {
                if(arr[i]!=arr[i-1])
                {
                    q.add(new Number(arr[i-1],c));
                    c=1;
                }
                else
                    c++;
            }
            q.add(new Number(arr[arr.length-1],c));
            while(q.size()>=3)
            {

                Number k1=q.poll();
                
                Number k2=q.poll();
                Number k3=q.poll();
                int temp[]=new int[3];
                temp[0]=k1.num;
                temp[1]=k2.num;
                temp[2]=k3.num;
                Arrays.sort(temp);
                sb.append(temp[2]+" "+temp[1]+" "+temp[0]+"\n");
                ans++;
                k1.count--;
                k2.count--;
                k3.count--;
                if(k1.count>0)q.add(k1);
                if(k2.count>0)q.add(k2);
                if(k3.count>0)q.add(k3);
            }
            System.out.println(ans);
            System.out.println(sb);

        }
        catch(Exception e)
        {
            e.printStackTrace();
        }

    }



}

class Parserdoubt
    {
       final private int BUFFER_SIZE = 1 << 17;

       private DataInputStream din;
       private byte[] buffer;
       private int bufferPointer, bytesRead;

       public Parserdoubt(InputStream in)
       {
          din = new DataInputStream(in);
          buffer = new byte[BUFFER_SIZE];
          bufferPointer = bytesRead = 0;
       }
       public String nextString() throws Exception
       {
           StringBuffer sb=new StringBuffer("");
           byte c = read();
           while (c <= ' ') c = read();
           do
           {
               sb.append((char)c);
               c=read();
           }while(c>' ');
           return sb.toString();
       }
       public char nextChar() throws Exception
       {
           byte c=read();
           while(c<=' ') c= read();
           return (char)c;
       }
       public int nextInt() throws Exception
       {
          int ret = 0;
          byte c = read();
          while (c <= ' ') c = read();
          boolean neg = c == '-';
          if (neg) c = read();
          do
          {
              ret = ret * 10 + c - '0';
             c = read();
          } while (c > ' ');
          if (neg) return -ret;
          return ret;
       }
       public long nextLong() throws Exception
       {
          long ret = 0;
          byte c = read();
          while (c <= ' ') c = read();
          boolean neg = c == '-';
          if (neg) c = read();
          do
          {
              ret = ret * 10 + c - '0';
             c = read();
          } while (c > ' ');
          if (neg) return -ret;
          return ret;
       }
       private void fillBuffer() throws Exception
       {
          bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
          if (bytesRead == -1) buffer[0] = -1;
       }

       private byte read() throws Exception
       {
          if (bufferPointer == bytesRead) fillBuffer();
          return buffer[bufferPointer++];
       }
    }
