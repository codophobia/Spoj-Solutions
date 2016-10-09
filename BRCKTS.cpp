#include <bits/stdc++.h>
using namespace std;
#define infinity 1e9
string a;
int ans[1000006];
int ql;
int qr;
int pos;
struct node
{
    int op;
    int cl;
    int val;
};
node s[5*30005];
struct node build(int node,int l,int r)
{
    if(l == r) {
        if(a[l] == '(') {
            s[node].op++;
        }
        else {
            s[node].cl++;
        }
        return s[node];
    }
    int mid = (l + r)/2;
    struct node left = build(node*2,l,mid);
    struct node right = build(node*2+1,mid+1,r);
    int x = min(left.op,right.cl);
    s[node].val = left.val + right.val + x;
    s[node].op = left.op + right.op - x;
    s[node].cl = left.cl + right.cl - x;
    return s[node];
}
void update(int node,int l,int r)
{
    if(pos < l || pos > r) {
        return;
    }
    if(l == r) {
        //cout<<s[node].op<<' '<<s[node].cl<<' '<<node<<' '<<l<<endl;
        if(s[node].op == 1) {
            s[node].op = 0;
            s[node].cl = 1;
            s[node].val = 0;
        }
        else {
            s[node].cl = 0;
            s[node].op = 1;
            s[node].val = 0;
        }
        return;
    }
    int mid = (l + r)/2;
    update(node*2,l,mid);
    update(node*2+1,mid+1,r);
    int x = min(s[node*2].op,s[node*2+1].cl);
    s[node].val = s[node*2].val + s[node*2+1].val + x;
    s[node].op = s[node*2].op + s[node*2+1].op - x;
    s[node].cl = s[node*2].cl + s[node*2+1].cl - x;
}
struct node query(int node,int l,int r)
{
    struct node ans;
    if(qr < l || ql > r) {
       ans.op = ans.cl = ans.val = 0;
       return ans;
    }
    if(ql <= l && qr >= r) {
        return s[node];
    }
    int mid = (l + r)/2;
    struct node left = query(node*2,l,mid);
    struct node right = query(node*2+1,mid+1,r);
    int x = min(left.op,right.cl);
    ans.val = left.val + right.val + x;
    ans.op = left.op + right.op - x;
    ans.cl = left.cl + right.cl - x;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    int i;
    int q;
    int k;

    for(i = 1; i <= 10; i++) {
        memset(s,0,sizeof(s));
        a.clear();
        cin>>n;
        cin>>a;
        build(1,0,a.size()-1);
        cin>>q;
        cout<<"Test "<<i<<":"<<endl;
        while(q--) {
            cin>>pos;
            if(pos == 0) {
                ql = 0;
                qr = n-1;
                struct node x = query(1,0,n-1);
                //cout<<x.op<<' '<<x.cl<<endl;
                if(x.cl == 0 && x.op == 0) {
                    cout<<"YES"<<endl;
                }
                else {
                    cout<<"NO"<<endl;
                }
            }
            else {
                pos--;
                update(1,0,n-1);
            }
        }
    }
}


