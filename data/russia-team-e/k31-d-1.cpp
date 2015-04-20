#include<fstream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
long long n, k, a[100009], q, p, x, y, w, u[100009], d[100009], mp;
int f(int x)
{
    mp=a[1];
    for(int i=2;i<=n;i++)
    {
        y=mp+x;
        if(y>k)
            return 0;
        mp=max(y, a[i]);
    }
    return 1;
}
void b_f(int l, int r)
{
    int m;
    while(l<=r)
    {
        m=(l+r)/2;
        if(f(m))
        {
            l=m+1;
            q=m;
        }
        else
        {
            r=m-1;
        }
    }
}
int main()
{
    ifstream cin("fence.in");
    ofstream cout("fence.out");
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1, a+n+1);
    b_f(1, a[1]);
    cout<<q;
}

