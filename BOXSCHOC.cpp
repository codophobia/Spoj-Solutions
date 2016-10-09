#include <bits/stdc++.h>
using namespace std;
#define pi 3.14159265358979323846264338327950;
int main()
{
    int t;
    int n;
    int i;
    int k;
    int as;
    int b;
    int q;
    int j;
    int count;
    int a[100005];

    scanf("%d",&t);

    for(j = 1; j <= t; j++) {
        scanf("%d",&n);

        for(i = 1; i <= n; i++) {
            scanf("%d",&a[i]);
        }
        printf("Case %d:",j);

        scanf("%d",&q);

       // printf("Case %d:",j);

        while(q--) {
            scanf("%d%d%d",&as,&b,&k);
            count = 0;
            for(i = as; i <= b; i++) {
                if(a[i] % k == 0) {
                    count++;
                }
            }
            printf("%d\n",count);
        }



    }

}
