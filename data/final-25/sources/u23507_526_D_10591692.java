import java.util.Arrays;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Tifuera
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    boolean[] answer;
    int[] zet;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        String str = in.next();

        getZetFunction(str);

        answer = new boolean[n];
        if (k == 1) {
            Arrays.fill(answer, true);
        } else {
            solveByTimes(str, k);
            addLastPart(str, k);
            //insert code for 2*k+1
            solveByTimes(str, k + 1);
        }

        for (boolean r : answer) {
            out.print(r ? '1' : '0');
        }
    }

    private void addLastPart(String str, int k) {
        int idx = 1;
        boolean[] answerCopy = new boolean[answer.length];
        System.arraycopy(answer, 0, answerCopy, 0, answerCopy.length);
        int lastSetLeft = -1;
        while (idx < answer.length) {
            if (answer[idx]) {
                int step = (idx + 1) / k;
                int zz = idx + 1 < str.length() ? zet[idx + 1] : 0;
                int toGo = Math.min(step, zz + 1);

                int start = Math.max(idx + 1, lastSetLeft + 1);
                for (int i = start; i < idx + toGo; i++) {
                    answerCopy[i] = true;
                    lastSetLeft = Math.max(lastSetLeft, i);
                }
                idx++;

            } else {
                idx++;
            }
        }

        for (int i = 0; i < answerCopy.length; i++) {
            if (answerCopy[i]) {
                answer[i] = answerCopy[i];
            }
        }
    }

    private void solveByTimes(String str, int k) {
        for (int i = 0; i < str.length(); i++) {
            if ((i + 1) % k == 0) {
                int step = (i + 1) / k;
                int j = (step - 1);
                boolean isGood = true;
                while (j < i) {
                    if (zet[j + 1] < step) {
                        isGood = false;
                        break;
                    }
                    j += step;
                }

                if (isGood) {
                    answer[i] = true;
                }
            }
        }
    }

    private int[] getZetFunction(String str) {
        int n = str.length();
        zet = new int[n];
        for (int i = 1, l = 0, r = 0; i < n; ++i) {
            if (i <= r) {
                zet[i] = Math.min(r - i + 1, zet[i - l]);
            }

            while (i + zet[i] < n && str.charAt(zet[i]) == str.charAt(i + zet[i])) {
                zet[i]++;
            }

            if (i + zet[i] - 1 > r) {
                l = i;
                r = i + zet[i] - 1;
            }
        }
        return zet;
    }

//    private int[] getPrefixFunction(String str) {
//        int n = str.length();
//        pi = new int[n];
//        for (int i = 1; i < n; i++) {
//            int j = pi[i - 1];
//            while (j > 0 && str.charAt(i) != str.charAt(j)) {
//                j = pi[j - 1];
//            }
//
//            if (str.charAt(i) == str.charAt(j)) {
//                j++;
//            }
//            pi[i] = j;
//        }
//
//        return pi;
//    }

}

class InputReader {
    private BufferedReader reader;
    private String[] currentArray;
    private int curPointer;

    public InputReader(InputStream inputStream) {
        reader = new BufferedReader(new InputStreamReader(inputStream));
    }


    public String next() {
        try {
            currentArray = null;
            return reader.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public int nextInt() {
        if ((currentArray == null) || (curPointer >= currentArray.length)) {
            try {
                currentArray = reader.readLine().split(" ");
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            curPointer = 0;
        }
        return Integer.parseInt(currentArray[curPointer++]);
    }

}

