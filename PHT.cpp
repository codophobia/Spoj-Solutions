#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    int t;
    int i;
    long long int ans;

    scanf("%d",&t);

    for(i = 1; i <= t; i++) {
        scanf("%lld",&n);
        n = n + 1;
        ans = sqrt(n) - 1;
        printf("Case %d: %lld\n",i,ans);

        }
        return 0;
    }
