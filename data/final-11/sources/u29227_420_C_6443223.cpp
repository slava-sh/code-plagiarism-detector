#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int N, P;
int A[300002], B[300002];
int D[300002];
map<pair<int, int>, int> M;
set<pair<int, int> > S;
long long result;

int main()
{
    cin.sync_with_stdio(false);

    cin >> N >> P;
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i] >> B[i];
        ++D[A[i]];
        ++D[B[i]];

        if (A[i] > B[i]) swap(A[i], B[i]);
        ++M[make_pair(A[i], B[i])];
    }

    for (int i = 1; i <= N; ++i)
        if (S.find(make_pair(A[i], B[i])) == S.end())
        {
            if (D[A[i]] + D[B[i]] >= P && D[A[i]] + D[B[i]] - M[make_pair(A[i], B[i])] < P)
                result -= 2;
            S.insert(make_pair(A[i], B[i]));
        }

    sort(D + 1, D + N + 1);

    int pnow = N;
    for (int i = 1; i <= N; ++i)
    {
        while (pnow >= 1 && D[i] + D[pnow] >= P)
            --pnow;
        result += (N - pnow) - (pnow < i);
    }

    cout << result / 2 << '\n';
}
