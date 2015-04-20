import java.io.*;
import java.util.*;
import java.lang.*;

public class H {
    class Man implements Comparable <Man>{
        String name, surname, fname;

        Man(String surname, String name, String fname) {
            this.name = name;
            this.surname = surname;
            this.fname = fname;
        }

        @Override
        public int compareTo(Man o) {
            if(this.surname.compareTo(o.surname) == 0) {
                if(this.name.compareTo(o.name) == 0) {
                    return this.fname.compareTo(o.fname);
                }
                return this.name.compareTo(o.name);
            }
            return this.surname.compareTo(o.surname);
        }
    }

    BufferedReader br;
    StringTokenizer in;
    PrintWriter out;

    String nextToken() throws IOException {
        while (in == null || !in.hasMoreTokens()) {
            in = new StringTokenizer(br.readLine());
        }
        return in.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    void solve() throws IOException {
        int n = nextInt();
        Man[] men = new Man[n];
        for (int i = 0; i < n; ++i) {
            String s1 = nextToken();
            String s2 = nextToken();
            String s3 = nextToken();
            men[i] = new Man(s1, s2, s3);
            for(int j = 0; j < i; j++) {
                if(men[j].surname.equals(men[i].surname)) {
                    String t = men[i].fname;
                    men[i].fname =  men[i].name;
                    men[i].name =  men[i].surname;
                    men[i].surname = t;
                    t = men[j].fname;
                    men[j].fname =  men[j].name;
                    men[j].name =  men[j].surname;
                    men[j].surname = t;
                }else if(men[j].surname.equals(men[i].name)) {
                    String t = men[j].fname;
                    men[j].fname =  men[j].name;
                    men[j].name =  men[j].surname;
                    men[j].surname = t;
                }else if(men[j].name.equals(men[i].surname)) {
                    String t = men[i].fname;
                    men[i].fname =  men[i].name;
                    men[i].name =  men[i].surname;
                    men[i].surname = t;
                }
            }
        }
        Arrays.sort(men);
        for(int i = 0; i < n; i++) {
            out.println(men[i].surname + " " + men[i].name + " " + men[i].fname);
        }
    }

    void run() {
        try {
            br = new BufferedReader(new FileReader("names.in"));
            out = new PrintWriter("names.out");
            solve();
        } catch (Exception e) {
            e.printStackTrace();
        }
        out.close();
    }



    public static void main(String[] args) {
        new H().run();
    }
}
