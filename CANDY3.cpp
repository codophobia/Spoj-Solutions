#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    long long int t;
    long long int n,a;
    long long int sum;

    long long int i;

    scanf("%lld",&t);

    while(t--) {
        printf("\n");
        scanf("%lld",&n);
        sum = 0;

        for(i = 0; i < n; i++) {
            scanf("%lld",&a);
            sum = (sum + a) % n;
        }

        sum = sum % n;

        if(sum == 0) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }

    return 0;

}
