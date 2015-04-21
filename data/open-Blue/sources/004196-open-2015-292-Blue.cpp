// This program is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License fqor more details.
//
// You should have received a copy of the GNU General Public License and
// along with this program If not, see http://www.gnu.org/licenses/>.

#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <stdint.h>
#include <map>
#include <set>
#include <stack>
#include <utility>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using std::vector;
using std::string;
using std::map;
using std::set;
using std::stack;

using std::min;
using std::max;

using std::pair;
using std::make_pair;

template <typename T>
T input()
{
	T ans;
	cin >> ans;
	return ans;
}

/*
 * 
*/

string fit_with_one_word(string s)
{
	vector<uint32_t> Z(s.size(), 0);
	
	uint32_t L = 0;
	uint32_t R = 0;
	for (uint32_t i = 1; i < s.size(); i++)
	{
		if (i <= R)
			Z[i] = min(R - i + 1, Z[i - L]);
		while (i + Z[i] < s.size() and s[i + Z[i]] == s[Z[i]])
			Z[i]++;
		if (i + Z[i] - 1 > R)
			L = i, R = i + Z[i] - 1;
	}
	
	for (uint32_t i = 1; i < s.size(); i++)
		if (s.size() % i == 0 and Z[i] + i == s.size())
			return s.substr(0, i);
	return s;
}

pair<bool, pair<string, string>> fit_with_two_words(string s, uint32_t l)
{
	
	
	return make_pair(false, make_pair(string(""), string("")));
}

int main()
{
	uint32_t l = input<uint32_t>();
	string s = input<string>();
	bool has_a = false;
	bool has_b = false;
	bool has_c = false;
	
	for (char c: s)
		if (c == 'a')
			has_a = true;
		else if (c == 'b')
			has_b = true;
		else
			has_c = true;
	
	auto print_all = [has_a, has_b, has_c]()
	{
		if (has_a)
			cout << "a\n";
		if (has_b)
			cout << "b\n";
		if (has_c)
			cout << "c\n";
	};
	if (uint32_t(has_a) + uint32_t(has_b) + uint32_t(has_c) <= 2u)
	{
		auto ans = fit_with_one_word(s);
		if (ans.size() <= l)
		{
			cout << 1 << endl;
			cout << ans << endl;
		}
		else
		{
			cout << uint32_t(has_a) + uint32_t(has_b) + uint32_t(has_c) << endl;
			print_all();
		}
	}
	if (uint32_t(has_a) + uint32_t(has_b) + uint32_t(has_c) == 3u)
	{
		auto ans = fit_with_one_word(s);
		if (ans.size() <= l)
		{
			cout << 1 << endl;
			cout << ans << endl;
		}
		else
		{
			pair<bool, pair<string, string>> nans = fit_with_two_words(s, l);
			if (nans.first) // success.
			{
				cout << 2 << endl;
				cout << nans.second.first << " " << nans.second.second << endl;
			}
			else
			{
				cout << 3 << endl;
				print_all();
			}
		}
	}

	return 0;
}
