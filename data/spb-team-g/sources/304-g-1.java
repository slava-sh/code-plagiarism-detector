import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class G {
	public static void main(String[] args) throws FileNotFoundException {
//		Scanner in = new Scanner(System.in);
		Scanner in = new Scanner(new File("merlin.in"));
		PrintWriter out = new PrintWriter(new File("merlin.out"));
		int n = in.nextInt();
		long[] array = new long[n];
		for (int i = 0; i < n; i++) {
			array[i] = in.nextLong();
		}
		Arrays.sort(array);
		long[] prefSum = new long[n + 1];
		for (int i = 1; i < n + 1; i++) {
			prefSum[i] = prefSum[i - 1] + array[i - 1];
		}
		long sum = 0;
		for (int i = n;; i--) {
			if (array[i - 1] * i - prefSum[i] <= sum) {
				out.println(n - i);
				out.close();
				in.close();
				return;
			}
			sum += array[i - 1];
		}
	}
}
