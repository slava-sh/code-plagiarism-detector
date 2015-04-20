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
//    int i, j, k, h, S1 = 0, S2 = 0, S3 = 0, PLose = 0;
//    int N, M;
//    int Dir[4][2] = {{1, 1}, {1, -1}, {1, 0}, {0, 1}};
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
//            if (i == 0 || j == 0 || Desk[i - 1][j - 1] != 'X')
//            {
//                for (h = 0, k = 0; h < 5; h++)
//                {
//                    if (Desk[i + h][j + h] == '.')
//                        k++;
//                    else if (Desk[i + h][j + h] == '0')
//                        k += 5;
//                }
//                if (k == 1)
//                    S1++;
//                else
//                {
//                    if (k == 2 && Desk[i][j] == '.' && Desk[i + 4][j + 4])
//                    {
//                        if (i == 0 || j == 0 || Desk[i - 1][j - 1] == '.')
//                            S2++;
//                        if (i + 5 == N || j + 5 == M || Desk[i + 4][j + 4] == '.')
//                            S2++;
//                    }
//                }
//            }
//            if (i == 0 || j == 0 || Desk[i - 1][j - 1] != '0')
//            {
//                for (h = 0, k = 0; h < 5; h++)
//                {
//                    if (Desk[i + h][j + h] == '.')
//                        k++;
//                    else if (Desk[i + h][j + h] == 'X')
//                        k += 5;
//                }
//                if (k == 1)
//                {
//                    PLose++;
//                }
//            }
//        }
//}


#include <cmath>
#include <cstdio>

template<class T>
void mswap (T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template<class T>
T gcd (T a, T b)
{
    while (b != 0)
    {
        T tmp = a % b;
        a = b;
        b = tmp;
    }

    return a;
}

template<class T>
T mmin (T a, T b)
{
    return a < b ? a : b;
}

template<class T>
T mmax (T a, T b)
{
    return a > b ? a : b;
}

int main ()
{
    FILE *fin, *fout;

    fin = fopen ("gcm.in", "rt");
    fout = fopen ("gcm.out", "wt");

    int a, b, pr, shift;
    long long n;

    fscanf (fin, "%d %d", &a, &b);
    if (a > b)
        mswap (a, b);
    pr = (int)floor(sqrt (n = (long long)a * (long long)b)) + 1;
    shift = gcd (a, b);
    pr = (pr / shift + 1) * shift;

    while (pr > a)
    {
        if (n % pr == 0 && gcd<int>(pr, n / pr) == shift)
        {
            fprintf (fout, "%d %d", mmin<int> (pr, n / pr), mmax<int> (pr, n / pr));

            return 0;
        }

        pr -= shift;
    }

    fprintf (fout, "%d %d", a, b);

    return 0;
}
