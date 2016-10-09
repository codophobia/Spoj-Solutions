#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    int a[1005];
    int n;
    int s;
    int i;
    int sum;
    int count;
    int j;

    scanf("%d",&t);

    for(j = 1; j <= t; j++) {
        scanf("%d%d",&s,&n);

        for(i = 0; i < n; i++) {
            scanf("%d",&a[i]);
        }

        sort(a,a+n);
        count = 0;
        sum = 0;

        for(i = n - 1; i >= 0; i--) {
            sum = sum + a[i];
            if(sum < s) {
                count++;
            }

        }

        printf("Scenario #%d:\n",j);
        if(sum < s){
            printf("impossible\n");
        }
        else {
        printf("%d\n",count + 1);
        }
        printf("\n");




    }

    return 0;
}
