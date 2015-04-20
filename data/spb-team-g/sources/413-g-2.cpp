#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>


using namespace std;

int compare(const void* a, const void* b)
{
    return *((int*)a) - *((int*)b);
}

int main()
{
    ifstream in("merlin.in");
    ofstream out("merlin.out");

    int n;
    in >> n;
    long long a[100001];
    for(int i = 0; i < n; i++) in >> a[i];

    qsort(a, n, sizeof(int), compare);

    long long d[100001];
    long long sum = a[0];
    d[0] = 0;
    for(int i = 1; i < n; i++)
    {
        sum += a[i];
        d[i] = a[i]*(i+1)-sum;
    }

    int res = 0;

    sum = 0;
    for(int i = 0; i < n; i++)
    {
        if(sum >= d[n-1-i])
        {
            res = i;
            break;
        }
        sum += a[n-1-i];
    }

    out << res << endl;

    return 0;
}
