#include <bits/stdc++.h>
using namespace std;
long long int dp[200005][5];
long long int n;
long long int a[200010];
long long int f(long long int pos,long long int num)
{

    if(pos == n) {
        dp[pos][num] =  a[pos];
        return dp[pos][num];
    }
    else if(pos == n-1) {
        dp[pos][num] = a[pos]+a[pos+1];
        return dp[pos][num];
    }
    else if(pos == n-2) {
        dp[pos][num] = a[pos]+a[pos+1]+a[pos+2];
    }
    else if(pos > n) {
        dp[pos][num] =  0;
        return dp[pos][num];
    }
    if(dp[pos][num] != -1) {
        return dp[pos][num];
    }
    long long int first = f(pos+2,1) + a[pos];
    long long int second = f(pos+4,2) + a[pos] + a[pos+1];
    long long int third = f(pos+6,3) + a[pos] + a[pos+1] + a[pos+2];
    long long int mx = max(first,second);
    mx = max(mx,third);
    //cout<<first<<' '<<second<<' '<<third<<endl;
    dp[pos][num] = mx;
    return dp[pos][num];
}
int main()
{
    int t;
    int i;
    int j;

    cin>>t;
    while(t--) {
        cin>>n;
        for(i = 1; i <= n; i++) {
            scanf("%lld",&a[i]);
        }
        for(i =0; i <= n; i++) {
            for(j = 0; j < 5; j++) {
                dp[i][j] = -1;
            }
        }
        long long int first = f(1,1);
        long long int second = f(1,2);
        long long int third = f(1,3);
        long long int mx = max(first,second);
        mx = max(mx,third);
        printf("%lld\n",mx);
    }

}

