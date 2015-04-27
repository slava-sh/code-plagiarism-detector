#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair <int, int> PII;
const LD eps=1e-9;
const LL INF=1ll<<61, Mo=1e9+7;
set <int> ::iterator ii;
int n,m;
int f[200000],a[200000],b[200000];
int h[200000];

int main(){
    scanf("%d%d",&n,&m);
    int i,j,k;
    for (k=1; k<=m; k++){
        char c[2]; int id;
        scanf("%s%d",c,&id);
        if (c[0]=='+') a[k]=1;
        b[k]=id;
    }
    int sum=0;
    vector <int> u;
    for (k=1; k<=m; k++){
        if (sum==0){
            if (a[k] && k==1){
                u.push_back(b[k]); sum++;
            }
            if (a[k] && k>1){
                int flag=0;
                for (i=0; i<u.size(); i++)
                    if (u[i]!=b[k]) f[u[i]]=-1; else flag=1;
                u.clear();
                if (!flag) f[b[k]]=-1;
                else u.push_back(b[k]);
                sum++;
            }
            if (a[k]==0){
                for (i=0; i<u.size(); i++) f[u[i]]=-1;
                u.clear();
                u.push_back(b[k]);
            }
            if (a[k]) h[b[k]]=1; else h[b[k]]=0;
            continue;
        }
        if (a[k]==0 && h[b[k]]==0){
            for (i=0; i<u.size(); i++) f[u[i]]=-1;
            u.clear(); f[b[k]]=-1; //sum--;
            continue;
        }
        if (sum>1 || a[k]!=0) f[b[k]]=-1;
        if (a[k]) sum++; else sum--;
        if (a[k]) h[b[k]]=1; else h[b[k]]=0;
    }
    vector <int> V;
    for (i=1; i<=n; i++)
        if (f[i]>=0) V.push_back(i);
    printf("%d\n",V.size());
    for (i=0; i+1<V.size(); i++) printf("%d ",V[i]);
    if (V.size()>0) printf("%d\n",V.back());
    return 0;
}
