#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
	freopen("numbers.in","r",stdin);
	freopen("numbers.out","w",stdout);
	int n, k, r;
	cin >> n;
	vector<string> a(n);
	vector<vector<string> > b(n, vector<string>());
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		cin >> k;
		b[i].resize(k);
		for(int j = 0; j < k; j++) {
			cin >> b[i][j];
		}
	}
	cin >> n;
	vector<string> nom(n);
	for(int i = 0; i < n; i++) {
		cin >> nom[i];
	}
	for(int i = 0; i < n; i++) {
		int in, in1;
		int l, l1;
		if(nom[i][0] == '0') {
			cout << "Incorrect" << "\n";
			continue;
		}
		for(int j = 0; j < a.size(); j++) {
			l = nom[i].find(a[j]);
			if(l == 0) {
				in = j;
				break;
			}
		}
		if(l != 0 || nom[i][l] == '0' || a[in].size() > 3) {
			cout << "Incorrect" << "\n";
			continue;
		}
		for(int j = 0; j < b[in].size(); j++) {
			l1 = nom[i].find(b[in][j]);
			if(l1 == a[in].size()) {
				in1 = j;
				break;
			}
		}
		if(l1 != a[in].size() || b[in][in1].size() < 3 || b[in][in1].size() < 3 > 5) {
			cout << "Incorrect" << "\n";
			continue;
		}
		int z = nom[i].size() - a[in].size() - b[in][in1].size();
		if(nom[i][a[in].size() + b[in][in1].size()] == '0') {
			cout << "Incorrect" << "\n";
			continue;
		}
		cout << "+" << a[in] << "(" << b[in][in1] << ")";
		if(z == 3) {
			cout << nom[i][a[in].size() + b[in][in1].size()] << nom[i][a[in].size() + b[in][in1].size() + 1];
			cout << nom[i][a[in].size() + b[in][in1].size() + 2];
		}
		if(z == 4) {
			cout << nom[i][a[in].size() + b[in][in1].size()] << nom[i][a[in].size() + b[in][in1].size() + 1] << "-";
			cout << nom[i][a[in].size() + b[in][in1].size() + 2] << nom[i][a[in].size() + b[in][in1].size() + 3];
		}
		if(z == 5) {
			cout << nom[i][a[in].size() + b[in][in1].size()] << nom[i][a[in].size() + b[in][in1].size() + 1];
			cout << nom[i][a[in].size() + b[in][in1].size() + 2] << "-" << nom[i][a[in].size() + b[in][in1].size() + 3];
			cout << nom[i][a[in].size() + b[in][in1].size() + 4];
		}
		if(z == 6) {
			cout << nom[i][a[in].size() + b[in][in1].size()] << nom[i][a[in].size() + b[in][in1].size() + 1] << "-";
			cout << nom[i][a[in].size() + b[in][in1].size() + 2] << nom[i][a[in].size() + b[in][in1].size() + 3] << "-";
			cout << nom[i][a[in].size() + b[in][in1].size() + 4] << nom[i][a[in].size() + b[in][in1].size() + 5];
		}
		if(z == 7) {
			cout << nom[i][a[in].size() + b[in][in1].size()] << nom[i][a[in].size() + b[in][in1].size() + 1];
			cout << nom[i][a[in].size() + b[in][in1].size() + 2] << "-" << nom[i][a[in].size() + b[in][in1].size() + 3];
			cout << nom[i][a[in].size() + b[in][in1].size() + 4] << "-" << nom[i][a[in].size() + b[in][in1].size() + 5];
			cout << nom[i][a[in].size() + b[in][in1].size() + 6];
		}
		cout << "\n";
	}
	return 0;
}