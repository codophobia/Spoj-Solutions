#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
void subtract(char x[],char y[],char n[],int l1,int l2)
{
    int a;
    int b;
    int i;
    int c;
    int k;
    int temp[101];
    c = 0;
    k = 0;

    memset(temp,0,sizeof(temp));
    while(l1 > 0) {
        a = x[l1 - 1] - '0';
        b = y[l2 - 1] - '0';
        if(l2 <= 0) {
            b = 0;
        }

        if(a < b + c) {
                temp[k++] = (10 + a) - b - c + '0';
                c = 1;
        }
        else {
            temp[k++] = a - b - c + '0';
            c = 0;
        }
        l1--;
        l2--;
    }


    int num;
    int j;
    j = 0;
    int count;
    count = 0;
    strcpy(n,"0");



    for(i = k - 1,a = 0; i >= 0; i--) {

            num = ((10 * a) + (temp[i] - '0')) / 2;

            a = ((10 * a) + (temp[i] - '0')) % 2;
            temp[i] = num + '0';

            if(num == 0 && count == 0) {

            }
            else {
                n[j++] = num + '0';
                count++;
            }



    }
    if(!j) {
        j++;
    }
    n[j] = 0;



}

void addition(char x[],char y[],char ka[],int l1,int l2)
{
    int a,b,c,k,i,j;
    char temp[101];
    int count,num;
    c = 0;
    count = 0;
    num = 0;
    k = 0;
    j = 0;

    memset(temp,0,sizeof(temp));

    while(l1 > 0 || l2 > 0||c) {
        a = l1 > 0?x[l1 - 1] - '0':0;
        b = l2 > 0?y[l2 - 1] - '0':0;
        temp[k++] = ((a + b + c) % 10) + '0';
        c = (a + b + c) / 10;
        l1--;
        l2--;
    }

    strcpy(ka,"0");

     for(i = k - 1,a = 0; i >= 0; i--) {

            num = ((10 * a) + (temp[i] - '0')) / 2;

            a = ((10 * a) + (temp[i] - '0')) % 2;
            temp[i] = num + '0';

            if(num == 0 && count == 0) {

            }
            else {
                ka[j++] = num + '0';
                count++;
            }
     }
     if(!j) {
        j++;
     }

     ka[j] = 0;



}

int main()
{
    char x[101];
    int t;
    char y[101];
    char ka[101];
    char n[101];

    int l1;
    int l2;
    memset(n,0,sizeof(n));
    memset(ka,0,sizeof(ka));
    t = 10;

    while(t--) {
    scanf("%s",x);
    scanf("%s",y);

    l1 = strlen(x);
    l2 = strlen(y);

    addition(x,y,ka,l1,l2);
    subtract(x,y,n,l1,l2);


    printf("%s\n",ka);
    printf("%s\n",n);




}
return 0;
}
























