#include <stdio.h>
#include <string.h>
long int p[10000009];
long long int res[10000009];
void series() {
    memset(p,0,sizeof(p));
    memset(res,0,sizeof(res));
    long int i;
    long int j;

    for(i = 2; i <= 10000000; i++) {
        if(!p[i]) {
            for(j = i ; j <= 10000000; j = j + i) {
                if(!p[j] ) {
                    p[j] = i;
                    res[i] = res[i - 1] + i;
                }
            }
        }
        else {
            res[i] = res[i - 1] + p[i];
        }
    }

    

}

int main()
{
    series();
    int t;
    long int n;

    scanf("%d",&t);

    while(t--) {
        scanf("%ld",&n);
        printf("%lld\n",res[n]);
    }
}
