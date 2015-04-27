#include <iostream>
#include <vector>
using namespace std;
vector <double> p,r;
int n;
double q;
int m1,m2;
double a1,a2;
int main()
{
    cout.setf(ios::fixed);
    cout.precision(7);
    cin >> n;
    m1=n;
    m2=0;
    p.resize(n+1);
    r.resize(n+1);
    for (int i=0;i<=n;i++) cin >> p[i];
    if (n%2) q=(p[n/2]+p[n/2+1])/2;
    else q=p[n/2];
    while (true)
    {
        if (n%2)
        {
            for (int i=0;i<=n/2;i++)
            {
                r[i]=2.0*(q-p[i])/(n-2.0*i);
                r[n-i]=2.0*(p[n-i]-q)/(n-2.0*i);
            }
            for (int i=0;i<=n/2;i++)
            {
                if (r[i]<r[m2]) m2=i;
                if (r[n-i]>r[m1]) m1=n-i;
            }
        }
        else
        {
            for (int i=0;i<n/2;i++)
            {
                r[i]=(q-p[i])/(n/2-i);
                r[n-i]=(p[n-i]-q)/(n/2-i);
            }
            for (int i=0;i<n/2;i++)
            {
                if (r[i]<r[m2]) m2=i;
                if (r[n-i]>r[m1]) m1=n-i;
            }
        }
        a1=(double)(n-2*m2)/(2*m1-2*m2);
        a2=(double)(2*m1-n)/(2*m1-2*m2);
        if (p[m1]*a1+p[m2]*a2<=q)
        {
            cout << q;
            return 0;
        }
        else q=p[m1]*a1+p[m2]*a2;
    }
}
