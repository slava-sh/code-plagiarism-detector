#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<long long> a;
vector<long long> b;
set<pair<long long, long long> > have;

int main()
{
    long long N, K;
    cin >> N >> K;
    long long N1 = N;
    long long  num2 = 0;
    for (long long i = 2; i * i <= N1; ++i)
    {
        while (N1 % i == 0)
        {
            N1 /= i;
            if (i == 2) num2 += 1;
            else a.push_back(i);
        }
    }
    if (N1 != 1)
    {
        if (N1 == 2) num2 += 1;
        else a.push_back(N1);
    }

    while (a.size() + num2 < K)
    {
        a.push_back(1);
    }

    long long answ = 1;

    if (num2 >= K)
    {
        for (long long i = 0; i < a.size(); ++i)
        {
            answ *= a[i];
        }
        for (long long i = 0; i < num2 - K; ++i)
        {
            answ *= 2;
        }
        cout << answ;
    }
    else
    {
        long long ost = K;
        for (long long i = 0; i < min(num2, a.size() + num2 - ost); ++i)
        {
            answ *= a[i];
        }
        for (long long i = min(num2, a.size() + num2 - ost); i < a.size(); ++i)
        {
            b.push_back(a[i]);
            //cout << a[i] << "  bb\n";
        }
        ost -= num2;
        for (long long i = min(num2, a.size() + num2 - ost); i < num2; ++i)
        {
            b.push_back(2);
            ost += 1;
            //cout << 2 << "  bb\n";
        }
        for (long long i = b.size() - 1; i >= b.size() - ost; --i)
        {
            have.insert(make_pair(b[i], i));
        }
        for (long long i = b.size() - ost - 1; i >= 0; --i)
        {
            pair<long long, long long> mn = *have.begin();
            have.erase(mn);
            have.insert(make_pair(mn.first * b[i], mn.second));
        }
        for (set<pair<long long, long long> > :: iterator it = have.begin(); it != have.end(); ++it)
        {
            answ *= ((*it).first / 2 + 1);
            //cout << (*it).first << '\n';
        }
        cout << answ;
    }

    return 0;
}
