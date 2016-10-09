#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[1005];
    int b[1005];
    int i;
    int n;
    int flag;
    int t;

    scanf("%d",&t);

    while(t--) {
        scanf("%d",&n);
        memset(b,0,sizeof(b));
        flag = 0;
        for(i = 0; i < n; i++) {
            scanf("%d",&a[i]);

        }

        for(i = 0; i < n; i++) {

             if(b[a[i]] == 0) {
                b[a[i]] = 1;
            }
            else if(b[a[i]] == 1 && b[n-a[i]-1] == 0 && a[i] < n) {
                b[n-a[i]-1] = 1;
            }


        }

        /*for(i = 0; i < n; i++) {
            printf("%d ",b[i]);
        }
        printf("\n");*/

        for(i = 0; i < n; i++) {
            if(b[i] == 0) {
                flag = 1;
                break;
            }
        }

        if(flag == 1) {
            printf("NO\n");
        }
        else {
            printf("YES\n");
        }
    }
}
