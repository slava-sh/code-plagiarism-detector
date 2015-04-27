#include <cstdio>

const int MAX = 2000020;

int n, m;

int BIT[MAX];

int get(int pos){
	int ret = 0;
	while(pos){
		ret += BIT[pos];
		pos -= pos & -pos;
	}

	return ret;
}

void update(int pos, int val){
	while(pos < MAX){
		BIT[pos] += val;
		pos += pos & -pos;
	}
}

int pos[MAX], last, match[MAX];
bool used[MAX];

void solve(){
	last = n;

	int i;
	for(i = 1; i<=n; i++){
		update(i, 1);
		pos[i] = i;
	}

	int query;
	for(query = 0; query < m; query++){
		int num, at;
		scanf("%d%d", &num, &at);

		int l = 0, r = last, m;
		while(l <= r){
			m = (l+r)>>1;
			if(get(m) >= n-at+1) r = m-1;
			else l = m+1;
		}

		int index = r+1;
		if((match[pos[index]] == 0 && !used[num]) || match[pos[index]] == num){
			used[num] = 1;

			match[pos[index]] = num;
			update(index, -1);

			pos[++last] = pos[index];
			pos[index] = 0;
			update(last, 1);
		} else {
			puts("-1");
			return;
		}
	}

	int j = 1;
	for(i = n; i>=1; i--){
		if(match[i]) printf("%d ", match[i]);
		else {
			while(used[j]) j++;
			printf("%d ", j++);
		}
	}
	puts("");
}

int main(){
	scanf("%d%d", &n, &m);

	solve();

	return 0;
}