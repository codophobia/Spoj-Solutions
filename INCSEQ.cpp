#include <bits/stdc++.h>
#define ll long long
#define mod 5000000
using namespace std;
int a[10005];
int b[10005];
int s[4*10005][55];
int pos;
int val;
int ql,qr;

void update(int node,int l,int r,int k)
{
    if(pos < l || pos > r) {
        return;
    }
    if(l == r) {
        s[node][k] = (s[node][k] + val);
        if(s[node][k] > mod) {
            s[node][k] -= mod;
        }
        return;
    }
    int mid = (l+r)/2;
    update(node*2,l,mid,k);
    update(node*2+1,mid+1,r,k);
    s[node][k] = (s[node*2][k] + s[node*2+1][k]);
    if(s[node][k] > mod) {
        s[node][k] -= mod;
    }
}
int query(int node,int l,int r,int k)
{
    if(qr < l || ql > r) {
        return 0;
    }
    if(ql <= l && qr >= r) {
        return s[node][k];
    }
    int mid = (l+r)/2;
    int x = (query(node*2,l,mid,k) + query(node*2+1,mid+1,r,k));
    if(x > mod) {
        x -= mod;
    }
    return x;
}

int main()
{
    int n;
    int i;
    int j;
    int k;
    unordered_map<int,int> m;

    cin>>n>>k;
    for(i = 1; i <= n; i++) {
        scanf("%d",&a[i]);
        b[i] = a[i];
    }
    sort(a+1,a+n+1);
    for(i = 1; i <= n; i++) {
        if(m[a[i]] == 0) {
            m[a[i]] = i;
        }
    }
    for(i = 1; i <= n; i++) {
        ql = 1;
        qr = m[b[i]]-1;
        pos = m[b[i]];
        val = 1;
        update(1,1,n,1);
        for(j = 2; j <= k; j++) {
            val = query(1,1,n,j-1);
            update(1,1,n,j);
        }

    }
    ql = 1;
    qr = n;
    cout<<query(1,1,n,k);


}

