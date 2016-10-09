#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main()
{
    char a[202];
    char b[100][100];
    int c;
    int r;
    int i;
    int j;
    int k;

    while(1) {
        scanf("%d",&c);
        if(c == 0) {
            break;
        }
        scanf("%s",a);

        r = strlen(a) / c;
        k = 0;

        for(i = 0; i < r; i++) {
            if(i % 2 == 0) {
                for(j = 0; j < c; j++) {
                    b[i][j] = a[k++];
                }
            }
            else {
                for(j = c - 1; j >= 0; j--) {
                    b[i][j] = a[k++];
                }
            }
        }



        for(i = 0; i < c; i++) {
            for(j = 0; j < r; j++) {
                printf("%c",b[j][i]);
            }
        }

        printf("\n");



    }
}
