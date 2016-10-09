#include <bits/stdc++.h>
using namespace std;
#define infinity -1e15
struct node
{
    long long int left;
    long long int right;
    long long int total;
    long long int mx;
};
node s[1000005];
int a[100005];
int ql;
int qr;
int pos;
int val;
struct node build(int node,int l,int r)
{
    if(l == r) {
        s[node].right = s[node].left = s[node].total = s[node].mx = a[l];
        return s[node];
    }
    int mid = (l+r)/2;
    struct node left = build(node*2,l,mid);
    struct node right = build(node*2+1,mid+1,r);
    s[node].left = max(left.left,left.total + right.left);
    s[node].right = max(right.right,right.total + left.right);
    s[node].total = left.total + right.total;
    s[node].mx = max(left.mx,right.mx);
    s[node].mx = max(s[node].mx,left.right + right.left);
    return s[node];
}
void update(int node,int l,int r)
{
    if(pos < l || pos > r) {
        return;
    }
    if(l == r) {
        a[l] = val;
        s[node].left = s[node].right = s[node].mx = s[node].total = val;
        return;
    }
    int mid = (l+r)/2;
    update(node*2,l,mid);
    update(node*2+1,mid+1,r);
    struct node left = s[node*2];
    struct node right = s[node*2+1];
    s[node].left = max(left.left,left.total + right.left);
    s[node].right = max(right.right,right.total + left.right);
    s[node].total = left.total + right.total;
    s[node].mx = max(left.mx,right.mx);
    s[node].mx = max(s[node].mx,left.right + right.left);


}
struct node query(int node,int l,int r )
{
    struct node x;
    if(qr < l || ql > r) {
        x.left = x.right = x.mx = infinity;
        x.total = 0;
        return x;
    }
    if(ql <= l && qr >= r) {
        return s[node];
    }
    int mid = (l+r)/2;
    struct node left = query(node*2,l,mid);
    struct node right = query(node*2+1,mid+1,r);
    x.left = max(left.left,left.total+right.left);
    x.right = max(right.right,right.total + left.right);
    x.total = left.total + right.total;
    x.mx = max(left.mx,right.mx);
    x.mx = max(x.mx,left.right+right.left);
    return x;

};
int main()
{

    int n;
    int i;
    int q;
    int c;

    scanf("%d",&n);
    for(i = 1; i <= n; i++) {
        scanf("%d",&a[i]);
    }
    build(1,1,n);


    scanf("%d",&q);
    while(q--) {
        cin>>c;
        if(c == 0) {
            scanf("%d%d",&pos,&val);
            update(1,1,n);
        }
        else {
            scanf("%d%d",&ql,&qr);
            struct node x = query(1,1,n);
            printf("%lld\n",x.mx);
        }
    }


}

