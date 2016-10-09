#include <bits/stdc++.h>
using namespace std;
int dp[5001][5001];
int main()
{
    string s;
    int t;
    int i;
    int j;
    int k;
    int n;

    cin>>t;
    while(t--) {
        cin>>s;
        n = s.size();
        for(i = 1; i <= n; i++) {
            for(j = 1, k = i; j <= n && k <= n;k++,j++) {
                if(j == k) {
                    dp[j][k] = 0;
                }
                else if((j+1) == k) {
                    dp[j][k] = (s[j-1] == s[k-1])?0:1;
                }
                else if(s[j-1] == s[k-1]) {
                    dp[j][k] = dp[j+1][k-1];
                }
                else {
                    dp[j][k] = min(dp[j+1][k],dp[j][k-1])+1;
                }
            }
        }
        cout<<dp[1][n]<<endl;
    }
}
