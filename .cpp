#include <bits/stdc++.h>
using namespace std;
int a[1000][1000];
int dp[1000][1000];
int n;
int m;
int f(int x,int y)
{
    if(x >= n || y >= m) {
        return INT_MAX;
    }
    if(x == n-1 && y == m-1) {
        if(a[x][y] < 0) {
            return a[x][y]*-1 + 1;
        }
        else {
            return 1;
        }
    }
    if(dp[x][y] != -1) {
        return dp[x][y];
    }
    int left = f(x+1,y);
    int right = f(x,y+1);
    int req = min(left,right);
    if(a[x][y] >= req) {
        dp[x][y] =  1;
    }
    else {
        dp[x][y] = req + a[x][y]*-1;
    }
    return dp[x][y];
}
int main()
{

    int t;
    int i;
    int j;

    cin>>t;
    while(t--) {
        scanf("%d %d",&n,&m);
        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                scanf("%d",&a[i][j]);
                dp[i][j] = -1;
            }
        }
        int x = f(0,0);
        cout<<x<<endl;

    }
}
