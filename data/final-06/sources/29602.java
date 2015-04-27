import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

@SuppressWarnings("ReturnOfCollectionOrArrayField")
public final class Reshenie {
    @SuppressWarnings("PublicField")
    public InputStreamReader f1 = new InputStreamReader(System.in);
    private final BufferedReader f2 = new BufferedReader(f1);
    private final Scanner f3 = new Scanner(f1);

    private final int[] f4 = new int[28];
    private final int[] f5 = new int[28];
    private final int[] f6 = new int[28];
    private final int[] f7 = new int[28];
    private final int[] f8 = new int[28];

    private int f9;
    private int[][] f10;

    private int f11;
    private int f12;

    private boolean[][] f13;

    public InputStreamReader getF1() {
        return f1;
    }

    public Scanner getF3() {
        return f3;
    }

    public int[] getF4() {
        return f4;
    }

    public int[] getF5() {
        return f5;
    }

    public int[] getF6() {
        return f6;
    }

    public int[] getF7() {
        return f7;
    }

    public int[] getF8() {
        return f8;
    }

    public int getF9() {
        return f9;
    }

    public int[][] getF10() {
        return f10;
    }

    public int getF11() {
        return f11;
    }

    public int getF12() {
        return f12;
    }

    public boolean[][] getF13() {
        return f13;
    }

    public int getF14() {
        return f14;
    }

    public int[] getF15() {
        return f15;
    }

    public int[] getF16() {
        return f16;
    }

    public char[][] getF17() {
        return f17;
    }

    @SuppressWarnings({"OverlyComplexMethod", "OverlyLongMethod", "CharUsedInArithmeticContext"})
    void m1() {
        f11 = f3.nextInt();
        f12 = f3.nextInt();
        String[] v1 = new String[f11];
        for (int v2 = 0; v2 < f11; v2++) {
            v1[v2] = f3.next();
        }
        f13 = new boolean[f11][f12];
        f10 = new int[f11][f12];
        for (int v3 = 0; v3 < f11; v3++) {
            for (int v4 = 0; v4 < f12; v4++) {
                f13[v3][v4] = v1[v3].charAt(v4) != '.';
                if (f13[v3][v4]) {
                    char v5 = v1[v3].charAt(v4);
                    int v6;
                    if (v5 == 'A') {
                        v6 = 26;
                    } else if (v5 == 'B') {
                        v6 = 27;
                    } else {
                        v6 = v5 - 'a';
                    }
                    f4[v6]++;
                    if (f4[v6] == 1) {
                        f5[v6] = v3;
                        f6[v6] = v4;
                    } else {
                        f7[v6] = v3;
                        f8[v6] = v4;
                    }
                }
            }
        }

        for (int v7 = 0; v7 < f11; v7++) {
            Arrays.fill(f10[v7], -1);
        }
        for (int v8 = 0; v8 < f11; v8++) {
            for (int v9 = 0; v9 < f12; v9++) {
                if (f13[v8][v9] && f10[v8][v9] == -1) {
                    f10[v8][v9] = f9;
                    f10[v8 + 1][v9] = f9;
                    f10[v8][v9 + 1] = f9;
                    f10[v8 + 1][v9 + 1] = f9++;
                }
            }
        }
    }

    private int f14;

    private final int[] f15 = new int[7];
    private final int[] f16 = new int[14];

    private char[][] f17;

    @SuppressWarnings({"CharUsedInArithmeticContext", "NumericCastThatLosesPrecision", "OverlyComplexMethod", "OverlyLongMethod"})
    void m2(int v10, int v11) {
        if (v10 == 14) {
            boolean[][] v12 = new boolean[7][7];
            for (int v13 = 0; v13 < 28; v13++) {
                int v14 = f16[f10[f5[v13]][f6[v13]]];
                int v15 = f16[f10[f7[v13]][f8[v13]]];
                if (v14 < v15) {
                    int v16 = v14;
                    v14 = v15;
                    v15 = v16;
                }
                if (v12[v14][v15]) {
                    return;
                }
                v12[v14][v15] = true;
            }
            f14++;
            if (f14 == 1) {
                f17 = new char[f11][f12];
                for (int v17 = 0; v17 < f11; v17++) {
                    for (int v18 = 0; v18 < f12; v18++) {
                        if (f13[v17][v18]) {
                            f17[v17][v18] = (char) ('0' + f16[f10[v17][v18]]);
                        } else {
                            f17[v17][v18] = '.';
                        }
                    }
                }
            }
            return;
        }
        for (int v19 = 0; v19 < v11; v19++) {
            if (f15[v19] < 2) {
                f16[v10] = v19;
                f15[v19]++;
                m2(v10 + 1, v11);
                f15[v19]--;
            }
        }
        if (v11 < 7) {
            f16[v10] = v11;
            f15[v11]++;
            m2(v10 + 1, v11 + 1);
            f15[v11]--;
        }
    }

    void m3() {
        m2(0, 0);
    }

    void m4() {
        System.out.println(5040 * f14);
        for (int v20 = 0; v20 < f11; v20 += 1) {
            System.out.println(new String(f17[v20]));
        }
    }

    static void m5() throws Exception {
        Reshenie v21 = new Reshenie();
        v21.m1();
        v21.m3();
        v21.m4();
    }

    public static void main(String[] args) throws Exception {
        m5();
    }

    public BufferedReader getF2() {
        return f2;
    }
}
