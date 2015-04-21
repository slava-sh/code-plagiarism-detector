#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n;
    fin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        fin>>v[i];
    int z=1;
    for(int i=1;i<n;i++)
        if(v[i]!=v[i-1])
            z++;
    int k;
    fin>>k;
    while(k>0)
    {
        k--;
        int a,b;
        fin>>a>>b;
        a--;
        if(v[a]==v[a-1])
            z++;
        if(v[a]==v[a+1])
            z++;
        v[a]=b;
        if(v[a]==v[a-1])
            z--;
        if(v[a]==v[a+1])
            z--;
        fout<<z<<endl;
    }
    return 0;
}
