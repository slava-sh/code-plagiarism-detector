#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    long long n;
    int k;
    fin>>n>>k;
    if(k==1)
    {
        n=(n+1)/2;
        fout<<n;
    }
    else
    {
        vector<long long>v(k);
        for(int i=0;i<k;i++)
            v[i]=1;
        int f=0;
        while(n%2==0)
        {
            n/=2;
            if(f!=k)
            {
                v[f]=2;
                f++;
            }
            else
            {
                v[k-1]*=2;
            }
        }
        long long p=2;
        int z=f;
        if(f==k)
            z--;
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
                    f=z;
                    for(int i=z+1;i<n;i++)
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
            f=z;
            for(int i=z+1;i<k;i++)
                if(v[i]<v[f])
                    f=i;
            v[f]*=n;
        }
        long long re=(v[0]+1)/2;
        for(int i=1;i<k;i++)
        re=re*((v[i]+1)/2);
        fout<<re<<endl;
    }
    return 0;
}
