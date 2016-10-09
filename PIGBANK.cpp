#include <bits/stdc++.h>
using namespace std;
struct points
{
    int p;
    int w;
};
points a[505];
int main()
{
    int n;
    int t;
    int e;
    int f;
    int i;
    int j;
    int x;
    int min;

    scanf("%d",&t);

    while(t--) {
        scanf("%d%d",&e,&f);
        scanf("%d",&n);
        for(i = 0; i < n; i++) {
            scanf("%d%d",&a[i].p,&a[i].w);
        }
        x = f - e;
        int m[x+5];
        m[0] = 0;


        for(i = 1; i <= x; i++) {
            min = 1000000000;
            for(j = 0; j < n; j++) {
                if((m[i-a[j].w] + a[j].p) < min && a[j].w <= i) {
                    min = m[i-a[j].w] + a[j].p;
                }

            }

            m[i] = min;
        }

        if(m[x] == 1000000000) {
            printf("This is impossible.\n");
        }
        else {
            printf("The minimum amount of money in the piggy-bank is %d.\n",m[x]);
        }

    }
}
