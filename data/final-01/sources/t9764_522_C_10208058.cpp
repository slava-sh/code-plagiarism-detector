#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <cstdio> 

using namespace std;

int main(){
    int t, n, k, m, q;
    scanf("%d", &t);
    for (int ii = 0; ii < t; ii++){
        scanf("%d%d", &m, &k);
        vector <int> food(k, 0);
        for (int i = 0; i < k; i++){
            scanf("%d", &food[i]);
        }
        vector <int> ans(m - 1, 0);
        int num;
        int f = 0;
        for (int i = 0; i < m - 1; i++){
            scanf("%d%d", &ans[i], &q);
            if ((q == 1) && (f != 1)){
                num = i;
                f = 1;
            }
        }


        if (f == 0){
            int kol = 0;
            for (int i = 0; i < m - 1; i++){
                if (ans[i] != 0){
                    food[ans[i] - 1]--;
                }
                else{
                    kol++;
                }
            }
            for (int i = 0; i < k; i++){
                if (food[i] <= kol){
                    cout << "Y";
                }
                else{
                    cout << "N";
                }
            }
            cout << "\n";
        }

        else{
            vector <int> fan(k, 1);
            vector <int> used(k, 0);
            int kol = 0;
            for (int i = num; i < m - 1; i++){
                if (ans[i] != 0){
                    used[ans[i] - 1] = 1;
                }
            }
            for (int i = 0; i < num; i++){
                if (ans[i] != 0){
                    food[ans[i] - 1]--;
                }
                else{
                    kol++;
                }
            }
            int minkol, minnum;
            minkol = 10000000;
            for (int i = 0; i < k; i++){
                if ((food[i] <= kol) && (used[i] != 1)){
                    fan[i] = 0;
                    if ((food[i] < minkol) && (used[i] != 1)){
                        minkol = food[i];
                        minnum = i;
                    }
                }
            }
            int kol2 = 0;
            for (int i = num; i < m - 1; i++){
                if (ans[i] != 0){
                    food[ans[i] - 1] --;
                }
                else{
                    kol2++;
                }
            }
            for (int i = 0; i < k; i++){
                if (fan[i] == 0){
                    cout << "Y";
                    continue;
                }
                if (food[i] <= (kol - minkol) + kol2){
                    cout << "Y";
                }
                else{
                    cout << "N";
                }
            }
            cout << "\n";
        }

    }
    return 0;
}