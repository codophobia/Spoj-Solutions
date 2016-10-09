#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int a[10005];
    int n;
    int i;
    int count1;
    int count2;
    int avg;
    int sum;

    while(1) {
        scanf("%d",&n);
        if(n == -1) {
            break;
        }
        sum = 0;
        count1 = 0;
        count2 = 0;

        for(i = 0; i < n; i++) {
            scanf("%d",&a[i]);
            sum = sum + a[i];
        }
        avg = sum / n;

        for(i = 0; i < n; i++) {
            if(a[i] > avg) {
                count1 = count1 + (a[i] - avg);
            }
            else {
                count2 = count2 + (avg - a[i]);
            }
        }

        if(count1 == count2) {
            printf("%d\n",count1);
        }
        else {
            printf("%d\n",-1);
        }
    }
}
