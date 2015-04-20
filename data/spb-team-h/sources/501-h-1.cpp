#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class pupil
{
    string first, second, mid;
    char ofirst[30], osecond[30], omid[30];
    bool shift;

public:
    pupil (const char *f, const char *s, const char *m) : first (f), second (s), mid (m), shift (false)
    {
        strcpy (ofirst, f);
        strcpy (osecond, s);
        strcpy (omid, m);
    }

    bool concat (const string &name) const
    {
        return name == first || name == second;
    }

    void swap (const vector<pupil> &people)
    {
        bool flag = false;

        for (unsigned int i = 0; i < people.size (); i++)
            if (people[i].concat (first))
            {
                if (flag)
                {
                    shift = true;

                    return;
                }
                else
                    flag = true;
            }
    }

    void output (FILE *fout)
    {
        if (shift)
            fprintf (fout, "%s %s %s\n", omid, ofirst, osecond);
        else
            fprintf (fout, "%s %s %s\n", ofirst, osecond, omid);
    }

    const string &get_first () const
    {
        return shift ? mid : first;
    }

    bool operator< (const pupil &p) const
    {
        return get_first () < p.get_first ();
    }
};

int main ()
{
    FILE *fin, *fout;

    fin = fopen ("names.in", "rt");
    fout = fopen ("names.out", "wt");

    int n;
    vector<pupil> people;

    fscanf (fin, "%d", &n);

    for (int i = 0; i < n; i++)
    {
        char f[30], s[30], m[30];

        fscanf (fin, "%s %s %s", &f, &s, &m);

        people.push_back (pupil (f, s, m));
    }

    for (int i = 0; i < n; i++)
        people[i].swap (people);

    sort (people.begin (), people.end ());

    for (int i = 0; i < n; i++)
        people[i].output (fout);

    return 0;
}
