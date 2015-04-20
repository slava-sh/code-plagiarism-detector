#include <fstream>

using namespace std;
ifstream cin("sochi.in");
ofstream cout("sochi.out");
int main()
{
    long long int a[100100],n,d,res=0;
    cin>>n>>d;
    int sum = 0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum += a[i];
    }
    cout<<sum - (2 * d * (n - 1));

    return 0;
}
