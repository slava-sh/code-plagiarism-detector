import java.util.*;
import java.io.*;

public class J {
	public static void main(String[] args) throws FileNotFoundException {
		File fin = new File("seq.in"), fout = new File("seq.out");
		Scanner in = new Scanner(fin);
		PrintWriter out = new PrintWriter(fout);
//		Scanner in = new Scanner(System.in);
//		PrintWriter out = new PrintWriter(System.out);
		int n = in.nextInt(), h = in.nextInt();
		int[] arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = in.nextInt();
		}
		int rightBoarder = n - 1;
		long min = Long.MAX_VALUE;
		int leftBorder = n - 1;
		long[] prefSum = new long[n + 1];
		for (int i = 1; i < n + 1; i++) {
			prefSum[i] = prefSum[i - 1] + arr[i - 1];
		}
		long mustSum = h * (h + 1) / 2;
		while (leftBorder >= 0) {
			if (rightBoarder - leftBorder == h - 1 && arr[leftBorder] <= 1) {
				min = Math.min(min, mustSum - (prefSum[rightBoarder + 1] - prefSum[leftBorder]));
				rightBoarder--;
				leftBorder--;
				continue;
			}
			if (arr[leftBorder] > arr[rightBoarder] - (rightBoarder - leftBorder)) {
				rightBoarder -= arr[leftBorder] - arr[rightBoarder] + (rightBoarder - leftBorder);
			}
			leftBorder--;
		}
		out.println(min == Long.MAX_VALUE? -1 : min);
		out.close();
		in.close();
	}
}
