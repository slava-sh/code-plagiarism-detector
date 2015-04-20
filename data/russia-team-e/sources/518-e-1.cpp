#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

string s;
int lenC, lenR;

struct v {
	bool isT;
	v *nxt[10];
	v () {
		for (int i = 0; i < 10; ++i) nxt[i] = 0;
		isT = 0;
	}
};

struct V {
	bool isT;
	V *nxt[10];
	v *down;
	V () {
		for (int i = 0; i < 10; ++i) nxt[i] = 0;
		down = new v();
		isT = 0;
	}
	V *addC() { // string s is global
		V *now = this;
		for (int i = 0; i < s.size(); ++i) {
			if (now->nxt[s[i] - '0'] == 0) now->nxt[s[i] - '0'] = new V();
			now = now->nxt[s[i] - '0'];
		}
		now->isT = 1;
		return now;
	}
	void addR() { // string s is global
		v *now = down;
		for (int i = 0; i < s.size(); ++i) {
			if (now->nxt[s[i] - '0'] == 0) now->nxt[s[i] - '0'] = new v();
			now = now->nxt[s[i] - '0'];
		}
		now->isT = 1;
	}
};


V *base;

int isR(V *curC, int pos) {
	lenR = 0;
	v *now = curC->down;
	for (int i = 0; i < 3; ++i) {
		if (!now->nxt[s[i + pos] - '0']) return 0;
		now = now->nxt[s[i + pos] - '0'];
	}
	for (int i = 3; i <= 5; ++i) {
		if (now->isT && s[i + pos] != '0') {
			lenR = i;
			return i;
		}
		if (!now->nxt[s[i + pos] - '0']) return 0;
		now = now->nxt[s[i + pos] - '0'];
	}
	return 0;
}

int isC() {
	lenC = 0;
	V *now = base;
	for (int i = 0; i < 3; ++i) {
		if (!now->nxt[s[i] - '0']) return 0;
		now = now->nxt[s[i] - '0'];
		if (now->isT && isR(now, i + 1)) {
			lenC = i + 1;
			return i + 1;
		}
	}
	return 0;
}

void doit() {
	if (!isC()) {
		printf("Incorrect\n");
		return;
	}
	printf("+");
	int i, len = lenC + lenR;
	for (i = 0; i < lenC; ++i) printf("%c", s[i]);
	printf("(");
	for (i = lenC; i < lenC + lenR; ++i) printf("%c", s[i]);
	printf(")");
	switch (11 - len) {
	case (3):
		for (i = len; i < 11; ++i) printf("%c", s[i]);
		break;
	case (4):
		for (i = len; i < len + 2; ++i) printf("%c", s[i]);
		printf("-");
		for (i = len + 2; i < 11; ++i) printf("%c", s[i]);
		break;
	case (5):
		for (i = len; i < len + 3; ++i) printf("%c", s[i]);
		printf("-");
		for (i = len + 3; i < 11; ++i) printf("%c", s[i]);
		break;
	case (6):
		for (i = len; i < len + 2; ++i) printf("%c", s[i]);
		printf("-");
		for (i = len + 2; i < len + 4; ++i) printf("%c", s[i]);
		printf("-");
		for (i = len + 4; i < 11; ++i) printf("%c", s[i]);
		break;
	case (7):
		for (i = len; i < len + 3; ++i) printf("%c", s[i]);
		printf("-");
		for (i = len + 3; i < len + 5; ++i) printf("%c", s[i]);
		printf("-");
		for (i = len + 5; i < 11; ++i) printf("%c", s[i]);
		break;
	}
	printf("\n");
}

int main() {
	freopen("numbers.in", "r", stdin);
	freopen("numbers.out", "w", stdout);

	base = new V();
	V* curC;
	int n, i, j, k, m;
	cin >> n;
	for (i = 0; i < n; ++i) {
		cin >> s >> k;
		curC = base->addC();
		getline(cin, s);
		for (j = 0; j < k; ++j) {
			getline(cin, s);
			curC->addR();
		}
	}
	cin >> m;
	getline(cin, s);
	for (i = 0; i < m; ++i) {
		getline(cin, s);
		doit();
	}
	return 0;
}