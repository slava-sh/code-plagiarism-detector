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
			int petaHits = 0;
			int vasaHits = 0;
			/*
			System.out.println(stolb + " " + kolca);
			System.out.println(l1 + " " + r1);
			System.out.println(l2 + " " + r2);
			System.out.println("-------------------");
			*/
			boolean[] rounds = new boolean[stolbs.length];
			for(int i = 0; i < stolbs.length; i++){
				if(kolca <= 0) break;
				kolca--;
				if(i % 2 == 0){
					int stI = chooseStolb(rounds,stolbs,l1, r1, l2, r2);
					rounds[stI] = true;
					int height = Integer.valueOf(stolbs[stI]);
					if(height >= l1 && height <= r1) {
						petaHits++;
						System.out.println("peta hits");
					}
				}
				if(i % 2 == 1){
					int stI = chooseStolb(rounds,stolbs,l2, r2, l1, r1);
					rounds[stI] = true;
					int height = Integer.valueOf(stolbs[stI]);
					if(height >= l2 && height <= r2) {
						vasaHits++;
						System.out.println("vasa hits");
					}
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
	
	
	public static int chooseStolb(boolean[] rounds, String[] stolbs, int l1, int r1, int l2, int r2){
		int ff = -1; int per = -1;
		for(int i = 0; i < stolbs.length; i++){
			int height = Integer.valueOf(stolbs[i]);
			if(rounds[i]) continue;
			if(ff == -1) ff = i;
			if(height >= l1 && height <= r1){
				ff = i;
				if(height >= l2 && height <= r2) per = i;
			}
		}
		return per == -1 ? ff : per;
	}
}
