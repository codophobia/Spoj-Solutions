#include <bits/stdc++.h>
using namespace std;
int dp[105][105];
int f(int a[][105],int x,int y,int n,int m)
{
    if(x >= n || y >= m) {
        return 0;
    }
    if(dp[x][y] != -1) {
        return dp[x][y];
    }
    int mx = 0;
    mx = max(f(a,x+1,y+1,n,m),f(a,x+1,y-1,n,m));
    mx = max(mx,f(a,x+1,y,n,m));
    dp[x][y] = a[x][y]+mx;
    return dp[x][y];

}
int main()
{
    int t;
    int a[105][105];
    int n;
    int m;
    int i;
    int j;
    int mx;

    cin>>t;
    while(t--) {
        cin>>n>>m;
        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                cin>>a[i][j];
                dp[i][j] = -1;
            }
        }
        mx = 0;
        for(i = 0; i < m; i++) {
            mx = max(mx,f(a,0,i,n,m));
        }
        cout<<mx<<endl;
    }

}
