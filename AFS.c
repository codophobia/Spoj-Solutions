#include <stdio.h>
#include <string.h>
#define size 1000005
long long int res[size];
long int p[size];;
void sieve()
{


        long int i;
        long int j;
        for(i = 0; i < size; i++) {
            p[i] = 1;
        }
        res[0] = 0;
        res[1] = 0;
        for(i = 2; i < size; i++) {
            res[i] = res[i - 1] + p[i];
            for(j = i + i; j < size; j = j + i) {
                p[j] = p[j] + i;


            }
        }


}



    int main()
    {

        sieve();
        int t;
        long int n;

        scanf("%d",&t);

        while(t--) {
            scanf("%ld",&n);
            printf("%lld\n",res[n]);
        }

        return 0;
    }






