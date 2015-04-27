#include <iostream>
#include <cstdio>
using namespace std;
int sum1[262145]; int kol1 = 0;
int sum2[262145]; int kol2 = 0;
int summa1(int l, int r, int L, int R, int x){
    //cout << l << " -- " << r << "  " << L << " -- " << R << " " << x << endl;
    if(L == l && R == r)return sum1[x];
    int M = (L + R) / 2;
    if(r <= M)return summa1(l, r, L, M, (2 * x));
    if(l > M)return summa1(l, r, (M + 1), R, (2 * x + 1));
    return summa1(l, M, L, M, (2 * x)) + summa1((M + 1), r, (M + 1), R, (2 * x + 1));
}
int summa2(int l, int r, int L, int R, int x){
    //cout << l << " -- " << r << "  " << L << " -- " << R << " " << x << endl;
    if(L == l && R == r)return sum2[x];
    int M = (L + R) / 2;
    if(r <= M)return summa2(l, r, L, M, (2 * x));
    if(l > M)return summa2(l, r, (M + 1), R, (2 * x + 1));
    return summa2(l, M, L, M, (2 * x)) + summa2((M + 1), r, (M + 1), R, (2 * x + 1));
}
void add1(int i, int x){
    sum1[i] = x;
    while(i != 0){
        if(i % 2 == 0)i /= 2;
        else i = (i - 1) / 2;
        sum1[i] = sum1[2 * i] + sum1[2 * i + 1];
    }
}
void add2(int i, int x){
    sum2[i] = x;
    while(i != 0){
        if(i % 2 == 0)i /= 2;
        else i = (i - 1) / 2;
        sum2[i] = sum2[2 * i] + sum2[2 * i + 1];
    }
}
int main(){
    freopen("signchange.in", "rt", stdin);
    freopen("signchange.out", "wt", stdout);

    for(int i = 0; i < 262145; i++){
        sum1[i] = 0;
        sum2[i] = 0;
    }
    int n = 0; cin >> n;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            cin >> sum1[kol1 + 131072];
            ++kol1;
        }if(i % 2 == 1){
            cin >> sum2[kol2 + 131072];
            ++kol2;
        }
    }
    for(int i = 131071; i > 0; --i){
        sum1[i] = sum1[2 * i] + sum1[2 * i + 1];
        sum2[i] = sum2[2 * i] + sum2[2 * i + 1];
    }
    int m = 0; cin >> m;
    int t1, t2, t3, l1, l2, r1, r2;
    for(int i = 0; i < m; i++){
        cin >> t1 >> t2 >> t3;
        //cout << t1 << " " << t2 << " " << t3 << endl;
        if(t1 == 1){
            //cout << "*";
            if(t2 % 2 == 0 && t3 % 2 == 0){
                l1 = t2 / 2;
                r1 = t3 / 2;
                if(l1 == r1){
                    cout << summa2(l1, r1, 1, 131071, 1) << endl;
                }
                else{
                    l2 = t2 / 2 + 1;
                    r2 = t3 / 2;
                    //cout << "00   " << t2 << " -- " << t3 << " " << l1 << " - " << r1 << " " << l2 << " - " << r2 << endl;
                    cout << summa2(l1, r1, 1, 131071, 1) - summa1(l2, r2, 1, 131071, 1) << endl;
                }
            }if(t2 % 2 == 0 && t3 % 2 == 1){
                l1 = t2 / 2;
                r1 = t3 / 2;
                l2 = t2 / 2 + 1;
                r2 = t3 / 2 + 1;
                //cout << "01   " << t2 << " -- " << t3 << " " <<  l1 << " - " << r1 << " " << l2 << " - " << r2 << endl;
                cout << summa2(l1, r1, 1, 131071, 1) - summa1(l2, r2, 1, 131071, 1) << endl;
                //cout << summa2(l1, r1, 1, 131071, 1) << " ";
                //cout << summa1(l2, r2, 1, 131071, 1) << endl;
            }if(t2 % 2 == 1 && t3 % 2 == 0){
                l1 = t2 / 2 + 1;
                r1 = t3 / 2;
                l2 = t2 / 2 + 1;
                r2 = t3 / 2;
                //cout << "10   " << t2 << " -- " << t3 << " " <<  l1 << " - " << r1 << " " << l2 << " - " << r2 << endl;
                cout << summa1(l1, r1, 1, 131071, 1) - summa2(l2, r2, 1, 131071, 1) << endl;
            }if(t2 % 2 == 1 && t3 % 2 == 1){
                l1 = t2 / 2 + 1;
                r1 = t3 / 2 + 1;
                if(l1 == r1){
                    cout << summa1(l1, r1, 1, 131071, 1) << endl;
                }
                else{
                    l2 = t2 / 2 + 1;
                    r2 = t3 / 2;
                    //cout << "11   " << t2 << " -- " << t3 << " " <<  l1 << " - " << r1 << " " << l2 << " - " << r2 << endl;
                    cout << summa1(l1, r1, 1, 131071, 1) - summa2(l2, r2, 1, 131071, 1) << endl;
                }
            }
        }
        else if(t1 == 0){
            if(t2 % 2 == 0)add2(131071 + t2 / 2, t3);
            if(t2 % 2 == 1)add1(131071 + t2 / 2 + 1, t3);
        }
    }
    return 0;
}
