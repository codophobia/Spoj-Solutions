#include <stdio.h>
#include <string.h>
#include <math.h>
int p[100000];
int in[10000005];
void sieve()
{
    int i;
    int j;
    int k;

    in[1] = 1;

    for(i = 2; i <= 3200; i++) {
        if(in[i] != 1) {
            for(j = i * i; j < 10000005; j = j + i) {
                in[j] = 1;
            }
        }
    }
    p[0] = 2;
    k = 1;

    for(i = 3; i < 10000005; i++) {
            if(in[i] == 0) {
                p[k++] = i;
            }

    }


}
int main()
{
    sieve();
    int t;
    long long int n;
    long long int i;
    int k;
    int ceven;
    int codd;
    int count;
    int flag;

    scanf("%d",&t);

    while(t--) {
        scanf("%lld",&n);
        ceven = 0;
        codd = 0;
        k = 0;
        flag = 0;

        if(n < 10000000 && in[n] == 0) {
            printf("Ordinary Number\n");
            continue;
        }
        if(n > 10000000 && n % 2 != 0) {


            for(i = 3; i <= sqrt(n); i = i + 2) {
                if(n % i == 0) {
                    flag = 1;
                    break;
                }
            }

            if(flag == 0) {
                printf("Ordinary Number\n");
                continue;
            }
        }



        for(i = p[k]; i * i <= n; i = p[k++]) {
            count = 0;
            while(n % i == 0) {
                count++;
                n = n / i;
            }

            if(n < 10000000 && in[n] == 0) {
                break;
            }






            if(count % 2 == 0 && count != 0) {
                ceven++;
            }
            else if(count % 2 == 1){
                codd++;
            }

        }



        if(n != 1) {
            codd++;
        }

        if(ceven > codd) {
            printf("Psycho Number\n");
        }
        else {
            printf("Ordinary Number\n");
        }
    }

    return 0;

}


