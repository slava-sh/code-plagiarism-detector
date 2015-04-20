import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class travel_od_j {
  static int[] dh = {1, 0, -1, 0};
  static int[] dw = {0, 1, 0, -1};
  static String ds = "SENW";

  public static void main( String[] args ) throws FileNotFoundException {
    Scanner in = new Scanner(new File("travel.in"));
    PrintWriter out = new PrintWriter("travel.out");

    int w = in.nextInt();
    int h = in.nextInt();
    int n = in.nextInt();
  
    char[][] map = new char[h][w];
    for (int i = 0; i < h; i++) {
      String line = in.next();
      for (int j = 0; j < w; j++)
        map[i][j] = line.charAt(j);
    }

  int vh = -1, vw = -1;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      if (map[i][j] == 'V') {
        vh = i;
        vw = j;
      }

  int[][] d = new int[h][w];
  int[][] r = new int[h][w];
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      d[i][j] = 0x7f7f7f7f;

  int[] qh = new int[w * h * 2];
  int[] qw = new int[w * h * 2];
  int ql = w * h, qr = w * h;
  r[vh][vw] = -1;
  d[vh][vw] = 0;
  qh[qr] = vh;
  qw[qr] = vw;
  qr++;
  while (ql < qr) {
    int uh = qh[ql];
    int uw = qw[ql];
    ql++;
    for (int i = 0; i < 4; i++) {
      int th = uh + dh[i];
      int tw = uw + dw[i];
      if (th < 0 || th >= h || tw < 0 || tw >= w)
        continue;
      if (d[th][tw] != 0x7f7f7f7f)
        continue;
      r[th][tw] = i;
      if (map[th][tw] == 'T') {
        d[th][tw] = d[uh][uw];
        ql--;
        qh[ql] = th;
        qw[ql] = tw;
      } else {
        d[th][tw] = d[uh][uw] + 1;
        qh[qr] = th;
        qw[qr] = tw;
        qr++;
      }
    }
  }

  int[][] b = new int[h][w];
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++) {
      b[i][j] = 0;
      if (map[i][j] != 'T')
        continue;
      b[i][j]++;
      for (int t = 0; t < 4; t++) {
        int th = i + dh[t];
        int tw = j + dw[t];
        if (th < 0 || th >= h || tw < 0 || tw >= w)
          continue;
        if (map[th][tw] == 'T')
          b[i][j]++;
      }
    }

  int ans = (int)1e9;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++) {
      if (b[i][j] == 0)
        continue;
      if (b[i][j] == 1)
        ans = Math.min(ans, Math.abs(i - vh) + Math.abs(j - vw) + 2 * (n - 1));
      else
        ans = Math.min(ans, d[i][j] + n);
    }
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++) {
      if (b[i][j] == 0)
        continue;
      if (b[i][j] == 1 && ans == Math.abs(i - vh) + Math.abs(j - vw) + 2 * (n - 1)) {
        char cr = '?', cf = '?';
        while (vh < i) {
          out.print(cf = 'S');
          cr = 'N';
          vh++;
        }
        while (vh > i) {
          out.print(cf = 'N');
          cr = 'S';
          vh--;
        }
        while (vw < j) {
          out.print(cf = 'E');
          cr = 'W';
          vw++;
        }
        while (vw > j) {
          out.print(cf = 'W');
          cr = 'E';
          vw--;
        }
        for (int t = 1; t < n; t++) {
          out.print(cr);
          out.print(cf);
        }
        out.println();
        out.close();
        return;
      }
      if (b[i][j] > 1 && ans == d[i][j] + n) {
        int[] path = new int[w + h + 2 * n];
        int k = 0;
        int th = i, tw = j;
        while (r[th][tw] != -1) {
          int rr = r[th][tw];
          path[k++] = rr;
          th -= dh[rr];
          tw -= dw[rr];
        }
        for (int t = k - 1; t >= 0 && n > 0; t--) {
          out.print(ds.charAt(path[t]));
          vh += dh[path[t]];
          vw += dw[path[t]];
          if (map[vh][vw] == 'T')
            n--;
        }
        while (n > 0) {
          for (int t = 0; t < 4; t++) {
            int xh = vh + dh[t];
            int xw = vw + dw[t];
            if (xh < 0 || xh >= h || xw < 0 || xw >= w)
              continue;
            if (map[xh][xw] == 'T') {
              out.print(ds.charAt(t));
              vh = xh;
              vw = xw;
              n--;
              break;
            }
          }
        }
        out.println();
        out.close();
        return;
      }
    }
  }
}

