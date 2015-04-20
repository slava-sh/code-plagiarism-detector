package olimp;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;

public class taskH {
	public static void main(String[] args){
		try {
			BufferedReader reader = new BufferedReader(new FileReader("names.in"));
			FileWriter writer = new FileWriter("names.out");
			int count = Integer.valueOf(reader.readLine());
			String[][] names = new String[count][3];
			
			for(int i = 0; i < count; i++){
				String fio = reader.readLine();
				names[i] = sortOneName(fio);
			}
			
			for(int i = 0; i < names.length; i ++){
				for(int j = 0; j < names.length - 1; j ++){
					String[] fio1 = names[j];
					String[] fio2 = names[j + 1];
					if(!compareFIOs(fio1, fio2)){
						names[j] = fio2;
						names[j + 1] = fio1;
					}
				}
			}
			
			for(int i = 0; i < names.length; i++){
				writer.write(names[i][0] + " " + names[i][1] + " " + names[i][2] + "\n");
			}
			
			writer.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	public static String[] sortOneName(String name){
		String[] fio1 = name.split(" ");
		String f = "", im = "", o = "";
		for(int i = 0; i < fio1.length; i++){
			String el = fio1[i];
			//System.out.println(el.substring(el.length() - 3));
			if(el.substring(el.length() - 3).equals("ich")) o = el;
			else if(el.substring(el.length() - 2).equals("ov")) f = el;
			else im = el;
		}
		return new String[]{f,im, o};
	}
	
	public static boolean compareFIOs(String[] fio1, String[] fio2){
		if(compareStrings(fio1[0], fio2[0])){
			return true;
		}
		else{
			return false;
		}
	}
	
	public static boolean compareStrings(String s1, String s2){
		for(int i = 0; i < Math.max(s1.length(), s2.length()); i++){
			if(i >= s1.length()) return true;
			if(i >= s2.length()) return false;
			if(s1.charAt(i) < s2.charAt(i)) return true;
			if(s1.charAt(i) > s2.charAt(i)) return false;
		}
		return true;
	}
}
