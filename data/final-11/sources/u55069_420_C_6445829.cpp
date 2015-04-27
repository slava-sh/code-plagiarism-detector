//Author: net12k44
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <ctime>
#include <algorithm> 

using namespace std;

#define For(i,a,b)  for(i=(a);i<=(b);++i)
#define Ford(i,a,b) for(i=(a);i>=(b);--i)
#define Rep(i,n)    for(i=0  ;i <(n);++i)
#define Repd(i,n)   for(i=(n-1);i>=0;--i)
#define FOR(i,a,b)  for(i=(a);i!=(b);i++)


#define pp  pair<int,int>

int NUM, AM; 
#define SIZE (1 << 16)
char BUFFER[SIZE+1], *pNum = BUFFER;
#define GET(NUM)\
{\
      if (!*pNum)\
      {\
            if (feof(stdin) ) memset(BUFFER,0,sizeof BUFFER);\
            else fread(BUFFER, 1, SIZE, stdin); pNum = BUFFER;\
      } NUM = *pNum++;\
}
#define IsNum(c) ( ('0' <= (c)) && ((c) <= '9' ) )
#define read(i)\
{\
      do  GET(NUM) while(!IsNum(NUM) && NUM!='-' );\
      if (NUM == '-') {AM=1; GET(NUM);} else AM=0;\
      i = NUM-'0'; GET(NUM);\
      while( IsNum(NUM) ) { i = i * 10 + (NUM-'0'); GET(NUM); }\
      if (AM) i = -i;\
}
template<class T> void minimize( T &i , const T &j ) { if ( i > j ) i = j; }
template<class T> void maximize( T &i , const T &j ) { if ( i < j ) i = j; }

int MAIN();


int main()
{
	#ifndef ONLINE_JUDGE
		freopen("file.inp","r",stdin);
//		freopen("file.out","w",stdout);

		#ifdef TEST_JUDGE
			freopen("file.out","w",stdout);
		#endif
	#endif
	
	MAIN();
		
	 #ifndef ONLINE_JUDGE
            printf("\n");
            printf("%.2lf", (double) clock() / CLOCKS_PER_SEC);
      #endif
}

const int limit = (int)3e5 + 5;
list<int> a[limit];
int b[limit], c[limit];
int f[limit];
int cnt[limit];

//get other node j like beside i
int get(int i , int j){
	if (i == b[j]) return c[j];
	return b[j];
}

int MAIN(){
	int n,p;
	scanf("%d%d",&n,&p);
	for(int i = 1; i <= n; ++i){
		scanf("%d%d",&b[i],&c[i]);
		f[ b[i] ]++, f[c[i]]++;
		a[ b[i] ] . push_back(i);
		a[ c[i] ] . push_back(i);
	}
	
	long long kq = 0;
	int t = 0;
	for(int i = 1; i <= n; ++i) cnt[f[i]]++;
	for(int i = n-1; i >= 0; --i) cnt[i] += cnt[i+1];
	
	for(int i = 1; i <= n; ++i){
		int P = max(0, p - f[i]);
		t = cnt[P]; if (f[i] >= P) t--;
		//cout << t << endl;
		
		for(auto j: a[i]) {
			int k = get(i,j);
			//if (k < i) continue;			
			if (f[k] == P) t--;
			f[k]--;
		}
		kq = kq + t;
		for(auto j: a[i]) {
			int k = get(i,j);
			//if (k < i) continue;
			f[k]++;
			if (f[k] == P) t++;			
		}		
	}
	cout << kq/2 << endl;
	return 0;
	
}