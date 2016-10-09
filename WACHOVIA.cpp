#include <bits/stdc++.h>
using namespace std;
struct items
{
    int w;
    int v;
};
items a[100000];
int dp[10000][10000];
int f(int W,int n)
{
    if(n == 0) {
        return 0;
    }
    if(dp[W][n] != -1) {
        return dp[W][n];
    }
    if(W-a[n-1].w < 0) {
        dp[W][n] = f(W,n-1);
        return dp[W][n];
    }
    dp[W][n] =  max(f(W-a[n-1].w,n-1)+a[n-1].v,f(W,n-1));
    return dp[W][n];
}
int main()
{

    int wmax;
    int t;
    int n;
    int i;
    int j;

    cin>>t;
    while(t--) {
        cin>>wmax>>n;
        for(i = 0; i <= wmax; i++) {
            for(j = 0; j <= n; j++) {
                dp[i][j] = -1;
            }
        }
        for(i = 0; i < n; i++) {
            cin>>a[i].w>>a[i].v;
        }
        printf("Hey stupid robber, you can get %d.\n",f(wmax,n));
    }
}
