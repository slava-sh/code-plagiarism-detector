#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int n, h;
long long min_sum = 1e10, sum;
int a[200001];
long long gsum[200001];
int shift[200001];
bool flag = false;

int main()
{
    ifstream in("seq.in");
    ofstream out("seq.out");

    in >> n >> h;

    in >> a[0];
    gsum[0] = a[0];

    memset(shift, 0, sizeof(shift));

    for(int i = 1; i < n; i++)
    {
        in >> a[i];
        gsum[i] = gsum[i-1]+a[i];

        if (a[i]<=1) continue;

        if (a[i] < h)
            if (i-a[i]+2 >= 0) shift[i-a[i]+2] = a[i]-1;
            else shift[0] = i+1;
        else
            if (i-h+2 >= 0) shift[i-h+2] = h-1;
            else shift[0] = i+1;
    }

    //for (int i = 0; i < n; i++) cout << shift[i] << " ";
    //cout << endl;

    for (int i = 0; i <= n-h; i++)
    {
        if (shift[i]>0)
        {
            i += shift[i]-1;
            continue;
        }
        if (a[i] > 1) continue;

        if (i > 0) sum = gsum[i+h-1]-gsum[i-1];
        else sum = gsum[i+h-1];

        //cout << i << " " << sum << endl;

        if ((min_sum > h*(h+1)/2 - sum) || !flag)
        {
            min_sum = h*(h+1)/2 - sum;
            flag = true;
        }
    }

    if (flag) out << min_sum;
    else out << -1;

    return 0;
}
