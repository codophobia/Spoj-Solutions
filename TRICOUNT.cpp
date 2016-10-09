#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;

    long long int res,n;
    

    scanf("%d",&t);

    while(t--) {
        scanf("%lld",&n);

        res = (n * (n + 2) * ( (2 * n) + 1)) / 8;

        printf("%lld\n",res);
    }

    return 0;
}
