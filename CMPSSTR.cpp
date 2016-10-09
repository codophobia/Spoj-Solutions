#include <bits/stdc++.h>
using namespace std;
int main()
{
    char a[100];
    char b[100];
    int i;
    int j;
    int mx;
    int dp[100][100];

    while(cin.getline(a,100)) {
        cin.getline(b,100);
        memset(dp,0,sizeof(dp));
        mx = 0;
        int n = strlen(a);
        int m = strlen(b);
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= m; j++) {
                if(a[i-1] == b[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    mx = max(mx,dp[i][j]);
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }
        printf("%d\n",mx);
    }

}
