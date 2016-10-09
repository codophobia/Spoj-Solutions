#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int a[100005];
    int t;
    int i;
    int k;
    long long int sum;

    scanf("%d",&t);

    while(t--) {
        scanf("%d",&n);
        k = n - 1;
        sum = 0;
        for(i = 0; i < n; i++) {
            scanf("%d",&a[i]);
            sum = sum + a[i] * k;
            k = k - 2;
        }

        if(n == 1) {
            printf("%d\n",n);
        }
        else {

        printf("%lld\n",abs(sum));
        }


    }
}
