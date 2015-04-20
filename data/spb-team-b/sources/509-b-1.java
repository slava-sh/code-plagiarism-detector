package olimp;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;

public class taskB {
	public static void main(String[] args){
		try {
			BufferedReader reader = new BufferedReader(new FileReader("chess.in"));
			FileWriter writer = new FileWriter("chess.out");
			int count = Integer.valueOf(reader.readLine());
			String[] ls = reader.readLine().split(" ");
			
			int c = 0;
			String out = "";
			for(int i = 0; i < ls.length; i++){
				int coord = i;
				if(coord >= Integer.valueOf(ls[i])) break;
				else out +="\n" + (coord + 1) + " " + (coord + 1);
				c++;
			}
			writer.write(c + out);
			writer.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
