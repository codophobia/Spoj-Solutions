#include <bits/stdc++.h>
using namespace std;
int s[5*200005];
int pos;
int ql;
int qr;
void update(int node,int l, int r)
{
    if(pos < l || pos > r) {
        return;
    }
    if(l == r) {
        s[node] = 1;
        return;
    }
    int mid = (l+r)/2;
    update(node*2,l,mid);
    update(node*2+1,mid+1,r);
    s[node] = s[node*2] + s[node*2+1];
}
int query(int node,int l,int r)
{
    if(ql > r || qr < l) {
        return 0;
    }
    if(ql <= l && qr >= r) {
        return s[node];
    }
    int mid = (l+r)/2;
    return query(node*2,l,mid) + query(node*2+1,mid+1,r);
}
int main()
{
    int t;
    int n;
    int a[200005];
    int b[200005];
    int i;
    int j;
    long long int cnt;

    cin>>t;
    cout<<endl;
    while(t--) {
        cin>>n;
        memset(s,0,sizeof(s));
        cnt = 0;
        for(i = 0; i < n; i++) {
            cin>>a[i];
            b[i] = a[i];
        }
        sort(b,b+n);
        for(i = 0; i < n; i++) {
            int lb = lower_bound(b,b+n,a[i])-(b);
            lb++;
            //cout<<lb<<endl;
            ql = lb+1;
            qr = n;
            cnt = cnt + (long long)query(1,1,n);
            pos = lb;
            update(1,1,n);
        }
        cout<<cnt<<endl;
        cout<<endl;

    }
}
