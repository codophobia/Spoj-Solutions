#include <bits/stdc++.h>
using namespace std;
struct cards
{
    int c;
    int v;
};
cards a[10000];
int tpos[1000][1000];
int dp[10000];
int f(int n)
{
    if(n == 1) {
        return 1;
    }
    if(dp[n] != -1) {
        return dp[n];
    }
    int mx = 1;
    for(int i = n-1; i >= 1; i--) {
        if(tpos[a[n-1].c][a[n-1].v] > tpos[a[i-1].c][a[i-1].v]) {
            mx = max(mx,f(i)+1);
        }
    }
    dp[n] = mx;
    return dp[n];
}
int main()
{
    int tc;
    int tv;
    int i;
    int j;
    int k;
    int mx = 0;
    int tmax = 1000000000;
    int t = 1;
    vector<int> v;

    cin>>tc>>tv;
    for(i = 0; i < tc*tv; i++) {
        cin>>a[i].c>>a[i].v;
    }
    for(i = 1; i <= tc; i++) {
        v.push_back(i);
    }
    do {
        t = 1;
        for(i = 0; i < v.size(); i++) {
            k = v[i];
            for(j = 1; j <= tv; j++) {
                tpos[k][j] = t;
                t++;
            }
        }
        for(i = 0; i <= tv*tc; i++) {
            dp[i] = -1;
        }
        mx = 0;
        for(i = tv*tc; i >= 1; i--) {
            mx = max(mx,f(i));
        }
        mx = (tv*tc) - mx;
        tmax = min(mx,tmax);

    }while(next_permutation(v.begin(),v.end()));
    cout<<tmax<<endl;

}
