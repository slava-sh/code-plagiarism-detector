#include <fstream>
#include <vector>

using namespace std;

struct t
{
    int n, num;
    t(int N = 0, int NUM = 0) : n(N), num(NUM) {}
};

struct my
{
    t code;
    vector<t> v;
};

t f(int n)
{
    int ans = 0, num = n;
    while (num)
    {
        num /= 10;
        ans++;
    }
    return t(n, ans);
}

int main()
{
    ifstream cin("numbers.in");
    ofstream cout("numbers.out");
    int n, c, k, m;
    string S;
    cin >> n;
    vector<my> V(n);
    for (int i = 0; i < n; i++)
    {
        cin >> c >> k;
        V[i].code = f(c);
        for (int j = 0; j < k; j++)
        {
            cin >> c;
            V[i].v.push_back(f(c));
        }
    }
    cin >> m;
    for (int q = 0; q < m; q++)
    {
        bool Was = false;
        cin >> S;
        for (int i = 0; !Was && i < n; i++)
        {
            int num;
            if (V[i].code.num == 1)
                num = S[0] - '0';
            else if (V[i].code.num == 2)
                num = S[0] * 10 + S[1] - '0' * 11;
            else
                num = S[0] * 100 + S[1] * 10 + S[2] - '0' * 111;
            if (num == V[i].code.n)
                for (int j = 0; !Was && j < V[i].v.size(); j++)
                {
                    int op = S[V[i].code.num] * 100 + S[V[i].code.num + 1] * 10 + S[V[i].code.num + 2] - '0' * 111;
                    if (V[i].v[j].num > 3)
                        op = op * 10 + S[V[i].code.num + 3] - '0';
                    if (V[i].v[j].num > 4)
                        op = op * 10 + S[V[i].code.num + 4] - '0';
                    if (op == V[i].v[j].n)
                    {
                        string now = S.substr(V[i].code.num + V[i].v[j].num, S.size() - V[i].code.num - V[i].v[j].num);
                        if (now[0] != '0')
                        {
                            cout << '+' << num << '(' << op << ')';
                            if (now.size() == 3)
                                cout << now;
                            else if (now.size() == 4)
                                cout << now[0] << now[1] << '-' << now[2] << now[3];
                            else if (now.size() == 5)
                                cout << now[0] << now[1] << now[2] << '-' << now[3] << now[4];
                            else if (now.size() == 6)
                                cout << now[0] << now[1] << '-' << now[2] << now[3] << '-' << now[4] << now[5];
                            else
                                cout << now[0] << now[1] << now[2] << '-' << now[3] << now[4] << '-' << now[5] << now[6];
                            cout << '\n';
                            Was = true;
                        }
                    }
                }
        }
        if (!Was)
            cout << "Incorrect\n";
    }
    return 0;
}
