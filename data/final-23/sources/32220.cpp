#include <iostream>
#include <cstdio>
#include <stdlib.h>

#define tree struct_tree
#define rvq struct_rvq
#define inf 9999999999
#define MaxN 262145

using namespace std;
FILE *input, *output;

struct tree{
	long long add, i, sum;
};


tree leaf1[MaxN], leaf2[MaxN];
signed long long pow = 1, n, k, a, b, c, norm;// o[MaxN], s, norm, brut;
int cmd;

void push(tree leaf[MaxN], long long t, long long l, long long r, long long lb, long long rb){
	long long m = (lb + rb) / 2;

	if (leaf[t].add == -1){
		return;
	}

	if (((lb <= r) || (m >= l)) && (leaf[t].i)){
		leaf[t * 2 + 1].add = leaf[t].add;
		leaf[t * 2 + 1].sum = leaf[t].add * (lb - m + 1);
	}

	if (((m + 1 <= r) || (rb >= l)) && (leaf[t].i)){
		leaf[t * 2 + 2].add = leaf[t].add;
		leaf[t * 2 + 2].sum = leaf[t].add * (m - rb + 2);
	}

	leaf[t].sum = leaf[t].add * (rb - lb + 1);
	leaf[t].add = -1;
}

void change(tree leaf[MaxN], long long t, long long l, long long r, long long x, long long lb, long long rb){
	long long m = (lb + rb) / 2;
	
	if ((lb > r) || (rb < l)){
		return;
	}

	if ((lb >= l) && (rb <= r)){
		leaf[t].add = x;

		push(leaf, t, l, r, lb, rb);

		return;
	}	

	push(leaf, t, l, r, lb, rb);

	if (leaf[t].i){	
		change(leaf, t * 2 + 1, l, r, x, lb, m);
		change(leaf, t * 2 + 2, l, r, x, m + 1, rb);
		push(leaf, t * 2 + 1, l, r, lb, m);
		push(leaf, t * 2 + 2, l, r, m + 1, rb);
		leaf[t].sum = leaf[t * 2 + 1].sum + leaf[t * 2 + 2].sum;
	}
}
long long sum(tree leaf[MaxN], long long t, long long l, long long r, long long lb, long long rb){
	long long res = 0, m = (lb + rb) / 2;
	
	push(leaf, t, l, r, lb, rb);

	if ((lb > r) || (rb < l)){
		return 0;
	}

	if ((lb >= l) && (rb <= r)){
		return leaf[t].sum;
	} else { 
		res = sum(leaf, t * 2 + 1, l, r, lb, m) + sum(leaf, t * 2 + 2, l, r, m + 1, rb);
	}

	return res;
}
int main(){
	input = fopen("signchange.in", "r");
	freopen("signchange.out", "w", stdout);
	
	fscanf(input, "%i\n", &n);
	
	while (pow < n){
		pow *= 2;
	}
	pow--;

	for (int i = pow; i < pow + n; i++){
		leaf1[i].add = -1;
		leaf2[i].add = -1;
	
		fscanf(input, "%i", &c);

		if (i % 2){
			leaf2[i].sum = c;
		} else {
			leaf1[i].sum = c;
		}
	}

	for (int i = pow + n; i < pow * 2 + 2; i++){
		leaf1[i].add = -1;
		leaf2[i].add = -1;
	}

	for (int i = pow - 1; i >= 0; i--){
		leaf1[i].add = -1;
		leaf1[i].sum = leaf1[i * 2 + 1].sum + leaf1[i * 2 + 2].sum;
		leaf1[i].i = 1;
		leaf2[i].add = -1;
		leaf2[i].sum = leaf2[i * 2 + 1].sum + leaf2[i * 2 + 2].sum;
		leaf2[i].i = 1;
	}

	fscanf(input, "%i", &k);

	for (long long i = 0; i < k; i++){
		fscanf(input, "%i", &cmd);

		if (cmd == 0){
			fscanf(input, "%lld %lld\n", &a, &b);
			if ((a) % 2){
				change(leaf2, 0, a - 1, a - 1, b, 0, pow);
			} else {
				change(leaf1, 0, a - 1, a - 1, b, 0, pow);
			}
		} else {
			fscanf(input, "%lld %lld\n", &a, &b);
			if ((a) % 2){
				norm = sum(leaf2, 0, a - 1, b - 1, 0, pow);
				norm -= sum(leaf1, 0, a - 1, b - 1, 0, pow);
			} else {
				norm = sum(leaf1, 0, a - 1, b - 1, 0, pow);
				norm -= sum(leaf2, 0, a - 1, b - 1, 0, pow);
			}
			cout << norm << endl;
		}
	}

//	}
	return 0;
}