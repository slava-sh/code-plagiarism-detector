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
    for(int i=3;i<=m;i+=4)
    {
        s++;
    }
    for(int i=3;i<=n;i+=4)
    {
        p++;
    }
    cout<<min(s, p);
}
