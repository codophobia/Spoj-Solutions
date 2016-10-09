#include <bits/stdc++.h>
using namespace std;
long long int dp[10][100005];
int f(int a[],int s,int n)
{
    if(s == 0) {
        dp[n][s] = 1;
        return dp[n][s];
    }
    if(s < 0) {
        return 0;
    }
    if(n <= 0) {
        return 0;
    }
    if(dp[n][s] != -1) {
        return dp[n][s];
    }
    long long int x = f(a,s,n-1);
    long long int y = f(a,s-a[n-1],n);
    dp[n][s] = x + y;
    return dp[n][s];
}
int main()
{
    int n;
    int s;

    int a[] = {2,3,6,7,8};
    int i;
    int t;
    int j;

    cin>>t;
    while(t--) {
    scanf("%d",&s);
    for(i = 0; i <= 10; i++) {
        for(j = 0; j <= s; j++) {
            dp[i][j] = -1;
        }
    }
    n = 5;

    f(a,s,n);
    printf("%lld\n",dp[n][s]);
    }
}

