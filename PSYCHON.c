#include <stdio.h>
#include <string.h>
#include <math.h>
int p[10000];
int in[3200];
void sieve()
{
    int i;
    int j;
    int k;
    memset(in,0,sizeof(in));
    in[1] = 1;

    for(i = 2; i <= sqrt(3200); i++) {
        if(in[i] != 1) {
            for(j = i * i; j < 3200; j = j + i) {
                in[j] = 1;
            }
        }
    }
    p[0] = 2;
    k = 1;

    for(i = 3; i < 3200; i++) {
            if(in[i] == 0) {
                p[k++] = i;
            }

    }


}
int main()
{
    sieve();
    int t;
    int n;
    int i;
    int k;
    int ceven;
    int codd;
    int count;

    scanf("%d",&t);

    while(t--) {
        scanf("%d",&n);
        ceven = 0;
        codd = 0;
        k = 0;

        for(i = p[k]; i * i <= n; i = p[k++]) {
            count = 0;
            while(n % i == 0) {
                count++;
                n = n / i;
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

