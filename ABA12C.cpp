#include <bits/stdc++.h>
using namespace std;
struct points
{
    int x;
    int count;
};
points a[105];
int main()
{
    int n;
    int k;
    int t;
    int i;
    int j;

    scanf("%d",&t);

    while(t--) {
        scanf("%d%d",&n,&k);
        for(i = 1; i <= k; i++) {
            scanf("%d",&a[i].x);
            a[i].count = 1;
            if(a[i].x == -1) {
                a[i].x = 1000000000;
            }
        }

        for(i = 2; i <= k; i++) {
            for(j = 1; j < i; j++) {
                if((a[i-j].x + a[j].x) < a[i].x && (a[i-j].count + a[j].count) <= n) {
                    a[i].x = a[i-j].x + a[j].x;
                    a[i].count = a[i-j].count + a[j].count;
                }
            }
        }

        if(a[k].x == 1000000000) {
            printf("-1\n");
        }
        else {
            printf("%d\n",a[k].x);
        }
    }



}
