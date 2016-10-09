#include <bits/stdc++.h>
using namespace std;


int c[10000007];
void sieve()
{
    int i;
    int j;

    for(i = 2; i < 10000007 ; i++) {
        if(c[i] == 0) {
            for(j = i + i; j < 10000007; j = j + i) {
                if(c[j] == 0) {
                    c[j] = i;
                }
            }
        }
    }
}
int main()
{
    sieve();
    int i;
    int n;

    while(scanf("%d",&n) != EOF) {
        if(n == 1) {
            printf("1\n");
            continue;
        }
        printf("1 ");

        if(c[n] != 0) {
        while(n % c[n] == 0) {
            printf("x %d ",c[n]);
            n = n / c[n];

            if(c[n] == 0) {
                break;
            }
        }
        }

        printf("x %d",n);
        printf("\n");

    }

    return 0;
}
