#include <bits/stdc++.h>
using namespace std;
int binarysrch(int a[],int n,int c)
{
    int low;
    int high;
    int mid;
    int i;
    long int currentdis;
    int placed;
    low = 0;
    high = a[n-1]-a[0];
    //cout<<high<<endl;

    while(low < high) {
         mid = low + (high-low+1)/2;
        //cout<<mid<<endl;

        placed = 1;
        currentdis = a[0];

        for(i = 1; i < n; i++) {
            if(a[i]-currentdis >= mid) {
                placed++;
                currentdis = a[i];
            }

        }

        if(placed >= c) {
            low = mid;
        }
        else {
            high = mid-1;
        }
    }



    return low;






}
int main()
{
    int t;
    int n;
    int c;
    int i;
    //int b[100005];
    int a[100005];

    scanf("%d",&t);

    while(t--) {
        scanf("%d%d",&n,&c);

        for(i = 0; i < n; i++) {
            scanf("%d",&a[i]);
        }

        sort(a,a+n);



        printf("%d\n",binarysrch(a,n,c));
    }
}
