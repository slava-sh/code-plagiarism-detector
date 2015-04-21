#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <functional>
#include <queue>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <algorithm>

#define pb push_back
#define mp make_pair
#define ll long long
#define ld long double
#define y1 yy1

using namespace std;

char ans;
char c[2]={'D','R'};
int mut,curc;

int main()
{
	//ios_base::sync_with_stdio(false);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	srand(time(NULL));
	curc=0;
	while (1)
	{
		mut=rand()%10;
		if (mut==5)
			cout<<c[1-curc]<<endl;
		else
			cout<<c[curc]<<endl;
		cout.flush();
		cin>>ans;
		if (ans=='Y' || ans=='E')
			return 0;
		curc=1-curc;
	}
	return 0;
}



