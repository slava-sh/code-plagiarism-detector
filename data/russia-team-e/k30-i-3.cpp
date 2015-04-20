#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;
int n,m,a[1000000],j=1,s[1000000],maxi=-99999999;
int main()
{
    ifstream cin("sochi.in");
    ofstream cout("sochi.out");
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]-m*2<0&&i!=1&&i!=n)
        {
            a[i]=-1;
        }
        if(a[i]-m<0&&i==1&&i==n)
        {
            a[i]=-1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]==-1)
        {
            j++;
            i++;
        }
        if(i==1)
        {
            s[j]+=a[i]-m;
        }
        if(i==n)
        {
            s[j]+=a[i]-m;
        }
        if(a[i-1]==-1)
        {
            s[j]+=a[i]-m;
        }
        if(a[i+1]!=-1&&a[i-1]!=-1&&i!=1&&i!=n)
        {
            s[j]+=a[i]-(m*2);
        }
        if(a[i+1]==-1)
        {
            s[j]+=a[i]-m;
        }
    }
    for(int i=1;i<=j;i++)
        if(s[i]>maxi)
            maxi=s[i];
        cout<<maxi;
}
