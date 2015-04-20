#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

ifstream cin("binary.in");
ofstream cout("binary.out");

void nothing_to_do_here()
{
    cout << "0\n";
    exit(0);
}

int main()
{
    int n, ans = 0;
    cin >> n;
    vector<int> Z(n), A(n, -1), Link(n, -1);
    for (int i = 0; i < n; i++)
        cin >> Z[i];
    A[0] = 0;
    for (int q = 0; q < n; q++)
    {
        for (int i = 1; i < n; i++)
        {
            if (Z[i] != -1)
            {
                if (Z[i] > n - i)
                    nothing_to_do_here();
                for (int j = 0; j < Z[i]; j++)
                {
                    if (A[j] != -1)
                    {
                        if (A[i + j] == -1)
                            A[i + j] = A[j];
                        else if (A[i + j] != A[j])
                            nothing_to_do_here();
                    }
                    else if (A[i + j] != -1)
                        A[j] = A[i + j];
                    else
                        Link[i + j] = j;
                }
                if (i + Z[i] < n)
                {
                    if (A[Z[i]] != -1)
                    {
                        if (A[i + Z[i]] != -1 && A[i + Z[i]] == A[Z[i]])
                            nothing_to_do_here();
                        else if (A[i + Z[i]] == -1)
                            A[i + Z[i]] = 1 - A[Z[i]];
                    }
                    else if (A[i + Z[i]] != -1)
                        A[Z[i]] = A[i + Z[i]];
                    else
                        Link[i + Z[i]] = Z[i];
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
        if (A[i] == -1 && Link[i] == -1)
            ans++;
    int num = 1;
    for (int i = 0; i <= ans; num = (num * 2) % 1000000007, i++) ;
    cout << num;
    return 0;
}
