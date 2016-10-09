#include <bits/stdc++.h>
using namespace std;
#define LOG2(X) ((unsigned) (8*sizeof (unsigned long long) - __builtin_clzll((X)) - 1))

int main()
{
    int t;
    long long int n,k,m;
    long long int count;



    scanf("%d",&t);

    while(t--) {
        scanf("%lld%lld%lld",&n,&k,&m);

        if(m <= n) {
            printf("0\n");
            continue;
        }

        count = LOG2(m/n)/LOG2(k);

        printf("%lld\n",count);









    }

    return 0;
}
