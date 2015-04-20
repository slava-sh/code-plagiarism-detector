import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;


public class H {
	static class people implements Comparable<people>{
		String[] names;
		public people (String a, String b, String c) {
			names = new String[3];
			names[0] = a;
			names[1] = b;
			names[2] = c;
		}
		
		void remake() {
			String[] array = new String[3];
			array[0] = names[2];
			array[1] = names[0];
			array[2] = names[1];
			names = array;
		}
		
		@Override
		public int compareTo(people o) {
			int min = Math.min(o.names[0].length(), names[0].length());
			for (int i = 0; i < min; i++) {
				if (o.names[0].charAt(i) > names[0].charAt(i)) {
					return -1;
				} else if (o.names[0].charAt(i) < names[0].charAt(i)) {
					return 1;
				}
			}
			if (o.names[0].length() > names[0].length()) {
				return -1;
			}
			return 1;
		}
		
		@Override
		public String toString() {
			return names[0] + " " + names[1] + " " + names[2];
		}
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(System.in);
//		Scanner in = new Scanner(new File("names.in"));
		PrintWriter out = new PrintWriter(new File("names.out"));
		int n = in.nextInt();
		HashMap<String, Boolean> map = new HashMap<String, Boolean>(); 
		people[] array = new people[n];
		for (int i = 0; i < n; i++) {
			String a = in.next();
			String b = in.next();
			String c = in.next();
			map.put(a, map.containsKey(a));
			map.put(b, map.containsKey(b));
			map.put(c, map.containsKey(c));
			array[i] = new people(a, b, c);
		}
		for (int i = 0; i < n; i++) {
			if (map.get(array[i].names[0])) {
				array[i].remake();
			}
		}
		Arrays.sort(array);
		for (int i = 0; i < n; i++) {
			out.println(array[i]);
		}
		out.close();
		in.close();
	}
}
