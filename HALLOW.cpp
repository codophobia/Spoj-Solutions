#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    long long int m;
    long long int i;
    long long int l;
    long long int r;
    long long int a[100005];
    long long int vis[100005];
    long long int s[100005];

    while(1) {
        cin>>m>>n;
        if(m == 0 && n == 0) {
            break;
        }
        s[0] = 0;
        for(i = 1; i <= n; i++) {
            cin>>a[i];
            s[i] = s[i-1] + a[i];
        }
        for(i = 1; i <= n; i++) {
            s[i] = s[i]%m;
        }
        for(i = 1; i < 100005; i++) {
            vis[i] = -1;
        }
        vis[0] = 0;
        for(i = 1; i <= n; i++) {
            if(vis[s[i]] != -1) {
                l = vis[s[i]]+1;
                r = i;
                break;
            }
            else {
                vis[s[i]] = i;
            }
        }
        for(i = l; i <= r; i++) {
            cout<<i<<' ';
        }
        cout<<endl;
    }
}
