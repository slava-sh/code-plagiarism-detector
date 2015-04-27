#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <iostream>
#include <queue>

#define mkp make_pair
#define A   first
#define B   second 
#define Rep(i,a,b)  for(int i=a;i<b;i++)

using namespace std;

typedef long long LL ;
LL mod ; 
int n , m  ; 
char str[510] ; 
int l[510] , cnt ; 
LL dp[2][510][510] ;

void Add(LL &a, LL b){
    a = a + b ;
    if( a >= mod )  a -= mod; 
}
void MAIN(){
    while( scanf("%d%d%I64d",&n,&m,&mod)==3 ){
        for(int i=0;i<n;i++)    l[i] = 2 ; 
        for(int i=0;i<m;i++){
            scanf("%s",str) ; 
            for(int j=0;j<n;j++)    if( str[j] == '1' ){
                l[j]--; 
            }
        }
        int pre = 0 , now = 1 ;
        memset( dp , 0 ,sizeof(dp) ) ;  cnt = n - m ; 
        dp[now][0][0] = 1 ; 
        
        for(int i=0;i<n;i++) if( l[i]!=0 ){
            pre ^= 1 ; now ^= 1 ;
            memset( dp[now] , 0 , sizeof(dp[now]) ) ; 
            
            for(int x=0;x<=cnt;x++){
                for(int y=0;x+y<=cnt;y++) if( dp[pre][x][y] != 0 ){
//                  printf("%d %d %I64d\n" , x, y , dp[pre][x][y]) ; 
                    if( l[i] == 0 ) {
                        Add( dp[now][x][y] , dp[pre][x][y] ) ; 
                    }
                    else if( l[i] == 1 ){
                        if( y > 0 )
                            Add( dp[now][x+1][y-1] , y * dp[pre][x][y] % mod) ;
                        if( cnt - x - y > 0 ){
                            Add( dp[now][x][y+1] , (cnt - x - y) * dp[pre][x][y] % mod) ;  
                        }
                    }
                    else if( l[i] == 2 ){
                        if( cnt - x - y >= 2 ){
//                          printf("%d %d %d %d\n" , x, y , cnt , dp[pre][x][y] ) ; 
                            Add( dp[now][x][y+2] , (cnt - x - y) * ( cnt - x - y - 1 ) / 2 * dp[pre][x][y] % mod ) ; 
//                          printf("%I64d\n" , dp[now][x][y+2]) ; 
                        }
                        if( y >= 2 ){
                            Add( dp[now][x+2][y-2] , y*(y-1)/2*dp[pre][x][y] % mod) ;
                        }
                        if( y>=1 && cnt-x-y>=1 ){
                            Add( dp[now][x+1][y] , y*(cnt-x-y)*dp[pre][x][y]%mod) ; 
                        }
                    }
                }
            }
//          printf("OKOKOKO\n");
        }
        printf("%I64d\n", dp[now][cnt][0] ) ;
        
    }
    
}
int main(){
    MAIN() ;
    return 0 ; 
}
