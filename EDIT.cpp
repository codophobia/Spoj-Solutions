#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    char a[1005];
    int b1[1005];
    int b2[1005];
    int b3[1005];

    int i;
    int count1,count2;
    int len;
    int j;



    while(scanf("%s",a) != EOF) {

        len = strlen(a);
        i = 0;
        for(i = 0; i < len; i++) {
            if(islower(a[i])) {
                b1[i] = 0;
            }
            else {
                b1[i] = 1;
            }
        }
        int a;
        int b;

        for(i = 0; i < len; i++) {
                a = (i % 2 == 0)?1:0;
                b = (i % 2 == 0)?0:1;
                b2[i] = a;
                b3[i] = b;


        }


        count1 = 0;
        count2 = 0;

        for(i = 0; i < len; i++) {
            if(b1[i] != b2[i]) {
                count1++;
            }
            else if(b1[i] != b3[i]) {
                count2++;
            }
        }

        if(count1 < count2) {
            printf("%d\n",count1);
        }
        else {
            printf("%d\n",count2);
        }
    }
    return 0;
}














