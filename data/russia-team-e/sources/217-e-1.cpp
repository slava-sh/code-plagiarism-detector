#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

struct item{
    int next[30];
    bool leaf;
};

int n, m;
item a[101][101];
string s[101];
int t[101];
char z[12];

inline void init(int i, int v){
    for (int j=0; j<30; ++j)
        a[i][v].next[j]=-1;
    a[i][v].leaf=0;
}

inline string toStr(int x){
    string s="";
    while (x){
        s+=char(int('0') + x%10);
        x/=10;
    }
    int l=s.length();
    for (int i=0; i<l/2; ++i)
        swap(s[i], s[l-i-1]);
    return s;
}

inline void add(int i, string s){
    int v=0, l=s.length();
    for (int j=0; j<l; ++j){
        char c=s[j]-'0';
        if (a[i][v].next[c]==-1){
            init(i, t[i]);
            a[i][v].next[c]=t[i];
            ++t[i];
        }
        v=a[i][v].next[c];
    }
    a[i][v].leaf=1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    freopen("numbers.in", "r", stdin);
    freopen("numbers.out", "w", stdout);
    scanf("%d", &n);
    for (int i=0; i<n; ++i){
        t[i]=1;
        init(i, 0);
        int x, k;
        scanf("%d%d", &x, &k);
        s[i]=toStr(x);
        for (int j=0; j<k; ++j){
            scanf("%d", &x);
            add(i, toStr(x));
        }
    }
    scanf("%d", &m);
    while (m--){
        scanf("%s", z);
        bool q=0;
        for (int i=0; i<n; ++i){
            bool f=1;
            int l=s[i].length();
            for (int j=0; j<l; ++j)
                if (s[i][j]!=z[j]){
                    f=0;
                    break;
                }
            if (!f) continue;
            int v=0;
            int r;
            for (int j=l; j<11; ++j){
                if (a[i][v].leaf==1&&z[j]!='0'){
                    r=j;
                    break;
                }
                if (a[i][v].next[z[j]-'0']==-1){
                    f=0;
                    break;
                }
                v=a[i][v].next[z[j]-'0'];
            }
            if (!f) continue;
            q=1;
            printf("+");
            for (int j=0; j<l; ++j)
                printf("%c", z[j]);
            printf("(");
            for (int j=l; j<r; ++j)
                printf("%c", z[j]);
            printf(")");
            if (11-r==3)
                printf("%c%c%c\n", z[r], z[r+1], z[r+2]);
            else
                if (11-r==4)
                    printf("%c%c-%c%c\n", z[r], z[r+1], z[r+2], z[r+3]);
                else
                    if (11-r==5)
                        printf("%c%c%c-%c%c\n", z[r], z[r+1], z[r+2], z[r+3], z[r+4]);
                    else
                        if (11-r==6)
                            printf("%c%c-%c%c-%c%c\n", z[r], z[r+1], z[r+2], z[r+3], z[r+4], z[r+5]);
                        else
                            printf("%c%c%c-%c%c-%c%c\n", z[r], z[r+1], z[r+2], z[r+3], z[r+4], z[r+5], z[r+6]);
            break;
        }
        if (!q) puts("Incorrect");
    }
    return 0;
}
