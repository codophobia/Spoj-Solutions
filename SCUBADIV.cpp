#include <bits/stdc++.h>
using namespace std;
struct items
{
    int ox;
    int nt;
    int w;
};
items a[10005];
int dp[22][80][1001];
int f(int ox,int nt,int n)
{
    if(ox == 0 && nt == 0) {
        return 0;
    }
    if(n == 0) {
        return 100000000;
    }
    if(dp[ox][nt][n] != -1) {
        return dp[ox][nt][n];
    }
    dp[ox][nt][n] =  min(f(ox,nt,n-1),f(ox-min(ox,a[n-1].ox),nt-min(nt,a[n-1].nt),n-1)+a[n-1].w);
    return dp[ox][nt][n];
}
int main()
{
    int n;
    int i;
    int j;
    int t;
    int W;
    int ox;
    int nt;
    int k;

    cin>>t;
    while(t--) {
        cin>>ox>>nt;
        cin>>n;
        for(i = 0; i < n; i++) {
            cin>>a[i].ox>>a[i].nt>>a[i].w;
        }
        for(i = 0; i <= ox; i++) {
            for(j = 0; j <= nt; j++) {
                for(k = 0; k <= n; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
        cout<<f(ox,nt,n)<<endl;
    }
}

