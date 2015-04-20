#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;
long long int n,m,c,l, a[100002],ch, d;
int main()
{
ifstream cin("sochi.in");
    ofstream cout("sochi.out");
    cin>>n>>d;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a, a+n);
    for(int i=0;i<n;i++)
        if(a[i]>=d+d)
            {ch=i;
            break;
            }
    if(n-1==ch){
        cout<<a[ch];
        return 0;}
    for(int i=n-2;i>=ch;i--)
    {
        a[i]=a[i]-d+a[i+1]-d;
        }
    cout<<a[ch];
}
