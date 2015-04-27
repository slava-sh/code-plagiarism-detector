#include <stdio.h>
#include <list>
#include <limits.h>
using namespace std;
    const int Q_ARRAY_LENGTH = 13;
    int queue[13][400000];
	int qstart[13];
	int qend [13];
list <pair<int,int> > dest[500004];
int rasst[500004];
int main (){
	int start = 0;
	int fin = 0;
	int we = 0;	
	freopen ("graph.in","r",stdin);
	freopen ("graph.out","w",stdout);
	int cur_queue = 0;
    queue[cur_queue][qend[cur_queue]] = 1;
	qend[cur_queue]++;
	int vershs = 0;
	scanf("%d ",&vershs);
	int reb = 0;
	scanf("%d ",&reb);
	for (int i = 2; i <= vershs;i++)
		rasst[i] = INT_MAX/3;
	for (int i = 0; i < reb;i++){		
		scanf("%d %d %d",&start,&fin,&we);
        we = 12/we;
		dest[start].push_back(pair<int,int>(fin,we));
		dest[fin].push_back(pair<int,int>(start,we));
	}
	rasst[1] = 0;
	int num = 1;
	int obr = 0;
	while (num){
		while (qend[cur_queue] != qstart[cur_queue]){
			obr = queue[cur_queue][qstart[cur_queue]];
			qstart[cur_queue]++;
			num--;

			for (list<pair<int,int> >::iterator it = dest[obr].begin(); it != dest[obr].end();it++){
				if (rasst[it->first] > rasst[obr] + it->second){
					rasst[it->first] = rasst[obr] + it->second;
					queue[(cur_queue + it->second) % Q_ARRAY_LENGTH][qend[(cur_queue + it->second) % Q_ARRAY_LENGTH]]=it->first;
					qend[(cur_queue + it->second) % Q_ARRAY_LENGTH]++;
					num++;
				}

			}

		}
		cur_queue=(cur_queue+1)%Q_ARRAY_LENGTH;
	}

	for (int i = 2; i <= vershs;i++){
		printf("%.10lf\n",(double)rasst[i]/12.0);
	}
	return 0;
}   