#include<iostream>
#include<cstring>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#define mp make_pair
#define pb push_back
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
#define F first
#define S second
using namespace std;
int n,i,j,k,c,Q,x,y,ind,T;
vector<int> v[1050];
vector<char> e;
string s;

int check(int x,int ind){
    int ans=-1,i,r=0,u,g;
    if(s[ind]=='0')return -1;
    for(i=ind;i<ind+3;i++)r=r*10+(int)(s[i]-'0');
    u=r*10+(int)(s[ind+3]-'0');
    g=u*10+(int)(s[ind+4]-'0');
    for(i=0;i<v[x].size();i++)
        if(v[x][i]==r && s[ind+3]!='0')return 3;else
        if(v[x][i]==u  && s[ind+4]!='0')return 4;else
        if(v[x][i]==g && s[ind+5]!='0')return 5;
    return -1;
}

main()
{freopen("numbers.in","r",stdin);
 freopen("numbers.out","w",stdout);
 cin>>n;
 for(i=1;i<=n;i++){
    cin>>c>>k;
    for(j=1;j<=k;j++){
        cin>>x;
        v[c].pb(x);
    }
 }
 cin>>Q;
 while(Q--){
    cin>>s;
    if(s[0]=='0'){cout<<"Incorrect"<<endl;continue;}
    x=0;
    T=0;
    for(i=0;i<3;i++){
        x=x*10+(int)(s[i]-'0');
        y=check(x,i+1);
        if(y!=-1){T=1;ind=i+1;break;}
    }
    if(!T){cout<<"Incorrect"<<endl;continue;}
    cout<<"+"<<x<<"(";
    for(i=ind;i<ind+y;i++)cout<<s[i];
    cout<<")";
    e.clear();
    for(i=ind+y;i<11;i++)e.pb(s[i]);
    if((int)e.size()%2==1)cout<<e[0]<<e[1]<<e[2],ind=3;else
        cout<<e[0]<<e[1],ind=2;
    for(i=ind;i<e.size();i+=2)
        cout<<"-"<<e[i]<<e[i+1];
    cout<<endl;
 }
}
