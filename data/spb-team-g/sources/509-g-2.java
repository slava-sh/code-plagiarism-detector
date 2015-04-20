package olimp;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;

public class taskG {
	public static void main(String[] args){
		try {
			BufferedReader reader = new BufferedReader(new FileReader("merlin.in"));
			FileWriter writer = new FileWriter("merlin.out");
			int n = Integer.valueOf(reader.readLine());
			String[] rawData = reader.readLine().split(" ");
			
			int[] data = new int[n];
			int max = -1; boolean allEqual = true;
			
			boolean allEq = true; int lastEq = data[0];
			for(int i = 0; i < n; i++){
				data[i] = Integer.valueOf(rawData[i]);
				lastEq = data[0];
				if(lastEq != data[i]) allEq = false;
				
			}
			
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n - 1; j++){
					int e1 = data[j]; int e2 = data[j + 1];
					if(e1 > e2){
						data[j] = e2;
						data[j + 1] = e1;
					}
				}
			}
			int lastPos = data.length - 1; int broke = 0; 
			int vol = 0;
			while(lastPos > 0){
				vol += data[lastPos]; lastPos --; broke++;
				int last = data[lastPos]; int need = 0;
				for(int i = 0; i < lastPos; i++){
					need += data[i];
				}
				if(vol >= need) break;
			}
			
			if(allEq) writer.write("0");
			else
				writer.write(broke + "");
			writer.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
