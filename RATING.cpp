#include <bits/stdc++.h>
using namespace std;
struct code
{
    int otr;
    int hr;
};
code a[300005];




/*int compare(code x,code y)
{
    if(x.otr = y.otr && x.hr > y.hr) {
        return(x.hr > y.hr);
    }
    else if(x.hr == y.hr && x.otr > y.otr) {
        return(x.otr > y.otr);
    }
    else {
        return (x.otr > y.otr && x.hr > y.hr);
    }
}*/
int main()
{
    int i;
    int n;

    int count;
    int j;

    scanf("%d",&n);

    for(i = 0; i < n; i++) {
        scanf("%d%d",&a[i].otr,&a[i].hr);
    }

    for(i = 0; i < n; i++) {
        count = 0;
        for(j = 0; j < n; j++) {
            if((a[j].hr >= a[i].hr || a[j].otr > a[i].otr) && (a[j].hr > a[i].hr || a[j].otr >= a[i].otr) ) {
                //cout<<a[j].otr<<' '<<a[j].hr<<endl;
                count++;
            }
        }
        cout<<n-count<<endl;
        //cout<<n-count-1<<endl;
    }



}
