#include <stdio.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
long long int modexp(long long base,long long power,long long M)
{
        long long result=1;
        while (power>0)
        {
                if (power%2==1)
                        result = (result*base)%M;
                base = (base*base)%M;
                power/=2;
        }
        return result % M;
}
int prime(long long int n)
{
    int i;
    long long int a;
    long long int s;
    long long int temp;
    s = n - 1;
    srand(time(NULL));

    if(n == 1) {
        return 0;
    }
    if(n % 2 == 0 & n != 2) {
        return 0;
    }

    while(s % 2 == 0) {
        s = s / 2;
    }

    temp = s;


    for(i = 0; i < 20; i++) {

        a = rand() % (n - 1) + 1;

        long long int x = modexp(a,temp,n);

        while(temp != n -1 && x != 1 && x != n - 1) {
            x = modexp(x,x,n);
            temp = temp * 2;
        }

        if(x != n - 1 && temp % 2 == 0) {
            return 0;
        }
    }
    return 1;

}


int main()
{
    int t;
    long long int n;


    scanf("%d",&t);

    while(t--) {
            scanf("%lld",&n);

            if(prime(n)) {
                printf("YES\n");
            }
            else {
                printf("N0\n");
            }


    }
    return 0;
}

