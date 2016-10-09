#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int a[100005];
    int t;
    int i;
    int b[] = {-4, -3, -2, -4, -4, -3};

    scanf("%d",&t);

    while(t--) {
        scanf("%d",&n);
        for(i = 0; i < n; i++) {
            scanf("%d",&a[i]);
        }

        for(i = 0; i < n; i++) {
            if(a[i] < 0) {
                printf("%d ",a[i]);
            }
            else if(a[i] >= 6) {
                printf("-4 ");
            }
            else {
                printf("%d ",b[a[i]]);
            }

        }
        printf("\n");
    }
}
