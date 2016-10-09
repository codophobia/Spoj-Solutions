#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int l[2005];
    int i;
    int j;
    int sum;
    int k;
    int count;



        scanf("%d",&n);
        while(n != 0) {
        for(i = 0; i < n; i++) {
            scanf("%d",&l[i]);
        }
        sort(l,l+n);
        count = 0;

        for(i = 0; i <  n; i++) {
            for(j = i + 1; j < n; j++) {
                sum = l[i] + l[j];

                if(sum < l[n-1]) {
                    int b = upper_bound(l+j,l+n,sum)-l;
                    count = count + (n - b);
                }
            }
        }



        printf("%d\n",count);
         scanf("%d",&n);
    }

    return 0;
}
