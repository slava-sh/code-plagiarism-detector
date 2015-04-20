//#include <cstdio>
//#include <vector>
//#include <string>
//#include <algorithm>
//
////using namespace std;
////
////class pupil
////{
////    string first, second, mid;
////    char ofirst[30], osecond[30], omid[30];
////    bool shift;
////
////public:
////    pupil (const char *f, const char *s, const char *m) : first (f), second (s), mid (m), shift (false)
////    {
////        strcpy (ofirst, f);
////        strcpy (osecond, s);
////        strcpy (omid, m);
////    }
////
////    bool concat (const string &name) const
////    {
////        return name == first || name == second;
////    }
////
////    void swap (const vector<pupil> &people)
////    {
////        bool flag = false;
////
////        for (unsigned int i = 0; i < people.size (); i++)
////            if (people[i].concat (first))
////            {
////                if (flag)
////                {
////                    shift = true;
////
////                    return;
////                }
////                else
////                    flag = true;
////            }
////    }
////
////    void output (FILE *fout)
////    {
////        if (shift)
////            fprintf (fout, "%s %s %s\n", omid, ofirst, osecond);
////        else
////            fprintf (fout, "%s %s %s\n", ofirst, osecond, omid);
////    }
////
////    const string &get_first () const
////    {
////        return shift ? mid : first;
////    }
////
////    bool operator< (const pupil &p) const
////    {
////        return get_first () < p.get_first ();
////    }
////};
////
////int main ()
////{
////    FILE *fin, *fout;
////
////    fin = fopen ("names.in", "rt");
////    fout = fopen ("names.out", "wt");
////
////    int n;
////    vector<pupil> people;
////
////    fscanf (fin, "%d", &n);
////
////    for (int i = 0; i < n; i++)
////    {
////        char f[30], s[30], m[30];
////
////        fscanf (fin, "%s %s %s", &f, &s, &m);
////
////        people.push_back (pupil (f, s, m));
////    }
////
////    for (int i = 0; i < n; i++)
////        people[i].swap (people);
////
////    sort (people.begin (), people.end ());
////
////    for (int i = 0; i < n; i++)
////        people[i].output (fout);
////
////    return 0;
////}
//
//int main (void)
//{
//    char Desk[200][200];
//    int i, j, k, h, S = 0;
//    int N, M;
//    FILE *fin, *fout;
//    
//    fin = fopen ("tictactoe.in", "rt");
//    fout = fopen ("tictactoe.out", "wt");
//
//    fscanf (fin, "%d %d", &N, &M);
//    for (i = 0; i < N; i++)
//        for (j = 0; j < M; j++)
//        {
//            fscanf (fin, "%c", &(Desk[i][j]));
//        }
//
//    for (i = 0; i < N; i++)
//        for (j = 0; j < M; j++)
//        {
//            if (i <= 0 || j <= 0 || Desk[i - 1][j - 1] != 'X')
//            {
//                for (h = 0, k = 0; h < 5; h++)
//                {
//                    if (Desk[i + h][j + h] == '.')
//                        k++;
//                    else if (Desk[i + h][j + h] == '0')
//                        k += 5;
//                }
//                if ( k = 1 )
//            }
//        }
//}


#include <cmath>
#include <cstdio>

void mswap (long long &a, long long &b)
{
    long long tmp = a;
    a = b;
    b = tmp;
}

int gcd (int a, int b)
{
    while (b != 0)
    {
        int tmp = a % b;
        a = b;
        b = tmp;
    }

    return a;
}

long long mmin (long long a, long long b)
{
    return a < b ? a : b;
}

long long mmax (long long a, long long b)
{
    return a > b ? a : b;
}

int main ()
{
    FILE *fin, *fout;

    fin = fopen ("gcm.in", "rt");
    fout = fopen ("gcm.out", "wt");

    long long a, b, pr, n, shift;

    fscanf (fin, "%I64d %I64d", &a, &b);
    if (a > b)
        mswap (a, b);
    pr = (long long)floor(sqrt (n = a * b)) + 1;
    shift = gcd ((int)a, (int)b);
    pr = (pr / shift + 1) * shift;

    while (pr > a)
    {
        if (n % pr == 0 && gcd((int)pr, (int)(n / pr)) == shift)
        {
            fprintf (fout, "%I64d %I64d", mmin (pr, n / pr), mmax (pr, n / pr));

            return 0;
        }

        pr -= shift;
    }

    fprintf (fout, "%I64d %I64d", a, b);

    return 0;
}