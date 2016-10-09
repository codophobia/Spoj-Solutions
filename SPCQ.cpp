#include <bits/stdc++.h>
using namespace std;
int sum(long long int n)
{
    int sum;
    int r;
    sum = 0;

    while(n > 0) {
        r = n % 10;
        sum = sum + r;
        n = n / 10;
    }

    return sum;
}
int main()
{
    long long int n;

    int r;
    int t;

    scanf("%d",&t);

    while(t--) {
        scanf("%lld",&n);

        while(1) {
            if(n % sum(n) == 0) {
                printf("%lld\n",n);
                break;
            }
            else {
                n = n + 1;
            }
        }

    }
}
