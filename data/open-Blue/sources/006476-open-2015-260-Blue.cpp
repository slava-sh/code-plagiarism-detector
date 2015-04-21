#include <stdio.h>
#include <string.h>

int main() {
    char s[50000];
    int l, len;
    scanf("%d%s",&l, s);
    len = strlen(s);
    if(l >= len) {
        printf("1\n%s", s);
    }
    for(int i = 1; i<=len && i<=l; i++)
    {
        if(len%i == 0) {
            bool fl = true;
            for(int j = 0; j < len; j++) {
                if(s[j] != s[j%i]) {
                    fl = false;
                    break;
                }
            }
            if(fl) {
                printf("1\n");
                for(int j = 0; j < i; j++)
                    printf("%c", s[j]);
                return 0;
            }
        }
    }
    printf("2\na\nb");
}
