#include <bits/stdc++.h>
using namespace std;

int in[1000005];
int p[100000];
void sieve()
{
    int i ;
    int j;
    int k;

    in[1] = 1;
    memset(in,0,sizeof(in));

    for(i = 2; i <= sqrt(1000005); i++) {
        if(in[i] == 0) {
            for(j = i * i; j < 1000005; j= j + i) {
                in[j] = 1;
            }
        }
    }

    p[0] = 2;
    k = 1;

    for(i = 3; i < 1000005; i++) {
        if(in[i] == 0) {
            p[k++] = i;
        }
    }

    /*for(i = 0; i < v.size(); i++) {
        cout<<v[i]<<endl;
    }*/


}
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
            }
        }

        return 1;
    }
}
int main()
{
    int t;
    int n;
    int a[10];
    sieve();
    int i;
    int j;
    int k;
    int m;
    int max;

    scanf("%d",&t);

    for(j = 1; j <= t; j++) {
        scanf("%d",&n);
        m = 1;
        k = 0;
        max = 0;
        for(i = 0; i < n; i++) {
            scanf("%d",&a[i]);
        }
        for(i = 0; i < n; i++) {
            m = m * a[i];
        }

        m = m + 1;

        if(prime(m) == 1) {
            //cout<<111<<endl;
            printf("Case #%d: %d\n",j,m);
            continue;
        }
        else {
            for(i = p[k]; i * i <= m; i = p[k++]) {
                while(m % i == 0) {
                    if(i > max) {
                        max = i;
                    }
                    m = m / i;
                }
            }

            if(m != 1) {
                if(m > max) {
                    max = m;
                }
            }

            printf("Case #%d: %d\n",j,max);
        }



    }


}
