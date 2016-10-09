#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int t;
    int a[500];
    int n;
    int i;
    int temp;
    int x;
    int m;
    int j;

    scanf("%d",&t);

    while(t--) {
        scanf("%d",&n);
        int p = n;
        m = 0;
        while(p > 0) {
            a[m] = p % 10;
            p = p / 10;
            m++;
        }


        for(j = n - 1; j > 0; j--) {
                temp = 0;
            for(i = 0; i < m; i++) {
                x = (a[i] * j) + temp;
                a[i] = x % 10;
                temp = x / 10;
            }
            while(temp > 0) {
                a[m] = temp % 10;
                temp = temp / 10;
                m++;
            }
        }

        for(i = m - 1; i >= 0; i--) {
            printf("%d",a[i]);
        }

        printf("\n");


        }
    }
