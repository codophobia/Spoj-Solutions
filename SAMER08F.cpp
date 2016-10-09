#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int n;
    int i;
    int sum;

    while(1) {
        scanf("%d",&n);
        sum = 0;
        if(n == 0) {
            break;
        }
        else {
            for(i = 1; i <= n; i++) {
                sum = sum + (i * i);
            }
            printf("%d\n",sum);
        }
    }
}
