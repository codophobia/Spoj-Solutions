#include <bits/stdc++.h>
using namespace std;
long long int dp[100000];
long long int f(int a[],int l,int r)
{
    if(l == r) {
        dp[l] = a[l];
        return dp[l];
    }
    if(l > r) {
        return 0;
    }
    if(dp[l] != -1) {
        return dp[l];
    }

    dp[l] = max(a[l]+f(a,l+2,r),f(a,l+1,r));
    return dp[l];
}
int main()
{
    int t;
    int a[100000];
    int n;
    int i;
    int j;

    cin>>t;
    for(j = 1; j <= t; j++) {
        scanf("%d",&n);
        for(i = 0; i < n; i++) {
            scanf("%d",&a[i]);
            dp[i] = -1;
        }
        printf("Case %d: %lld\n",j,f(a,0,n-1));
    }
}
