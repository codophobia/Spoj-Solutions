#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    int d[100005];
    int dp[100005];
    int vp[100005];
    int i;
    int j;
    int k;
    long long int dis;
    int total_d;
    int total_v;



    while(1) {
        scanf("%d",&n);

        if(n == 0) {
            break;
        }


        j = 0;
        k = 0;
        dis = 0;

        for(i = 0; i < n; i++) {
            scanf("%d",&d[i]);
            if(d[i] >= 0) {
                vp[j] = i;
                j++;
            }

            else if(d[i] < 0) {
                d[i] = -1 * d[i];
                dp[k] = i;
                k++;
            }
        }

       /*for(i = 0; i  <n; i++) {
            printf("%d ",d[i]);
        }
        printf("\n");

         for(i = 0; i  < j; i++) {
            printf("%d ",vp[i]);
        }
        printf("\n");

         for(i = 0; i  < k; i++) {
            printf("%d ",dp[i]);
        }
        printf("\n");

        printf("%d %d\n",j,k);*/




        total_d = k;
        total_v = j;

        i = 0;
        j = 0;

        while(i < total_v && j < total_d) {

            if(d[vp[i]] < d[dp[j]] ) {


                dis = dis + (d[vp[i]] * abs(dp[j] - vp[i]));

                d[dp[j]] = d[dp[j]] - d[vp[i]];
                d[vp[i]] = 0;
                i++;
            }
             else if(d[vp[i]] > d[dp[j]]) {



                dis = dis + (d[dp[j]] * abs(dp[j] - vp[i]));

                d[vp[i]] = d[vp[i]] - d[dp[j]];
                d[dp[j]] = 0;
                j++;
            }
            else {



                dis = dis + (d[vp[i]] * abs(dp[j] - vp[i]));
                 d[dp[j]] = 0;
                d[vp[i]] = 0;
                i++;
                j++;
            }


        }

        printf("%lld\n",dis);
    }

    return 0;








}
