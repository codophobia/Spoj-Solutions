#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    long long int r;
    int i;

    scanf("%d",&t);
    for(i = 1; i <= t; i++) {
        scanf("%lld",&r);

        double ans;
        ans = (double)(4 * r * r) + 0.25;

        printf("Case %d: %.2lf\n",i,ans);


    }

    return 0;
}

