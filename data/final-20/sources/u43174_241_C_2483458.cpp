#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

#define mp make_pair
#define x first
#define y second

using namespace std;

typedef pair<double, double> pdd;

const int MaxN = 105;
const double Eps = 1e-6;

pdd RealP[MaxN], VirtualP[MaxN];
double H, W, YS, YE, SegmentsY[MaxN];
int NS, Value[MaxN], Sol;
pdd Segments[MaxN];

inline pdd Symmetrical(pdd P, double Y) {
    P.y = 2*Y-P.y;
    return P;
}

inline void GetEquation(pdd P1, pdd P2, double &m, double &n) {
    m = (P2.y-P1.y)/(P2.x-P1.x);
    n = P1.y-m*P1.x;
}

void BuildP(int N, int d) {
    RealP[1] = mp(0, YS);
    VirtualP[N] = Symmetrical(mp(W, YE), (d ? 0 : H));
    for (int i = N-1; i > 1; --i, d ^= 1)
        VirtualP[i] = Symmetrical(VirtualP[i+1], (d^1 ? 0 : H));
    for (int i = 2; i <= N; ++i) {
        pdd P1 = RealP[i-1], P2 = VirtualP[i];
        RealP[i].y = (P2.y < -Eps ? 0.0 : H);
        double m, n; GetEquation(P1, P2, m, n);
        RealP[i].x = (RealP[i].y-n)/m;
    }
}

int Solve(int N, int d) {
    BuildP(N, d);
    int Shot[MaxN]; memset(Shot, 0, sizeof(Shot));
    for (int i = 2; i <= N; ++i) {
        bool Valid = false;
        for (int j = 1; j <= NS; ++j) {
            if (abs(RealP[i].y-SegmentsY[j]) < Eps && Segments[j].x-Eps < RealP[i].x && RealP[i].x < Segments[j].y+Eps) {
                ++Shot[j], Valid = true;
            }
        }
        if (!Valid)
            return 0;
    }
    int CSol = 0;
    for (int i = 1; i <= NS; ++i)
        CSol += (Shot[i] ? Value[i] : 0);
    for (int i = 1; i <= NS; ++i)
        if (Shot[i] > 1)
            CSol = 0;
    return CSol;
}

void Read() {
    W = 100000, H = 100;
    scanf("%lf %lf %d", &YS, &YE, &NS);
    for (int i = 1; i <= NS; ++i) {
        char Type; scanf("%d %c %lf %lf", &Value[i], &Type, &Segments[i].x, &Segments[i].y);
        SegmentsY[i] = Type == 'F' ? 0 : H;
    }
}

void Print() {
    printf("%d\n", Sol);
}

int main() {
    Read();
    for (int i = 2; i <= NS+1; ++i)
        Sol = max(Sol, max(Solve(i, 0), Solve(i, 1)));
    Print();
    return 0;
}
