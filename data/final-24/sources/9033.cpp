#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int INF=1000000000;

char s[20200];
bool u[3];
int p[20200];

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int m;
    scanf("%d\n", &m);
    gets(s);
    int n=strlen(s);
    for (int i=0; i<n; ++i)
        u[s[i]-'a']=true;
    int t=u[0]+u[1]+u[2];
    if (t==1){
        printf("1\n%c\n", s[0]);
        return 0;
    }
    p[0]=0;
    for (int i=1; i<n; ++i){
        int j=p[i-1];
        while (j && s[i]!=s[j])
            j=p[j-1];
        if (s[i]==s[j])
            ++j;
        p[i]=j;
    }
    if (n%(n-p[n-1])==0 && n-p[n-1]<=m){
        puts("1");
        for (int i=0; i<n-p[n-1]; ++i)
            putchar(s[i]);
        puts("");
        return 0;
    }
    if (t==2){
        puts("2");
        if (!u[0])
            printf("b\nc\n");
        if (!u[1])
            printf("a\nc\n");
        if (!u[2])
            printf("a\nb\n");
        return 0;
    }
    for (int i=1; i<=min(m, n); ++i){
        int x=i, l=0;
        for (int k=i; k<n; ++k){
            if (s[l]==s[k])
                ++l;
            else
                break;
            if (l==i)
                l=0, x=k+1;
        }
        for (int j=x+1; j<=min(x+m, n); ++j){
            bool f=true;
            int l=0, r=x;
            for (int k=j; k<n; ++k){
                if (l!=-1 && s[k]==s[l])
                    ++l;
                else
                    l=-1;
                if (r!=-1 && s[k]==s[r])
                    ++r;
                else
                    r=-1;
                if (l==i || r==j)
                    l=0, r=x;
                if (l==-1 && r==-1){
                    f=false;
                    break;
                }
            }
            if (f && (l==0 || r==x)){
                puts("2");
                for (int k=0; k<i; ++k)
                    putchar(s[k]);
                puts("");
                for (int k=x; k<j; ++k)
                    putchar(s[k]);
                puts("");
                return 0;
            }
        }
    }
    printf("3\na\nb\nc\n");
    return 0;
}
