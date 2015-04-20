package olimp;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.HashMap;

public class taskD {
	public static void main(String[] args){
		try {
			BufferedReader reader = new BufferedReader(new FileReader("dunes.in"));
			FileWriter writer = new FileWriter("dunes.out");
			
			String[] nm = reader.readLine().split(" ");
			int n = Integer.valueOf(nm[0]);
			int m = Integer.valueOf(nm[1]);
			
			HashMap<Integer, Integer> regs = new HashMap();
			int[][] data = new int[n][3];
			for(int i = 0; i < n; i++){
				String[] dataEl = reader.readLine().split(" ");
				data[i] = new int[]{Integer.valueOf(dataEl[0]), Integer.valueOf(dataEl[1]), Integer.valueOf(dataEl[2])};
			}
			
			for(int i = 0; i < n; i++){
				int li = data[i][0];
				int ri = data[i][1];
				int xi = data[i][2];
				for(int j = li; j <= ri; j++){
					if(!regs.containsKey(j)) regs.put(j, 0);
					if((j - li) % 2 == 0) regs.put(j, regs.get(j) + xi);
					if((j - li) % 2 == 1) regs.put(j, regs.get(j) - xi);
				}
			}
			
			for(int i = 0; i < m; i++){
				int ind = Integer.valueOf(reader.readLine());
				if(!regs.containsKey(ind)) regs.put(ind, 0);
				writer.write(regs.get(ind) + "\n");
			}
			
			writer.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
