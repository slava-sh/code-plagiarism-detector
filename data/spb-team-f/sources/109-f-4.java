import java.io.*;
import java.util.*;

public class f1 {
	static int p[];
	static int alpha[];
	static int d[];
	static int count_all;
	static long numb[];
	static long ans_1;
	static long ans_2;
	static long ans;
	
	static void gen(int count, long f, long s){
		if (count == count_all){
			if (ans > Math.abs(f - s)){
				ans_1 = f;
				ans_2 = s;
				ans = Math.abs(f - s);
			}
		}
		else{
			gen(count + 1, 1l * f * numb[count], s);
			gen(count + 1, f, 1l * s  * numb[count]);
		}
	}
	
	
	static long pow(long x, int q){
		if (q == 0){
			return 1; 
		}
		else{
			if (q % 2 == 0){
				long e = pow(x, q / 2);
				return 1l * e * e;
			}
			else{
				return 1l * pow(x, q - 1) * x;
			}
		}
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("gcm.in"));
		PrintWriter out = new PrintWriter("gcm.out");
		int a = in.nextInt();
		int b = in.nextInt();
		int p1[] = new int[13];
		int p2[] = new int[13];
		int d1[] = new int[13];
		int d2[] = new int[13];
		int x = a;
		int count = 0;
		for (int i = 2; i * i <= a; i++) {
			if (a % i == 0) {
				p1[count] = i;
				while (x % i == 0) {
					x /= i;
					d1[count]++;
				}
				count++;
			}
		}
		if (x > 1) {
			p1[count] = x;
			d1[count] = 1;
		} else {
			count--;
		}
		x = b;
		int count1 = 0;
		for (int i = 2; i * i <= b; i++) {
			if (b % i == 0) {
				p2[count1] = i;
				while (x % i == 0) {
					x /= i;
					d2[count1]++;
				}
				count1++;
			}
		}
		if (x > 1) {
			p2[count1] = x;
			d2[count1] = 1;
		} else {
			count1--;
		}
		p = new int[27];
		d = new int[27];
		count_all = 0;
		int l = 0;
		int l1 = 0;
		long nod = 1;
		while ((l <= count) || (l1 <= count1)) {
			if (l > count) {
				p[count_all] = p2[l1];
				d[count_all] = d2[l1];
				l1++;
				count_all++;
			} else {
				if (l1 > count1) {
					p[count_all] = p1[l];
					d[count_all] = d1[l];
					l++;
					count_all++;
				} else {
					if (p1[l] < p2[l1]) {
						p[count_all] = p1[l];
						d[count_all] = d1[l];
						l++;
						count_all++;
					} else {
						if (p1[l] == p2[l1]) {
							p[count_all] = p1[l];
							d[count_all] = Math.abs(d1[l] - d2[l1]);
							nod = 1l * nod * pow(p1[l], Math.min(d1[l], d2[l1]));
							l++;
							l1++;
							count_all++;
						} else {
							p[count_all] = p2[l1];
							d[count_all] = d2[l1];
							l1++;
							count_all++;
						}
					}
				}
			}
		}
		numb = new long[27];
		for (int i = 0; i < count_all; i++) {
			numb[i] = 1;
			for (int j = 0; j < d[i]; j++) {
				numb[i] = 1l * numb[i] * p[i];
			}
		}
		ans = Math.abs(a - b) / nod;
		ans_1 = a / nod;
		ans_2 = b / nod;
		gen(0, 1, 1);
		if (ans_1 > ans_2){
			long k = ans_1;
			ans_1 = ans_2;
			ans_2 = k;
		}
		out.println(1l * ans_1 * nod + " " + 1l * nod * ans_2);
		out.close();
	}
}
