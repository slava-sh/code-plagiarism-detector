#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int n,k;

vector<bool> b;
long long v[100000];

	ifstream in("fence.in");
	ofstream out("fence.out");
int count1(0);

void f(int tn, int tk, int c, vector<bool> tb)
{
	int tc(0);
	if(tn == n)
	{
		if(count1 < c)
			count1 = c;
		return;
	}
	for(int i=0; i<v[tn]; ++i)
	{
		if(tk+i < k)
		{
			if(!tb[tk+i])
			{
				tb[tk+i] = true;
				++tc;
			}
		}
		else
		{
			if(!tb[tk+i-k])
			{
				tb[tk+i-k] = true;
				++tc;
			}
		}
	}
	out << tc << ' ' <<  c << ' ' << tn << endl;
	f(tn+1,tk+1,(c>tc)?tc:c,tb);
}

int main ()
{
	in >> n >> k;
	for(int i=0;i<n;++i)
		in >> v[i];
	
	vector<bool> bb(k, false);
	b = bb;

	long long s(0LL);
	for(int i=0; i<n; ++i)
		s += v[i];

	if(k >= s)
	{
		out << *min_element(v, v+n);
		return 0;
	}
	else if(k < s)
	{
		if(k <= *max_element(v, v+n))
		{
			out << 0;
			return 0;
		}
		out << k - *max_element(v, v+n);
		/*for(int i=0; i<v[0]; ++i)
			b[i] = true;
		f(1,0,v[0],b);
		*/
	}

	return 0;
}
