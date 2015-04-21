#include<iostream>
#include<cstdlib>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#define ll long long
#define ld long double
#define cs(a) ((int)a.size())
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define BAD -1001230000
using namespace std;

char s[100000];

int main(void) {
	int l, ssize;
	scanf("%d", &l);
	scanf("%s", s);
	ssize = strlen(s);
	if (ssize <= l) {
		printf("1\n%s", s);
	} else
		printf("2\na\nb\n");
}