#include <bits/stdc++.h>
using namespace std;
int dp[6005][6005];
int r(char s[],int l, int h)
{
    if(l == h) {
        dp[l][h] = 0;
        return dp[l][h];
    }
    if(dp[l][h] != -1) {
        return dp[l][h];
    }
    if(s[l] == s[h]) {
        dp[l][h] = r(s,l+1,h-1);
        return dp[l][h];
    }
    else {
        dp[l][h] = min(r(s,l+1,h),r(s,l,h-1))+1;
        return dp[l][h];
    }
}
int main()
{
    char s[100000];
    int n;
    int t;

    int i,j;
    cin>>t;
    while(t--) {
        scanf("%s",s);
        n = strlen(s);
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                dp[i][j] = -1;
            }
        }
        printf("%d\n",r(s,0,strlen(s)-1));

}
}
