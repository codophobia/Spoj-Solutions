#include <bits/stdc++.h>
using namespace std;
int n;
long long int dp[65][10];
long long int f(int pos,int val)
{
    if(pos > n) {
        dp[pos][val] = 1;
        return 1;
    }
    if(dp[pos][val] != -1) {
        return dp[pos][val];
    }
    long long int count = 0;
    for(int i = val; i <= 9; i++) {
        count = count + f(pos+1,i);
    }
    dp[pos][val] =  count;
    return dp[pos][val];
}
int main()
{
    int t;
    int i;
    int j;
    int k;
    cin>>t;

    while(t--) {
        cin>>k>>n;
        for(i = 0; i <= n; i++) {
            for(j = 0; j <= 10; j++) {
                dp[i][j] = -1;
            }
        }
        cout<<k<<' '<<f(1,0)<<endl;
    }
}
