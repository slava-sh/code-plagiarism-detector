#include <fstream>
#include <iostream>
#include <vector>

long long GCD(long long a, long long b)
{
    if(a < b)
    {
        long long t = a;
        a = b;
        b = t;
    }

    while(a%b != 0)
    {
        long long t = a%b;
        a = b;
        b = t;
    }
    return b;
}

using namespace std;
long long primes[100000];
int main()
{
    ifstream in("gcm.in");
    ofstream out("gcm.out");

    long long pn = 1;
    primes[0] = 2;
    for(long long i = 3; i < 100000; i++)
    {
        bool prime = true;
        for(long long k = 0; primes[k]*primes[k] <= i && k < pn; k++)
        {
            if(i%primes[k] == 0) {prime = false; break;}
        }
        if(prime)
        {
            primes[pn] = i;
            pn++;
            //cout << i << endl;
        }
    }
    long long a, b;
    in >> a >> b;

    long long gcd = GCD(a, b);
    a /= gcd;
    b /= gcd;

    long long p = a*b;

    long long prs[10000]; long long prss = 0;
    long long prsn[10000];
    while(p > 1)
    {
        long long i = 0;
        long long prime = primes[i];
        while(prime*prime <= p && p%prime != 0){i++; prime = primes[i];}
        /*if(p%prime != 0)
        {
            prs[prss] = p;
            prsn[prss] = 1;
            prss++;
            break;
        }
        else
        {*/
        if(p%prime != 0) prime = p;
        bool was = false;
        for(long long i = 0; i < prss; i++)
        {
            if(prs[i] == prime)
            {
                prsn[i]++;
                was = true;
                break;
            }
        }
        if(!was)
        {
            prs[prss] = prime;
            prsn[prss] = 1;
            prss++;
        }
        p /= prime;
        //}
    }
    p = a*b;

    long long stp[1000];
    for(int i = 0; i < prss; i++)
    {
        stp[i] = 1;
        for(int k = 0; k < prsn[i]; k++) stp[i] *= prs[i];
    }

    bool mask[1000];
    for(int i = 0; i < prss; i++) mask[i] = false;


    long long min_ = -1;
    long long mina1 = 0;
    long long minb1 = 0;
    while(true)
    {
        long long a1 = 1;
        long long b1 = 1;
        for(int i = 0; i < prss; i++) if(mask[i]) a1 *= stp[i];
        b1 = p/a1;
        long long raz = a1-b1;
        if(raz < 0)
        {
            raz = -raz;
            long long t = a1;
            a1 = b1;
            b1 = t;
        }
        if(raz < min_ || min_ == -1)
        {
            min_ = raz;
            mina1 = a1;
            minb1 = b1;
        }

        int i = 0;
        int a_ = 1;
        while(i < prss && a_ == 1)
        {
            if(mask[i] == 0)
            {
                mask[i] = 1;
                a_ = 0;
            }
            else
            {
                mask[i] = 0;
                a_ = 1;
            }
            i++;
        }
        if(a_ == 1) break;
    }


    mina1 *= gcd;
    minb1 *= gcd;
    out << min(mina1, minb1) << " " << max(mina1, minb1) << endl;





    return 0;
}
