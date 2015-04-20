#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream in("che.in");
    ofstream out("che.out");
    int n,r,s=0;
    in>>n>>r;
    int* d=new int[n];
    for(int i=0;i<n;i++) in>>d[i];

    for(int i=0;i<n;i++)
    {
        for(int q=i+1;q<n;q++)
        {
            if(d[q] - d[i] > r)
            {
//              s++;
              s+=n-q;
              break;
            }
        }
    }
    out<<s;

    return 0;
}
