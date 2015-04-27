#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define MAXN 100010
using namespace std;
int n, m;
int cnt[MAXN];
char a[MAXN];
int b[MAXN];
bool appear[MAXN];
int ans[MAXN];

char getcc(){
    char ch;
    while (1){
        ch = getchar();
        if (ch == '+' || ch == '-') return ch;
    }
}

void output(){
    vector <int> Outp;
    for (int i = 1; i <= n; ++i){
        if (ans[i])
            Outp.push_back(i);
    }
    printf("%d\n", Outp.size());
    if (Outp.size()){
        for (int i = 0; i < Outp.size(); ++i){
            if (i) printf(" ");
            printf("%d", Outp[i]);
        }
        printf("\n");
    }
}

void check_first(){
    memset(cnt, 0, sizeof(cnt));
    //memset(tot, 0, sizeof(tot));
    int tmp = 0;
    int last = 0;
    for (int i = 0; i < m; ++i){
        if (a[i] == '-'){
            if (tmp > 1) ans[b[i]] = 0;
            if (tmp == 1 && last != b[i]) ans[b[i]] = 0;
            if (cnt[b[i]]){
                cnt[b[i]]--;
                tmp--;
            }
        }
        else{
            cnt[b[i]]++;
            tmp++;
            if (tmp == 1) last = b[i];
        }
    }
}


void check_end(){
    memset(cnt, 0, sizeof(cnt));
    int tmp = 0;
    int last = 0;
    for (int i = m - 1; i >= 0; --i){
        if (a[i] == '+'){
            if (tmp > 1) ans[b[i]] = 0;
            if (tmp == 1 && last != b[i]) ans[b[i]] = 0;
            if (cnt[b[i]]){
                cnt[b[i]]++;
                tmp--;
            }
        }else{
            cnt[b[i]]--;
            tmp++;
            if (tmp == 1) last = b[i];
        }
    }
}

int main(){
   // freopen("input.txt", "r", stdin);
    memset(appear, 0, sizeof(appear));
    memset(ans, 0, sizeof(ans));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        ans[i] = 1;
    for (int i = 0; i < m; ++i){
        a[i] = getcc();
        scanf("%d", &b[i]);
        //appear[b[i]] = 1;
    }
    for (int i = 1; i < m; ++i)
        if (a[i] == '+')
            if (a[i - 1] == '-' && b[i - 1] == b[i]);
            else ans[b[i]] = 0;
    for (int i = 0; i < m - 1; ++i)
        if (a[i] == '-')
            if (a[i + 1] == '+' && b[i + 1] == b[i]);
            else ans[b[i]] = 0;
    check_first();
    check_end();
    output();
    return 0;
}
