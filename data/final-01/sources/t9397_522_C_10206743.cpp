//
//  main.cpp
//  C
//
//  Created by Ilya Lukyanov on 08/03/15.
//  Copyright (c) 2015 Ilya Lukyanov & Alexander Zimin. All rights reserved.
//

#include <stdio.h>

int main() {
    int t, meals[100010], b[100010];
    bool c[100010];
    for (scanf("%d", &t); t > 0; t--) {
        int m, k;
        scanf("%d %d", &m, &k);
        m--;
        for (int i = 0; i < k; i++)
            scanf("%d", &meals[i]);
        
        int minBad = -1;
        for (int i = 0; i < m; i++) {
            int tmp;
            scanf("%d %d", &b[i], &tmp);
            b[i]--;
            if (tmp == 1 and minBad == -1)
                minBad = i;
        }
        
        if (minBad == -1) {
            int unknown = m;
            for (int i = 0; i < m; i++)
                if (b[i] >= 0) {
                    meals[b[i]]--;
                    unknown--;
                }

            for (int i = 0; i < k; i++) {
                if (meals[i] <= unknown)
                    printf("Y");
                else
                    printf("N");
            }
        } else {
            for (int i = 0; i < k; i++)
                c[i] = true;
            
            for (int i = minBad; i < m; i++)
                if (b[i] >= 0)
                    c[b[i]] = false;

            int unknown = minBad;
            for (int i = 0; i < minBad; i++)
                if (b[i] >= 0) {
                    meals[b[i]]--;
                    unknown--;
                }
            
            for (int i = 0; i < k; i++)
                if (unknown < meals[i])
                    c[i] = false;
            
            unknown += m - minBad;
            for (int i = minBad; i < m; i++)
                if (b[i] >= 0) {
                    meals[b[i]]--;
                    unknown--;
                }
            
            int res = -1, max = 1e9;
            for (int i = 0; i < k; i++)
                if (c[i] and meals[i] < max) {
                    res = i;
                    max = meals[i];
                }
            unknown -= meals[res];
            meals[res] = 0;
            
            for (int i = 0; i < k; i++) {
                if (meals[i] <= unknown or c[i])
                    printf("Y");
                else
                    printf("N");
            }
        }
        
        printf("\n");
    }
    return 0;
}
