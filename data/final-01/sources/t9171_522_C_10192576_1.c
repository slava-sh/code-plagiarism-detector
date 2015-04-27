#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NNN 100005
#define ooo 1000000000

int main () {
	int tests, test_index;
	scanf("%d",&tests);
	static int data[NNN];
    static char baka[NNN];
	static int strss[NNN];
    static int Val_u[NNN];
    static int dar[NNN];
	static char answer[NNN];

	for (test_index = 0; test_index < tests; test_index++)
	{
		int M, N;scanf("%d %d",&M,&N);M--;
		memset(answer, 'N', sizeof(answer));
		answer[N] = 0;int i;
		for (i = 0; i < N; i++)
        {
            scanf("%d",&(data[i]));
        }
		for (i = 0; i < M; i++)
        {
            scanf("%d %d",&(dar[i]),&(strss[i]));
        }
		int Q = 0;
		while (
            (Q < M) && (strss[Q] == 0)
        )
        Q++;
		int taken = 0; int fr;
		if (Q < M)
		{
			memset(Val_u,0,sizeof(Val_u)); fr = 0;
			for (i = 0; i < Q; i++)
			{
				if (dar[i])
                    Val_u[dar[i]-1]++;
				else
                    fr++;
			}
			memset(baka,1,sizeof(baka));
			for (i = Q; i < M; i++)
			{
				if (dar[i])
                    baka[dar[i]-1] = 0;
			}
			taken = ooo;
			for (i = 0; i < N; i++)
			{if (baka[i]) {
					int temp = data[i] - Val_u[i]; if (temp <= fr)
					{
						answer[i] = 'Y'; if (temp < taken)
                        taken = temp;
					}
				}
			}
		}
		fr = 0; 		memset(Val_u,0,sizeof(Val_u)); 		for (i = 0; i < M; i++)
		{
			if (dar[i]) Val_u[dar[i]-1]++;			else fr++;
		}
		fr -= taken;	for (i = 0; i < N; i++)
		{
			if (answer[i] == 'N')			{
				int temp = data[i]
                    -
                Val_u[i];
				if (temp <= fr)
                {
                    answer[i] = 'Y';
                }
			}
		}
		printf(
            "%s\n",
            answer
            );
	}
	return 0;	
}
