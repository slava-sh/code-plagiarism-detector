#include <iostream>
#include <iomanip>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;
#define mp make_pair
#define ll long long
#define mod 1000000007

static vector <char> vc;
static vector <int> vc1;

int main(){
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "-w", stdout);
	vc.push_back('U');
	vc.push_back('L');
	vc.push_back('D');
	vc.push_back('R');
	vc1.push_back(1);
	vc1.push_back(1);
	int cu = 0, a = 1, b = 1, c = 0;
	char ch = 'N';
	while (ch == 'N'){
        if (b == 0){
            c = (c + 1) % 2;
            b = vc1[c];
        }
        --b;
        cout << vc[c] << endl;
        cin >> ch;
	}
	//system("pause");
	return 0;
}
