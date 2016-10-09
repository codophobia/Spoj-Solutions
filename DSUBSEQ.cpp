#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
    ll int n;
    string s;
    int t;
    int i;
    ll int dp[100005];
    ll int sum[100005];
    int lst[200];
    cin>>t;
    while(t--) {
        cin>>s;
        memset(sum,0,sizeof(sum));
        memset(lst,0,sizeof(lst));
        dp[0] = 1;
        sum[0] = 1;
        n = s.size();
        for(i = 1; i <= n; i++) {
            if(lst[s[i-1]-'A'] != 0) {
                dp[i] = (sum[i-1] - sum[lst[s[i-1]-'A']-1])%mod;
                if(dp[i] < 0) {
                    dp[i] = (dp[i] + mod)%mod;
                }
            }
            else {
                dp[i] = sum[i-1];
            }
            sum[i] = (dp[i] + sum[i-1])%mod;
            lst[s[i-1]-'A'] = i;
        }
        cout<<sum[n]<<endl;

    }
}
