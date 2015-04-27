import java.io.InputStream;
import java.io.FilterInputStream;
import java.util.NoSuchElementException;
import java.io.BufferedInputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Iterator;
import java.io.IOException;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Zyflair Griffane
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputUtil in = new InputUtil(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, InputUtil in, PrintWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();

        String s = in.next();
        int[] z = ZValues.getZValues(s);

        int max = -1;
        if (k == 1) {
            max = n;
        }
        StringBuilder res = new StringBuilder();

        for (int i = 1; i <= n; i++) {
            if (k > 1 && i % k < 1) {
                int len = i / k;
                if (z[len] + len >= i) {
                    int j = 0;
                    if (i < n) {
                        j = Math.min(len, z[i]);
                    }
                    max = Math.max(max, i + j);
                }
            }
            res.append(max >= i ? "1" : "0");
        }

        out.println(res.toString());
    }
}

class InputUtil {

    JoltyScanner in;

    public InputUtil(InputStream istream) {
        in = new JoltyScanner(istream);
    }

    public String next() {
        return in.nextOrNull();
    }

    public int nextInt() {
        String s = next();
        if (s == null) {
            throw new NoSuchElementException("Attempted to read integer that is not there.");
        }
        return Integer.parseInt(s);
    }

}

class ZValues {
    public static int[] getZValues(String str) {
        char[] s = str.toCharArray();
        int n = s.length;
        int[] z = new int[n];
        int l = 0;
        int r = 0;
        z[0] = n;
        for (int i = 1; i < n; i++) {	
            if (i < r && z[i - l] != r - i) {
                z[i] = Math.min(z[i - l], r - i);
            }
            else {
                l = i;
                r = Math.max(r, l);
                z[i] = r - l;
                while (r < n && s[r] == s[z[i]]) {
                    r++;
                    z[i]++;
                }
            }
        }
        return z;
    }
}

class JoltyScanner {
    public static final int BUFFER_SIZE = 1 << 16;
	public static final char NULL_CHAR = (char) -1;

    BufferedInputStream in;
	StringBuilder str = new StringBuilder();
	byte[] buffer = new byte[BUFFER_SIZE];
	boolean EOF_FLAG = false;

    char c = NULL_CHAR;
	int bufferIdx = 0;
    int size = 0;

	public JoltyScanner(InputStream in) {
		this.in = new BufferedInputStream(in, BUFFER_SIZE);
	}

    public String next() {
		checkEOF();
		for (c = c == NULL_CHAR ? nextChar() : c; Character.isWhitespace(c); checkEOF()) {
			c = nextChar();
		}
		str.setLength(0);
		for (; !EOF_FLAG && !Character.isWhitespace(c); c = nextChar()) {
			str.append(c);
		}
		return str.toString();
	}

	public String nextOrNull() {
		try {
			return next();
		} catch (EndOfFileException e) {
			return null;
		}
	}

    public char nextChar() {
		if (EOF_FLAG) {
			return NULL_CHAR;
		}
		while (bufferIdx == size) {
			try {
				size = in.read(buffer);
				if (size == -1) {
					throw new Exception();
				}
			} catch (Exception e) {
				EOF_FLAG = true;
				return NULL_CHAR;
			}
			if (size == -1) {
				size = BUFFER_SIZE;
			}
			bufferIdx = 0;
		}
		return (char) buffer[bufferIdx++];
	}

    public void checkEOF() {
		if (EOF_FLAG) {
			throw new EndOfFileException();
		}
	}

	public class EndOfFileException extends RuntimeException {
	}
}

