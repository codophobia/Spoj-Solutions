#include <bits/stdc++.h>
using namespace std;
int in[1000070];
int d[1000100];
int c[10000070];
void sieve()
{

    int i;
    int j;
    int k;

    in[1] = 1;
    for(i = 2;i <= sqrt(1000070);i++ ) {
        if(!in[i]) {
            for(j = i + i; j < 1000070; j = i + j) {
                in[j] = 1;
            }
        }
    }
}

void devlali()
{
    int i;

    int j;
    j = 1;
    int n;

    int s;

    for(i = 0; i <= 1000005; i++) {


            n = i;
            s = n;

            while(n > 0) {
                s = s + (n % 10);
                n = n / 10;
            }

            d[s] = 1;

    }
    c[0] = 0;

    for(i = 1; i <=1000005; i++) {
            if(d[i] == 0 && in[i] == 0) {
                c[i] = c[i - 1] + 1;
            }
            else {
                c[i] = c[i - 1];
            }

    }





}

int main()
{
    memset(in,0,sizeof(in));
    memset(d,0,sizeof(d));
    sieve();
    devlali();
    int q;

    int a,b;
    int i;
    int count;

    scanf("%d",&q);

    while(q--){
        scanf("%d%d",&a,&b);
        if(a == 0)
        printf("%d\n",c[b] - c[a]);
        else {
            printf("%d\n",c[b]-c[a - 1]);
        }

    }
    return 0;
}
