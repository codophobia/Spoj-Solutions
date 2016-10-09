#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    int a;
    int b;
    int c;
    int i;

    scanf("%d",&t);

    for (i = 1; i <= t; i++) {
        scanf("%d%d%d",&a,&b,&c);

        if(c % __gcd(a,b) == 0) {
            printf("Case %d: Yes\n",i);

        }
        else {
            printf("Case %d: No\n",i);
        }
    }

    return 0;
}
