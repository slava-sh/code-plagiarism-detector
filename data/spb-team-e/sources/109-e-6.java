import java.io.*;
import java.util.*;

public class e1 {
	static PrintWriter out;
	static int a[];
	static int m;
	
	static void win(int v1, int v2) {
		if (v1 > (m + 1) / 2) {
			v1 = (m + 1) / 2;
		}
		if (v2 > m / 2) {
			v2 = m / 2;
		}
		if (v1 > v2) {
			out.print("Petya");
		}
		else {
			if (v1 < v2) {
				out.print("Vasya");
			}
			else {
				out.print("Draw");
			}
		}
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("game.in"));
		out = new PrintWriter("game.out");
		int n = in.nextInt();
		m = in.nextInt();
		int l1 = in.nextInt();
		int r1 = in.nextInt();
		int l2 = in.nextInt();
		int r2 = in.nextInt();
		a = new int[n];
		boolean flag1 = false;
		boolean flag2 = false;
		int il = 0;
		int ir = 0;
		int il1 = 0;
		int ir1 = 0;
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		Arrays.sort(a);
		for (int i = 0; i < n; i++) {
			if ((a[i] >= l1) && (a[i] <= r1)) {
				if (flag1) {
					ir++;
				} else {
					flag1 = true;
					il = i;
					ir = i;
				}
			}
			if ((a[i] >= l2) && (a[i] <= r2)) {
				if (flag2) {
					ir1++;
				} else {
					flag2 = true;
					il1 = i;
					ir1 = i;
				}
			}
		}
		if (flag1) {
			if (flag2) {
				if ((il > ir1) || (il1 > ir)){
					win(ir - il + 1, ir1 - il1 + 1);
					out.close();
				}
				if ((il <= il1) && (ir1 <= ir)){
					win((ir1 - il1 + 2) / 2 + ir - il - ir1 + il1, (ir1 - il1 + 1) / 2);
					out.close();
				}
				if ((ir <= ir1) && (il1 <= il)){
					win((ir - il + 2) / 2, (ir - il + 1) / 2 + ir1 - il1 - ir + il);
					out.close();
				}
				int count = Math.min(ir , ir1) - Math.max(il, il1) + 1;
				win((ir - il + 1) - count / 2, (ir1 - il1 + 1) - (count + 1) / 2);
			} else {
				out.print("Petya");
			}
		} else {
			if ((flag2) && (m > 1)) {
				out.print("Vasya");
			} else {
				out.print("Draw");
			}
		}
		out.close();
	}
}
