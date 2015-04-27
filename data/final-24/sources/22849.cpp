#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

string s;
string q;
int L, N;
vector <int> z;
vector <int> qz;
int ok_A = -1;
int ok_B = -1;
int t0 = 0;
int KQ = 0;
int con = 335000000;

ifstream fin("input.txt");
ofstream fout("output.txt");

bool f(int t, int A, int B)
{
    KQ++;
    if (KQ > con)
    {
        fout << 3 << endl;
        fout << 'a' << endl;
        fout << 'b' << endl;
        fout << 'c' << endl;
        fin.close();
        fout.close();
        return 0;
    }
    if (B == -1)
    {
        t0 = t;
        q.clear();
        for (int i = t; i < N; ++i)
        {
            q.push_back(s[i]);
        }
        qz.resize((int)q.size());
        qz[0] = (int)q.size();
        int l, r = 0;
        for (int i = 1; i <= (int)q.size() - 1; ++i)
        {
            KQ++;
            if (i > r)
            {
                l = i;
                r = i;
            }
            qz[i] = min(qz[i - l], r - i);
            while (i + qz[i] < N && q[i + qz[i]] == q[qz[i]])
            {
                KQ++;
                qz[i]++;
            }
            if (i + qz[i] > r)
            {
                l = i;
                r = i + qz[i];
            }
            if (KQ > con)
            {
                fout << 3 << endl;
                fout << 'a' << endl;
                fout << 'b' << endl;
                fout << 'c' << endl;
                fin.close();
                fout.close();
                return 0;
            }
        }
        for (int j = 0; j < (int)q.size() && j < L; ++j)
        {
            f(t + j + 1, A, j);
        }
    }
    else
    {
        //cout << t << " " << A << " " << B << " " << q << endl;
        if (t == N)
        {
            ok_A = A;
            ok_B = B;
            return true;
           // cout << t << " " << A << " " << B << " " << q << endl;
        }
        if (t + A + 1 <= N && z[t] >= A + 1)
        {
            f(t + A + 1, A, B);
        }
        if (t + B + 1 <= N && qz[t - t0] >= B + 1)
        {
            f(t + B + 1, A, B);
        }
    }
    return true;
}

int main()
{
    fin >> L;
    fin >> s;
    N = (int)s.size();
    if (N == 1)
    {
        fout << 1 << endl;
        fout << s << endl;
        return 0;
    }
    int l, r = 0;
    z.resize(N);
    z[0] = N;
    for (int i = 1; i <= N - 1; ++i)
    {
        if (i > r)
        {
            l = i;
            r = i;
        }
        z[i] = min(z[i - l], r - i);
        while (i + z[i] < N && s[i + z[i]] == s[z[i]])
        {
            z[i]++;
        }
        if (i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
    }
    //return 0;
    for (int i = 1; i < N && i <= L; ++i)
    {
        bool is_good = true;
        if (N % i == 0)
        {
            for (int j = 0; j < N; j += i)
            {
                if (z[j] < i)
                {
                    is_good = false;
                    break;
                }
            }
            if (is_good)
            {
                fout << 1 << endl;
                for (int ii = 0; ii < i; ++ii)
                {
                    fout << s[ii];
                }
                fin.close();
                fout.close();
                return 0;
            }
        }
    }
    bool p = false;
    for (int i = 0; i < (int)s.size(); ++i)
    {
        if (s[i] == 'c')
        {
            p = true;
        }
    }
    if (!p)
    {
        fout << 2 << endl;
        fout << 'a' << endl;
        fout << 'b' << endl;
        return 0;
    }
    p = false;
    for (int i = 0; i < (int)s.size(); ++i)
    {
        if (s[i] == 'a')
        {
            p = true;
        }
    }
    if (!p)
    {
        fout << 2 << endl;
        fout << 'b' << endl;
        fout << 'c' << endl;
        return 0;
    }
    p = false;
    for (int i = 0; i < (int)s.size(); ++i)
    {
        if (s[i] == 'b')
        {
            p = true;
        }
    }
    if (!p)
    {
        fout << 2 << endl;
        fout << 'a' << endl;
        fout << 'c' << endl;
        return 0;
    }
    //return 0;
    for (int i = 0; i < N && i < L; ++i)
    {
        int k = 1;
        if (i + 1 < N)
        {
            bool a = f(i + 1, i, -1);
            if (!a)
            {
                fout << 3 << endl;
                fout << 'a' << endl;
                fout << 'b' << endl;
                fout << 'c' << endl;
                fin.close();
                fout.close();
                return 0;
            }
            if (ok_A != -1)
            {
                fout << 2 << endl;
                for (int i = 0; i <= ok_A; ++i)
                {
                    fout << s[i];
                }
                fout << endl;
                for (int i = 0; i <= ok_B; ++i)
                {
                    fout << q[i];
                }
                fout << endl;
                fin.close();
                fout.close();
                return 0;
            }
        }
        if (KQ > con)
        {
            fout << 3 << endl;
            fout << 'a' << endl;
            fout << 'b' << endl;
            fout << 'c' << endl;
            fin.close();
            fout.close();
            return 0;
        }
        while (k * (i + 1) < N && z[k * (i + 1)] >= i + 1)
        {
           /* if ((clock() - ck) >= CLOCKS_PER_SEC)
            {
                fout << 3 << endl;
                fout << 'a' << endl;
                fout << 'b' << endl;
                fout << 'c' << endl;
                fin.close();
                fout.close();
                return 0;
            }*/
            f((k + 1) * (i + 1), i, -1);
            if (ok_A != -1)
            {
                fout << 2 << endl;
                for (int i = 0; i <= ok_A; ++i)
                {
                    fout << s[i];
                }
                fout << endl;
                for (int i = 0; i <= ok_B; ++i)
                {
                    fout << q[i];
                }
                fout << endl;
                fin.close();
                fout.close();
                return 0;
            }
            k++;
            //cout << (clock() - ck);
           /* if ((clock() - ck) >= CLOCKS_PER_SEC)
            {
                fout << 3 << endl;
                fout << 'a' << endl;
                fout << 'b' << endl;
                fout << 'c' << endl;
                fin.close();
                fout.close();
                return 0;
            }*/
            if (KQ > con)
            {
                fout << 3 << endl;
                fout << 'a' << endl;
                fout << 'b' << endl;
                fout << 'c' << endl;
                fin.close();
                fout.close();
                return 0;
            }
        }
    }
    fout << 3 << endl;
    fout << 'a' << endl;
    fout << 'b' << endl;
    fout << 'c' << endl;
    fin.close();
    fout.close();
    return 0;
}
