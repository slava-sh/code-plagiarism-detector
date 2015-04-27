#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

template <typename T>
class BinaryIndexedTree {

private:
	vector<T> data;

public:
	BinaryIndexedTree(int n = 0) : data(n + 1) { }
	T sum(int i){
		T s = T();
		for(; i > 0; i -= i & -i){ s += data[i]; }
		return s;
	}
	void add(int i, const T &x){
		for(++i; i < static_cast<int>(data.size()); i += i & -i){
			data[i] += x;
		}
	}

};

int main(){
	ios_base::sync_with_stdio(false);
	int n, p;
	cin >> n >> p;
	vector< vector<int> > conn(n);
	vector<int> hist(n);
	for(int i = 0; i < n; ++i){
		int a, b;
		cin >> a >> b;
		--a; --b;
		conn[a].push_back(b);
		conn[b].push_back(a);
		++hist[a];
		++hist[b];
	}
	BinaryIndexedTree<int> bit(n + 1);
	for(int i = 0; i < n; ++i){
		bit.add(n - hist[i], 1);
	}
	ll answer = 0;
	for(int i = 0; i < n; ++i){
		const int q = p - conn[i].size();
		for(int j = 0; j < conn[i].size(); ++j){
			const int t = conn[i][j];
			bit.add(n - hist[t], -1);
			--hist[t];
			bit.add(n - hist[t], 1);
		}
		bit.add(n - hist[i], -1);
		answer += bit.sum(n - max(0, q) + 1);
		bit.add(n - hist[i], 1);
		for(int j = 0; j < conn[i].size(); ++j){
			const int t = conn[i][j];
			bit.add(n - hist[t], -1);
			++hist[t];
			bit.add(n - hist[t], 1);
		}
	}
	cout << answer / 2 << endl;
	return 0;
}
