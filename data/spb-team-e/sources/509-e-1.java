package olimp;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;

public class taskB {
	public static void main(String[] args){
		try {
			BufferedReader reader = new BufferedReader(new FileReader("game.in"));
			FileWriter writer = new FileWriter("game.out");
			
			String[] stolbyIcolca = reader.readLine().split(" ");
			int stolb = Integer.valueOf(stolbyIcolca[0]);
			int kolca = Integer.valueOf(stolbyIcolca[1]);
			String[] peta = reader.readLine().split(" ");
			int l1 = Integer.valueOf(peta[0]);
			int r1 = Integer.valueOf(peta[1]);
			String[] wasq = reader.readLine().split(" ");
			int l2 = Integer.valueOf(wasq[0]);
			int r2 = Integer.valueOf(wasq[1]);
			String[] stolbs = reader.readLine().split(" ");
			int petaHits = 0, petaRounds = kolca;
			int vasaHits = 0, vasaRounds = kolca;
			/*
			System.out.println(stolb + " " + kolca);
			System.out.println(l1 + " " + r1);
			System.out.println(l2 + " " + r2);
			System.out.println("-------------------");
			*/
			for(int i = 0; i < stolbs.length; i++){
				int height = Integer.valueOf(stolbs[i]);
				if(height >= l1 && height <= r1 && petaRounds > 0){
					//System.out.println("peta hits");
					petaHits++; petaRounds--;
				}
				if(height >= l2 && height <= r2 && vasaRounds > 0){
					//System.out.println("vasa hits");
					vasaHits++; vasaRounds--;
				}
			}
			
			if(petaHits > vasaHits){
				writer.write("Petya");
			}
			if(petaHits < vasaHits){
				writer.write("Vasya");
			}
			if(petaHits == vasaHits){
				writer.write("Draw");
			}
			writer.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
