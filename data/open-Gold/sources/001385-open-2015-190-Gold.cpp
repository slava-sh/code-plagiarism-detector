#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n,k;
    long long c,d;
    cin>>n>>k>>c>>d;
    int a,b,f;
    long long rez=0;
    int r=1;
    cin>>a>>b;
    rez=rez+d*(b-a);
    f=b;
    n--;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        rez=rez+d*(b-a);
        v[i]=a-f;
        f=b;
        r++;
    }
    sort(v.begin(),v.end());
    int ind=0;
    int i=0;
    while(ind==0&&r>k)
    {
        long long qw=0;
        int z=r%k;
        if(z==0)
            z=k;
        for(int j=i;j<i+z;j++)
            qw=qw+d*v[j];
        if(qw<c)
        {
            r=r-z;
            rez=rez+qw;
            i=i+z;
        }
        else
            ind=1;
    }
    rez=rez+c*((r-1)/k);
    cout<<rez<<endl;
    return 0;
}
