#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll int a[1000006];
int main()
{
    ll int n,m;
    int i;
    ll int mx = 0;

    cin>>n>>m;
    for(i = 0; i < n; i++) {
        cin>>a[i];
    }
    ll int r = 0;
    ll int sum = a[0];
    for(i = 0; i < n; i++) {
        while(r+1 < n && (sum+a[r+1]) <= m) {
            sum += a[r+1];
            r++;
        }
        mx = max(mx,sum);
        sum -= a[i];
    }
    cout<<mx;
}
