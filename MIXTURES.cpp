#include <bits/stdc++.h>
using namespace std;
int c[101][101];
int dp[105][105];
int f(int i,int j)
{
    if(i == j) {
        return 0;
    }
    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    int mn = 1000000000;
    for(int k = i; k < j; k++) {
        int cnt = f(i,k) + f(k+1,j) + (c[i][k]*c[k+1][j]);
        mn = min(mn,cnt);
    }
    dp[i][j] =  mn;
    return dp[i][j];
}
int main()
{
    int t;
    int n;
    int i;
    int j;
    int a[1000];

    while(scanf("%d",&n) != EOF) {
        for(i = 1; i <= n; i++) {
            cin>>a[i];
        }
        for(i = n; i >= 1; i--) {
            c[i][i] = a[i];
            for(j = i+1; j <= n; j++) {
                c[i][j] = (c[i][j-1] + c[j][j])%100;
            }
        }
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= n; j++) {
                dp[i][j] = -1;
            }
        }
        cout<<f(1,n)<<endl;
    }
}
