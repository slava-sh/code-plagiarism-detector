package olimp;
import java.io.*;

public class taskA {
	public static void main(String[] args){
		try {
			BufferedReader reader = new BufferedReader(new FileReader("abcd.in"));
			FileWriter writer = new FileWriter("abcd.out");
			int count = Integer.valueOf(reader.readLine());
			for(int i = 0; i < count; i++){
				String code = reader.readLine();
				int a = Integer.valueOf(code.substring(0, 2));
				int b = Integer.valueOf(code.substring(2, 4));
				if((a * a + b * b) % 7 == 1) writer.write("YES\n");
				else writer.write("NO\n");
			}
			writer.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
