#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    int n;
    int k;
    long int h[20005];
    int i;
    long long int min;
    int j;

    scanf("%d",&t);

    while(t--) {
            min = 1000000000;
        scanf("%d%d",&n,&k);



        for(i = 1; i  <= n; i++) {
            scanf("%ld",&h[i]);
        }

         if(k == 1) {
            printf("0\n");
            continue;
        }

        sort(h+1,h+n+1);



        for(i = 1; i  <= n; i++) {
            if(abs(h[i] - h[k]) <=  min) {
                    min = abs(h[i] - h[k]);
            }
            k = k + 1;

            if(k > n) {
                break;
            }
        }

        printf("%lld\n",min);




    }

    return 0;
}
