#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int x;
    long long int y;
    long long int z;
    long long int a;
    long long int d;
    long long int n;
    long long int i;
    long long int j;
    long long int t;
 
    scanf("%lld",&t);
 
    while(t--) {
        scanf("%lld%lld%lld",&x,&y,&z);
        n = (2 * z) / (x + y);
        d = (y - x) / (n - 5);
        a = x - (2 * d);
        printf("%lld\n",n);
        i = a;
 
        for(j = 0;j < n;j++) {
            printf("%lld ",i);
            i = i + d;
        }
        printf("\n");
 
    }
 
 
    return 0;
}
 
 
 
 
 