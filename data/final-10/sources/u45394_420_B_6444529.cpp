#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int log_op[111111];
int log_man[111111];

int init_state[111111]; // 0 unk 1 in 2 out
bool meet[111111];

bool bye[111111];

int main(void)
{
	int n = 0;
	int m = 0;
	scanf("%d %d",&n,&m);
	for(int i = 0;i < m;i++)
	{
		char op[16] = {0};
		int man = 0;
		scanf("%s %d",op,&man);
		log_op[i] = op[0];
		log_man[i] = man;

		if(!meet[man])
		{
			if(log_op[i] == '+') init_state[man] = 2;
			else init_state[man] = 1;
			meet[man] = true;
		}
	}

	set<int> here;
	set<int> notty;
	set<int> banned;
	for(int i = 1;i <= n;i++)
	{
		if(init_state[i] == 1) here.insert(i);
		else if(init_state[i] == 2) notty.insert(i);
	}
	if(here.size() != 0)
	{
		for(auto x: notty)
		{
			banned.insert(x);
		}
		notty.clear();
	}
	int max_online = here.size();
	for(int i = 0;i < m;i++)
	{
		if(log_op[i] == '+')
		{
			if(!here.size() && i && log_op[i-1] == '-' && log_man[i-1] == log_man[i])
			{
				here.insert(log_man[i]);
				notty.erase(log_man[i]);
				continue;
			}
			if(here.size() || max_online) banned.insert(log_man[i]);
			if(notty.size())
			{
				for(auto& x: notty) if(x != log_man[i]) banned.insert(x);
				notty.clear();
			}
			here.insert(log_man[i]);
			max_online = max<int>(max_online, here.size());
		}
		else if(log_op[i] == '-')
		{
			here.erase(log_man[i]);
			if(here.size()) banned.insert(log_man[i]);
			else if(!banned.count(log_man[i]))
			{
				notty.insert(log_man[i]);
			}
		}
	}
	vector<int> candidate;
	for(int i = 1;i <= n;i++) if(!banned.count(i)) candidate.push_back(i);
	printf("%d\n",candidate.size());
	for(auto& x: candidate) printf("%d ",x);
	puts("");
	while(getchar() != EOF);
	return 0;
}
