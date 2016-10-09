#include <bits/stdc++.h>
using namespace std;
int a[100005];
int dp[1001][1001];
int f(int sum,int n)
{
   // cout<<sum<<' '<<n<<endl;
    if(sum < 0) {
        return INT_MAX;
    }
    if(n <= 0) {
        dp[sum][n] = sum;
        return sum;
    }
    if(dp[sum][n] != -1) {
        return dp[sum][n];
    }

    dp[sum][n] =  min(f(sum-a[n-1],n-2),f(sum,n-1));
    return dp[sum][n];
}
int main()
{
    int n;
    int j;
    int i;
    int t;
    int p;
    int k;

    cin>>t;
    for(j  = 1; j <= t; j++) {
        cin>>n>>k;
        for(i = 0; i < n; i++) {
            cin>>a[i];
        }
        for(i = 0; i <= k; i++) {
            for(p = 0; p <= n; p++) {
                dp[i][p] = -1;
            }
        }
        printf("Scenario #%d: %d\n",j,k-f(k,n));


    }

}
