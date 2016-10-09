#include <bits/stdc++.h>
using namespace std;
string a;
string b;
int len;
int c[1001][1001];
int dp[1001][1001];
int main()
{
    int n;
    int m;
    int i;
    int j;
    int k;

    while(1) {
        cin>>len;
        memset(c,0,sizeof(c));
        memset(dp,0,sizeof(dp));
        if(len == 0) {
            break;
        }
        cin>>a>>b;
        n = a.size();
        m = b.size();
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= m; j++) {
                if(a[i-1] == b[j-1]) {
                    c[i][j] = c[i-1][j-1] + 1;
                }
                if(c[i][j] >= len) {
                    for(int k = len; k <= c[i][j]; k++) {
                        dp[i][j] = max(dp[i][j],dp[i-k][j-k]+k);
                    }
                }
                else {
                    int first = dp[i-1][j-1];
                    int second = max(dp[i-1][j],dp[i][j-1]);
                    dp[i][j] = max(first,second);
                }

            }
        }
        cout<<dp[n][m]<<endl;

    }

}

