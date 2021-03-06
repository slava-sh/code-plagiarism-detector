#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    long long n;
    int k;
    fin>>n>>k;
    vector<long long>v(k);
    for(int i=0;i<k;i++)
        v[i]=1;
    int f=0;
    long long p=2;
    while(p*p<=n)
    {
        if(n%p==0)
        {
            n/=p;
            if(f!=k)
            {
                v[f]=p;
                f++;
            }
            else
            {
                f=0;
                for(int i=1;i<k;i++)
                    if(v[i]<v[f])
                        f=i;
                v[f]*=p;
                f=k;
            }
        }
        else
            p++;
    }
    if(f!=k)
        v[f]=n;
    else
    {
        f=0;
        for(int i=1;i<k;i++)
            if(v[i]<v[f])
                f=i;
        v[f]*=n;
    }
    long long z=(v[0]+1)/2;
    for(int i=1;i<k;i++)
        z=z*((v[i]+1)/2);
    fout<<z;
    return 0;
}
