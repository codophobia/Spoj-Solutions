#include <bits/stdc++.h>
using namespace std;
int a[300000];
int check[300000];
int prime[300009];
void sieve()
{
    int i;
    int j;
    int k;
    k = 1;
    check[1] = 1;

    for(i = 2; i <= (300000); i++) {
        if(check[i] == 0) {
            for(j = i + i; j < 300000; j = j + i) {
                a[j] = a[j] + 1;
                check[j] = 1;
            }
        }
    }

    for(i = 1; i < 300000; i++) {
        if(a[i] >= 3) {
            prime[k++] = i;

        }
    }


}
int main()
{
    sieve();
    int n;
    int t;

    scanf("%d",&t);

    while(t--) {
        scanf("%d",&n);
        printf("%d\n",prime[n]);
    }

    return 0;
}
