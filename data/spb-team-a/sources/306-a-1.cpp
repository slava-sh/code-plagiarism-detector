#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;
string s;
int n,t;
int main()
{
    freopen("abcd.in","r",stdin);
    freopen("abcd.out","w",stdout);
    cin >> n;
    for (int i =0; i< n;i++)
    {
        cin >> t;
        if(((t/100)*(t/100) + (t%100)*(t%100))%7==1)//(((t%100* t%100)*(t%100 + t%100)  + (t /100 + t/100)*(t /100 + t/100) %7) == 1)

            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";

    }
    return 0;
}
