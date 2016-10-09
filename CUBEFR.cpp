#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;
int a[1000001];
int c[1000001];
void sieve()
{
    int i;
    int j;
    int k;
    int cu;
    memset(a,0,sizeof(a));
    memset(c,0,sizeof(c));
    for(i = 2; i <= 100; i++) {
        if(a[i] == 0) {
            cu = i * i * i;
            for(j = cu;j <= 1000001;j = j + cu) {
                a[j] = 1;
            }
            }
        }


    k = 1;
    for(i = 1; i <= 1000003; i++) {
        if(a[i] == 0) {
            c[i] = k++;

        }
    }
    /*for(i = 100; i < 1000; i++) {
        printf("%d ",a[i]);
    }*/


}
int main()
{
    sieve();
    int t;
    int n;
    int i;

    scanf("%d",&t);

    for(i = 1; i <= t; i++) {
        scanf("%d",&n);
        if(a[n] != 1) {

            printf("Case %d: %d\n",i,c[n]);
        }
        else {

            printf("Case %d: Not Cube Free\n",i);
        }
    }

    return 0;

}


