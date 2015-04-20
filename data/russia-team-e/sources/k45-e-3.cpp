#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<vector>
#include<set>
#include<map>

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define sz(A) (int(A.size()))

using namespace std;
const int inf=1e9;

int n,k[111];string cg[111],cgo[111][111];

string t(string s,int pos,int le){
    string r="";
    for(int i=pos;i<pos+le;++i)r+=s[i];
    return r;
}

void doit(string s){
    int i,j;
    string inc="Incorrect";
    string ans="+";
    for(i=1;i<=n;++i){
        bool tr=1;
        for(int j=0;j<sz(cg[i]);++j){
            if(cg[i][j]!=s[j])tr=0;
        }
        if(s[sz(cg[i])]=='0')tr=0;
        if(tr){ans+=cg[i];break;}
    }
    if(i==n+1){cout<<inc<<endl;return ;}

    for(j=1;j<=k[i];++j){
        bool tr=1;
        for(int f=0;f<sz(cgo[i][j]);++f){
            if(cgo[i][j][f]!=s[f+sz(cg[i])])tr=0;
        }
        if(s[sz(cg[i])+sz(cgo[i][j])]=='0')tr=0;
        if(tr){ans=ans+"("+cgo[i][j]+")";break;}
    }
    if(j==k[i]+1){cout<<inc<<endl;return ;}
    int le=sz(cg[i])+sz(cgo[i][j]);

    if(sz(s)-le==3){if(s[le]=='0'){cout<<inc<<endl;return ;}ans+=t(s,le,3);}
    else if(sz(s)-le==4){if(s[le]=='0'){cout<<inc<<endl;return ;}ans+=t(s,le,2)+"-"+t(s,le+2,2);}
    else if(sz(s)-le==5){if(s[le]=='0'){cout<<inc<<endl;return ;}ans+=t(s,le,3)+"-"+t(s,le+3,2);}
    else if(sz(s)-le==6){if(s[le]=='0'){cout<<inc<<endl;return ;}ans+=t(s,le,2)+"-"+t(s,le+2,2)+"-"+t(s,le+4,2);}
    else if(sz(s)-le==7){if(s[le]=='0'){cout<<inc<<endl;return ;}ans+=t(s,le,3)+"-"+t(s,le+3,2)+"-"+t(s,le+5,2);}
    else {cout<<inc<<endl;return ;}
    cout<<ans<<endl;
}

int main(){
    freopen("numbers.in","r",stdin);
    freopen("numbers.out","w",stdout);
    int i,j,m;
    cin>>n;
    for(i=1;i<=n;++i){
        cin>>cg[i]>>k[i];
        for(j=1;j<=k[i];++j){
            cin>>cgo[i][j];
        }
    }
    cin>>m;
    for(i=1;i<=m;++i){
        string s;
        cin>>s;
        doit(s);
    }

    return 0;
}
