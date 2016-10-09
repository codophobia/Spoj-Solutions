#include <bits/stdc++.h>
#define ll long long
#define mod 5000000
using namespace std;
ll int a[10005];
ll int b[10005];
ll int s[4*10005][55];
int pos;
ll int val;
int ql,qr;

void update(int node,int l,int r,int k)
{
    if(pos < l || pos > r) {
        return;
    }
    if(l == r) {
        s[node][k] = (s[node][k] + val)%mod;
        return;
    }
    int mid = (l+r)/2;
    update(node*2,l,mid,k);
    update(node*2+1,mid+1,r,k);
    s[node][k] = (s[node*2][k] + s[node*2+1][k])%mod;
}
ll int query(int node,int l,int r,int k)
{
    if(qr < l || ql > r) {
        return 0;
    }
    if(ql <= l && qr >= r) {
        return s[node][k];
    }
    int mid = (l+r)/2;
    ll int x = (query(node*2,l,mid,k) + query(node*2+1,mid+1,r,k))%mod;
    return x;
}

int main()
{
    int n;
    int i;
    int j;
    int k;
    ll int x;
    int g = 0;
    int h = 0;
    unordered_map<ll int,int> m;

    cin>>n>>k;
    for(i = 1; i <= n; i++) {
        scanf("%lld",&x);
        if(m[x] == 0) {
            m[x] = 1;
            g++;
            a[g] = x;
            b[g] = x;
        }
    }
    sort(a+1,a+g+1);
    m.clear();
    for(i = 1; i <= g; i++) {
        m[a[i]] = i;
    }
    for(i = 1; i <= g; i++) {
        ql = 1;
        qr = m[b[i]]-1;
        pos = m[b[i]];
        val = 1;
        update(1,1,g,1);
        //cout<<ql<<' '<<qr<<endl;
        for(j = 2; j <= k; j++) {
            val = query(1,1,g,j-1);
            update(1,1,g,j);
        }

    }
    ql = 1;
    qr = g;
    cout<<query(1,1,g,k);


}

