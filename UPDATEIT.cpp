#include <bits/stdc++.h>
using namespace std;




int main()
{

    int n;
    int t;
    int i;
    int l;
    int r;
    int h;
    int q;
    int u;
    int val;
    int maxsize;
    scanf("%d",&t);

    while(t--) {

    scanf("%d%d",&n,&u);


    int a[n+5];

    memset(a,0,sizeof(a));

    while(u--) {
        scanf("%d%d%d",&l,&r,&val);
        a[l] += val;
        a[r+1] -= val;

    }

    for(i = 1; i < n; i++) {
        a[i] = a[i-1] + a[i];
    }

    scanf("%d",&q);

    while(q--) {
        scanf("%d",&l);
        printf("%d\n",a[l]);
    }
    }
}











