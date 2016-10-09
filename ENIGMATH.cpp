#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    int a;
    int b;
    int g;

    scanf("%d",&t);

    while(t--) {
        scanf("%d%d",&a,&b);
        if(a > b) {
            g = __gcd(a,b);
        }
        else {
            g = __gcd(b,a);
        }

        printf("%d %d\n",b/g,a/g);
    }
}
