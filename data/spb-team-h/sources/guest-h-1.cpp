#include <fstream>
#include <vector>
#include <string>
#include <tuple>
#include <set>
#include <algorithm>

int main()
{
	std::ifstream ifs("names.in");
	std::ofstream ofs("names.out");

	int n;
	ifs >> n;
	
	std::vector<std::tuple<std::string, std::string, std::string>> database(n);
	std::set<std::string> trash;
	for (int i = 0; i < n; ++i)
	{
		std::string f, s, t;
		ifs >> f >> s >> t;
		trash.insert(f);
		trash.insert(s);
		trash.insert(t);
		database[i] = std::make_tuple(f, s, t);
	}

	for (auto& x : database)
	{
		std::string f, s, t;
		std::tie(f, s, t) = x;
		if (trash.count(f) == 1) continue;
		x = std::make_tuple(t, f, s);
	}

	std::sort(database.begin(), database.end());
	for (auto & x : database)
	{
		std::string f, s, t;
		std::tie(f, s, t) = x;
		ofs << f << s << t << '\n';
	}
}