#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
using namespace std;
#define size 1005
int check[size];
int prime[100000];
void sieve()
{
    int i;
    int j;
    int k;
    memset(check,0,sizeof(check));

    for(i = 2; i < sqrt(size);i++) {
            if(check[i] == 0) {
        for(j = i + i; j < size; j = j + i) {
            check[j] = 1;
        }
            }
    }

    prime[0] = 2;
    k = 1;

    for(i = 3; i < size; i = i + 2) {
        if(check[i] == 0) {
            prime[k] = i;
            k++;
        }
    }



}
int main()
{
    sieve();
    int t;
    int n;
    int total;
    int i;
    int k;
    int m;

    scanf("%d",&t);

    while(t--) {
        scanf("%d",&n);
        k = 0;

        total = n;
        for(i = prime[k]; i * i  <= n ; i = prime[++k]) {

            if(n % i == 0) {
                total =  ((total - (total/ (float)i)));
                while(n % i == 0) {
                n = n / i;
                }

            }


        }
        if(n > 1) {
            total = (total -(total / n));
        }

        printf("%d\n", total);

    }
    return 0;

}

