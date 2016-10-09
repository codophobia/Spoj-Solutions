#include <iostream>
#include <stdio.h>
using namespace std;
long long int pow(long long int base,long long int power,int m)
{
        long long result=1;
        while (power>0)
        {
                if (power%2==1)
                        result = (result*base) % m;
                base = (base*base)%m;
                power/=2;
        }
        return result;
}
int main()
{
    long long int a;
    long long  int b;
    int t;

    scanf("%d",&t);

    while(t--) {
        scanf("%lld%lld",&a,&b);
        printf("%lld\n",pow(a,b,10));
    }
}
