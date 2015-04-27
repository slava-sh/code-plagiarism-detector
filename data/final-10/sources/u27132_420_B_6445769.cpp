#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

//#define GEN_LOCAL_TEST
//#define USE_LOCAL_TEST

#ifdef GEN_LOCAL_TEST
void genTest() {
    ofstream ofs("test.txt", ifstream::out);
    int n = 100000;
    ofs << n << endl;
    for (int i = 0; i < n; ++i)
        ofs << 0 << " ";
    ofs << endl;
    ofs.close();
}
#endif

int main(int argc, char* argv[])
{
#ifdef GEN_LOCAL_TEST
    genTest();
#endif

    int n, m;
#ifdef USE_LOCAL_TEST
    ifstream ifs("test.txt", ifstream::in);
    ifs >> n >> m;
#else
    cin >> n >> m;
#endif

    int id;
    char sig;
    vector<int> dt;
    for (int i = 0; i < m; ++i) {
#ifdef USE_LOCAL_TEST
        ifs >> sig >> id;
#else
        cin >> sig >> id;
#endif
        if (sig == '+')
            dt.push_back(id);
        else
            dt.push_back(-id);
    }

    vector<bool> valid(n + 1, true);
    vector<bool> used(n + 1, false);
    int idx = -1;
    for (int i = 0; i < dt.size(); ++i) {
        int id = abs(dt[i]);
        if (dt[i] > 0) {
            used[id] = true;
        }
        else {
            if (!used[id]) idx = i;
            used[id] = false;
        }
    }

    set<int> root;
    if (idx >= 0) {
        root.insert(abs(dt[idx]));
        for (int i = 0; i < idx; ++i) {
            int id = abs(dt[i]);
            valid[id] = false;
        }
    }

    vector<bool> used2(n + 1, false);
    int pqt = 0;
    for (int i = 0; i < dt.size(); ++i) {
        int id = abs(dt[i]);
        if (dt[i] > 0) {
            if (pqt > 0)
                valid[id] = false;
            else if (i > idx)
                root.insert(id);
            used2[id] = true;
            ++pqt;
        }
        else {
            if (used2[id]) --pqt;
            used2[id] = false;
            if (pqt > 0)
                valid[id] = false;
        }
    }
    if (root.size() > 1) {
        set<int>::iterator it = root.begin();
        for (; it != root.end(); ++it)
            valid[*it] = false;
    }

    ////
    int qt = 0;
    for (int i = 1; i <= n; ++i) {
        if (valid[i])
            ++qt;
    }
    cout << qt << endl;
    for (int i = 1; i <= n; ++i) {
        if (valid[i])
            cout << i << " ";
    }
    return 0;
}

