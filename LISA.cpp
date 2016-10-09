#include <bits/stdc++.h>
using namespace std;
int dp[101][101];
int f(int i,int j,string a,string b)
{
    if(i == j) {
        return (a[i-1]-'0');
    }
    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    int mn = 10000000;
    for(int k = i; k < j; k++) {
        int cnt;
        if(b[k-1] == '+') {
           cnt = f(i,k,a,b) + f(k+1,j,a,b);
        }
        else {
            cnt = f(i,k,a,b) * f(k+1,j,a,b);
        }
        mn = min(mn,cnt);
    }
    dp[i][j] =  mn;
    return dp[i][j];
}
int f1(int i,int j,string a,string b)
{
    if(i == j) {
        return (a[i-1]-'0');
    }
    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    int mx = 0;
    for(int k = i; k < j; k++) {
        int cnt;
        if(b[k-1] == '+') {
           cnt = f1(i,k,a,b) + f1(k+1,j,a,b);
        }
        else {
            cnt = f1(i,k,a,b) * f1(k+1,j,a,b);
        }
        mx = max(mx,cnt);
    }
    dp[i][j] =  mx;
    return dp[i][j];
}
void f2(int n)
{
    int i;
    int j;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            dp[i][j] = -1;
        }
    }
}

int main()
{
    int t;
    string s;
    string a;
    string b;
    int i;

    cin>>t;
    while(t--) {
        cin>>s;
        a.clear();
        b.clear();
        for(i = 0; i < s.size(); i++) {
            if(isdigit(s[i])) {
                a.push_back(s[i]);
            }
            else {
                b.push_back(s[i]);
            }
        }
        f2(a.size());
        int x = f(1,a.size(),a,b);
        f2(a.size());
        int y = f1(1,a.size(),a,b);
        cout<<y<<' '<<x<<endl;
    }

}
