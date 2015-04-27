#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define MP make_pair

using namespace std;

typedef pair<int, int> PII;
typedef pair<PII, int> PPI;

const double EPS = 1e-8;
const int MAXN = 105;

int hl, hr, N;
vector<PPI> mirror[3];
bool flag[MAXN];
int sco[MAXN];

double sabs(double x){
	if(x > 0) return x;
	else return -x;
}

bool check(PII inv, double x){
	if(sabs(x - inv.first) <= EPS || sabs(x - inv.second) <= EPS) return true;
	return (x > inv.first && x < inv.second);
}

int gaou(int v){
	int sty = hl;
	int tay;
	if(v % 2 == 0){
		tay = v * 100 + hr;
	}else{
		tay = v * 100 + (100 - hr);
	}
	double k = (tay - sty) * 1.0 / 100000.0;
	double b = sty;
	memset(flag, false, sizeof(flag));
	int ret = 0;
	for(int i = 1; i <= v; ++i){
		double nowy = i * 100;
		double nowx = (nowy - b) / k;
		bool ok = false;
		if(i % 2 == 0){
			//bottom
			for(int i = 0; i < mirror[1].size(); ++i)
				if(check(mirror[1][i].first, nowx)){
					if(!flag[mirror[1][i].second]){
						ret += sco[mirror[1][i].second];
						flag[mirror[1][i].second] = true;
						ok = true;
					}else return -1;
				}
		}else{
			//top
			for(int i = 0; i < mirror[0].size(); ++i)
				if(check(mirror[0][i].first, nowx)){
					if(!flag[mirror[0][i].second]){
						ret += sco[mirror[0][i].second];
						flag[mirror[0][i].second] = true;
						ok = true;
					}else return -1;
				}
		}
		if(!ok) return -1;
	}
	return ret;
}

int gaod(int v){
	return 0;
}

int main(){
	scanf("%d%d%d", &hl, &hr, &N);
	for(int i = 0; i < N; ++i){
		char ty[2];
		int l, r;
		scanf("%d%s%d%d", &sco[i], ty, &l, &r);
		if(ty[0] == 'T'){
			mirror[0].push_back(MP(PII(l, r), i));
		}else{
			mirror[1].push_back(MP(PII(l, r), i));
		}
	}
	int ans = 0;
	for(int i = 1; i <= N; ++i){
		ans = max(ans, gaou(i));
	}
	mirror[2] = mirror[1];
	mirror[1] = mirror[0];
	mirror[0] = mirror[2];
	hl = 100 - hl; hr = 100 - hr;
	for(int i = 1; i <= N; ++i){
		ans = max(ans, gaou(i));
	}
	printf("%d\n", ans);
}
