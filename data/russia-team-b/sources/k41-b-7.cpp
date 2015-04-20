#include <iostream>

using namespace std;

int main()
{
   long long int n , r , d1 , d2 , d3 , d4 , nr , d5 ;
   (2<=n<=300000);
   (1<=r<=10000000000);

   cin >> n >> r >> d1 >> d2 >> d3 >> d4 ;
   nr = n*r ;
   d5 = d1+d2+d3+d4 ;
   cout << d5-nr+d1 << endl ;

    return 0;
}
