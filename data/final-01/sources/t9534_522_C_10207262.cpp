#define _CRT_SECURE_NO_WARNINGS

#include <time.h>

#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <set>
#include <fstream>
#include <unordered_map>

using namespace std;

class DimaSolver
{
public:
    string solve(vector<int> a, const vector<pair<int, bool> > &log)
    {
        bool everybody_happy = true;
        int anydish = 0;       
        vector<bool> couldBeOver(a.size(), false);

        unordered_map<int, int> future;
        for (const pair<int, bool> &l : log)
        {
            if (l.first > 0)
            {
                ++future[l.first - 1];
            }
        }

        for (int place = 0; place < log.size(); ++place)
        {
            if (everybody_happy && !log[place].second)
            {
                // first unsatisfied

                everybody_happy = false;
                int old_anydish = anydish;
                anydish = 0;
                for (int dish_index = 0; dish_index < a.size(); ++dish_index)
                {
                    if (
                        a[dish_index] - old_anydish <= 0 
                        &&
                        (future.find(dish_index) == future.end() || future[dish_index] == 0)
                       )
                    {
                        couldBeOver[dish_index] = true;
                        anydish = max(anydish, old_anydish - a[dish_index]);
                    }
                }
            }

            if (log[place].first > 0)
            {
                // known dish

                int dish = log[place].first - 1;
                --a[dish];
                --future[dish];
            }
            else
            {
                // unknown dish
                
                ++anydish;                
            }
        }

        string ans(a.size(), 'N');
        for (int dish = 0; dish < a.size(); ++dish)
        {
            if (couldBeOver[dish] || a[dish] - anydish <= 0)
            {
                ans[dish] = 'Y';
            }
        }

        return ans;
    }
};

class DummySolver
{
    typedef vector<int> Distribution;
public:
    string solve(vector<int> a, const vector<pair<int, bool> > &log)
    {
        set<Distribution> possible;
        possible.insert(a);

        for (int place = 0; place < log.size(); ++place)
        {
            set<Distribution> new_possible;

            if (!log[place].second)
            {
                // unsatisfied

                for (const Distribution &distr : possible)
                {
                    bool good = false;
                    for (int dish = 0; dish < a.size() && !good; ++dish)
                    {
                        if (dish + 1 == log[place].first)
                        {
                            continue;
                        }

                        if (distr[dish] == 0)
                        {
                            good = true;
                        }
                    }
                    if (good)
                    {
                        new_possible.insert(distr);
                    }
                }
                possible.swap(new_possible);
                new_possible.clear();
            }

            if (log[place].first > 0)
            {
                // known dish

                int dish = log[place].first - 1;
                for (const Distribution &d : possible)
                {
                    if (d[dish] > 0)
                    {
                        Distribution new_d = d;
                        --new_d[dish];
                        new_possible.insert(new_d);
                    }
                }
            }
            else
            {
                // unknown dish

                for (int dish = 0; dish < a.size(); ++dish)
                {
                    for (const Distribution &d : possible)
                    {
                        if (d[dish] > 0)
                        {
                            Distribution new_d = d;
                            --new_d[dish];
                            new_possible.insert(new_d);
                        }
                    }
                }
            }
            possible.swap(new_possible);
        }

        string ans(a.size(), 'N');
        for (int dish = 0; dish < a.size(); ++dish)
        {
            for (const Distribution d : possible)
            {
                if (d[dish] == 0)
                {
                    ans[dish] = 'Y';
                    break;
                }
            }
        }
        return ans;
    }
};

void readInput(vector<vector<int> > &as, vector<vector<pair<int, bool> > > &logs)
{
    int t;
    cin >> t;
    as.resize(t);
    logs.resize(t);
    for (int test = 0; test < t; ++test)
    {
        int m, k;
        cin >> m >> k;
        as[test].resize(k);
        logs[test].resize(m - 1);
        for (int i = 0; i < k; ++i)
            cin >> as[test][i];
        for (int i = 0; i < m - 1; ++i)
        {
            int r;
            cin >> logs[test][i].first >> r;
            logs[test][i].second = r < 1;
        }
    }
}

void writeAnswer(const vector<string> &ans)
{
    for (const string & a : ans)
        cout << a << "\n";
}

void run_tests();
const double TL = 0.9;

int main(int argc, char* argv[])
{    
    // run_tests();
    // return 0;

    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);

    vector<vector<int> > as;
    vector<vector<pair<int, bool> > > logs;

    readInput(as, logs);
    vector<string> ans;

    for (int test = 0; test < as.size(); ++test)
    {
        DimaSolver sol1;
        ans.emplace_back(sol1.solve(as[test], logs[test]));

        //DummySolver sol2;
        //cout << sol1.solve(as[test], logs[test]) << endl;
        //cout << sol2.solve(as[test], logs[test]) << endl;
        //ans.emplace_back(sol2.solve(as[test], logs[test]));
    }

    writeAnswer(ans);

	return 0;
}

void generate_random_test(int k, int m, int maxA, vector<int> &a, vector<pair<int, bool> > &log)
{
    if (k == 2 && m == 3 && maxA == 4)
    {
        // cerr << "This" << endl;
    }

    if (k * maxA < m)
    {
        maxA = m / k + 1;
    }

    a.resize(k, 1);
    long long sum;
    do
    {
        sum = 0;
        for (int dish = 0; dish < a.size(); ++dish)
        {
            a[dish] = 1 + rand() % maxA;
            sum += a[dish];
        }
    } while (sum < m);

    log.resize(m - 1);
    vector<int> a_copy = a;
    vector<int> present;
    for (int dish = 0; dish < a.size(); ++dish)
    {
        if (a[dish] > 0)
        {
            present.push_back(dish);
        }
    }
    for (int place = 0; place < log.size(); ++place)
    {
        int dish = rand() % a.size();
        if (a_copy[dish] > 0)
        {
            log[place].second = true;
        }
        else
        {
            log[place].second = false;

            dish = present[rand() % present.size()];
        }

        if (rand() % 2)
        {
            log[place].first = dish + 1;
        }
        else
        {
            log[place].first = 0;
        }

        --a_copy[dish];
        if (a_copy[dish] == 0)
        {
            auto p = find(present.begin(), present.end(), dish);
            if (p == present.end())
            {
                throw logic_error("Can't eat this dish");
            }
            *p = present.back();
            present.pop_back();
        }
    }
}

void save_test(const vector<int>& a, const vector<pair<int, bool> >& log) {
    ofstream out("test.txt");
    out << 1 << endl;
    out << log.size() + 1 << ' ' << a.size() << endl;

    for (int i = 0; i < a.size(); ++i) {
        out << a[i] << " ";
    }
    out << endl;

    for (int i = 0; i < log.size(); ++i) {
        out << log[i].first << " " << (log[i].second ? 0 : 1 ) << endl;
    }
    out.close();
}

double max_vit_time;
double max_dima_time;
void run_test(const vector<int>& a, const vector<pair<int, bool> >& log, bool brute = true) 
{
    string brute_answer, dima_answer;
    int start_time;

    if (brute)
    {
        start_time = clock();
        DummySolver dummySolver;
        cerr << " brute";
        brute_answer = dummySolver.solve(a, log);
        cerr << "\b\b\b\b\b     \b\b\b\b\b\b";
        double vit_time = static_cast<double>(clock() - start_time) / CLOCKS_PER_SEC;

        if (vit_time > max_vit_time) {
            max_vit_time = vit_time;
        }
    }

    start_time = clock();
    DimaSolver dimaSolver;
    dima_answer = dimaSolver.solve(a, log);
    double dima_time = static_cast<double>(clock() - start_time) / CLOCKS_PER_SEC;   
    

    if (dima_time > TL) {
        cout << "TL DimaSolver" << endl;
        cout << dima_time << "sec" << endl;
        save_test(a, log);
        exit(1);
    }

    if (dima_time > max_dima_time) {
        max_dima_time = dima_time;
    }    

    if (brute)
    {
        if (brute_answer != dima_answer) {
            cout << "WA dimaSolver disagrees with bruteforce " << endl;
            save_test(a, log);

            cout << "Dima:\t" << dima_answer << endl;
            cout << "Brute:\t" << brute_answer << endl;

            exit(1);
        }
    }
}

void run_tests() {
    srand(123);
    vector<int> a;
    vector<pair<int, bool> > log;

    cerr << "Huge tests" << endl;
    for (int i = 0; i < 100; ++i) {
        generate_random_test(1e5, 1e5, 1e5, a, log);
        run_test(a, log, false);
        cerr << i << "\r";
    }

    cerr << "Random bruteforce" << endl;
    long long k, m;

    for (int MAX = 1; MAX <= 100000; MAX++)
    {
        cerr << "\r" << MAX;

        for (int k = 1; k <= MAX; ++k)
        {
            for (int m = 2; m <= MAX; ++m)
            {
                for (int maxA = m / k + 1; maxA < 2 * m; ++maxA)
                {
                    generate_random_test(k, m, maxA, a, log);
                    run_test(a, log);                                        
                }
            }
        }
    }    
}
