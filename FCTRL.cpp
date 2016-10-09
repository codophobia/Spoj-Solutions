#include <iostream>
#include <stdio.h>
using namespace std;

int trail_zeros(long int n)
{
    int count;
    count = 0;

    while(n > 0) {
        count = count + (n / 5);
        n = n / 5;
    }

    return count;
}
int main()
{
    int t;
    long int n;

    scanf("%d",&t);

    while(t--) {
        scanf("%ld",&n);
        printf("%ld\n",trail_zeros(n));
    }
}
