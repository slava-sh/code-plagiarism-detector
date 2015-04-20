#include<iostream>
#include<string.h>
#include<algorithm>
#include<string>
#include<fstream>
#include<math.h>
#include<stdio.h>
#include<vector>
#include<map>
using namespace std;
bool KOD(string s, string s1, int y)
{
    int n=s1.size();
    for (int i=0;i<n;i++)
        if (s1[i]!=s[i+y]) return false;
    return true;
}
void PECHAT(string s, int y)
{
    if ((11-y)%2==1) cout<<s[y]<<s[y+1]<<s[y+2], y+=3; else
            cout<<s[y]<<s[y+1], y+=2;
    while (11-y>0)
    {
        cout<<"-"<<s[y]<<s[y+1];
        y+=2;
    }
    cout<<endl;
    return;
}
int main()
{
    freopen("numbers.in","r",stdin);
    freopen("numbers.out","w",stdout);
int v[110],n,i,j,u,k;
string s,a[110],b[110][110];
cin>>n;
for (i=0;i<n;i++)
{
    cin>>a[i]>>v[i];
    for (j=0;j<v[i];j++)
        cin>>b[i][j];
}
cin>>k;
for (int z=0;z<k;z++)
{
    bool f=0;
    cin>>s;
    for (j=0;j<n && !f;j++)
    {
        if (KOD(s,a[j],0))
            for (u=0;u<v[j] && !f;u++)
                if (s[a[j].size()+b[j][u].size()]!='0' && KOD(s,b[j][u],a[j].size()))
                    {
                        cout<<"+"<<a[j]<<"("<<b[j][u]<<")";
                        //PECHAT(s,a[j].size()+b[j][u].size());
                        int y=a[j].size()+b[j][u].size();
    if ((11-y)%2==1) cout<<s[y]<<s[y+1]<<s[y+2], y+=3; else
            cout<<s[y]<<s[y+1], y+=2;
    while (11-y>0)
    {
        cout<<"-"<<s[y]<<s[y+1];
        y+=2;
    }
    cout<<endl;
                        f=1;
                    }
    }
    if (!f) cout<<"Incorrect"<<endl;
}
return 0;
}

