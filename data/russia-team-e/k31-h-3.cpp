#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cmath>
#define INF 10000000009
using namespace std;
long long n, m, g[5009][5009], d[100009], ind, u[100009],ans=INF,in[5009],ot[100009],ku[100009],st[100009],ansot,ansku;
int ser,der,asd;

void dij(int c){
    for(int i=1;i<=m;i++){
        if((in[ot[i]]==in[c]&&ot[i]!=c)||(in[ku[i]]==in[c]&&ku[i]!=c))
            g[ot[i]][ku[i]]=g[ku[i]][ot[i]]=0;
        else g[ot[i]][ku[i]]=g[ku[i]][ot[i]]=st[i];
    }
//    cout<<endl;
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=n;j++)
//            cout<<g[i][j]<<" ";
//        cout<<endl;
//    }
//    system("pause");
    for(int i=1;i<=n;i++)
        d[i]=INF,u[i]=0;
    d[c]=0;
    for(int i=1;i<=n;i++)
    {
        ind=-1;
        for(int j=1;j<=n;j++)
        {
            if(u[j]==0 && (ind==-1 || d[j]<d[ind]))
                ind=j;
        }
        if(d[ind]>=INF)
            break;
        u[ind]=1;
        for(int k=1;k<=n;k++)
        {
            if(g[ind][k]!=0)
                if(d[ind]+g[ind][k]<d[k])
                    d[k]=d[ind]+g[ind][k];
        }
    }
//    cout<<c<<endl;
//    for(int i=1;i<=n;i++)
//        cout<<d[i]<<" ";
//    system("pause");
    for(int i=1;i<=n;i++)
        if(in[i]!=in[c]&&in[i]!=0&&d[i]<INF)
            if(ans>d[i])
                ans=d[i],ansot=c,ansku=i;
}

int main()
{
    freopen("secure.in","r",stdin);
    freopen("secure.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>in[i];
        if(in[i]==1)ser++;
        if(in[i]==2)der++;
        }
    for(int i=1;i<=m;i++)
        cin>>ot[i]>>ku[i]>>st[i];
    if(ser>der){
        asd=1;
    }
    else asd=2;
    for(int i=1;i<=n;i++){
        if(in[i]==asd||in[i]==0)
            continue;
        dij(i);
    }
    if(ansot==0)
        cout<<-1<<endl;
    else {
        if(in[ansot]==1){
            cout<<ansot<<" "<<ansku<<" "<<ans<<endl;

        }
        else cout<<ansku<<" "<<ansot<<" "<<ans<<endl;

    }
}
/*
6 7
1 0 1 2 2 0
1 3 3
1 2 4
2 3 3
2 4 2
1 6 5
3 5 6
5 6 1
*/
