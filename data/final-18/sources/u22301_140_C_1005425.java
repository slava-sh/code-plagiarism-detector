import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;


public class CF140C {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int n = Integer.parseInt(br.readLine());
        int[] balls = new int[n];
        int spacePos = -1;
        String str = br.readLine();
        for (int i = 0; i < n; i++) {
            int prevPos = spacePos;
            spacePos = str.indexOf(' ', prevPos+1);
            balls[i] = Integer.parseInt(str.substring(prevPos+1, spacePos == -1 ? str.length() : spacePos));
        }
        Arrays.sort(balls);
        ArrayList<State> counts = new ArrayList<CF140C.State>(n/2);
        int nowSize = 0;
        int nowIndex = -1;
        for (int i = 0; i < n; i++) {
            if(nowSize != balls[i]) {
                nowSize = balls[i];
                nowIndex++;
                counts.add(new State(nowSize, 1));
            }
            else counts.get(nowIndex).count++;
        }
//        Collections.sort(counts);
        PriorityQueue<State> pq = new PriorityQueue<CF140C.State>(counts);
        StringBuilder ret =  new StringBuilder();
        int numSnowmen = 0;
        while(pq.size() >= 3) {
            numSnowmen++;
            State fst = pq.poll();
            State snd = pq.poll();
            State thd = pq.poll();
            int[] radii = new int[]{fst.num, snd.num, thd.num};
            Arrays.sort(radii);
            ret.append(radii[2]).append(' ').append(radii[1]).append(' ').append(radii[0]).append('\n');
            fst.count--;
            snd.count--;
            thd.count--;
            if (fst.count > 0) pq.add(fst);
            if (snd.count > 0) pq.add(snd);
            if (thd.count > 0) pq.add(thd);
        }
        System.out.println(numSnowmen);
        System.out.print(ret);
    }
    
    static class State implements Comparable<State> {
        int num;
        int count;
        public State(int num, int count) {
            this.num = num;
            this.count = count;
        }
        @Override
        public int compareTo(State o) {
            return o.count != count ? o.count - count : o.num - num;
        }
        
    }

}
