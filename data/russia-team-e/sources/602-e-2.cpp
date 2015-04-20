#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>

#include <algorithm>
#include <vector>

using namespace std;

#define PROBLEMNAME "numbers"

#ifdef LOCAL
# define DBG(fmt, ...) fprintf (stderr, "DBG: " fmt "\n", ## __VA_ARGS__)
#else
# define DBG(...)
#endif // LOCAL

static const unsigned NUMBER_LENGTH = 11,
                      BUFFER_SIZE = 12,
                      PREFIX_PRETTY_SIZE = 12, // +999(99999)
                      NUMBER_PRETTY_SIZE = 12 + 9; // +999(99999)999-99-99

struct Prefix
{
    char data[BUFFER_SIZE];
    char pretty[PREFIX_PRETTY_SIZE]; // +999(99999)
    unsigned country_length, area_length;
    
    void generate_output()
    {
        snprintf (pretty, PREFIX_PRETTY_SIZE, "+%.*s(%.*s)", country_length, data, area_length, data + country_length);
        DBG ("prefix '%s', pretty '%s'", data, pretty);
    }
    
    unsigned size() const
    {
        return country_length + area_length;
    }
    
    bool compare (const char* number) const
    {
        return !strncmp (number, data, size());
    }
};

#define verify(x) assert(x)

void read_prefixes (vector<Prefix>& prefixes)
{
    unsigned country_nr;
    scanf ("%u", &country_nr);
    
    for (unsigned i = 0; i < country_nr; ++i)
    {
        Prefix country;
        unsigned area_nr;

        scanf ("%s%n %u", country.data, &country.country_length, &area_nr);
        --country.country_length;
        
        for (unsigned j = 0; j < area_nr; ++j)
        {
            prefixes.push_back (country);
            Prefix& area = prefixes.back();

            scanf ("%s%n", area.data + area.country_length, &area.area_length);
            --area.area_length;
            
            area.generate_output();
        }
    }
}

const Prefix* find_prefix (const vector<Prefix>& prefixes, const char* number)
{
    for (vector<Prefix>::const_iterator it = prefixes.begin(); it != prefixes.end(); ++it)
        if (it->compare (number))
            return &*it;
    
    return 0;
}

int main()
{
    assert (freopen (PROBLEMNAME ".in", "r", stdin));
#ifndef LOCAL
    assert (freopen (PROBLEMNAME ".out", "w", stdout));
#endif // LOCAL

    vector<Prefix> prefixes;
    read_prefixes (prefixes);
    
    unsigned number_nr;
    scanf ("%u", &number_nr);
    
    for (unsigned i = 0; i < number_nr; ++i)
    {
        char input[BUFFER_SIZE];
        scanf ("%s", input);
        
        if (const Prefix* prefix = find_prefix (prefixes, input))
        {
            DBG ("input '%s' has prefix '%s'", input, prefix->data);
            
            const char* number = input + prefix->size();
            
            if (number[0] == '0')
            {
                printf ("Incorrect\n");
                continue;
            }
            
            printf ("%s", prefix->pretty);
            
            switch (NUMBER_LENGTH - prefix->size())
            {
            case 3: printf ("%s\n", number);                                     break;
            case 4: printf ("%.2s-%.2s\n", number, number + 2);                  break;
            case 5: printf ("%.3s-%.2s\n", number, number + 3);                  break;
            case 6: printf ("%.2s-%.2s-%.2s\n", number, number + 2, number + 4); break;
            case 7: printf ("%.3s-%.2s-%.2s\n", number, number + 3, number + 5); break;
            default: abort();
            }
        } else
        {
            printf ("Incorrect\n");
        }
    }

    return 0;
}
