#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <ctime>
#include <cstring>
#include <string>
#include <cstdlib>
#include <stack>
#include <queue>


using namespace std;

#define pb push_back
#define mp make_pair


typedef long long ll;
typedef long double ld;
typedef double db;
typedef unsigned long long ull;

int main(){
	srand(time(NULL));
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int i,n,na = 0, nb = 0, l;
	char s[300];
	scanf("%d\n", &l);
	n = strlen(s);
	scanf("%s", s);
	for (i = 0; i < n;i++)
		if (s[i] == 'a')
			na++;
		else
			nb++;
   	if (na && nb){
   		printf("2\na\nb");
   		return 0;
   	}
   	if (na)
   		printf("1\na");
   	else
   		printf("1\nb");	
	return 0;
}