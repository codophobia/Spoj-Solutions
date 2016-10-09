#include <stdio.h>
#include <iostream>
#include <bitset>
using namespace std;
int prime(int n)
{
    int i;

    if(n == 2) {
        return 1;
    }
    else if(n % 2 == 0 || n == 1 ) {
        return 0;
    }
    else {
        for(i = 3; i * i <= n; i = i + 2) {
            if(n % i == 0) {
                return 0;
                break;
            }
        }
        return 1;
    }
}
int main()
{
    int t;
    long long int a,b;
    long long int i;
    long long int count;
    long long int n;
    scanf("%d",&t);

    while(t--) {
        scanf("%lld%lld",&a,&b);
        count = 0;
        for(i = a; i <= b; i++) {
            n = __builtin_popcountll(i);
            if(prime(n)) {
                count++;
            }
        }
        printf("%lld\n",count);
    }
    
    return 0;
}
