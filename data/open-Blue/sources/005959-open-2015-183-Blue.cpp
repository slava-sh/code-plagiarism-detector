#include <iostream>
#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <ctime>
#include <cstdlib>

using namespace std;

const int maxn = 100100;

int l, n, p[maxn];
string s;

void prefix()
{
    p[0] = 0;
    int j = 0;
    for ( int i = 1; i < n; i++ )
    {
        while( s[i] != s[j] && j > 0 )
            j = p[j - 1];

        if ( s[i] == s[j] ) j++;
        p[i] = j;
    }
}

bool check1()
{
    int len = n - p[n - 1];
    if ( n % len != 0 )
        len = n;

    if ( len <= l )
    {
        cout << "1\n";
        for ( int i = 0; i < len; i++ )
            cout << s[i];
        cout << '\n';
        return 1;
    }
    return 0;
}

int z[maxn];
void z_f()
{
    z[0] = 0;
    int l = 0, r = 0;
    for ( int i = 1; i < n; i++ )
    {
        z[i] = 0;
        if ( i <= r )
            z[i] = min( z[i - l], r - i + 1 );

        while( i + z[i] < n && s[z[i]] == s[i + z[i]] )
            z[i]++;
        if ( i + z[i] - 1 > r )
            l = i, r = i + z[i] - 1;
    }
}

bool check( int len, string next )
{
//    cout << " next == " << next << " , len == " << len << '\n';
    int ptr = len;
    while( ptr < n )
    {
        if ( z[ptr] >= len )
            ptr += len;
        else
        {
            for ( int i = 0; i < next.size(); i++, ptr++ )
                if ( next[i] != s[ptr] )
                    return 0;
        }
    }

    cout << "2\n";
    for ( int i = 0; i < len; i++ )
        cout << s[i];
    cout << '\n' << next << '\n';
    return 1;
}

bool check2()
{
//    bool a, b, c;
//    a = b = c = 0;
//    for ( int i = 0; i < n; i++ )
//        if ( s[i] == 'a' )
//            a = 1;
//        else
//            if ( s[i] == 'b' )
//                b = 1;
//            else
//                c = 1;
//
//    if ( !a || !b || !c )
//    {
//        cout << "2\n";
//        if ( !a )
//        {
//            cout << "b\nc\n";
//        }
//        else
//        if ( !b )
//        {
//            cout << "a\nc\n";
//        }
//        else
//        {
//            cout << "a\nb\n";
//        }
//        return 1;
//    }

    z_f();
    string next;
    bool ok = 1;
    for ( int len = 1; len <= l; len++ )
    {
        ok = 1;
        int ptr = len;
        next = "";

        while( ptr < n )
        {
            if ( z[ptr] >= len )
                ptr += len;
            else
            {
                for ( int i = 0; i < l && i + ptr < n; i++ )
                {
                    next += s[i + ptr];
                    if ( check( len, next ) )
                        return 1;
                }
                break;
            }

        }
    }
    return 0;
}

void solve()
{
    cin >> l;
    cin >> s;
    n = s.size();
    prefix();
    if ( check1() )
        return;
    if ( check2() )
        return;

    cout << "3\na\nb\nc\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio( 0 );
    srand( time( NULL ) );
    solve();
    return 0;
}
