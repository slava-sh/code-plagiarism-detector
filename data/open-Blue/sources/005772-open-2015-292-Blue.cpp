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

inline string fit_with_one_word(string s)
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


inline pair<bool, pair<string, string>> fit_with_two_words(string s, uint32_t l)
{
	const uint64_t mod = 1000 * 1000 * 1000 + 33;
	vector<uint64_t> hashes(s.size() + 1);
	vector<uint64_t>   pows(s.size() + 1);
	pows  [0] = 1;
	hashes[0] = 0;
	for (uint32_t i = 0; i < s.size(); i++)
	{
		hashes[i + 1] = (5 * hashes[i] + s[i] - 'a' + 1) % mod;
		pows[i + 1] = (5 * pows[i]) % mod;
	}
	auto get_hash = [hashes, pows](uint32_t l, uint32_t r)
	{
		return (hashes[r + 1] + mod - (hashes[l] * pows[r - l + 1]) % mod) % mod;
	};
	
	
	for (uint32_t i = 0; i < l and i + 1 <= s.size(); i++)
	{
		// [0, i] word.
		
		uint64_t word1_hash = get_hash(0, i);
		uint32_t word1_len = i + 1;
		
		for (uint32_t cur_pos_ = i + 1; cur_pos_ < s.size();)
		{
			if (cur_pos_ + word1_len <= s.size())
				if (word1_hash == get_hash(cur_pos_, cur_pos_ + word1_len - 1))
				{
					cur_pos_ += word1_len;
					continue;
				}
			
			for (uint32_t j = 0; j < l and (cur_pos_ + j + 1 <= s.size()); j++)
			{
				uint64_t word2_hash = get_hash(cur_pos_, cur_pos_ + j);
				uint32_t word2_len = j + 1;
				
				for (uint32_t cur_pos = cur_pos_ + j + 1; cur_pos < s.size();)
				{
					if (cur_pos + word1_len <= s.size())
						if (word1_hash == get_hash(cur_pos, cur_pos + word1_len - 1))
						{
							cur_pos += word1_len;
							continue;
						}
					if (cur_pos + word2_len <= s.size())
						if (word2_hash == get_hash(cur_pos, cur_pos + word2_len - 1))
						{
							cur_pos += word2_len;
							continue;
						}
					
					goto insuccess;
				}
				
				return make_pair(true, make_pair(s.substr(0, i + 1), s.substr(cur_pos_, j + 1)));
				insuccess:;
			}
			goto insuccess_2;
		}
		insuccess_2:;
	}
	
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
				cout << nans.second.first << endl << nans.second.second << endl;
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
