#include <bits/stdc++.h>
using namespace std;
int one[201][201];
int zero[201][201];
int dp[201][201];
string s;
int f(int i,int j)
{
    if(i == j) {
        return s[i-1]-'0';
    }
    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    int mx = 0;
    int cnt;
    for(int k = i; k < j; k++) {
        cnt = f(i,k)+f(k+1,j);
        mx = max(mx,cnt);
    }
    if(one[i][j] > zero[i][j]) {
        mx = (j-i+1);
    }
    dp[i][j] = mx;
    return dp[i][j];
}
int main()
{
    int t;
    int n;
    int i;
    int j;

    cin>>t;
    while(t--) {
        cin>>n;
        cin>>s;
        for(i = n; i >= 1; i--) {
            one[i][i] = s[i-1]-'0';
            for(j = i+1; j <= n; j++) {
                one[i][j] = one[i][j-1] + one[j][j];
            }
        }
        for(i = n; i >= 1; i--) {
            zero[i][i] = (s[i-1]-'0')?0:1;
            for(j = i+1; j <= n; j++) {
                zero[i][j] = zero[i][j-1] + zero[j][j];
            }
        }
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= n; j++) {
                dp[i][j] = -1;
            }
        }

        cout<<f(1,n)<<endl;
    }

}
