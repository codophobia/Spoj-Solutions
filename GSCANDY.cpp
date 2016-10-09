#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    long long int a[10005];
    long long int c[10005];
    int i;
    long long int x;
    long long int max;
    int t;

    scanf("%d",&t);

    while(t--) {
        scanf("%d",&n);
        for(i = 1; i <= n; i++) {
            scanf("%lld",&a[i]);
        }
        map<long long int,pair<int,int> > m;

        max = 0;
        memset(c,0,sizeof(c));

        for(i = 1; i <= n; i++) {
                x = a[i];
            if(m[x].first + c[m[x].second] >= c[i-1]) {
                c[i] = c[m[a[i]].second] + m[a[i]].first + 1;
                m[a[i]].first += 1;
                m[a[i]].second = i;
                //cout<<1<<' '<<c[i]<<endl;

            }
            else {
                c[i] = c[i-1] + 1;
                m[a[i]].first = 1;
                m[a[i]].second = i;
               // cout<<c[i]<<endl;
            }


        }

        for(i = 1; i <= n; i++) {
            if(c[i] > max) {
                max = c[i];
            }
        }

        printf("%lld\n",max);
    }


}
