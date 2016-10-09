#include <bits/stdc++.h>
using namespace std;
#define pi 3.14159265358979323846264338327950;
int compare(long double x,long double y)
{
    return(x > y);
}
long double bsearch(long double a[],int n,int f)
{
    long double low,mid,high;
    long double current;
    low = 0;
    high = a[0];
    int req;
    int i;
    int j;

    for(i = 0; i < 100; i++) {
        mid = (high + low) / 2;
        req = 0;
        //cout<<mid<<endl;

        for(j = 0; j < n; j++) {
            req = req + (int)floor(a[j]/mid);
        }


        if(req >= f) {
            low = mid;
        }
        else {
            high = mid;
        }



    }

    return low;
}
int main()
{
    int t;
    int n;
    int f;
    int b[10005];
    long double a[10005];
    int i;

    scanf("%d",&t);
    long double ans;

    while(t--) {
        scanf("%d%d",&n,&f);

        for(i = 0; i < n; i++) {
            scanf("%d",&b[i]);
            a[i] = b[i] * b[i] * pi;
        }

        sort(a,a+n,compare);

       /* for(i = 0; i < n; i++) {
            cout<<a[i]<<endl;
        }*/



        ans = bsearch(a,n,f+1);


        printf("%.4Lf\n",ans);




    }
}
