#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n;
    int i;
    int j;
    long long int count;
    count = 0;

    scanf("%d",&n);

    for(i = 1; i <= sqrt(n); i++) {
        for(j = i + 1; i * j <= n; j++) {
            count++;
        }
    }
    count = count + sqrt(n);

    printf("%lld\n",count);
    
    return 0;



}
