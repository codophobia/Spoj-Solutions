#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
using namespace std;

int check[1000009];
int a[1000];


int prime(int n)
{
    int i;

    if(n == 2) {
        return 1;
    }
    else if(n % 2 == 0 || n == 1) {
        return 0;
    }

    else {
        for(i = 3; i <= sqrt(n); i = i + 2) {
                if(n % i == 0) {
                    return 0;
                    break;
                }

        }
        return 1;
    }

}


long int divsum(int n)
{
    int i;
    long int sum;
    sum = 0;

    for(i = 2; i <= sqrt(n);i++) {

            if(n % i == 0) {
            sum = sum + i + (n / i);
            }

            if(n == i * i) {
                sum = sum - i;
            }

    }


    return (sum + 1 + n);
}

int main()
{

    int t;
    int i;
    int count;
    int sum;

    int c,b;
    int res;

    scanf("%d",&t);
    memset(check,0,sizeof(check));


    for(i = 2; i <= 1000; i++) {
        a[i] = i * i;
    }
    int k;
    k = 1;
    check[0] = 2;

    for(i = 2;i <= 1000; i++) {
            res = divsum(a[i]);
        if(prime(res) == 1) {
            check[k] = a[i];
            k++;
        }
    }


    while(t--) {
        scanf("%d%d",&b,&c);

        i = 0;
        count = 0;

        for(i = 0; i < k; i++) {
            if(check[i] >= b && check[i] <= c) {
                count++;
            }
        }

        printf("%d\n",count);
    }


    /*while(t--) {
        scanf("%d%d",&c,&b);
        count = 0;
        for(i = c; i <= b; i++) {
                sum = a[i];
                if((check[sum]) == 0) {
                    count++;
                }

        }
        printf("%d\n",count);
    }*/
}
