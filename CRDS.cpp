#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;

    long long int n;
    long long int a;
    long long int i;
    long long int m;
    long long int b;
    long long int c;
    m = 1000007;

    scanf("%d",&t);

    for(i = 1; i <= t; i++) {
        scanf("%lld",&n);

        printf("%lld\n",(n*(3*n+1)/2)% m);


        //printf("%lld\n",a%m);


    }


}
