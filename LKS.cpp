#include <bits/stdc++.h>
using namespace std;
struct items
{
    int v;
    int w;
};
items a[10005];
int dp[2000005][105];
int f(int W,int n)
{
    if(W == 0 || n == 0) {
        return 0;
    }
    if(dp[W][n] != -1) {
        return dp[W][n];
    }
    if(a[n-1].w > W) {
        dp[W][n] =  f(W,n-1);
    }
    else {
        dp[W][n] =  max(f(W-a[n-1].w,n-1)+a[n-1].v,f(W,n-1));
    }
    return dp[W][n];
}
int main()
{
    int n;
    int i;
    int j;
    int t;
    int W;

    
        cin>>W>>n;
        for(i = 0; i < n; i++) {
            cin>>a[i].v>>a[i].w;
        }
        for(i = 0; i <= W; i++) {
            for(j = 0; j <= n; j++) {
                dp[i][j] = -1;
            }
        }
        cout<<f(W,n)<<endl;
    
}
