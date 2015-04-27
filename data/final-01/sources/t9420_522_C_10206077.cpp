#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> PII;

int nxt() {
    int a;
    scanf("%d", &a);
    return a;
}


struct InputData {
    int m, k;
    vector<int> a;
    vector<PII> b;
};

const int M = 11;
const int K = 11;
const int A = 6;

InputData gen() {
    InputData ret;
    ret.m = rand() % (M - 1) + 2;
    ret.k = rand() % K + 1;
    ret.a.resize(ret.k);
    for (int i = 0; i < ret.k; ++i) {
        ret.a[i] = rand() % A + 1;
    }
    ret.b.resize(ret.m - 1);
    for (int i = 0; i + 1 < ret.m; ++i) {
        if (rand() & 1) {
            ret.b[i].first = 0;
        } else {
            ret.b[i].first = rand() % (ret.k + 1);
        }
        ret.b[i].second = rand() & 1;
    }
    return ret;
}

InputData read() {
    InputData ret;
    ret.m = nxt();
    ret.k = nxt();
    ret.a.resize(ret.k);
    for (int i = 0; i < ret.k; ++i) {
        ret.a[i] = nxt();
    }
    ret.b.resize(ret.m - 1);
    for (int i = 0; i + 1 < ret.m; ++i) {
        ret.b[i].first = nxt();
        ret.b[i].second = nxt();
    }
    return ret;
}

InputData testInput;
int testAnswer = -1;

void rec(int pos) {
    if (pos == testInput.m - 1) {
        int ret = 0;
        bool ok = false;
        for (int i = 0; i < testInput.k; ++i) {
            if (testInput.a[i] == 0) {
                ret |= (1 << i);
            } else {
                ok = true;
            }
        }
        if (!ok) {
            return;
        }
        if (testAnswer == -1) {
            testAnswer = ret;
        } else {
            testAnswer |= ret;
        }
        return;
    }
    int type = testInput.b[pos].first;
    int res = testInput.b[pos].second;

    if (res) {
        bool ok = false;
        for (int i = 0; i < testInput.k; ++i) {
            if (testInput.a[i] == 0) {
                ok = true;
                break;
            }
        }
        if (!ok) {
            return;
        }
    }
    if (type > 0) {
        int id = type - 1;
        if (testInput.a[id] == 0) {
            return;
        }
        testInput.a[id]--;
        rec(pos + 1);
        testInput.a[id]++;
    } else {
        for (int i = 0; i < testInput.k; ++i) {
            if (testInput.a[i] > 0) {
                testInput.a[i]--;
                rec(pos + 1);
                testInput.a[i]++;
            }
        }
    }
    return;
}


string solveTest(const InputData &data) {
    testInput = data;
    testAnswer = -1;
    rec(0);
    if (testAnswer == -1) {
        return string(1, '-');
    }
    string ret;
    for (int i = 0; i < data.k; ++i) {
        if (testAnswer & (1 << i)) {
            ret += 'Y';
        } else {
            ret += 'N';
        }
    }
    return ret;
}


string solve(const InputData & data) {
    vector<int> a = data.a;
    vector<PII> b = data.b;

    int m = data.m - 1;
    int k = data.k;

    int cnt[k];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < m; ++i) {
        if (b[i].first > 0) {
            int id = b[i].first - 1;
            cnt[id]++;
        }
    }

    int unknown = 0;
    bool isZero = false;
    char maybe[k];
    memset(maybe, 0, sizeof(maybe));
    int minVal = INT_MAX;

    for (int i = 0; i < m; ++i) {
        if (b[i].second == 1) {
            if (!isZero) {
                for (int j = 0; j < k; ++j) {
                    if (a[j] <= unknown && cnt[j] == 0) {
                        maybe[j] = 1;
                    }
                }
                isZero = true;
            }
        }
        if (b[i].first == 0) {
            ++unknown;
        } else {
            int id = b[i].first - 1;
            a[id]--;
            cnt[id]--;
            if (a[id] == 0) {
                isZero = true;
            }
        }
    }

    string ans(k, 'N');
    for (int i = 0; i < k; ++i) {
        if (maybe[i]) {
            minVal = min(minVal, a[i]);
        }
    }
    if (minVal == INT_MAX) {
        minVal = 0;
    }

    for (int i = 0; i < k; ++i) {
        if (a[i] <= unknown - minVal || maybe[i]) {
            ans[i] = 'Y';
        }
    }
    return ans;
}

void stress() {
    int IT = 20000;
    int it = IT;
    int last = 0;
    while (true) {
        InputData data = gen();
        string ansTest = solveTest(data);
        if (ansTest[0] == '-') {
            continue;
        }
        --it;
        string ans = solve(data);
        if (ans != ansTest) {
            cout << data.m << " " << data.k << endl;
            for (int i = 0; i < data.k; ++i) {
                cout << data.a[i] << " ";
            }
            cout << endl;
            for (int i = 0; i + 1 < data.m; ++i) {
                cout << data.b[i].first << " " << data.b[i].second << endl;
            }
            cout << endl;

            cout << "Stress: Fail" << endl;
            cout << ansTest << endl << ans << endl;
            return;
        }
        if ((IT - it) * 100 / IT > last) {
            cout << ((IT - it) * 100 / IT) << "%" << endl;
            last = (IT - it) * 100 / IT;
        }
        if (it == 0) {
            break;
        }
    }
    cout << "Stress: OK" << endl;
    return;
}

void solution() {
    InputData data = read();
    string ans = solve(data);
    printf("%s\n", ans.c_str());
    return;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);

//    stress();

    int t = nxt();
    for (int i = 0; i < t; ++i) {
        solution();
    }

    return 0;
}