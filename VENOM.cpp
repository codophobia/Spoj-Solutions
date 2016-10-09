#include <bits/stdc++.h>
using namespace std;
int bsearch(int h,int p,int a)
{
    long long int lo;
    long long int hi;
    long long int mid;
    long long int val;
    hi = h;
    lo = 1;

    while(lo < hi) {
        mid = lo + (hi-lo) / 2;
        val = h - (p*mid*(mid+1))/2 + (mid-1)*a;
        //cout<<val<<endl;
        if(val <= 0) {
            hi = mid;
        }
        else {
            lo = mid + 1;
        }
    }

    return lo;
}
int main()
{
    int t;
    int h;
    int p;
    int a;
    long long int ans;

    scanf("%d",&t);

    while(t--) {
        scanf("%d%d%d",&h,&p,&a);
        ans = bsearch(h,p,a);
        printf("%lld\n",2*ans-1);

    }
}
