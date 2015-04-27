#include <cstdio>
#include <set>

using namespace std;

int t, pos, meals, minPoss, cntUnknown, anyEaten, got[200000], nHappy[200000], cnt[200000], cntAte[200000], state[200000], lastAte[200000], i ;
set < pair < int, int > > mLeft ;
set < pair < int, int > > :: iterator testCheck ;

main()
{
    scanf( "%d", &t ) ;
    while( t-- ) {
        scanf( "%d %d", &pos, &meals ) ;
        for( i = 1 ; i <= meals ; ++i ) {
            scanf( "%d", &cnt[i] ) ;
            state[i] = 0 ;
        }
        for( i = 1 ; i <= pos-1 ; ++i ) {
            scanf( "%d %d", &got[i], &nHappy[i] ) ;
            lastAte[got[i]] = i ;
            ++cntAte[got[i]] ;
        }
        for( i = 1 ; i <= meals ; ++i )
            if( cntAte[i] == 0 )
                mLeft.insert( make_pair(cnt[i],i) ) ;
        for( i = 1 ; i <= pos-1 ; ++i ) {
            if( nHappy[i] && !anyEaten ) {
                minPoss = 0 ;
                testCheck = mLeft.begin() ;
                while( testCheck != mLeft.end() ) {
                    if( (*testCheck).first > cntUnknown )
                        break ;
                    if( !minPoss )
                        minPoss = (*testCheck).first ;
                    state[ (*testCheck).second ] = 1 ;
                    ++testCheck ;
                }
                while( !mLeft.empty() && (*mLeft.begin()).first <= cntUnknown )
                    mLeft.erase( mLeft.begin() ) ;
                if( !anyEaten )
                    cntUnknown -= minPoss ;
                anyEaten = 1 ;
            }
            if( !got[i] )
                ++cntUnknown ;
            else {
                --cnt[got[i]] ;
                if( !cnt[got[i]] ) {
                    state[got[i]] = 1 ;
                    anyEaten = 1 ;
                }
                if( !state[got[i]] && lastAte[got[i]] == i )
                    mLeft.insert( make_pair(cnt[got[i]],got[i]) ) ;
            }
        }
        for( i = 1 ; i <= meals ; ++i )
            if( !state[i] && cntUnknown >= cnt[i] )
                state[i] = 1 ;
        for( i = 1 ; i <= meals ; ++i )
            printf( state[i]?"Y":"N" ) ;
        printf( "\n" ) ;

        for( i = 1 ; i <= meals ; ++i )
            state[i] = cntAte[i] = lastAte[i] = 0 ;
        pos = meals = minPoss = cntUnknown = anyEaten = 0 ;
        mLeft.clear() ;
    }
}
