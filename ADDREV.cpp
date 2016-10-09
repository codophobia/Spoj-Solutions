#include <iostream>
#include <stdio.h>
using namespace std;

int reverse(int n)
{
    int sum;
    int q;
    sum = 0;

    while(n > 0) {
            q = n % 10;
            sum = q + (sum * 10);
            n = n / 10;
    }

    return sum;

}
int main()
{
    int t;
    int a;
    int b;
    int s;

    scanf("%d",&t);

    while(t--) {
        scanf("%d%d",&a,&b);
        s = reverse(a) + reverse(b);
        printf("%d\n",reverse(s));
    }
    return 0;
}

