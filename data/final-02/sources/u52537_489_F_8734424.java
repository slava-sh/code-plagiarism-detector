import java.io.*;
import java.util.*;

public class F {
    public static void main(String[] args) throws IOException {
        new F().solve();
    }


    void solve() throws IOException {
        FastScanner in = new FastScanner(System.in);

        int C = in.nextInt();
        int R1 = in.nextInt();
        int R2 = C - R1;
        long mod = in.nextLong();

        String[] str = new String[R1];
        for (int r = 0; r < R1; r++) {
            str[r] = in.next();
        }

        int count1 = 0;
        for (int c = 0; c < C; c++) {
            int cnt = 0;
            for (int r = 0; r < R1; r++) {
                cnt += str[r].charAt(c) - '0';
            }
            if (cnt == 1) {
                count1++;
            }
        }

        long[][] dp = new long[R2 + 1][C + 1];
        dp[0][0] = 1;
        for (int r = 1; r <= R2; r++) {
            for (int c1 = 0; c1 <= C; c1++) {
                int c2 = (2 * r - c1) / 2;
                if (0 <= c2 && c2 <= C && c1 + c2 * 2 == r * 2) {
                    for (int x1 = 0; x1 <= Math.min(2, c1); x1++) {
                        int x2 = 2 - x1;
                        if (0 <= x2 && x2 <= c2 && c1 - x1 + x2 <= C) {
                            dp[r][c1] += comb(c1, x1) * comb(c2, x2) * dp[r - 1][c1 - x1 + x2];
                        }
                    }
                }
                dp[r][c1] %= mod;
            }
        }
        System.out.println(dp[R2][count1]);
    }

    // b= 0~2
    long comb(long a, int b) {
        if (b == 0) {
            return 1;
        } else if (b == 1) {
            return a;
        } else if (b == 2) {
            return a * (a - 1) / 2;
        } else {
            // ?????
            return new int[] { 1, 2, 3 }[-1];
        }
    }
    class FastScanner {

        private InputStream _stream;
        private byte[] _buf = new byte[1024];
        private int _curChar;
        private int _numChars;
        private StringBuilder _sb = new StringBuilder();

        FastScanner(InputStream stream) {
            this._stream = stream;
        }

        public int read() {
            if (_numChars == -1) throw new InputMismatchException();
            if (_curChar >= _numChars) {
                _curChar = 0;
                try {
                    _numChars = _stream.read(_buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (_numChars <= 0) return -1;
            }
            return _buf[_curChar++];
        }

        public String next() {
            int c = read();
            while (isWhitespace(c)) {
                c = read();
            }
            _sb.setLength(0);
            do {
                _sb.appendCodePoint(c);
                c = read();
            } while (!isWhitespace(c));
            return _sb.toString();
        }

        public int nextInt() {
            return (int) nextLong();
        }
        public long nextLong() {
            int c = read();
            while (isWhitespace(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isWhitespace(c));
            return res * sgn;
        }

        public boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
    }

}

//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
