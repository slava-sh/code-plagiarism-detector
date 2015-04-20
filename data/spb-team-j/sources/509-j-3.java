package olimp;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;

public class taskJ {
	public static void main(String[] args){
		try {
			BufferedReader reader = new BufferedReader(new FileReader("seq.in"));
			FileWriter writer = new FileWriter("seq.out");
			String[] nh = reader.readLine().split(" ");
			int n = Integer.valueOf(nh[0]);
			int h = Integer.valueOf(nh[1]);
			String[] strings = reader.readLine().split(" ");
			int[] posl = new int[n];
			
			for(int i = 0; i < n; i++){
				posl[i] = Integer.valueOf(strings[i]);
			}
			
			int min = 1000000;
			for(int i = 0; i < n; i++){
				int cp = getPosInts(posl, i, h);
				if(cp < min && cp != -1) min = cp;
			}
			writer.write((min == 1000000 ? "-1" : min) + "");
			writer.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	public static int getPosInts(int[] posl, int pos, int h){
		int sum = 0;
		for(int i = pos; i < pos + h; i++){
			int max = i - pos + 1;
			if(posl[max] > max) return -1;
			sum += (max - posl[max]);
		}
		return sum;
	}
}
