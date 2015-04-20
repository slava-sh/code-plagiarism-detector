import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.OutputStream;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;


public class Main {
	public static void main(String[] args) throws Exception{
		BufferedReader in = new BufferedReader(new FileReader("chess.in"));
        int n = Integer.parseInt(in.readLine());
        String line = in.readLine();
        int[] mas = new int[n];
        String[] smas = line.split(" ");
        for(int i = 0; i < n; i++){
            mas[i] = Integer.parseInt(smas[i]);
        }
        List<String> lst = new ArrayList<String>();
        int j = 0;
        for(int i = 0; i < n; i++){
            if(mas[i] >= lst.size()){
                lst.add((i + 1) + " " + (j + 1));
                j++;
            }
        }
        String line1 = "";
        line1+= lst.size() + "\n";
        for(int i = 0; i < lst.size(); i++){
            line1+=lst.get(i) + "\n";
        }
        Path p = Paths.get("chess.out");
        Files.write(p, line1.getBytes());
	}

}
