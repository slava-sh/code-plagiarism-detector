import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


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
		for (int i = 0; i < r; i++) {
			if (go('U')) {
				return true;
			}
		}
		return false;
	}
	
	public static void main(String[] args) throws IOException {
		in  = new BufferedReader(new InputStreamReader(System.in));
		for (int i = 1;; i++) {
			if (go('R')) {
				in.close();
				return;
			}
			if (makeCircle(i)) {
				in.close();
				return;
			}
		}
	}
}
