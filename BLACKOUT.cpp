#include <bits/stdc++.h>
using namespace std;
long long int b[2001][2001];
long long int area[2001][2001];
long long int p[2001][2001];
long long int dp[2001][2001];
struct points
{
    int s1;
    int s2;
    int d1;
    int d2;
};
points a[10005];
long long int f(long long int k,long long int n)
{
    if(k == 0 || n == 0) {
        return 0;
    }
    if(dp[k][n] != -1) {
        return dp[k][n];
    }
    long long int tp = (p[a[n-1].s1-1][a[n-1].s2-1] + p[a[n-1].d1][a[n-1].d2]) - (p[a[n-1].s1-1][a[n-1].d2] + p[a[n-1].d1][a[n-1].s2-1]);
    long long int tarea = (area[a[n-1].s1-1][a[n-1].s2-1] + area[a[n-1].d1][a[n-1].d2]) - (area[a[n-1].s1-1][a[n-1].d2] + area[a[n-1].d1][a[n-1].s2-1]);
    //cout<<n<<' '<<tp<<' '<<tarea<<endl;
    if(tp > k) {
        dp[k][n] =  f(k,n-1);
        return dp[k][n];
    }
    else {
        dp[k][n] =  max(f(k-tp,n-1)+tarea,f(k,n-1));
        return dp[k][n];
    }
}
int main()
{
    long long int n;
    long long int m;
    long long int q;
    long long int k;
    int i;
    int j;
    long long int asum = 0;
    long long int psum = 0;

    cin>>n>>m>>q>>k;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            scanf("%lld",&b[i][j]);
            area[i][j] = 1;
        }
    }
    for(i = 1; i <= n; i++) {
        asum = 0;
        psum = 0;
        for(j = 1; j <= m; j++) {
            psum = psum + b[i][j];
            asum = asum + area[i][j];
            p[i][j] = p[i-1][j] + psum;
            area[i][j] = area[i-1][j] + asum;
        }
    }
    for(i = 0; i <= k; i++) {
        for(j = 0; j <= q; j++) {
            dp[i][j] = -1;
        }
    }
    for(i = 0; i < q; i++) {
        scanf("%d %d %d %d",&a[i].s1,&a[i].s2,&a[i].d1,&a[i].d2);
    }
    cout<<f(k,q)<<endl;

}
