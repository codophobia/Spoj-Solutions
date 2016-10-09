#include <bits/stdc++.h>
using namespace std;
int a[100005];
int dp[1001][1001];
int n;
int f(int i,int j)
{
    int f1 = 0;
    int f2 = 0;
    if(i > j) {
        return 0;
    }
    if(i == j) {
        dp[i][j] = a[i];
        return a[i];
    }
    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    if(i+1 < n && a[i+1] >= a[j]) {
        f1 = f1 + f(i+2,j);
    }
    else {
        f1 = f1 + f(i+1,j-1);
    }
    if(j-1 >= 0 && a[i] >= a[j-1]) {
        f2 = f2 + f(i+1,j-1);
    }
    else {
        f2 = f2 + f(i,j-2);
    }
    dp[i][j] =  max(f1+a[i],f2+a[j]);
    return dp[i][j];
}
int main()
{
    int i;
    int j;
    int k;
    int first;
    int second;
    int sum;

    for(k = 1; ; k++) {
        cin>>n;
        sum = 0;
        if(n == 0) {
            break;
        }
        for(i = 0; i < n; i++) {
            cin>>a[i];
            sum = sum + a[i];
        }
        for(i = 0; i <= n; i++) {
            for(j = 0; j <= n; j++) {
                dp[i][j] = -1;
            }
        }
        first = f(0,n-1);
        second = sum - first;
        printf("In game %d, the greedy strategy might lose by as many as %d points.\n",k,first-second);
    }

}
