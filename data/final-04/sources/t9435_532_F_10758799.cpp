#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

const int N = (int) 2e5 + 10;
const int M = 26;

const int P = (int) 239017;
const int A = 3, B = 7;

long long ht[M], h[M][N], p[N];
int n, n2;
string s, t;
vector <int> ans;
bool have[M], taked[M], m[M][M];

int get (bool flag)
{
    return flag ? B : A;
}

bool test (int pos, int i, int j)
{
    return ht[i] == (h[j][pos + n] - h[j][pos] * p[n]);
}

bool run (int pos)
{
    memset(taked, 0, sizeof(taked));

    for (int i = 0; i < M; i++) {
        if (have[i]) {
            bool flag = false;;
            for (int j = 0; j < M; j++) {
                if (!taked[j] && test(pos, i, j) && test(pos, j, i)) {
                    taked[j] = true;
                    flag = true;
                    break;
                }
            }

            if (!flag)
                return false;
        }
    }

    return true;
}

int main ()
{
    cin >> n >> n2 >> s >> t;
    n = t.size();

    p[0] = 1;
    for (int i = 1; i < N; i++)
        p[i] = p[i - 1] * P;
    for (int letter = 0; letter < M; letter++) {
        for (int i = 0; i < s.size(); i++) {
            h[letter][i + 1] = h[letter][i] * P + get(s[i] - 'a' == letter);
        }
        for (int i = 0; i < t.size(); i++) {
            ht[letter] = ht[letter] * P + get(t[i] - 'a' == letter);
        } 
    }

    for (auto i = 0; i < t.size(); i++) {
        have[t[i] - 'a'] = true;
    }

    for (int i = 0; i <= s.size() - t.size(); i++)
        if (run(i))
            ans.push_back(i);

    cout << ans.size() << endl;
    for (int i : ans) {
        cout << i + 1 << ' ';
    }
    cout << endl;

    return 0;
}