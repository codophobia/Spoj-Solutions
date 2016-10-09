#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[100005];
    int b[100005];
    int n;
    int q;
    int i;
    int t;
    int r;
    int l;
    int j;

    scanf("%d",&t);

    for(j = 1; j <= t; j++) {
        scanf("%d%d",&n,&q);
        a[0] = -1;
        memset(b,0,sizeof(b));
        for(i = 1; i <= n; i++) {
            scanf("%d",&a[i]);
            if(a[i] == a[i-1]) {
                b[i] = b[i-1];
            }
            else if(a[i] != a[i-1]) {
                b[i] = b[i-1] + 1;
            }
        }
        printf("Case %d:\n",j);

        while(q--) {
            scanf("%d%d",&l,&r);
            printf("%d\n",b[r]-b[l]+1);
        }


    }
}
