#include <bits/stdc++.h>
using namespace std;
int main()
{
    long int n;

    scanf("%ld",&n);

    if(n % 10 == 0) {
        printf("2\n");
    }
    else {
        printf("1\n");
        printf("%d\n",n%10);
    }

    return 0;
}
