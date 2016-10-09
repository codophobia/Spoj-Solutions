#include <bits/stdc++.h>
using namespace std;

struct activity
{
    int start;
    int end;

};
int compare(activity x,activity y)
{
    if(x.end == y.end) {
        return(x.start < y.start);
    }

    return(x.end < y.end);
}
activity a[100005];

int main()
{
    int n;
    int i;
    int j;
    int count;
    int t;

    scanf("%d",&t);

    while(t--) {
        scanf("%d",&n);
        for(i = 0; i < n; i++) {
            scanf("%d%d",&a[i].start,&a[i].end);
        }
        sort(a,a+n,compare);

        count = 0;

        /*for(i = 0; i < n; i++) {
            printf("%d %d\n",a[i].start,a[i].end);
        }
        printf("\n");*/
        int e;
        e = -1;

        for(i = 0; i < n; i++) {
                if(a[i].start >= e) {
                   // printf("%d %d\n",i,j);
                    count++;
                    e = a[i].end;
                }
            }


        printf("%d\n",count);
    }

    return 0;

}
