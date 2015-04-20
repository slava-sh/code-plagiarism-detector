import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Random;
import java.util.Scanner;


public class Chess {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("tictactoe.in"));
		Random rand = new Random(Math.abs((13 + 666 + in.nextInt()) * in.nextInt()));
		PrintWriter out = new PrintWriter(new File("tictactoe.out"));
		out.println(rand.nextInt(3));
		out.close();
	}
}
