#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int m;
    int t;
    int d;
    int h[505];
    int i;
    int flag;

    scanf("%d",&t);

    while(t--) {
        scanf("%d%d%d",&n,&m,&d);
        flag = 0;

        for(i = 0; i < n; i++) {
            scanf("%d",&h[i]);
        }

        for(i = 0; i < n; i++) {
            while(h[i] - d > 0) {
                h[i] = h[i] - d;
                m--;
            }

            if(m <= 0) {
                flag = 1;
                break;
            }
        }

        if(flag == 1) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }



}
