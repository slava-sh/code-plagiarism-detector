//#define ONLINE_JUDGE

#if defined(ONLINE_JUDGE)
#define _SECURE_SCL 0
#endif

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <functional>
#include <cmath>
#include <climits>
#include <numeric>
#include <tuple>
#include <memory.h>

#if !defined(__GNUC__)
typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed short int16_t;
typedef unsigned short uint16_t;
typedef signed long int32_t;
typedef unsigned long uint32_t;
typedef signed long long int64_t;
typedef unsigned long long uint64_t;
#else // !defined(__GNUC__)
#define _CrtDbgBreak()
#endif // !defined(__GNUC__)

#if defined(ONLINE_JUDGE)
#define LOCAL_TEST 0
#else 
#define LOCAL_TEST 1
#endif

#if LOCAL_TEST
#define LOCAL_ASSERT(expr) { if (!(expr)) {std::cout << "ASSERT FAILED: '" << #expr << "'" << std::endl; _CrtDbgBreak(); } }
#else
#define LOCAL_ASSERT(expr)
#endif

typedef long double double_t;
typedef std::string string8_t;

typedef std::vector<size_t> vector_size_t;
typedef std::vector<int32_t> vector_int32_t;
typedef std::vector<uint32_t> vector_uint32_t;
typedef std::vector<int64_t> vector_int64_t;
typedef std::vector<uint64_t> vector_uint64_t;

typedef std::vector<vector_size_t> vector_2d_size_t;
typedef std::vector<string8_t> vector_string8_t;
typedef std::vector<vector_string8_t> vector_2d_string8_t;

typedef std::set<size_t> set_size_t;
typedef std::set<int32_t> set_int32_t;
typedef std::set<uint32_t> set_uint32_t;
typedef std::set<int64_t> set_int64_t;
typedef std::set<uint64_t> set_uint64_t;

typedef std::set<string8_t> set_string8_t;
typedef std::multiset<string8_t> multiset_string8_t;

// Auxiliary functions definition
// 
template<typename T> inline T Abs(const T a) { return a < 0 ? -a : a; }
template<typename T> inline T Min(const T a, const T b) {return a < b ? a : b;}
template<typename T> inline T Max(const T a, const T b) {return a > b ? a : b;}
template<typename T> inline void UpdateMin(T& a, const T b) {a = Min(a, b);}
template<typename T> inline void UpdateMax(T& a, const T b) {a = Max(a, b);}

static const double_t eps = 1.0e-09;
template<typename T> inline bool IsEqual(const T a, const T b) { return Abs(a - b) < eps; }
template<typename T> inline bool IsGreater(const T a, const T b) { return a > b + eps; }
template<typename T> inline bool IsLess(const T a, const T b) { return a + eps < b; }

template<typename T> inline string8_t ToStr(const T& val) { std::ostringstream ostr; ostr << val; return ostr.str(); }
template<typename T> inline bool FromStr(const string8_t& str, T& val) {std::istringstream istr(str); istr >> val; return !!istr; }

#if defined(ONLINE_JUDGE)
template<size_t id> class StopWatch { };
#else
#include <library/lib_stopwatch.h>
#include <library/lib_random.h>
library::random::Rand g_rnd;
#endif

struct move_t
{
    move_t() {index = 0; way = 0;}
    move_t(size_t index_, size_t way_) {index = index_; way = way_; }
    size_t index;
    size_t way;
};

typedef std::vector<move_t> vector_move_t;

size_t GetMinUnused(const set_size_t& used, const set_size_t& unused, const vector_2d_size_t& diff, size_t& minDiff, size_t& minIndex)
{
    LOCAL_ASSERT(!used.empty());
    LOCAL_ASSERT(!unused.empty());

    minDiff = 1UL << 30;
    size_t minUnused = 0;

    for (auto pu = used.begin(); pu != used.end(); ++pu)
    {
        for (auto pn = unused.begin(); pn != unused.end(); ++pn)
        {
            const size_t usedIndex = *pu;
            const size_t unusedIndex = *pn;
            const size_t d = diff[usedIndex][unusedIndex];
            if (d < minDiff)
            {
                minDiff = d;
                minUnused = unusedIndex;
                minIndex = usedIndex;
            }
        }
    }

    return minUnused;
}

size_t GetAns(const size_t fieldSize, const size_t w, const vector_2d_size_t& diff, const size_t firstLevel, vector_move_t& sequence)
{
    const size_t k = diff.size();   

    size_t ans = fieldSize;
    sequence.clear();
    sequence.push_back(move_t(firstLevel, 0));

    set_size_t used;
    used.insert(firstLevel);

    set_size_t unused;
    for (size_t i = 0; i < k; i++)
    {
        if (i != firstLevel)
            unused.insert(i);
    }

    for (size_t i = 1; i < k; i++)
    {
        size_t minDiff = 0;
        size_t minIndex = 0;
        const size_t minUnused = GetMinUnused(used, unused, diff, minDiff, minIndex);
        LOCAL_ASSERT(used.find(minUnused) == used.end());
        LOCAL_ASSERT(unused.find(minUnused) != unused.end());
        if (minDiff * w < fieldSize)
        {
            sequence.push_back(move_t(minUnused, minIndex + 1));
            ans += minDiff * w;
        }
        else
        {
            sequence.push_back(move_t(minUnused, 0));
            ans += fieldSize;
        }
        used.insert(minUnused);
        unused.erase(minUnused);
    }

    LOCAL_ASSERT(unused.empty());
    return ans;
}

bool Solve(std::istream& ist, std::ostream& ost, const bool multipleTestMode)
{
    StopWatch<1> sw; sw;

    // 
    size_t n, m, k;
    size_t w;
    ist >> n >> m >> k >> w;

    if (multipleTestMode && !ist)
        return false;

    vector_2d_string8_t levels(k, vector_string8_t(n));

    for (size_t l = 0; l < k; l++)
    {
        for (size_t i = 0; i < n; i++)
        {
            ist >> levels[l][i];
        }
    }

    // 
    vector_2d_size_t diff(k, vector_size_t(k));
    for (size_t a1 = 0; a1 < k; a1++)
    {
        for (size_t a2 = a1 + 1; a2 < k; a2++)
        {
            for (size_t i = 0; i < n; i++)
            {
                for (size_t j = 0; j < m; j++)
                {
                    if (levels[a1][i][j] != levels[a2][i][j])
                    {
                        diff[a1][a2] += 1;
                        diff[a2][a1] += 1;
                    }
                }
            }
        }
    }

    size_t minDiff = 1UL << 31;
    size_t minA1 = 0;
    size_t minA2 = 0;
    for (size_t a1 = 0; a1 < k; a1++)
    {
        for (size_t a2 = a1 + 1; a2 < k; a2++)
        {
            const size_t d = diff[a1][a2];
            if (minDiff > d)
            {
                minDiff = d;
                minA1 = a1;
                minA2 = a2;
            }
        }
    }
    const size_t fieldSize = n * m;
    LOCAL_ASSERT(minA1 != minA2);

    vector_move_t minSequence;
    const size_t ans = GetAns(fieldSize, w, diff, minA1, minSequence);

    ost << ans << std::endl;
    for (size_t i = 0; i < k; i++)
    {
        ost << (minSequence[i].index + 1) << ' ' << minSequence[i].way << std::endl;
    }
    
    return multipleTestMode;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::istream& ist = std::cin;
    std::ostream& ost = std::cout;
#if defined(ONLINE_JUDGE)
    Solve(ist, ost, false);
#else
    while(Solve(ist, ost, true)) {};
#endif
}
