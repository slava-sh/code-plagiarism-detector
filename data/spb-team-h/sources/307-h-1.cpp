#include <fstream>
#include <string>
#include <set>
#include <vector>

using namespace std;

class Name
{
    public: string a, b, c;
};

set<string> Names;
Name arr[1000];
set<string> MySet;

int Compare(const void *a, const void *b)
{
	Name n1 = *(Name *)a, n2 = *(Name *)b;
	if (n1.a < n2.a)
		return -1;
	if (n1.a > n2.a)
		return 1;
	return 0;
}

int main()
{
	ifstream fin("names.in");
	ofstream fout("names.out");
	int n, i, l;
	string d;
	fin >> n;
	for (i = 0; i < n; i++)
	{
		fin >> arr[i].a >> arr[i].b >> arr[i].c;
		l = MySet.size();
		MySet.insert(arr[i].a);
		if (MySet.size() == l)
			Names.insert(arr[i].a);
		l = MySet.size();
		MySet.insert(arr[i].b);
		if (MySet.size() == l)
			Names.insert(arr[i].b);
	}
	for (i = 0; i < n; i++)
	{
		if (Names.find(arr[i].a) != Names.end())
		{
			d = arr[i].c;
			arr[i].c = arr[i].b;
			arr[i].b = arr[i].a;
			arr[i].a = d;
		}
	}
	qsort(arr, n, sizeof(Name), Compare);
	for (i = 0; i < n; i++)
		fout << arr[i].a << ' ' << arr[i].b << ' ' << arr[i].c << '\n';
	return 0;
}