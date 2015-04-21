import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Random;


public class Magenta {
	static BufferedReader in;
	static boolean go(char c) throws IOException {
		System.out.println(c);
		System.out.flush();
		if (in.readLine().charAt(0) != 'N') {
			return true;
		}
		return false;
	}

	static boolean makeCircle(int r) throws IOException {
		for (int i = 0; i < r; i++) {
			if (go('R')) {
				return true;
			}
		}
		// go to begin
		//
		for (int i = 0; i < r; i++) {
			if (go('U')) {
				return true;
			}
		}
		for (int i = 0; i < 2 * r; i++) {
			if (go('L')) {
				return true;
			}
		}
		for (int i = 0; i < 2 * r; i++) {
			if (go('D')) {
				return true;
			}
		}
		for (int i = 0; i < 2 * r; i++) {
			if (go('R')) {
				return true;
			}
		}
		for (int i = 0; i < r - 1; i++) {
			if (go('U')) {
				return true;
			}
		}
		//go back
		for (int i = 0; i < r - 1; i++) {
			if (go('D')) {
				return true;
			}
		}
		for (int i = 0; i < 2 * r; i++) {
			if (go('L')) {
				return true;
			}
		}
		for (int i = 0; i < 2 * r; i++) {
			if (go('U')) {
				return true;
			}
		}
		for (int i = 0; i < 2 * r; i++) {
			if (go('R')) {
				return true;
			}
		}
		for (int i = 0; i < r; i++) {
			if (go('D')) {
				return true;
			}
		}
		for (int i = 0; i < r; i++) {
			if (go('L')) {
				return true;
			}
		}
		return false;
	}

	//	public static void main(String[] args) throws IOException {
	//		in  = new BufferedReader(new InputStreamReader(System.in));
	//		for (int i = 1;; i++) {
	//			if (makeCircle(i)) {
	//				in.close();
	//				return;
	//			}
	//		}
	//	}

	public static void main(String[] args) throws IOException {
		in  = new BufferedReader(new InputStreamReader(System.in));
		//		for (int i = 0;; i++) {
		//			if (go('U')) {
		//				return;
		//			}
		//			if ((i & 1) == 1) {
		//				for (int k = 0; k < i; k++) {
		//					if (go('L')) {
		//						return;
		//					}
		//				}
		//			} else {
		//				for (int k = 0; k < i; k++) {
		//					if (go('R')) {
		//						return;
		//					}
		//				}
		//			}
		//		}
		//		Random rand = new Random(42);
		//		char[] steps = {'L', 'U', 'R', 'D'};
		//		int cur = 0;
		//		for (int i = 1;; i++) {
		//			for (int it = 0; it < 2; it++) {
		//				cur++;
		//				for (int j = 0; j < i; j++) {
		//					if (go(steps[cur & 3])) {
		//						return;
		//					}
		//				}
		//			}
		//		}
		//		for (int i = 1;; i++) {
		//			if (go('R')) {
		//				return;
		//			}
		//			for (int j = 0; j < 2 * i - 1; j++) {
		//				if (go('U')) {
		//					return;
		//				}
		//			}
		//			for (int j = 0; j < 2 * i - 1; j++) {
		//				if (go('L')) {
		//					return;
		//				}
		//			}
		//			if (go('U')) {
		//				return;
		//			}
		//			for (int j = 0; j < 2 * i; j++) {
		//				if (go('R')) {
		//					return;
		//				}
		//			}
		//			for (int j = 0; j < 2 * i; j++) {
		//				if (go('D')) {
		//					return;
		//				}
		//			}
		//		}

		int x = 2;
		int y = 19;
		for (int i = 0;; i++) {
			for (int j = 0; j < x; j++) {
				if (go('R')) {
					return;
				}
			}
			for (int j = 0; j < y; j++) {
				if (go('D')) {
					return;
				}
			}
		}
	}
}
