#include<fstream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
long long n, m, s, sum, q, p;
int main()
{
    ifstream cin("prizes.in");
    ofstream cout("prizes.out");
    cin>>n>>m;
    if(n==1)
    {
        for(int i=3;i<=m;i+=4)
            s++;
        cout<<s;
        return 0;
    }
    if(m==1)
    {
        for(int i=3;i<=n;i+=4)
            s++;
        cout<<s;
        return 0;
    }
    if(n==2 || m==2)
    {
        cout<<0;
        return 0;
    }
    cout<<1;
}

