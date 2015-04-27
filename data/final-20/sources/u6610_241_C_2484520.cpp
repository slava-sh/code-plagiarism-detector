#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <queue>

#define fii(x,y) for(int i=x;i<y;i++)
#define fjj(x,y) for(int j=x;j<y;j++)
#define fkk(x,y) for(int k=x;k<y;k++)
#define fi(x) fii(0,x)
#define fj(x) fjj(0,x)
#define fk(x) fkk(0,x)
#define eps 0.0000000001
#define inf 1<<28

using namespace std;

typedef long long ll;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef vector <VVI> VVVI;
typedef vector <ll> VL;
typedef vector <VL> VVL;
typedef vector <double> VD;
typedef vector <VD> VVD;
typedef vector <bool> VB;
typedef vector <VB> VVB;
typedef queue <int> QI;
typedef pair<int,int> PI;
typedef pair<int,PI> PT;
typedef queue<PI> QPI;
typedef priority_queue<PT> QPT;
typedef pair<double,double> PD;
typedef vector<char> VC;

int main()
{
  double hl,hr;
  int n;
  cin >> hl >> hr >> n;
  VI v, a, b;
  VC c (n);
  v = a = b = VI (n);
  fi (n) cin >> v[i] >> c[i] >> a[i] >> b[i];
  int vm = 0;
  for (int dir = 0; dir < 2; dir++)
  fii (1,3*n+7)
  {
    double left = hl;
    double right = 100*i;
    if (dir == 1) right *= -1;
    if (i%2 == 1) right += 100-hr;
    else right += hr;
    double dif = fabs(left-right);
    double per = 10000000./dif;
    double ini = 100000.*(100-hl)/dif;
    if (dir == 1)
      ini = 100000.*(hl)/dif;
    char lc = 'T';
    if (dir == 1) lc = 'F';
    VI lesp;
    bool ok = true;
    fj (i)
    {
      fk (n) if (c[k] == lc and a[k] <= ini and b[k] >= ini)
      {
        lesp.push_back(k);
      }
      if (lesp.size() != j+1)
      {
        ok = false;
        break;
      }
      if (lesp.size() > 2 and lesp[j] == lesp[j-2])
      {
        ok = false;
        break;
      }
      if (lc == 'T') lc = 'F';
      else lc = 'T';
      ini += per;
    }
    if (not ok) continue;
    int sm = 0;
    fj (lesp.size()) sm += v[lesp[j]];
    vm = max (vm, sm);
  }
  cout << vm << endl;
}