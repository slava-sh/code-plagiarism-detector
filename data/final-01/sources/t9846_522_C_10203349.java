import java.io.*;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        //BufferedReader in = new BufferedReader(new FileReader("input.txt"));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int t = Integer.parseInt(st.nextToken());
        int mas[];
        //мультитест
        //PrintWriter pw=new PrintWriter("output.txt");
        for (int i = 0; i < t; i++) {
            in.readLine();
            st = new StringTokenizer(in.readLine());
            int m = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
            mas = new int[k + 1];
            st = new StringTokenizer(in.readLine());
            //блюда
            int min=Integer.MAX_VALUE;
            for (int j = 1; j < k + 1; j++) {
                mas[j] = Integer.parseInt(st.nextToken());
            }
            int pust = 0;
            int pust1 = -1;
            boolean b = false;
            int mas1[] = new int[k+1];
            int ochered[][]=new int[m-1][2];
            for (int j = 0; j <m-1 ; j++) {
                st = new StringTokenizer(in.readLine());
                ochered[j][0] = Integer.parseInt(st.nextToken());
                ochered[j][1] = Integer.parseInt(st.nextToken());
            }
            HashSet<Integer> hs=new HashSet<Integer>();
            for (int j = 0; j < m - 1; j++) {
                int tj = ochered[j][0], rj = ochered[j][1];
                if (tj == 0 & rj == 0) {
                    pust++;
                } else {
                    if (rj == 0) {
                        mas[tj]--;
                        if ( mas[tj]==0) {
                            b = true;
                        }
                    } else {
                        if (tj != 0) {
                            mas[tj]--;
                        }else{
                            pust++;
                        }
                        if (b)
                            continue;
                        for (int l = j; l < m-1; l++) {
                          hs.add(ochered[l][0]);
                        }
                        pust1 = pust;
                        mas1 = mas.clone();
                        if (tj != 0)
                            mas1[tj]++;
                        else{
                           pust1--;
                        }
                        min=Integer.MAX_VALUE;
                        for (int l = 1; l <k+1 ; l++) {
                            if(min>mas1[l]&(!hs.contains(l))){
                                min=mas1[l];
                            }
                        }
                        pust -= min;
                        b = true;

                    }
                }

            }

            for (int j = 1; j < k + 1; j++) {
                if ((!hs.contains(j)&mas1[j] <= pust1) | mas[j] <= pust | mas[j] == 0) {
                    System.out.print("Y");
                    //pw.print("Y");
                } else {
                    System.out.print("N");
                    //pw.print("N");
                }
            }
            System.out.println();
            //pw.println();

        }
        //pw.flush();


    }

}
