#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
long long int minv(long long int a,long long int n,long long int p)
{

    long long int b[100];
    long long int i;
    long long int s,t;
    t = 1;
    s = 0;




    b[0] = a % p;

    for(i = 1; i < 100; i++) {
        b[i] = (b[i - 1] * b[i - 1]) % p;
    }

    for(i = 0; ; i++) {
        if(n & 1 << i){
            t = t * b[i];
            s = s + pow(2,i);
            if(s == n) {
                break;
            }
        }

    }

        return t % p;
}
int main()
{

    int t;
    long long int p;
    long long int n;
    long long int m;
    long long int i;
    long long int temp;


    scanf("%d",&t);

    while(t--) {
            m = -1;
        scanf("%lld%lld",&n,&p);

        if(n >= p) {
            printf("0\n");
            continue;
        }

        for(i = n + 1; i < p; i++) {
                temp = minv(i,p-2,p);
                m = (m * temp) % p;
        }

        printf("%lld\n",p + m);
    }

    return 0;
}
