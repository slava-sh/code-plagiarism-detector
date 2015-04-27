// Actual code is in the very bottom of the file.

// template.hpp starts
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <typeinfo>
using namespace std;

typedef long long i64;

int next(int *dummy = 0) {
  int t;
  scanf("%d", &t);
  return t;
}

string next(string *dummy = 0) {
  char t[1000];
  scanf("%s", t);
  return string(t);
}

i64 next(i64 *dummy = 0) {
  i64 t;
  scanf("%lld", &t);
  return t;
}

double next(double *dummy = 0) {
  double t;
  scanf("%lf", &t);
  return t;
}

template<class T>
vector<T> nextVector(int n, T *dummy = 0) {
  vector<T> ans(n);
  for (int i = 0; i < n; ++i) {
    ans[i] = next((T*)0);
  }
  return ans;
}

int nextInt() {
  return next((int *) 0);
}

string nextString() {
  return next((string *) 0);
}

i64 nextLong() {
  return next((i64 *) 0);
}

double nextDouble() {
  return next((double *) 0);
}

vector<int> nextVectorInt(int n) {
  return nextVector(n, (int*) 0);
}

vector<double> nextVectorDouble(int n) {
  return nextVector(n, (double*) 0);
}

vector<i64> nextVectorLong(int n) {
  return nextVector(n, (i64*) 0);
}


void print(int x) {
  printf("%d", x);
}

void print(i64 x) {
  printf("%lld", x);
}

void print(string x) {
  printf("%s", x.c_str());
}

void print(double x) {
  printf("%lf", x);
}

template<class T1, class T2>
void print(pair<T1, T2> &x) {
  printf("(");
  printf(x.first);
  printf(", ");
  printf(x.second);
  printf(")");
}


typedef char True;
typedef long long False;

template<typename T>
True hasIteratorCheck(T * t, typename T::iterator* dummy = 0) { }

template<typename T>
False hasIteratorCheck(void *) { }

template<typename T>
struct HasIterator {
  static const bool value = sizeof(hasIteratorCheck<T>((T*)0)) == sizeof(True);
};

template <bool B>
struct EnableIf {
  typedef char type;
};

template <>
struct EnableIf<false> {};

template <bool B>
struct DisableIf {
  typedef char type;
};

template <>
struct DisableIf<true> {};

template <class T>
void _smart_print(T x, typename DisableIf<HasIterator<T>::value>::type* dummy = 0) {
  print(x.to_s());
}  

template <class T>
void _smart_print(T x, typename EnableIf<HasIterator<T>::value>::type* dummy = 0) {
  printf("[");
  for (typename T::iterator i = x.begin(); i != x.end(); ++i) {
    if (i == x.begin()) {
      printf(" ");
    } else {
      printf(", ");
    }
    print(*i);
  }
  printf(" ]"); 
}

template <class T>
void print(T t) {
  _smart_print(t);
}

template <class T>
void println(T t) {
  print(t);
  printf("\n");
}
/// template.hpp ends

/// single_test.hpp starts
void solve(int testN = 0);

int main() {
  solve(0);
  return 0;
}
/// single_test.hpp ends

/// Proble source:



vector< vector<int> > tAns;
vector< vector<bool> > visited;

void make_good(int i, int j) {  
  vector<int> que(20);
  vector<int> near(10, 0);
  vector<int> comp;
  int start = 0;
  int end = 0;
  que[end++] = i;
  que[end++] = j;
  visited[i][j] = true;
  int di[] = {-1, 0, 0, 1};
  int dj[] = {0, -1, 1, 0};
  comp.push_back(i);
  comp.push_back(j);
  int col  = tAns[i][j];
  while (end != start) {
    int ci = que[start++];
    int cj = que[start++];
    for (int t = 0; t < 4; ++t) {
      int ni = ci + di[t];
      int nj = cj + dj[t];
      if (tAns[ni][nj] == -1) {
	continue;
      }
      if (tAns[ni][nj] < 9) {
	++near[tAns[ni][nj]];
      }
      if (tAns[ni][nj] == col && !visited[ni][nj]) {
	visited[ni][nj] = true;
	comp.push_back(ni);
	comp.push_back(nj);
	que[end++] = ni;
	que[end++] = nj;
      }
    }
  }
  int acol = 9999;
  for (int i = 0; i < 10; ++i) {
    if (near[i] == 0) {
      acol = i;
      break;
    }
  }
  for (int i = 0; i < comp.size(); i += 2) {
    tAns[comp[i]][comp[i + 1]] = acol;
  }
}

void solve(int testN) {
  //ToDo --- code here.
  int n = nextInt();
  int m = nextInt();
  vector<string> table(n);
  for (int i = 0 ; i < n; ++i) {
    char buf[2000];
    scanf("%s", buf);
    table[i] = buf;
  }
  int cn = 0;
  tAns = vector< vector<int> >(n + 2, vector<int>(m + 2, 0));;
  visited = vector< vector<bool> >(n + 2, vector<bool>(m + 2, false));;
  for (int i = 0 ; i <= n + 1; ++i) {
    tAns[i][0] = -1;
    tAns[i][m + 1] = -1;
  }

  for (int i = 0 ; i <= m + 1; ++i) {
    tAns[0][i] = -1;
    tAns[n + 1][i] = -1;
  }

  for (int i = 0 ; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (table[i][j] == '#') {
	tAns[i + 1][j + 1] = -1;
      }
    }    
  }

  bool ok = true;
  for (int i = 0; i < n + 2; ++i) {
    for (int j = 0; j < m + 2; ++j) {
      if (tAns[i][j] == 0) {
	if (tAns[i][j + 1] == 0) {
	  tAns[i][j] = ++cn;
	  tAns[i][j + 1] = cn;
	} else {
	  if (tAns[i + 1][j] != -1) {
	    tAns[i][j] = ++cn;
	    tAns[i + 1][j] = cn;	    
	  } else if (tAns[i - 1][j] != -1) {
	    tAns[i][j] = tAns[i - 1][j];
	  } else if (tAns[i][j - 1] != -1) {
	    tAns[i][j] = tAns[i][j - 1];
	  } else if (tAns[i][j + 1] != -1) {
	    tAns[i][j] = tAns[i][j + 1];
	  } else {
	    ok = false;
	    break;
	  }
	}
      }
      if (!ok) {
	break;
      }
    }
  }
  if (ok) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
	if (tAns[i][j] == -1) {
	  printf("#");
	} else {
	  if (tAns[i][j] > 9) {
	    make_good(i, j);
	  }
	  print(tAns[i][j]);
	}
      }
      println(string(""));
    }
  } else {
    println(-1);
  }
}




///Eof
