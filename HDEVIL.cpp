#include <bits/stdc++.h>
using namespace std;
long long int sum(int n)
{
    long long int sum;
    int i;
    sum = 0;

    for(i = 2; i <= sqrt(n); i++) {
        if( i*i == n) {
            sum = (sum + i);
        }
        else if(n % i == 0) {
            sum = (sum + i + (n / i));
        }
    }

    return (sum + 1);
}
int count(long long int n)
{
    int count;
    int i;
    count = 0;

    for(i = 2; i <= sqrt(n); i++) {
        if(i * i == n) {
            count = count + 1;
        }
        else if(n % i == 0) {
            count = count + 2;
        }
    }

    return (count + 1);
}
int main()
{
    int t;
    int n;
    int m;
    int i;
    long long int s;
    long long int a;
    long long int b;
    long long int as;
    long long int bs;

    scanf("%d",&t);

    for(i = 1; i <= t; i++) {
        scanf("%d%d",&n,&m);
        s = sum(n);

        s = s % m;
        s = count(s);
        a = (5 * s * s) + 4;
        b = (5 * s * s) - 4;
        as = sqrt(a);
        bs = sqrt(b);

        if(as * as == a || bs * bs == b) {
                printf("Case #%d : YES.\n",i);

        }
        else {
             printf("Case #%d : NO.\n",i);
        }



    }

    return 0;
}
