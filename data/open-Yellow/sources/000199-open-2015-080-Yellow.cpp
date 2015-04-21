#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
const int N = 1e6;
using namespace std;
struct leaf
{
	int l, r, num;
};
int n;
int beg[N];
leaf ar[2*N];

void build(int l, int r, int t)
{
	if (l == r)
		{
			ar[t] = {beg[l], beg[l], 1};
			return;
		}
	int mid  = (l + r) / 2;
	build(l, mid, t*2);
	build(mid + 1, r, t * 2 + 1);

	ar[t] = {ar[t*2].l, ar[t * 2 + 1].r, ar[t*2].num + ar[t*2+1].num - (ar[t*2].r == ar[t*2 + 1].l)};
}

void change(int k, int p, int l, int r, int t)
{
	if (l == r)
	{
		ar[t] = {p, p, 1};
		return;
	}
	int mid = (l + r) / 2;
	if (k <= mid)
	{
		change(k, p, l, mid, t * 2);

	} else {
		change(k, p, mid + 1, r, t * 2 + 1);
	}
	ar[t] = {ar[t*2].l, ar[t * 2 + 1].r, ar[t*2].num + ar[t*2+1].num - (ar[t*2].r == ar[t*2 + 1].l)};
}


int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
	for (int i=0; i<n; i++)
		cin >> beg[i];
	build (0, n-1, 1);
	int q;
	cin >> q;
	for (int i=0; i<q; i++)
		{
			int a, b;
			cin >> a >> b;
			change(a-1, b, 0, n-1, 1);
			cout << ar[1].num << "\n";
		}
    return 0;
}
