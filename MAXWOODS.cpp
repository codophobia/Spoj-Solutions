#include <bits/stdc++.h>
using namespace std;
char a[201][201];
int dp[201][201][2];
int n;
int m;
int f(int i,int j,int d)
{
    if(i >= n || j >= m || a[i][j] == '#'|| j < 0) {
        return 0;
    }
    if(dp[i][j][d] != -1) {
        return dp[i][j][d];
    }
    if(d == 1) {
        if(a[i][j] == 'T') {
            dp[i][j][d] = max(f(i,j+1,1),f(i+1,j,0))+1;
        }
        else {
            dp[i][j][d] = max(f(i,j+1,1),f(i+1,j,0));
        }
        return dp[i][j][d];
    }
    else {
       if(a[i][j] == 'T') {
            dp[i][j][d] =  max(f(i,j-1,0),f(i+1,j,1))+1;
        }
        else {
            dp[i][j][d] = max(f(i,j-1,0),f(i+1,j,1));
        }
        return dp[i][j][d];
    }
}
int main()
{
    int t;
    int i;
    int j;

    cin>>t;
    while(t--) {
        cin>>n>>m;
        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                cin>>a[i][j];
            }
        }
        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                dp[i][j][0] = -1;
                dp[i][j][1] = -1;
            }
        }
        cout<<f(0,0,1)<<endl;
    }
}
