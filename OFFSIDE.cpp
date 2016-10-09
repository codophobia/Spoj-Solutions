#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a;
    int d;
    int b[10005];
    int c[10005];
    int i;

    while(1) {
        scanf("%d%d",&a,&d);

        if(a == 0 && d == 0) {
            break;
        }

        for(i = 0; i < a; i++) {
            scanf("%d",&b[i]);
        }

        for(i = 0; i < d; i++) {
            scanf("%d",&c[i]);
        }

        sort(b,b+a);
        sort(c,c+d);

        if(b[0] >= c[1]) {
            printf("N\n");
        }
        else {
            printf("Y\n");
        }
    }

    return 0;
}
