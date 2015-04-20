#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 1e3;
const int MAXK = 1e5;

bool code[MAXN][MAXK];

long long pow(int a, int b) {
    long long tmp = 1;
    for (int i = 0; i < b; i++) {
        tmp *= a;
    }
    return tmp;
}

int main() {
    freopen("numbers.in", "r", stdin);
    freopen("numbers.out", "w", stdout);
    int n;
    int m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int codeGov;
        scanf("%d", &codeGov);
        int codeReg;
        int c;
        scanf("%d", &c);
        //printf("%d\n", c);
        for (int j = 0; j < c; j++) {
            scanf("%d", &codeReg);
            code[codeGov][codeReg] = true;
        }
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
       // printf("%d\n", 5);
        int tmp1;
        int tmp2;
        int tmp3;
        long long number;
        bool fl = true;
        cin >> number;
        for (int j = 1; j <= 3; j++) {
            long long div1 = pow(10, 11 - j);
            tmp1 = number / div1;
            //cout << div1 << " " << tmp1 << "\n";
            for (int k = j + 3; k <= j + 5; k++) {
                long long div2 = pow(10, 11 - k);
                tmp2 = (number % div1) / div2;
                tmp3 = number % div2;
                //printf("%d %d %d\n", tmp1, tmp2, tmp3);
                if ((code[tmp1][tmp2]) && (tmp3 >= (div2 / 10)) && (tmp2 >= pow(10, 11 - j - 1) / div2) && (tmp1 >= 1e10 / div1)) {
                    fl = false;
                    printf("+%d(%d)", tmp1, tmp2);
                    if (div2 == 1e7 || div2 == 1e6) {
                        //printf("%d-%d-%d", tmp3 / 10000, (tmp3 % 10000) / 100, tmp3 % 100);
                        int a = tmp3 / 10000;
                        printf("%d-", a);
                        a = (tmp3 % 10000) / 100;
                        if (a < 10) {
                            printf("0");
                        }
                        printf("%d-", a);
                        a = tmp3 % 100;
                        if (a < 10) {
                            printf("0");
                        }
                        printf("%d", a);
                        break;
                    }
                    if (div2 == 1e5 || div2 == 1e4) {
                        printf("%d-", tmp3 / 100);
                        if (tmp3 % 100 < 10) {
                            printf("0");
                        }
                        printf("%d", tmp3 % 100);
                        break;
                    }
                    if (div2 == 1e3) {
                        printf("%d", tmp3);
                        break;
                    }
                }

            }
        }
        if (fl) {
            printf("Incorrect");
        }
        printf("\n");
    }
}
