#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int m[15000009];
int treeconstruct(int m[],int a[],int s,int e,int node)
{
    if(s == e) {
        m[node] = a[s];
        return a[s];
    }

    int right = treeconstruct(m,a,s,(s+e)/2,2*node);
    int left = treeconstruct(m,a,((s+e)/2)+1,e,2*node+1);

   m[node] = left+right;

    return m[node];
}
int query(int m[],int a[],int s,int e,int node,int i,int j)
{


    if(s >= i && e <= j)  {
        return m[node];
    }

    if(i > e || j < s) {
        return 0;
    }



    int right = query(m,a,s,(s+e)/2,node*2,i,j);
    int left = query(m,a,((s+e)/2)+1,e,node*2+1,i,j);

    return left+right;



}
int update(int m[],int a[],int s,int e,int node,int i,int val)
{
    if(s > i || e < i) {
        return m[node];
    }

    if(s == e) {
        m[node] = val + m[node];
        return m[node];
    }


    //m[node] = min(m[node],val);

        int right = update(m,a,s,(s+e)/2,node*2,i,val);
        int left  = update(m,a,((s+e)/2)+1,e,node*2+1,i,val);
        m[node] = left + right;
        return m[node];

}
int main()
{

    string s;
    int n;
    int i;
    int l;
    int r;
    int h;
    int q;
    int val;
    int maxsize;

    scanf("%d%d",&n,&q);





    memset(a,0,sizeof(a));


    treeconstruct(m,a,1,n,1);





    while(q--) {
        cin>>s;
        if(s == "add") {
                //cout<<"yes"<<endl;
            scanf("%d%d",&i,&val);
            update(m,a,1,n,1,i,val);
        }
        else if(s == "find") {
            //cout<<"no"<<endl;
            scanf("%d%d",&l,&r);
            printf("%d\n",query(m,a,1,n,1,l,r));
        }

    }
}
