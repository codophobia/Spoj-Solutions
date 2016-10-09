#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    int n;
    int i;
    int a[100005];
    long long int sum,sumt;

    scanf("%d",&t);

    while(t--) {
        scanf("%d",&n);
        sumt = 0;
        multimap<int,int> m;
        multimap<int,int>::iterator it;
        for(i = 0; i < n; i++) {
            scanf("%d",&a[i]);
        }

        for(i = 0; i < n; i++) {
                sum = 0;
            for(it = m.begin(); it != m.end(); it++) {
                if(it->first >= a[i]) {
                    break;
                }
                else {
                    sum = sum + it->first;
                }
            }

            m.insert(pair<int,int> (a[i],0));
            sumt = sumt + sum;
        }

        printf("%lld\n",sumt);
        m.clear();
    }


}
