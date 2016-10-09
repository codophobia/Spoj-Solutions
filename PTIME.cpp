#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;
int p[3008];
int in[10007];
void sieve()
{
    int i;
    int j;
    int k;
    memset(in,0,sizeof(in));

    for(i = 2; i <= 105; i++) {
        if(in[i] == 0) {
            for(j = i * i; j <= 10007; j = i + j) {
                in[j] = 1;
            }
        }
    }


    p[0] = 2;
    k = 1;
    for(i = 3; i <= 10007; i++) {
        if(in[i] == 0) {
            p[k]= i;
            k++;
        }
    }








}
int main()
{
    sieve();

    int i;
    int k;
    int n;
    int j;
    int s;
    int count;
    int m;



        scanf("%d",&n);
        k = 0;
        j = 0;
        s = 0;
        for(i = p[k]; i  <= n; i = p[++k]) {
                count = 0;
                m = n;

            while(m > 0){
                   // printf("%d ",i);
                m = m / i;
                count = count + m;
            }
            s++;

           if(s > 1) {
                printf(" * ");
            }
            printf("%d^%d",i,count);









        }
        printf("\n");
        return 0;
    }



