#include <stdio.h>

int main()
{
    int need = 1;
    int cur = 1;

    while (true) {
        if (need) {
            printf("U\n");
            need--;
        }
        else{
            printf("R\n");
            cur++;
            need = cur;
        }
        fflush(stdout);

        char c; scanf("%c", &c);
        if (c == 'Y') return 0;
    }

    /*
    int d = 3;
    int need = 1;
    int visited = 1;

    int x = 0, y = 0;

    while (true) {
        if (need == visited) {

            if (visited%2==0) {
                printf("R\n");
                x++;
            }
            else {
                printf("U\n");
                y++;
            }

            visited++;
            need += d;
            d += 2;

        }
        else {
            if (need%2==0) {
                if (x < y) {
                    printf("R\n");
                    x++;
                }
                else {
                    printf("D\n");
                    y--;
                }

                visited++;
            }
            else {
                if (x > y) {
                    printf("U\n");
                    y++;
                }
                else {
                    printf("L\n");
                    x--;
                }

                visited++;
            }
        }

        fflush(stdout);

        char c; scanf("%c", &c);

        if (c == 'Y') return 0;
    }
    */
}
