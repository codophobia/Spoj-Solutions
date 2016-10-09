#include <bits/stdc++.h>
using namespace std;
int n;
int a[10005];
int h[100005];
int dp[100005][101];
int main()
{
    int i;
    int sum;
    int ans;
    int t;
    int j;

    cin>>t;
    while(t--) {
        cin>>n;
        ans = 0;
        sum = 0;
        for(i = 0; i < n; i++) {
            cin>>a[i];
            sum = sum + a[i];
        }
        for(i = 0; i <= n; i++) {
            dp[0][i] = 1;
        }
        for(j = 1; j <= sum; j++) {
            dp[i][0] = 0;
        }
        for(i = 1; i <= sum; i++) {
            for(j = 1; j <= n; j++) {
                if(i - a[j-1] >= 0) {
                    dp[i][j] = dp[i-a[j-1]][j-1] || dp[i][j-1];
                }
                else {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }

        for(i = 1; i <= sum; i++) {
            if(dp[i][n] == 1) {
                ans = ans + i;
            }
        }
        cout<<ans<<endl;
    }

}
