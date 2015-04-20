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
    
    void set_country (unsigned country_code)
    {
        country_length = snprintf (data, BUFFER_SIZE, "%u", country_code);
    }
    
    void set_area (unsigned area_code)
    {
        area_length = snprintf (data + country_length, BUFFER_SIZE - country_length, "%u", area_code);
    }
    
    void generate_output()
    {
        snprintf (pretty, PREFIX_PRETTY_SIZE, "+%.*s(%.*s)", country_length, data, area_length, data + country_length);
        DBG ("prefix '%s', pretty '%s'", data, pretty);
    }
    
    unsigned size() const
    {
        return country_length + area_length;
    }
    
    bool compare (const char* input) const
    {
        return !strncmp (input, data, size());
    }
};

#define verify(x) assert(x)

void read_prefixes (vector<Prefix>& prefixes)
{
    unsigned n_country;
    scanf ("%u", &n_country);
    
    for (unsigned i = 0; i < n_country; ++i)
    {
        unsigned country_code, n_area;
        scanf ("%u %u", &country_code, &n_area);
        
        Prefix country;
        country.set_country (country_code);
        
        for (unsigned j = 0; j < n_area; ++j)
        {
            unsigned area_code;
            scanf ("%u", &area_code);
            
            prefixes.push_back (country);
            
            Prefix& area = prefixes.back();
            area.set_area (area_code);

            area.generate_output();
        }
    }
}

const Prefix* find_prefix (const vector<Prefix>& prefixes, const char* input)
{
    for (vector<Prefix>::const_iterator it = prefixes.begin(); it != prefixes.end(); ++it)
    {
        const Prefix* prefix = &*it;

        if (prefix->compare (input))
        {
            const char* number = input + prefix->size();
            if (number[0] == '0') continue;
            
            return prefix;
        }
    }
    
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
        assert (strlen (input) == NUMBER_LENGTH);
        
        if (const Prefix* prefix = find_prefix (prefixes, input))
        {
            DBG ("input '%s' has prefix '%s'", input, prefix->data);
            printf ("%s", prefix->pretty);
            
            const char* number = input + prefix->size();
            
            switch (NUMBER_LENGTH - prefix->size())
            {
            case 3: printf ("%.3s\n", number);                                   break;
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
