#include<algorithm>
#include<fstream>

int n, r, d[300001], l, j, a[300001];
 std::ifstream cin("che.in");
    std::ofstream cout("che.out");
main()
{

        cin>>n>>r;
    for(int i=0;i<n;i++){
        cin>>d[i];
        a[i]=d[i]-r;
    }
    j=n-1;
    for(int i=n-1;i>=0;)
    {
        if(j<0)
            break;
        if(a[i]>d[j--])
        {
            l+=j+2;
            i--;
            j=i;
        }
    }
    cout<<l;
}