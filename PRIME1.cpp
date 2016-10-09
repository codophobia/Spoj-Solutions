#include <stdio.h>
#include <iostream>
 
using namespace std;
int a[32000];
int p[10000];
 
int seive()
{
 
    int i;
    int j;
    int k;
 
 
    for(i = 3;i <= 180; i = i + 2  ) {
        if(!a[i]) {
            for(j = i + i; j < 32000; j = i + j) {
                a[j] = 1;
            }
        }
    }
    p[0] = 2;
    k = 1;
    for(i = 3; i < 32000; i = i + 2) {
        if(a[i] == 0) {
            p[k] = i;
            k++;
        }
    }
    /*for(i = 0; i < k; i++) {
        printf("%d ",p[i]);
    } */
    return k;
 
}
int main()
{
    int l = seive();
 
    int t;
    long long int m,n;
    long long int i;
    int k;
    int j;
    int flag;
    scanf("%d",&t);
 
    while(t--) {
        scanf("%lld%lld",&m,&n);
        for(i = m; i <= n; i++) {
                flag = 0;
                k = 0;
                if (i == 1000000000)
                    break;
                //printf("p =%d\n",p[0]);
            for(j = p[k];j * j <= i;j = p[k++]){
                if(i % j == 0) {
                        //printf("i = %ld ",i);
                        flag = 1;
                    break;
                }
            }
        if(flag == 0 && i != 1) {
            printf("%lld\n",i);
        }
        }
        printf("\n");
    }
return 0;
} 
