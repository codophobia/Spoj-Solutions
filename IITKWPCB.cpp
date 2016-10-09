#include <bits/stdc++.h>
using namespace std;
int gcd(long long int a,long long int b)
{
    if(b == 0) {
        return a;
    }
    else {
        return gcd(b,a % b);
    }
}
int main()
{
    int t;
    long long int n;
    long long int f;
    long long int i;

    scanf("%d",&t);

    while(t--) {
        scanf("%lld",&n);
        f = n / 2;

        if(f == 0) {
            printf("0\n");
            continue;
        }

        for(i = f; i > 0; i--) {
            if(gcd(n,i) == 1) {
                printf("%lld\n",i);
                break;
            }
        }
    }

    return 0;


}
