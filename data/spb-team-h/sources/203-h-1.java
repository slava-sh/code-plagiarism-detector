import java.io.*;
import java.util.*;
public class Pysch {
	static StringTokenizer[] st = new StringTokenizer[1];
	public static int readInt(BufferedReader in) throws Exception {
		for (; !st[0].hasMoreTokens(); ) {
			st[0] = new StringTokenizer(in.readLine());
		}
		return Integer.parseInt(st[0].nextToken());
	}
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(new File("names.in")));
		PrintWriter out = new PrintWriter("names.out");
//		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
//		PrintWriter out = new PrintWriter(System.out);
		st[0] = new StringTokenizer(in.readLine());
		int n = readInt(in);
		String people[][] = new String[n][3];
		for(int i = 0; i < n; i++) {
			st[0] = new StringTokenizer(in.readLine());
			people[i][0] = st[0].nextToken();
			people[i][1] = st[0].nextToken();
			people[i][2] = st[0].nextToken();
		}
		String t;
		for(int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (people[i][0].equals(people[j][0])) {
					t = people[i][0];
					people[i][0] = people[i][2];
					people[i][2] = people[i][1];
					people[i][1] = t;
					t = people[j][0];
					people[j][0] = people[j][2];
					people[j][2] = people[j][1];
					people[j][1] = t;
					continue;
				}
				if (people[i][0].equals(people[j][1])) {
					t = people[i][0];
					people[i][0] = people[i][2];
					people[i][2] = people[i][1];
					people[i][1] = t;
					continue;
				}
				if (people[i][1].equals(people[j][0])) {
					t = people[j][0];
					people[j][0] = people[j][2];
					people[j][2] = people[j][1];
					people[j][1] = t;
					continue;
				}
			}
		}
		Arrays.sort(people, new Comparator<String[]>() {
			@Override
			public int compare(String[] o1, String[] o2) {
				return o1[0].compareTo(o2[0]);
			}
		});
		for (int i = 0; i < n; i++) {
			out.print(people[i][0] + " ");
			out.print(people[i][1] + " ");
			out.print(people[i][2] + "\n");
		}
		out.close();
		in.close();
	}
}
