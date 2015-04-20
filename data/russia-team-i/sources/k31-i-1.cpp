#include<fstream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
long long n, d, a[100009], vs[100009], sum[100009], kol, k, p, x, y, sn[100009], ind1, ind2, sum1;
int main()
{
    ifstream cin("sochi.in");
    ofstream cout("sochi.out");
    cin>>n>>d;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]-2*d>=d)
        {
            ind1++;
            x+=a[i];
            vs[ind1]=a[i];
        }
        else if(a[i]-d>=d)
        {
            ind2++;
            sn[ind2]=a[i];
        }
    }
    if(n==1)
    {
        cout<<a[1];
        return 0;
    }
    if(n==2)
    {
        if(a[1]-d>=d && a[2]-d>=d)
        {
            cout<<(a[1]-d)+(a[2]-d);
            return 0;
        }
        else
        {
            cout<<max(a[1], a[2]);
            return 0;
        }
    }
    if(!ind1)
    {
        sort(a+1, a+n+1);
        if(a[n]-d>=d && a[n-1]-d>=d)
        {
            cout<<(a[n]-d)+(a[n]-d);
            return 0;
        }
        else
        {
            cout<<a[n];
            return 0;
        }
    }
    if(!ind2)
    {
        sum1=(ind1-2)*2*d;
        x-=(sum1+2*d);
        cout<<x;
        return 0;
    }
    if(ind2==1)
    {
        sum1=(ind1-1)*2*d;
        x+=sn[1];
        x-=(sum1+2*d);
        cout<<x;
        return 0;
    }
    sort(sn+1, sn+ind2+1);
    sum1=ind1*2*d;
    x+=sn[ind2];
    x+=sn[ind2-1];
    x-=(sum1+2*d);
    cout<<x;

}

