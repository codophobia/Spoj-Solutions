#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char a[1000005];
void nextpalin(int n)
{
    int i;
    int j;
    int mid;
    int flag;
    flag = 0;

    mid = n / 2;
    i = mid - 1;
    j = (n % 2)?mid + 1:mid;


    while(i >= 0 && a[i] == a[j]) {
        i--;
        j++;
    }



    if(i < 0 || a[j] > a[i]) {

        flag = 1;
    }

    while(i >= 0) {

        a[j] = a[i];
        i--;
        j++;
    }


    int carry = 1;
    if(flag == 1){



        i = mid - 1;

        if(n % 2 == 1) {
            a[mid] = a[mid] + carry  ;
            carry = (a[mid] - '0') / 10;
            a[mid] = ((a[mid] - '0') % 10) + '0';
            j = mid + 1;
        }

        else {
            j = mid;
        }

    }



    while(i >= 0) {
        a[i] = a[i] + carry ;

        carry = ((a[i] - '0') / 10);

        a[i] = ((a[i] - '0') % 10) + '0';

        a[j] = a[i];
        j++;
        i--;


    }


}
int all9(int n)
{
    int i;


    for(i = 0; i < n; i++) {
        if(a[i] != 9 + '0') {
                return 0;

        }
    }

    return 1;
}
void all99(int n)
{
    int i;
    printf("1");

    for(i = 1; i < n; i++) {
        printf("0");
    }
    printf("1");
}
int main()
{
    int n;
    int t;
    int i;


    scanf("%d",&t);

    while(t > 0) {
        scanf("%s",a);
        n = strlen(a);


        if(all9(n)) {

            all99(n);

        }
        else {
            nextpalin(n);
            printf("%s",a);
        }
        t--;
        if(t > 0) {
            printf("\n");
        }

    }
    return 0;
}
