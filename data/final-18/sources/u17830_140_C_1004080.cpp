#pragma comment(linker, "/STACK:12000000")

#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <iterator>
#include <cmath>
#include <cassert>
#include <iomanip>

using namespace std;

// --------------------- Template ---------------------------------------------

#define FOR(i, f, t) for (int i = (int)(f); i < (int)(t); ++i)
#define FORN(i, n) for (int i = 0; i < (int)(n); ++i)

template <class T, class IT>
inline void PRINT(IT i1, IT i2) {
    cout << '['; copy(i1, i2, ostream_iterator<T>(cout, ", ")); cout << "]\n";
}

#if defined(M_H_HOME) && (0)
#define DBG(x) (x)
#else
#define DBG(x)
#endif

typedef long long ll;
typedef long double ld;

// ------------------ Template end --------------------------------------------


#if 1

const int MAX = 100005;

template <typename IntegralT, typename PredicateT>
IntegralT ibsearch(IntegralT l, IntegralT r, PredicateT P) {

    // ����� ��� ���� ������ �������, ���������������
    // ������������ �����������
    //  �� ����, � ������������������ ������������ P ��������
    //  0 0 0 0 0 0 0 1 1 1 1 1
    //                ^
    //  ����� ������ ���������� �������
    //  ���� ��� ���� -> ibsearch(l, r) == r + 1
    //  ���� ��� 1    -> ibsearch(l, r) == l 
    while (l < r) {
        IntegralT x = l + ((r - l) >> 1); 
        if ( !P(x) ) {
            r = x;
        } else {
            l = x + 1;
        }
    }
    return l;
}

vector<int> vec;
int hea[MAX / 3][3];

// ���������, ����� �� ��������� ������ �� k ���
bool check(int k) {

    if (3LL*k > (ll)(vec.size())) return false; 

    int hi = 0, i = 0;

    FORN(j, MAX/3) hea[j][0] = hea[j][1] = hea[j][2] = -1;

    // ������ ���
    while (hi < k && i < vec.size()) { hea[hi][0] = vec[i]; ++i; ++hi; }
    // ������ ���
    hi = 0;
    while (hi < k && i < vec.size()) { 
        while (i < vec.size() && hea[hi][0] >= vec[i]) ++i;
        if (i < vec.size()) {
            hea[hi][1] = vec[i];
            ++hi; ++i;
        } else {
            return false;
        }
    }
    if (hi != k) return false;
    // ������ ���
    hi = 0;
    while (hi < k && i < vec.size()) { 
        while (i < vec.size() && hea[hi][1] >= vec[i]) ++i;
        if (i < vec.size()) {
            hea[hi][2] = vec[i];
            ++hi; ++i;
        } else {
            return false;
        }
    }
    if (hi != k) return false;

    return true;
}

int main() {

#if defined(M_H_HOME) && (1)
    ifstream ___ifs("c.in.1");
    cin.rdbuf(___ifs.rdbuf());
#endif

    int n;
    int temp;

    cin >> n;
    FORN(i, n) { cin >> temp; vec.push_back(temp); }
    sort(vec.begin(), vec.end());

    int r = ibsearch(0, n / 3 + 1, check);
    r = r - 1;    

    cout << r << endl;
    FORN(i, r) {
        cout << hea[i][2] << " " << hea[i][1] << " " << hea[i][0] << '\n';
    }

    return 0;
}
#endif
