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


uint64_t ans(uint64_t n, uint32_t k)
{
	if (k == 1)
	{
		//cerr << "n = " << n << " k = " << k << " res: " << n / 2 + n % 2<< endl;
		return n / 2 + n % 2;
	}
	
	uint64_t temp = pow(1.0L * n, 1.0L / k);
	if (n % temp == 0)
	{
		auto res = (temp / 2 + temp % 2) * ans(n / temp, k - 1) ; // perfect forwarding.
		//cerr << "n = " << n << " k = " << k << " res: " << res << endl;
		return res;
	}
	
	for (uint64_t v = temp; true; v--)
		if (n % v == 0)
		{
			auto res = min( (v / 2 + v % 2) * ans(n / v, k - 1), ans(v, k - 1) * ((n / v) / 2 + (n / v) % 2) );
			//cerr << "n = " << n << " k = " << k << " res: " << n << endl;
			return res;
		}
	assert(false);
}

int main()
{
	uint64_t n = input<uint32_t>();
	uint32_t k = input<uint32_t>();
	
	cout << ans(n, k) << endl;
	
	return 0;
}
