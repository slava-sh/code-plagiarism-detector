#include <stdio.h>
#include <string>
#include <iostream>
#include <string.h>
#include <map>

using namespace std;
typedef map<int, int>::iterator mii;
const int msize = 100*1000;

int main() {
    int t;
    int* a;
    char* str;
    map<int, int> sub;  
    
    scanf("%d", &t);
    a =   new int[msize];
    str = new char[msize+1];
    
    for (; t; t--){
        int m, k, d = 0, D = 0;
        int tmp, r;    
        bool empty = false;
        sub.clear();
        
        scanf("%d", &m);
        scanf("%d", &k);
        
        memset(str, 'N', sizeof(char)*k );
        str[k] = 0;
        
        for ( int j = 0; j < k; j++)
            scanf("%d", a+j);
        
        for ( int j = 1; j < m; j++){
            scanf("%d", &tmp);
            scanf("%d", &r);
            
            if ( r & !empty){
                empty = true;
                D = d;
                for( int i = 0; i < k; i++)
                    if ( a[i] <= d ){
                        sub[i] = a[i];
                        //str[i] = 'Y';
                    }
            }

            
            if ( tmp ){
                sub.erase(tmp-1);
                if (  !(--a[tmp-1]) ){
                    empty = true;
                    str[tmp-1] = 'Y';    
                }
            }else        d++;

        }
        
        if( sub.size() ){
            int min = 1e7;
            for( mii i = sub.begin(); i != sub.end(); i++ ){
                min = min < i->second ? min : i->second;
                if( i->second <= D ) str[i->first] = 'Y';
            }
            d -= min;
        }
        for(int i = 0; i < k; i++)
            if ( a[i] <= d ) str[i] = 'Y';
        printf("%s\n", str);
        
    }
        
    return 0;
}
