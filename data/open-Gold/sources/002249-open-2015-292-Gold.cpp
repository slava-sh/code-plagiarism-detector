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

int main()
{
	uint32_t N = input<uint32_t>();
	uint32_t K = input<uint32_t>();
	uint32_t C = input<uint32_t>();
	uint32_t D = input<uint32_t>();
	
	//dp[i][k_left] - the minimum amount of money we have to pay after i'th visit, and k_left will be left after this turn.
	// i parametre is redundant.
	vector<uint32_t> dp(K + 1, UINT32_MAX);
	dp[K] = 0; 
	
	uint32_t prev_b;
	
	for (uint32_t x = 1; x <= N; x++)
	{
		uint32_t a = input<uint32_t>();
		uint32_t b = input<uint32_t>();
		
		vector<uint32_t> new_dp(K + 1);
		
		for (uint32_t i = 0; i <= K; i++)
		{
			new_dp[i] = (i != K) ? (dp[i + 1]) : (UINT32_MAX);
			if (i == K - 1)
				new_dp[i] = min(new_dp[i], dp[0] == UINT32_MAX ? UINT32_MAX : (dp[0] + C));
			if (x != 1)
				new_dp[i] = min(new_dp[i], dp[i] == UINT32_MAX ? UINT32_MAX : (dp[i] + D * (a - prev_b)));
			if (new_dp[i] != UINT32_MAX)
				new_dp[i] += D * (b - a);
		}
		prev_b = b;
		dp = std::move(new_dp);
	}
	
	cout << *std::min_element(dp.begin(), dp.end()) << endl;
	
	return 0;
}
