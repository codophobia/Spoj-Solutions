#include <iostream>
#include <stdio.h>
#include <string.h>
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

    long long  int b;
    char a[1005];
    int t;

    scanf("%d",&t);

    while(t--) {
        scanf("%s%lld",a,&b);
        int d = a[strlen(a)-1] - '0';
        printf("%lld\n",pow(d,b,10));
    }
    
    return 0;
}

