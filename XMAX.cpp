#include <bits/stdc++.h>
using namespace std;
long long int a[100005];
int main()
{
    
    int i;
    int n;

    long long int y;
    long long int max;
    map<long long,int> m1,m2;
    map<long long,int>:: iterator it;

        scanf("%d", &n);


        for (i = 0; i < n; i++){
            scanf("%lld", &a[i]);
        }
        m1[0] = 1;
        for (i = 0; i < n; i++){
        m2 = m1;
        for(it = m2.begin();it != m2.end();it++){
            m1[(it->first)^a[i]] = 1;

        }
        }
        max = 0;

        for(it = m1.begin(); it != m1.end();it++) {
            y = (it->first);
            if(y > max) {
                max = y;
            }
        }

        printf("%lld\n", max);
        m1.clear();
        m2.clear();

    return 0;
}
