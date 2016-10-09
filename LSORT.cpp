#include <bits/stdc++.h>
using namespace std;
int dx[1005][1005];
int dy[1005][1005];
long long int dp[1005][1005];
int h[10005];
long long int f(int v[],int x,int y,int n,int level)
{

    if(x < 1 || y > n) {
        return LONG_MAX;
    }

    if(level == n) {

        return n;
    }
    if(dp[x][y] != 0) {
        return dp[x][y];
    }

     long long int left = f(v,min(x,y)-1,y,n,level+1) + ((long long)level*(long long)dx[x][y]);
    //cout<<h[x]<<' '<<h[y]<<endl;
    //cout<<level<<' '<<dx[x][y]<<endl;
     long long int right = f(v,x,max(x,y)+1,n,level+1) + ((long long)level*(long long)dy[y][x]);
   // cout<<x<<' '<<y<<endl;
   // cout<<level<<' '<<left<<' '<<right<<endl;
    dp[x][y] =  min(left,right);
    return dp[x][y];


}
int main()
{
    int n;
    int t;
    int i;
    long long int x;
    long long int min;
    int j;
    int a[100005];



    cin>>t;
    while(t--) {

        //n = 1000;
        cin>>n;
        memset(dp,0,sizeof(dp));
        min = LONG_MAX;
        for(i = 0; i < n; i++) {
            cin>>a[i];
            //a[i] = i+1;
            h[a[i]] = i+1;
        }
        if(n == 1) {
            printf("%d\n",1);
            continue;
        }
        for(i = 1; i <= n; i++) {
            dx[i][i] = h[i];
            for(j = i+1; j <= n; j++) {
                dx[i][j] = dx[i][j-1] - (h[i]>h[j]?1:0);
            }
        }
        for(i = 1; i <= n; i++) {
            dy[i][i] = h[i];
            for(j = i-1; j >= 1; j--) {
                dy[i][j] = dy[i][j+1] - (h[i]>h[j]?1:0);
            }

        }
        for(i = 0; i < n; i++) {
            x = f(a,a[i],a[i],n,1);
         //   cout<<x<<" ss"<<endl;
            //cout<<"ss"<<endl;
            if(x < min) {
                min = x;
            }
        }
        printf("%lld\n",min);
       // bool y = next_permutation(a,a+n);
    }
}
