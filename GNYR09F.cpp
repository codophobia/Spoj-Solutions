#include <bits/stdc++.h>
using namespace std;
int n;
long long int dp[500][2][500];
long long int f(int pos,int prev,int count)
{
    /*b[pos-1] = prev;
    cout<<count<<' '<<pos<<endl;
    for(int i = 1; i < pos; i++) {
        cout<<b[i]<<' ';
    }
    cout<<endl;*/
    if(count == 0 && pos-1 == n) {
        dp[pos][prev][count] = 1;
        return 1;
    }
    if(pos > n) {
        return 0;
    }
    if(dp[pos][prev][count] != -1) {
        return dp[pos][prev][count];
    }
    long long int right,left;
    left = f(pos+1,0,count);
    if(prev == 1) {
        right = f(pos+1,1,count-1);
    }
    else {
        right = f(pos+1,1,count);
    }


    dp[pos][prev][count] =  right+left;
    return dp[pos][prev][count];
}
int main()
{
    int k;
    int i;
    int j;
    int p;
    int t;
    int c;
    int bit;

    cin>>t;
    while(t--) {
        cin>>c>>n>>bit;
        for(i = 0; i <= n; i++) {
            for(j = 0; j < 2; j++) {
                for(k = 0; k <= n; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
        cout<<c<<' '<<f(2,0,bit)+f(2,1,bit)<<endl;
    }
}
