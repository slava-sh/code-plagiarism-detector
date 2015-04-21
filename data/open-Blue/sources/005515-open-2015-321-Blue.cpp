#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
using namespace std;
string s;
int mar[40000],t,ff[100000],ln[300000],ll[100000],rr[10000],kl,n,m,a[50000];
void tryfind1() {
    for (int len=1;len<=n;len++) {
        if (m%len!=0) continue;
        int l=a[1];
        int r=a[len];
        int st=len+1;
        int bad=0;
        while (st<=m) {
            if (a[st]!=l || a[st+len-1]!=r) bad=1;
            st+=len;
        }
        if (bad==0) {
            if (n>10) return;
            cout << 1 << "\n";
            for (int i=0;i<len;i++) cout << s[i];
            cout << "\n";
            exit(0);
        }
    }
}
bool check(int x, int len) {
    int l=a[1];
    int r=a[len];
    int st=len+1;
    int bad=0;
    while (st<=x) {
            if (a[st]!=l || a[st+len-1]!=r) bad=1;
            st+=len;
    }
    if (bad==0) return false;
    return true;
}
void go(int x) {
    if (x==m+1) {
        if (n>10) return;
        cout << 2 << "\n";
        for (int i=ll[1]-1;i<rr[1];i++) cout <<s[i];
        cout << "\n";
        for (int i=ll[2]-1;i<rr[2];i++) cout <<s[i];
        cout << "\n";
        exit(0);
    }
    if (ff[x]==t) return;
    ff[x]=t;
    for (int j=1;j<=2;j++)
        if (x+ln[j]-1<=m) {
            if (a[x]!=a[ll[j]]) continue;
            if (a[x+ln[j]-1]!=a[rr[j]]) continue;
            go(x+ln[j]);
        }
}
void tryfind2() {
    for (int len=1;len<=n;len++) {
        kl=1;
        ll[kl]=1;
        rr[kl]=len;
        ln[kl]=len;
        for (int j=len;j<=m;j+=len) {
            if (check(j,len)) break;
            for (int k=1;k<=min(m-j,n);k++) {
                kl=2;
                ll[kl]=j+1;
                rr[kl]=j+k;
                ln[kl]=k;
                t++;
                go(j+k+1);
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    cin >> s;
    m=s.size();
    if (n>=m) {
        if (n>10) return 0;
        cout << 1 << "\n";
        cout << s << "\n";
        exit(0);
    }
    for (int i=1;i<=m;i++) a[i]=s[i-1]-'a'+1;
    tryfind1();
    tryfind2();
    int v=0;
    for (int i=0;i<m;i++) {
        int k=s[i]-'a'+1;
        if (mar[k]==0) v++;
        mar[k]=1;
    }
    if (n>10) return 0;
    cout << v << "\n";
    for (int i=1;i<=3;i++) {
        if (mar[i]==1) {
            char c='a'+i-1;
            cout << c << "\n";
        }
    }

    return 0;
}
