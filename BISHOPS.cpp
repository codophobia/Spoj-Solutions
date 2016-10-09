#include <bits/stdc++.h>
using namespace std;
int main()
{
    char a[110];
    int c[110];
    int i;
    int x;
    int temp;
    int b;
    int j;
    int k;

    while(scanf("%s",a) != EOF) {


        if(strlen(a) == 1 && (a[0]-'0') == 1) {
            printf("1\n");
            continue;
        }
        j = 0;

        for(i = strlen(a) - 1; i >= 0; i--) {
            c[j] = a[i] - '0';
            j++;
        }



        temp = 0;

        for(i = 0; i < j; i++) {
            x = c[i] * 2 + temp;
            c[i] = x % 10;
            temp = x / 10;
        }


        if(temp > 0) {
            c[i] = temp;
            k = i;
        }
        else {
            k = i - 1;
        }

        b = 2;

        for(i = 0; i <= k; i++) {
            if(c[i] >= b) {
                c[i] = c[i] - b;
                break;
            }
            else {
                c[i] = 10 + c[i] - b;
                b = 1;


            }
        }

        if(c[k] > 0) {
            printf("%d",c[k]);
        }

            for(i = k - 1; i >= 0; i--) {
                printf("%d",c[i]);
            }




    printf("\n");




    }
    return 0;
}

