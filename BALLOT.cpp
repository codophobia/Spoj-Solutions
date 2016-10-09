#include <bits/stdc++.h>
using namespace std;
int a[500005];
int bsearch(int a[],int n,int k)
{
     int lo;
    long long int hi;
    long long int mid;
    int i;
    long long int count;
    lo = 1;
    hi = a[n-1];

    while(lo < hi) {
        mid = lo + (hi-lo)/2;
        count = 0;
        for(i = 0; i < n; i++) {
            if(a[i] > mid) {
                count = count + (a[i]/mid);
                if(a[i] % mid > 0) {
                    count++;
                }
            }
            else {
                count = count + 1;
            }
        }

        if(count <= k) {
            hi = mid;
        }
        else {
            lo = mid+1;
        }
    }

    return lo;

}
int main()
{
    int k;
    int n;
    int t;

    int i;
    int ans;



        while(1) {
        scanf("%d%d",&n,&k);
        if(n == -1 && k == -1) {
            break;
        }

        for(i = 0; i < n; i++) {
            scanf("%d",&a[i]);
        }

        sort(a,a+n);

        ans = bsearch(a,n,k);

        printf("%d\n",ans);
        }




}
